#include "tree.h"
#include "Generator.hpp"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

void init();

Generator generator;

void setGenerator(char * p)
{
    if(!generator.open(p))
    {
        printf("Cannot open target asm file.\n");
        exit(2);
    }
}

typedef vector<map<string, Variable> > VarList;
VarList varList;

void init()
{
    varList.clear();
    varList.push_back(map <string, Variable> ());

    generator.labels[0].push_back("# produced by SYF compiler");

    int k;
    k = generator.nextAsm;
    generator << ".string\t\"%d\\n\"\n";
    generator.labels[k].push_back(".WT");
    k = generator.nextAsm;
    generator << ".string\t\"%d\"\n";
    generator.labels[k].push_back(".RD");
}

// 在最外层搜索，cpp文件中使用
Variable findVarInOut(string name, int * found)
{
    if(varList.back().count(name))
    {
        *found = 1;
        return varList.back()[name];
    }
    else
    {
        *found = 0;
        return Variable();
    }
}

// 不同的作用域
Variable findVar(string name, int * found)
{
    for(auto i = varList.end()-1; i >= varList.begin(); i--)
    {
        if(i->count(name))
        {
            *found = 1;
            return (*i)[name];
        }
    }
    *found = 0;
    return Variable();
}

int insertVarList(Variable var)
{
    int s;
    findVarInOut(var.name, &s);
    if(s)
    {
        // 已经有一个变量叫这个名字了
        printf("Error when looking up table!\n");
        exit(4);
    }

    varList.back()[var.name] = var;
    return 1;
}

int insertVarList(char * name, VarType type, int value, int dim, int dim1, int dim2)
{
    if(type == Const)
    {
        Variable var(name, type);
        var.value = value;
        generator.genConst(var);
        return insertVarList(var);
    }
    else if(type == Normal)
    {
        Variable var(name, type);
        var.pos = generator.newInt();
//        generator << "movl\t$" << to_string(value)
//            << ", " << genAddr(var.pos) << "\n";
        return insertVarList(var);
    }
    else if(type == ConstArray)
    {
        // TODO: Const Array
        printf("ERROR! Unfinished\n");
    }
    else if(type == Array)
    {
        Variable var(name, type);
        var.dim = dim;
        int size = 4;
        if(dim == 1)
        {
            var.dim1 = dim1;
            size *= dim1;
        }
        else if(dim == 2)
        {
            var.dim1 = dim1;
            var.dim2 = dim2;
            size *= dim1 * dim2;
        }
        else
        {
            printf("Error! Todo...\n");
            return 0;
        }
        var.pos = generator.newBytes(size);

        return insertVarList(var);
    }
    else if(type == GlobalNormal)
    {
        Variable var(name, type);
        generator << ".text\n";
        generator << ".data\n";
        generator << ".align\t4\n";
        generator << ".globl\t" << name << "\n";
        generator << ".type\t" << name << ", @object\n";
        generator << ".size\t" << name << ", 4\n";
        int k = generator.nextAsm;
        generator << ".long\t" << to_string(value) << "\n";
        generator.labels[k].push_back(name);
        varList.back()[name] = var;
    }
    else if(type == GlobalArray)
    {
        Variable var(name, type);
        var.dim = dim;
        int size = 4;
        if(dim == 1)
        {
            var.dim1 = dim1;
            size *= dim1;
        }
        else if(dim == 2)
        {
            var.dim1 = dim1;
            var.dim2 = dim2;
            size *= dim1 * dim2;
        }
        else
        {
            printf("Error! Todo...\n");
            return 0;
        }
        generator << ".text\n";
        generator << ".bss\n";
        generator << ".align\t32\n";
        generator << ".globl\t" << name << "\n";
        generator << ".type\t" << name << ", @object\n";
        generator << ".size\t" << name << ", " << to_string(size) << "\n";
        int k = generator.nextAsm;
        generator << ".zero\t" << to_string(size) << "\n";
        generator.labels[k].push_back(name);
        varList.back()[var.name] = var;
    }

    return 0;
}

void genFuncHead(char * p)
{
    generator.genFuncHead(p);
}

const char * TerminalAndNonTerminalNames [] = {
    "Start",
    "CompUnit",
    "OtherCompUnit",
    "Declaration",
    "ConstDecl",
    "ConstDef",
    "ConstExp",
    "ConstInitVal",
    "VarDecl",
    "VarDef",
    "VarInitVal",
    "ooB",
    "Func",
    "FuncFParams",
    "FuncRParams",
    "FuncDef",
    "Block",
    "BlockItem",
    "Statement",
    "LValue",
    "Condition",
    "Expression",
    "AddExp",
    "OrOrExp",
    "PrimaryExp",
    "UnaryExp",
    "UnaryOp",
    "MultiExp",
    "RelExp",
    "EqualExp",
    "AndAndExp",
    "FuncFParam",
    "BlockItems",
    "ConstDefList",
    "ArrayDimExp",
    "ConstArrayDimExp",
    "ArrayContent",
    "VarDefList",
    "ConstArrayContent",
    "ConstArrayInitVal",
    "ArrayInitVal",
    "UndefinedSymbol",
    "Number",
    "Identifier",
    "int",
    "void",
    "if",
    "else",
    "break",
    "continue",
    "return",
    "const",
    "while",
    "(",
    ")",
    "{",
    "}",
    "[",
    "]",
    ";",
    ",",
    "+",
    "-",
    "*",
    "/",
    "=",
    "%",
    ">",
    ">=",
    "<",
    "<=",
    "==",
    "!",
    "&&",
    "||",
    "+",
    "-",
    "!="
};

