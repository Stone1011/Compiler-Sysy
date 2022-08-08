//
// Created by 石依凡 on 2022/6/22.
//

#ifndef COMPILER_GENERATOR_HPP
#define COMPILER_GENERATOR_HPP

#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <queue>

bool RegStatus [] = // true for busy, false for free
        {
        true,
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false
        };

Registers getFreeReg()
{
    for(int i = 0; i < sizeof(RegStatus) / sizeof(RegStatus[0]); i++)
    {
        if(!RegStatus[i])
            return (Registers)i;
    }

    printf("Cannot find free registers!!!\n");
    return EDI;
}

void setReg(Registers r)
{
    RegStatus[r] = true;
}

void freeReg(Registers r)
{
    RegStatus[r] = false;
}

const char * RegisterNames [] =
        {
            "%rbp",
            "%rsp",
            "%edi",
            "%esi",
            "%r8d",
            "%r9d",
            "%r10d",
            "%r11d",
            "%eax",
            "%ebx",
            "%ecx",
            "%edx",
            "rdi",
            "rsi"
        };

using namespace std;

struct Variable
{
    // int type var
    string name;
    VarType type;
    int value;
    int pos; // ebp + ?
    int dim;
    int dim1, dim2;

    Variable() = default;
    Variable(char * n, VarType t, int v, int d)
    {
        name = n;
        type = t;
        dim = d;
        pos = 0;
        value = v;
    }
    Variable(char * n, VarType t)
    {
        name = n;
        type = t;
        dim = 0;
        pos = 0;
        value = 0;
    }
};

struct Function
{
    string name;
    int hasReturnValue;
    vector <Variable> params;

    Function(string n): name(n) {}
    Function(const Function & other)
    {
        name = other.name;
        hasReturnValue = other.hasReturnValue;
        params = other.params;
    }
    Function() = default;
};

Variable findVarInOut(string name, int * found);
extern void init();
extern vector<map<string, Variable> > varList;
map<string, Function> funcList;

void insertFuncList(char * name)
{
    funcList[name] = Function(name);
}

inline string genAddr(int i)
{
    return to_string(i)+"(%rbp)";
}

class Generator
{
public:
    std::string path;
    std::ofstream fout;

    stringstream buffer;

    int nextAsm = 0;
    int nextLabel = 0;
    vector <string> asms;
    map <int, vector <string> > labels;

    Generator() = default;

    int stackPos = 0; // 表示当前分配变量的栈位置

    int newInt()
    {
        stackPos -= 4;
        // Generate?
        write("subq\t$4, %rsp\n");
        return stackPos;
    }

    int newBytes(int size)
    {
        stackPos -= size;
        write("subq\t$" + std::to_string(size) + ", %rsp\n");
        return stackPos;
    }

    void genConst(Variable var)
    {
        auto & w = *this;

        // TODO: need to fix for array
        w << ".text\n";
        w << ".globl\t" << var.name << "\n";
        w << ".section\t.rodata\n";
        w << ".align\t4\n";
        w << ".type\t" << var.name << ", @object\n";
        w << ".size\t" << var.name << ", 4\n";

        int line = nextAsm;
        labels[line].push_back(var.name);
        w << ".long\t" << to_string(var.value);
        w << "\n";
    }

    void genFuncHead(string name)
    {
        auto & w = *this;

        w << ".text\n";
        w << ".globl\t" << name << "\n";
        w << ".type\tmain, @function\n";

        int line = nextAsm;
        labels[line].push_back(name);
        w << "endbr64\n";
        w << "pushq\t%rbp\n";
        w << "pushq\t%r8\n";
        w << "pushq\t%r9\n";
        w << "movq\t%rsp, %rbp\n";
        stackPos = 0;
        varList.push_back(map <string, Variable> ());
    }

    void clearStackPos()
    {
        stackPos = 0;
    }

    bool open(std::string a)
    {
        path = a;
        fout.open(path);
        init();
        if (fout.is_open())
            return true;
        else
            return false;
    }

    void close()
    {
        fout.close();
    }

    void write(std::string content)
    {
        for(auto each: content)
        {
            if(each != '\n')
                buffer << each;
            else
            {
                string t;
                getline(buffer, t);
                asms.push_back(t);
                buffer.clear();
                nextAsm++;
            }
        }
    }

    void solidate()
    {
        for(int i = 0; i < asms.size(); i++)
        {
            if(labels.count(i))
            {
                for(auto each: labels[i])
                {
                    fout << each << ":\n";
                }
            }
            fout << "\t" << asms[i] << endl;
        }
    }

    Generator &operator<<(std::string a)
    {
        write(a);
        return *this;
    }
};

extern Generator generator;
extern Variable findVar(string name, int * found);

void genReturn()
{
    auto &w = generator;
    w << "movq\t%rbp, %rsp\n";
    w << "popq\t%r9\n";
    w << "popq\t%r8\n";
    w << "popq\t%rbp\n";
    w << "retq\n";
}

string genAsmForm(Node * a);

void genReturn(Node * a)
{
    auto & w = generator;
    w << "movq\t%rbp, %rsp\n";
    w << "movl\t" << genAsmForm(a) << ", %eax\n";
    w << "popq\t%r9\n";
    w << "popq\t%r8\n";
    w << "popq\t%rbp\n";
    w << "retq\n";
}

void popVarList()
{
    varList.pop_back();
}

void solidate()
{
    generator.solidate();
}

int getNextI()
{
    return generator.nextAsm;
}

string genAsmForm(Node * a)
{
    string result;
    if(a->isNum == 0)
    {
        int found = 0;
        Variable var = findVar(a->idname, &found);
        if(!found)
        {
            printf("Error! Cannot find variable.\n");
            exit(3);
        }
        if(var.type == Normal)
            return genAddr(var.pos);
        else if(var.type == Const)
            return "$" + to_string(var.value);
        else if(var.type == GlobalNormal)
            return var.name;
    }
    else if(a->isNum == 1)
    {
        return "$"+ to_string(a->idvalue);
    }
    else if(a->isNum == 2)
    {
        return RegisterNames[a->idvalue];
    }
    else if(a->isNum == 3)
    {
        int found = 0;
        Variable var = findVar(a->idname, &found);
        if(!found)
        {
            printf("Error! Cannot find variable.\n");
            exit(3);
        }

        if(var.type == GlobalArray)
        {
            generator.asms.push_back("leaq\t" + var.name + ", %rdi");
            generator.asms.push_back("movslq\t" + string(RegisterNames[a->offset]) + ", %rsi");
            // generator.asms.push_back("movl\t(%rdi, %rsi, 4), " + string(RegisterNames[r]));
            generator.nextAsm += 2;
            return "(%rdi, %rsi, 4)";
        }
        generator.asms.push_back("movslq\t" + string(RegisterNames[a->offset]) + ", %rsi");
        generator.nextAsm += 1;
        return to_string(var.pos) + "(%rbp, %rsi, 4)";
    }

    return result;
}

string genChangeToReg(Node * a, Registers reg)
{
    string result;
    if(a->isNum == 0)
    {
        // 查符号表
        int found = 0;
        Variable var = findVar(a->idname, &found);
        if(!found)
        {
            printf("Error! Cannot find variable.\n");
            exit(3);
        }
        else if(var.type == GlobalNormal)
        {
            result = "movl\t" + var.name + ", " + RegisterNames[reg] + "\n";
            return result;
        }
        result = "movl\t" + genAddr(var.pos) + ", " + RegisterNames[reg] + "\n";
    }
    else if(a->isNum == 1)
    {
        result = "movl\t$" + to_string(a->idvalue) + ", " + RegisterNames[reg] + "\n";
    }

    return result;
}

Registers genAdd(Node * a, Node * b)
{
    Registers result;
    int atype = a->isNum;
    int btype = b->isNum;
    int reg = -1; // 0表示a，1表示b在寄存器中

    if(atype == 2 or btype == 2)
    {
        // 有一个结果是在寄存器里的
        // 沿用
        if(a->isNum == 2)
        {
            result = (Registers) a->idvalue;
            reg = 0;
        }
        else
        {
            result = (Registers) b->idvalue;
            reg = 1;
        }
    }
    else
    {
        result = getFreeReg();
        setReg(result);
        string change = genChangeToReg(a, result);
        generator << change;
        reg = 0;
    }

    if(reg == 0)
    {
        // a在寄存器里
        generator << "addl\t" << genAsmForm(b) <<  ", " << RegisterNames[result] << "\n";
        if(b->isNum == 2)
        {
            freeReg((Registers)b->idvalue);
        }
    }
    else
    {
        // b在寄存器里
        generator << "addl\t" << genAsmForm(a) << ", " << RegisterNames[result] << "\n";
        if(a->isNum == 2)
        {
            freeReg((Registers)a->idvalue);
        }
    }

    return result;
}