const char * getTypeName(Type type)
{
    int t = (int)type;
    if(t < sizeof(TerminalAndNonTerminalNames) / sizeof(TerminalAndNonTerminalNames[0]))
    {
        return TerminalAndNonTerminalNames[t];
    }
    return NULL;
}

void addNode(Node * father, Node * a, Node * b, Node * c, Node * d, Node * e)
{
    if(a)
        appendNode(father, a);
    if(b)
        appendNode(father, b);
    if(c)
        appendNode(father, c);
    if(d)
        appendNode(father, d);
    if(e)
        appendNode(father, e);
}

Node * newNode(Type type)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->child_cnt = 0;
    node->father = NULL;
    for(int i = 0; i < CHILD_CNT; i++)
    {
        node->children[i] = NULL;
    }
    node->type = type;
    if(getTypeName(type))
    {
        strcpy(node->name, getTypeName(type));
    }
    else
    {
        strcpy(node->name, "No Name");
    }
    return node;
}

void appendNode(Node * father, Node * son)
{
    father->children[father->child_cnt] = son;
    son->father = father;
    father->child_cnt++;
}

int currentNode = 1;
struct Info
{
    int id;
    string nodeId;
    string nodeName;
    Node * parent;
};
map <Node *, Info> names;

struct Cmp
{
    bool operator()(const pair<Node *, Info>& a, const pair<Node *, Info>& b)
    {
        return a.second.id < b.second.id;
    }
};

void draw(Node * root, ofstream & fout)
{
    Info info = names[root];
    fout << info.nodeId;
    fout << "[label = \"" << info.nodeName << "\"];\n";
    if(names[info.parent].nodeId != "")
    {
        int ind = 0;
        Node * p = info.parent;
        for(int i = 0; i < p->child_cnt; i++)
        {
            if(p->children[i] == root)
            {
                ind = i;
                break;
            }
        }
        fout << "\"" << names[info.parent].nodeId << "\":f" << ind << "->\"";
        fout << info.nodeId << "\";\n";
    }
}

void processNodes(Node * root)
{
    Info info;
    info.id = currentNode;
    info.nodeId = "node" + to_string(currentNode);
    currentNode++;
    string tmp = "";
    for(int i = 0; i < root->child_cnt; i++)
    {
        tmp += "<f" + to_string(i) + "> ";
        if(root->children[i]->type == NUMBER_TYPE)
        {
            tmp += to_string(root->children[i]->value);
        }
        else if(root->children[i]->name[0] != '\0')
        {
            char e = root->children[i]->name[0];
            int j = 0;
            while(!isalpha(e) and e != 0)
            {
                // handle some special chars
                tmp += "\\";
                tmp += root->children[i]->name[j];
                j++;
                e = root->children[i]->name[j];
            }
            // else
            {
                tmp += root->children[i]->name + j;
            }
        }
        // else
        // {
        //     tmp += to_string(root->children[i]->value);
        // }
        if(i != root->child_cnt-1)
        {
            tmp += "|";
        }
    }
    // if(root->child_cnt == 0)
    // {
    //     tmp += "<f0> ";
    //     tmp += root->name;
    // }
    info.nodeName = tmp;
    info.parent = root->father;

    if(root->child_cnt != 0)
        names[root] = info;
    for(int i = 0; i < root->child_cnt; i++)
    {
        processNodes(root->children[i]);
    }
}

void generateGraph(Node * root, const char * path0)
{
    // printf("Please input the generate graph node path:\n");
    string path = path0;
    // getline(cin, path);
    ofstream fout(path);
    if(!fout.is_open())
    {
        cout << "File open error!" << endl;
        return;
    }

    fout << "digraph \" \"{\n";
    fout << "node [shape = record, height=.1]\n";
    fout << "node0[label = \"<f0> Start\"];\n";
    currentNode = 0;
    names.clear();
    processNodes(root);

    vector <pair<Node *, Info> > arr;

    for(auto each: names)
    {
        arr.push_back(each);
    }

    sort(arr.begin(), arr.end(), Cmp());

    for(auto each: arr)
    {
        // cout << each.second.id << endl;
        draw(each.first, fout);
    }
    fout << "}";
    fout.close();
}

int findConstValue(Node * node, int * valid)
{
    int found;
    auto var = findVar(node->idname, &found);
    if(found && var.type == Const)
    {
        *valid = 1;
        return var.value;
    }
    else
    {
        *valid = 0;
        return 0;
    }
}