Registers genMinus(Node * a, Node * b)
{
    Registers result;
    int atype = a->isNum;
    int btype = b->isNum;
    int reg = -1; // 0表示a，1表示b在寄存器中

    if(atype == 2 or btype == 2)
    {
        // 有一个结果是在寄存器里的
        // 沿用
        if(a->isNum == 2)
        {
            result = (Registers) a->idvalue;
            reg = 0;
        }
        else
        {
            result = (Registers) b->idvalue;
            reg = 1;
        }
    }
    else
    {
        result = getFreeReg();
        setReg(result);
        string change = genChangeToReg(a, result);
        generator << change;
        reg = 0;
    }

    if(reg == 0)
    {
        // a在寄存器里
        generator << "subl\t" << genAsmForm(b) <<  ", " << RegisterNames[result] << "\n";
        if(b->isNum == 2)
        {
            freeReg((Registers)b->idvalue);
        }
    }
    else
    {
        // b在寄存器里
        generator << "subl\t" << RegisterNames[result] << ", " << genAsmForm(a) << "\n";
        if(a->isNum == 2)
        {
            freeReg((Registers)a->idvalue);
        }
    }

    return result;
}

Registers genMulti(Node * a, Node * b)
{
    Registers result;
    int atype = a->isNum;
    int btype = b->isNum;
    int reg = -1; // 0表示a，1表示b在寄存器中

    if(atype == 2 or btype == 2)
    {
        // 有一个结果是在寄存器里的
        // 沿用
        if(a->isNum == 2)
        {
            result = (Registers) a->idvalue;
            reg = 0;
        }
        else
        {
            result = (Registers) b->idvalue;
            reg = 1;
        }
    }
    else
    {
        result = getFreeReg();
        setReg(result);
        string change = genChangeToReg(a, result);
        generator << change;
        reg = 0;
    }

    if(reg == 0)
    {
        // a在寄存器里
        generator << "imull\t" << genAsmForm(b) <<  ", " << RegisterNames[result] << "\n";
        if(b->isNum == 2)
        {
            freeReg((Registers)b->idvalue);
        }
    }
    else
    {
        // b在寄存器里
        generator << "imull\t" << genAsmForm(a) << ", " << RegisterNames[result] << "\n";
        if(a->isNum == 2)
        {
            freeReg((Registers)a->idvalue);
        }
    }

    return result;
}

void genAssign(Node * a, Node * b)
{
    // a=b
    // =>
    // movl b, a
    if(a->isNum == 0 || a->isNum == 2)
    {
        if (!(a->isNum == 0 and b->isNum == 0))
        {
            generator << "movl\t" << genAsmForm(b) << ", " << genAsmForm(a) << "\n";
            if (b->isNum == 2)
            {
                freeReg((Registers) b->idvalue);
            }
        }
        else
        {
            int found;
            Variable var = findVar(b->idname, &found);
            if(!found)
            {
                printf("Error! Cannot find symbol.\n");
                exit(10);
            }

            if(var.type == Normal)
            {
                Registers r = getFreeReg();
                generator << "movl\t" << genAsmForm(b) << ", " << RegisterNames[r] << "\n";
                generator << "movl\t" << RegisterNames[r] << ", " << genAsmForm(a) << "\n";
            }
            else
            {
                generator << "movl\t$" << to_string(var.value) << ", " << genAsmForm(a) << "\n";
            }
        }
    }
    else if(a->isNum == 3)
    {
        // Array
        if(b->isNum != 0)
        {
            // b is instant num or register
            generator << "movl\t" << genAsmForm(b) << ", " << genAsmForm(a) << "\n";
            if (b->isNum == 2)
            {
                freeReg((Registers) b->idvalue);
            }
        }
        else
        {
            // b is a variable
            Registers r = getFreeReg();
            generator << "movl\t" << genAsmForm(b) << ", " << RegisterNames[r] << "\n";
            generator << "movl\t" << RegisterNames[r] << ", " << genAsmForm(a) << "\n";
        }
        // Release offset register
        freeReg((Registers)a->offset);
    }
    else
    {
        printf("Cannot assign. error.\n");
        exit(10);
    }
}

Registers transferToReg(char * varName)
{
    Registers r = getFreeReg();
    setReg(r);
    int found;
    auto var = findVar(varName, &found);
    if(found)
    {
        generator << "movl\t" << genAddr(var.pos) << ", " << RegisterNames[r] << "\n";
        return r;
    }
    else
    {
        printf("Cannot find variable\n");
        exit(6);
    }
}

int calcOffsetAndFreeReg(Node * nameNode, Node * dimNode, int * type) // 返回值是一个寄存器编号或者立即数
{
    int found;
    auto var = findVar(nameNode->idname, &found);
    if(found)
    {
        if(var.dim == dimNode->dim)
        {
            int dim = var.dim;
            if(dim == 1)
            {
                int offset = dimNode->dim1;
                if(dimNode->dim1type == 1)
                {
                    // 立即数
                    *type = 1;
                    return offset;
                }
                else if(dimNode->dim1type == 2)
                {
                    // Regs
                    *type = 2;
                    return offset;
                }
            }
            else if(dim == 2)
            {
                int dim2 = var.dim2;
                // offset = dim2 * dimNode->dim1 + dimNode->dim2
                if(dimNode->dim1type == 1 && dimNode->dim2type == 1)
                {
                    int offset = dimNode->dim1 * dim2 + dimNode->dim2;
                    *type = 1;
                    return offset;
                }
                else
                {
                    Registers r = getFreeReg();
                    setReg(r);
                    if(dimNode->dim1type == 1)
                    {
                        generator << "movl\t$" << to_string(dim2*dimNode->dim1) << ", " << RegisterNames[r] << "\n";
                    }
                    else
                    {
                        generator << "movl\t" << "$" << to_string(dim2) << ", " << RegisterNames[r] << "\n";
                        generator << "imull\t" << RegisterNames[dimNode->dim1] << ", " << RegisterNames[r] << "\n";
                        freeReg((Registers)dimNode->dim1);
                    }

                    if(dimNode->dim2type == 1)
                    {
                        generator << "addl\t$" << to_string(dimNode->dim2) << ", " << RegisterNames[r] << "\n";
                    }
                    else
                    {
                        generator << "addl\t" << RegisterNames[dimNode->dim2] << ", " << RegisterNames[r] << "\n";
                        freeReg((Registers)dimNode->dim2);
                    }

                    *type = 2;
                    return r;
                }
            }
        }
        else
        {
            printf("Array dim error.\n");
            exit(8);
        }
    }
    else
    {
        printf("Cannot find array var by name.\n");
        exit(7);
    }

    return 0;
}

Registers transferToReg(int num)
{
    Registers r = getFreeReg();
    setReg(r);
    generator << "movl\t$" << to_string(num) << ", " << RegisterNames[r] << "\n";
    return r;
}

Registers arrayTransferToRegAndFree(char * arrayName, int offsetReg)
{
    Registers r = getFreeReg();
    setReg(r);
    int found;
    auto var = findVar(arrayName, &found);
    if(found)
    {
        if(var.type == Array)
        {
            generator << "movslq\t" << RegisterNames[offsetReg] << ", %rdi\n";
            generator << "movl\t" << to_string(var.pos) << "(%rbp, %rdi, 4)";
            generator << ", " << RegisterNames[r] << "\n";
            freeReg((Registers) offsetReg);
            return r;
        }
        else if(var.type == GlobalArray)
        {
            generator << "leaq\t" << var.name << ", %rdi\n";
            generator << "movslq\t" << RegisterNames[offsetReg] << ", %rsi\n";
            generator << "movl\t" << "(%rdi, %rsi, 4), " << RegisterNames[r] << "\n";
            freeReg((Registers)offsetReg);
            return r;
        }
    }
    else
    {
        printf("Could not find array.\n");
        exit(3);
    }

    return r;
}

void testZero(Node * a)
{
    if(a->isNum == 0)
    {
        Registers r = getFreeReg();
        generator << "movl\t" << genAsmForm(a) << ", " << RegisterNames[r] << "\n";
        generator << "testl\t" << RegisterNames[r] << ", " << RegisterNames[r] << "\n";
    }
    else if(a->isNum == 2)
    {
        generator << "testl\t" << RegisterNames[a->idvalue] << ", " << RegisterNames[a->idvalue] << "\n";
        freeReg((Registers)a->idvalue);
    }
}

void testCompare(Node * a, Node * b)
{
    Registers result;
    int atype = a->isNum;
    int btype = b->isNum;
    int reg = -1; // 0表示a，1表示b在寄存器中

    if(atype == 2 or btype == 2)
    {
        // 有一个结果是在寄存器里的
        // 沿用
        if(a->isNum == 2)
        {
            result = (Registers) a->idvalue;
            reg = 0;
        }
        else
        {
            result = (Registers) b->idvalue;
            reg = 1;
        }
    }
    else
    {
        result = getFreeReg();
        setReg(result);
        string change = genChangeToReg(a, result);
        generator << change;
        reg = 0;
    }

    if(reg == 0)
    {
        // a在寄存器里
        generator << "cmpl\t" << genAsmForm(b) <<  ", " << RegisterNames[result] << "\n";
        if(b->isNum == 2)
        {
            freeReg((Registers)b->idvalue);
        }
    }
    else
    {
        // b在寄存器里
        generator << "cmpl\t" << RegisterNames[result] << ", " << genAsmForm(a) << "\n";
        if(a->isNum == 2)
        {
            freeReg((Registers)a->idvalue);
        }
    }

    freeReg(result);
}

void genTrueFalseCompare(Node * a, char type, int equal)
{
    int trueindex = generator.nextAsm;
    string t = "j";
    t += type;
    if(equal)
        t += 'e';
    generator << t << "\t\t0\n";
    int falseindex = generator.nextAsm;
    generator << "jmp\t\t0\n";
    a->truelist[a->truelen ++] = trueindex;
    a->falselist[a->falselen ++] = falseindex;
}

void genTrueFalseZero(Node * a, int isneg)
{
    isneg = isneg % 2;
    if(a->isNum == 1)
    {
        int n = a->idvalue;
        if(isneg)
            n = !n;
        if(n != 0)
        {
            int trueindex = generator.nextAsm;
            generator << "jmp\t\t0\n";
            a->truelist[a->truelen++] = trueindex;
        }
        else
        {
            int falseindex = generator.nextAsm;
            generator << "jmp\t\t0\n";
            a->falselist[a->falselen++] = falseindex;
        }
        return;
    }
    else if(a->isNum == 0)
    {
        int found;
        Variable var = findVar(a->idname, &found);
        if(found)
        {
            if(var.type == Const)
            {
                int n = var.value;
                if(isneg)
                    n = !n;
                if(n != 0)
                {
                    int trueindex = generator.nextAsm;
                    generator << "jmp\t\t0\n";
                    a->truelist[a->truelen++] = trueindex;
                }
                else
                {
                    int falseindex = generator.nextAsm;
                    generator << "jmp\t\t0\n";
                    a->falselist[a->falselen++] = falseindex;
                }
                return;
            }
            else
            {
                int trueindex = generator.nextAsm;
                if(isneg)
                {
                    generator << "jz\t\t0\n";
                }
                else
                    generator << "jnz\t\t0\n";
                int falseindex = generator.nextAsm;
                generator << "jmp\t\t0\n";
                a->truelist[a->truelen++] = trueindex;
                a->falselist[a->falselen++] = falseindex;
            }
        }
        else
        {
            printf("Error when finding var.\n");
            exit(11);
        }
    }
    else
    {
        int trueindex = generator.nextAsm;
        if(isneg)
            generator << "jz\t\t0\n";
        else generator << "jnz\t\t0\n";
        int falseindex = generator.nextAsm;
        generator << "jmp\t\t0\n";
        a->truelist[a->truelen++] = trueindex;
        a->falselist[a->falselen++] = falseindex;
    }
}

string genLabel(int labelNum)
{
    return ".L" + to_string(labelNum);
}

void addLabel(int line, int labelNum)
{
    generator.labels[line].push_back(genLabel(labelNum));
}

vector <int> stackPos;

vector <int> loop; // 表示每一层循环对应的stackPos层数

//void loopStmt()
//{
////    loop.push_back(stackPos.size());
//}

// 回填
void modifyAsm(int line, int target, int isbreak)
{
    string s = generator.asms.at(line);
    int pos = s.find_last_of('\t');
    string modified = s.substr(0, pos + 1); // \t和之前的部分
    int labelnum = generator.nextLabel;
    generator.nextLabel++;
    // 本行修改，改为标签
    modified += genLabel(labelnum);

    if(isbreak)
    {
//        modified = "addq\t$" + to_string(stackPos[loop.back()] - generator.stackPos) + ", %rsp\n\t" + modified;
    }

    generator.asms[line] = modified;
    // 目标行修改
    addLabel(target, labelnum);
}

void cpylist(Node * tar, Node * from)
{
    memcpy(tar->truelist, from->truelist, sizeof(tar->truelist));
    memcpy(tar->falselist, from->falselist, sizeof(tar->falselist));
    tar->truelen = from->truelen;
    tar->falselen = from->falselen;
}

void backpatch(Node * a, int truetarget, int falsetarget)
{
    if (truetarget != -1)
        for (int i = 0; i < a->truelen; i++)
        {
            modifyAsm(a->truelist[i], truetarget);
        }

    if (falsetarget != -1)
        for (int i = 0; i < a->falselen; i++)
        {
            modifyAsm(a->falselist[i], falsetarget);
        }
}

int mergelist(int * des, int deslen, int * from, int fromlen)
{
    set <int> s;
    for(int i = 0; i < deslen; i++)
    {
        s.insert(des[i]);
    }
    for(int i = 0; i < fromlen; i++)
    {
        s.insert(from[i]);
    }

    int r = 0;
    for(auto each: s)
    {
        des[r++] = each;
    }
    return r;
}

void out(Node * a)
{
    a->truelist[a->truelen ++] = generator.nextAsm;
    generator << "jmp\t\t0\n";
}

int genJmp()
{
    int r = generator.nextAsm;
    generator << "jmp\t\t0\n";
    return r;
}

void addParam(char * funcName, char * varName, VarType type,
              int dim, int dimContent)
{
    if(!funcList.count(funcName))
    {
        printf("Cannot find function.\n");
        exit(12);
    }
    Function & func = funcList[funcName];
    Variable var(varName, type);
    func.params.push_back(var);
}

void processParams(char * funcName)
{
    if(!funcList.count(funcName))
    {
        printf("Cannot find function.\n");
        exit(12);
    }
    Function & func = funcList[funcName];

    int i = 0;
    for(auto each: func.params)
    {
        insertVarList((char *)each.name.c_str(), Normal);
        int found;
        generator << "movl\t" << RegisterNames[EDI + i] << ", "
            << genAddr(findVar(each.name, &found).pos) << "\n";
        i += 1;
    }
}

int align()
{
    // 16对齐
    int k = -generator.stackPos;
    int r = ((k >> 4) << 4) + 16;
    int delta = r - k;
    generator << "subq\t$" << to_string(delta) << ", %rsp\n";
    return delta;
}

void call(char * funcName)
{
    int delta = align();
    generator << "call\t" << string(funcName) << "\n";
    generator << "addq\t$" << to_string(delta) << ", %rsp\n";
}

//void popParams(char * funcName)
//{
//    if(!funcList.count(funcName))
//    {
//        printf("Cannot find function.\n");
//        exit(12);
//    }
//    Function & func = funcList[funcName];
//
//    for(auto each: func.params)
//    {
//        generator << "popl\t%ebx\n";
//    }
//}

queue <string> waitToPush;

void addToWaitPush(Node * node)
{
    waitToPush.push(genAsmForm(node));
}

void pushParams()
{
    int i = 0;
    while(!waitToPush.empty())
    {
        auto t = waitToPush.front();
        waitToPush.pop();
//        if(t[0] == '$')
//        {
//            Registers r = getFreeReg();
//            generator << "movl\t" << t << RegisterNames[r] << "\n";
//            t = RegisterNames[r];
//        }
//        generator << "pushl\t" << t << "\n";
        generator << "movl\t" << t << ", " << RegisterNames[EDI + i] << "\n";
        i++;
    }
}

void genPrintf(Node * a)
{
    int delta = align();
    generator << "leaq\t.WT(%rip), %rdi\n";
    generator << "movl\t" << genAsmForm(a) << ", %esi\n";
    generator << "call\tprintf@PLT\n";
    generator << "addq\t$" << to_string(delta) << ", %rsp\n";
}

void genScanf(Node * a)
{
    int delta = align();
    generator << "leaq\t.RD(%rip), %rdi\n";
    generator << "leaq\t" << genAsmForm(a) << ", %rsi\n";
    generator << "call\t__isoc99_scanf@PLT\n";
    generator << "addq\t$" << to_string(delta) << ", %rsp\n";
}

//int alignNum;
void enterStmt()
{
    stackPos.push_back(generator.stackPos);
//    alignNum = align();
//    generator.stackPos -= alignNum;
    varList.push_back(map <string, Variable> ());
}

void exitStmt()
{
    int p = generator.stackPos;
    generator.stackPos = stackPos.back();
    stackPos.pop_back();
    varList.pop_back();
    generator << "addq\t$" << to_string(- p + generator.stackPos) << ", %rsp\n";
}

#endif //COMPILER_GENERATOR_HPP
