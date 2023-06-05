# Implementation of a Small SysY Language Compiler

## Yifan SHI June 2022

## 1 Overview of the Experiment

This experiment completes a small compiler that compiles a subset language of the C language called SysY language into x86_64 AT&T format assembly code. The compiler consists of three stages: lexical analysis, syntax analysis, and semantic analysis.

In the lexical analysis stage, the lexical analyzer, based on the LEX analyzer, converts the input SysY language source code into machine-readable %tokens, including keywords (**K**eyword), delimiters (**D**elimiter), identifiers (**I**dentifier), operators (**O**perator), constant literals (**C**onstant), whitespace (**B**lank), and unknown values (**U**nknown). For each %token, the machine creates a corresponding node and passes it to the syntax analyzer.

In the syntax analysis stage, the syntax analyzer converts the input %token sequence into an output syntax tree. It is based on YACC and uses the bottom-up LR method. The syntax tree nodes consist of terminal leaf nodes, i.e., the %token nodes passed from the lexical analyzer, and non-terminal %node nodes formed by reductions.

In the semantic analysis stage, the semantic analyzer, based on the syntax analyzer, performs semantic actions such as register allocation, backpatching of true and false chains, value propagation, and assembly code generation during reductions. It finally outputs a complete AT&T format x86_64 assembly code source file.

## 2 Lexical Analysis

This part involves the use of the LEX language to generate a binary executable file capable of parsing SysY language words. The words are classified into specific categories, which will be further expanded in the following parts. This section reinforces the understanding of regular expressions, finite automata, and the equivalence of three forms of grammar. It utilizes modern tools to practice lexical analysis and generate an executable file that can be used in syntax analysis, semantic analysis, and compiler development.

### 2.1 Process Explanation

In this part, LEX language and the flex tool are used for programming, compiling, and execution on a Unix-like platform (MacOS). The process consists of the following steps:

* Learning LEX language: Familiarize yourself with the syntax of LEX language and study relevant materials.

* Writing LEX scripts: Use LEX language to define the syntax rules based on regular expressions for identifying specific words. Write corresponding C code blocks to process the identified words.

* Interpreting and translating LEX scripts: Use the flex 2.6.4 Apple (flex-34) tool to translate the LEX script into C source code.

* Compiling the C code to generate an executable program: Use the C compiler Apple clang version 13.0.0 (clang-1300.0.29.30) to compile the generated C code into a binary executable file, which serves as the lexer.

* Test the lexer with pre-prepared SYSY language test scripts for lexical analysis. Debug the program and repeat the above steps.

* Summarize and report the results.

### 2.2 LEX Script Design

The LEX script consists of four parts: preprocessing, constant definitions, action definitions, and the main function.

In the preprocessing part, the necessary header files, "stdio.h" and "string.h", are included. Global variables are defined: num_lines representing the current line number of the pointer yytext, num_chars representing the current column number of yytext, in_comments indicating whether yytext is inside a multi-line comment, and in_one_comments indicating whether yytext is inside a single-line comment. A helper function void print(int line, int chars, char type) is defined for formatting output.

Next, meaningful constants are defined: Newline represents a new line and is designed to handle different newline formats (CRLF and LF) for Windows and Unix

 & Linux systems. Keyword represents the keywords in the SysY language, Operator represents the operators defined in the SysY language, Digit($n$) represents the numeric characters in base 10 (or base $n$), Integer($n$) represents the integers in base 10 (or base $n$), InstantNum represents all the immediate numbers defined in the SysY language, including decimal, octal, and hexadecimal integers. Letter represents uppercase and lowercase letters, Identifier represents the identifiers defined in the SysY language, Delimiter represents the delimiters defined in the SysY language, and Blank represents non-newline separator blocks.

Then, the scanning actions are defined. For single-line comments starting with "//" and multi-line comments starting with "/*" and ending with "*/", the global states in_comments and in_one_comments are updated accordingly, and the line and column numbers are updated. For the rest of the defined word types, they are outputted in the format "content: category (line number, column number)", and the line and column numbers are updated. For blank blocks, the line and column numbers are updated. For undefined characters, an "undefined character" message is outputted.

Finally, the main function is defined. To facilitate usage, command-line parameters are set. By redirecting stdin, the executable file can take the address of the SysY language source code as a command-line parameter, making it more convenient to use. The function yylex() is called to start the lexical analysis process.

## 3 Syntax Analysis

In this part, based on the SysY language, we perform syntax analysis on SysY language files using the previous LEX lexer and generate syntax trees using Graphviz. The resulting syntax trees are shown in the image below:

![Syntax Tree](https://raw.githubusercontent.com/Stone1011/oss/master/uPic/image-20220626165122658.png)

When checking the generated syntax tree, we found that the following points are correctly handled:

- The overall analysis passes.
- Operator precedence and associativity are correctly recognized.
- The nearest precedence and associativity of `if...else...` statements are correctly handled.
- Octal, decimal, and hexadecimal integers are correctly recognized.
- Multi-dimensional arrays are correctly recognized.

Therefore, this part has completed the required tasks and can be used for the subsequent semantic analysis.

### 3.1 Syntax Analysis Process

The analysis process in this part is as follows:

1. The lexical analysis module (LEX) performs lexical analysis on the given file. It creates tree nodes based on different word types and passes the corresponding information to `yylval`. The lexer returns the recognized terminal token.
2. The syntax analysis module (YACC) determines whether to shift or reduce based on the terminal token received from the lexer. If it is a reduction, a new tree node is created, and the reduced content is added to its child nodes.
3. If the start symbol is reduced, the analysis is successful, and the syntax tree is outputted as a Graphviz tree file and visualized.
4. If a syntax error occurs, the program terminates and stops the analysis.

### 3.2 YACC Script Design

The YACC script consists of the following parts:

- C language preprocessing section and related function definitions.
- Definitions of YACC identifiers (`%token` and `%node`, etc.).
- Definitions of YACC grammar and semantic actions.
- Definition of the main function (program entry point).

The YACC grammar mainly forms a predictive parsing table based on LR reduction and is used for further analysis. Semantic actions are used to construct the syntax tree and provide a foundation for the subsequent parts to generate assembly code for a small SysY language compiler.

## 4 Semantic Analysis

In this part, based on the lexical analyzer and syntax analyzer, we design semantic actions and related structures to generate AT&T assembly code that can be successfully compiled on x86_64 machines.

### 4.1 Completion Status Explanation

The following functionalities have been implemented:

- Program entry point and main function.
- Proper program return.
- Declaration, definition, access, and assignment of variables (both normal and array variables).
- Declaration, definition, and access of normal constant variables.
- Declaration, definition, access, and assignment of global normal and array variables.
- Binary operations (+, -, *).
- Logical operations (&&, ||, !).
- `if` statements and `if...else...` statements.
- `while` loop statements.
- `break` and `continue` statements.
- Variable nesting and variable scope selection.
- Register allocation using the greedy method.
- Function calls.
- `printf` and `scanf` input/output.

The following functionalities are not supported at the moment:

- Division operation and parentheses.
- Pointer operations (e.g., `scanf(a[1])`).
- List initialization (e.g., `int a[] = {...};`).
- Non-simple constant left values or array definitions with numbers (e.g., `int a[N * 2]`).
- Handling missing or incorrect return statements in functions.
- Handling consecutive `break` and `continue` operations in `while` loops with multiple layers of local variables.
- Handling other error cases encountered during testing.

### 4.2 Overall Design

#### 4.2.1 Node Design

Each grammar node is defined as a Node type, with the detailed definition as follows:

```cpp
typedef struct Node
{
    Type type;
    char name[65];
    int value;

    int isNum;
    char idname[65];
    int idvalue;
    int dim;
    int dim1, dim2;
    int dim1type, dim2type;
    int offset; 

    int truelist[16];
    int falselist[16];
    int truelen = 0, falselen = 0;
    int isneg = 0;

    struct Node* father;
    int child_cnt;
    struct Node* children[CHILD_CNT];
} Node;
```

The meaning of each field is as follows:

* type: The type of the node (For non-terminal types, it corresponds to the name of the non-terminal; for terminal types, it is determined by the lexical analyzer).
* name: The name of the node in the syntax tree (if applicable).
* value: The value of the leaf node (if applicable).
* isNum: The information type corresponding to the non-terminal node
  * isNum = 0: Represents a regular variable or constant, and the identifier name is stored in idname.
  * isNum = 1: Represents an immediate value (already converted to decimal), and the value is stored in idvalue.
  * isNum = 2: Represents a register, and the register number (the literal value of an enumeration) is stored in idvalue.
  * isNum = 3: Represents an array type, and the identifier name is stored in idname. The dimension is stored in dim. The index of each dimension is stored in dim1 and dim2 (currently only supports 2 dimensions). The type of each dimension index value is stored in dim1type and dim2type (the same meaning as isNum, or an immediate value, such as `a[1]`, or a register number, with the computation result stored in the register, such as `a[m*n]`). The calculated offset is stored in offset.
  * isNum = 4: Represents a boolean type. The true and false chains and their lengths are stored in truelist & truelen and falselist & falselen, respectively. Whether it is negated is stored in isneg.
* father, children: The parent and child nodes of the node in the syntax tree.
* child_cnt: The number of child nodes of the node.

#### 4.2.2 Related Structure and Function Design

The program defines the Variable and Function structures to represent specific variables and functions, respectively. The symbol table stack and function table are represented using `std::vector<std::map <std::string, Variable> > varList` and `std::map <std::string, Function> funcList`, respectively.

```cpp
struct Variable
{
    // int type var
    string name;
    VarType type;
    int value;
    int pos; // pos(%rbp) or pos(%rbp, offset, 4)
    int dim;
    int dim1, dim2;

    Variable() = default;
    Variable(char * n, VarType t, int v, int d);
    Variable(char * n, VarType t);
};

struct Function
{
    string name;
    int hasReturnValue;
    vector <Variable> params;
  
    Function(string n);
    Function(const Function & other);
    Function() = default;
};
```

The program defines the Generator class, which is responsible for generating assembly code. The specific definition is as follows. This class has a global object that is used to manage and generate assembly code.

```cpp
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
    int stackPos = 0; // stands for the stack position of the currently allocated variable
  	
  	Generator() = default;
    int newInt();
    int newBytes(int size);
    void genConst(Variable var);
    void genFuncHead(string name);
    void clearStackPos();
    bool open(std::string a);
    void close();
    void write(std::string content);
    void solidate();
    Generator &operator<<(std::string a)
};
```

The global functions used in the program are as follows:

```cpp
void addNode(Node * father, Node * a, Node * b = NULL, Node * c = NULL, Node * d = NULL, Node * e = NULL);
Node * newNode(Type type);
void appendNode(Node * father, Node * son);
void generateGraph(Node * root, const char * a);
int insertVarList(char * name, VarType type, int value = NULL, int dim = NULL, int dim1 = NULL, int dim2 = NULL);
void setGenerator(char * p);
void genFuncHead(char * p);
void genReturn();
void freeReg(Registers r);
void setReg(Registers r);
Registers getFreeReg();
Registers transferToReg(char * varName);
Registers transferToReg(int num);
Registers arrayTransferToRegAndFree(char * arrayName, int offsetReg);
Registers genAdd(Node * a, Node * b);
Registers genMinus(Node * a, Node * b);
Registers genMulti(Node * a, Node * b);
void genAssign(Node * a, Node * b);
int findConstValue(Node * node, int * valid);
int calcOffsetAndFreeReg(Node * nameNode, Node * dimNode, int * type);
void solidate();
int getNextI();
void out(Node * a); // an unconditional jump when encountering a "break"
int genJmp();
void testZero(Node * a);
void genTrueFalseZero(Node * a, int isneg = NULL); // used after "cmp", only generating two chains
void testCompare(Node * a, Node * b);
void genTrueFalseCompare(Node * a, char type, int equal = NULL);
void modifyAsm(int line, int target, int isbreak = NULL); // Re-complete line "line" through refering to line "target", and also need to determine whether to "break"
void cpylist(Node * tar, Node * from);
int mergelist(int * des, int deslen, int * from, int fromlen); // des = des 并 from
void backpatch(Node * a, int truetarget = -1, int falsetarget = -1);
void genReturn(Node * a);
void insertFuncList(char * name);
void addParam(char * funcName, char * varName, VarType type, int dim = NULL, int dimContent = NULL);
void processParams(char * funcName);
void call(char * funcName);
// void popParams(char * funcName);
void addToWaitPush(Node * node); // use the method of waiting queue
void pushParams();
void popVarList(); // pop for the variable list
void genPrintf(Node * a);
void genScanf(Node * a);
void enterStmt();
void exitStmt();
```

## 5  File Descriptions

The organizing structure of files of this project is illustrated as follows:

```
.
├── Build
│   ├── 0
│   ├── 1
│   ├── 2
│   ├── 3
│   └── 4
├── Generator.hpp
├── grammar.y
├── lex.yy.c
├── Makefile
├── Output
│   ├── 0.s
│   ├── 1.s
│   ├── 2.s
│   ├── 3.s
│   ├── 4.s
├── readme.md
├── show.sh
├── sysyc
├── Test
│   ├── 0.sy
│   ├── 1.sy
│   ├── 2.sy
│   ├── 3.sy
│   ├── 4.sy
├── tree.cpp
├── tree.h
├── wordAnalysis.l
├── y.tab.c
└── y.tab.h
```

* y.tab.\* - C language source file and header file generated by YACC.
* lex.yy.c - C language source file generated by FLEX.
* Makefile - Makefile for the project, where the "main" target is used to build the project.
* show.sh - Shell script that compiles five test cases into assembly language separately and compiles the resulting files into executable files under the "Build" directory using gcc.
* sysyc - Executable binary file generated by the project compiler.
* Generator.hpp, grammar.y, tree.h/cpp, wordAnalysis.l - Source files and header files of the project.

**[Note]** The file "3.sy" in the project, due to an unknown error, cannot generate "3.s" on Linux Ubuntu 20.04. The "3.s" file mentioned here was generated on macOS 12.4. The executable file "3" was generated on Linux Ubuntu 20.04 by compiling and linking the "3.s" file generated on macOS using gcc.

## Appendix A: Partial Functional Test Cases for Testing

### Arithmetic Operations Test

```c
const int a = 1;

int main()
{
    int a = 2, b = 0x11;
    int c = 3+ a * b;
    int d = a*2+3;
    int e = a*b-c*c;
    int f = a*c-d*e+1;
  	return 0;
}
```

### Array Operations Test

```c
const int N = 10;

int main()
{
    int a[N][N];
    a[2*3][3*2] = 2*2+2*a[2][2];
  	return 0;
}
```

### Branching Test

```c
const int N = 100;
int main()
{
    int a = 2;
    if(1+1 == 2*a+1)
    {
      	a = 1;
      	a = a * 2;
    }
  return 0;
}
```

### Boolean Operation Test

```c
const int N = 100;
int main()
{
    int a = 2, b[2][3];
   
    if(a > 1 && a > 2 || a > 3)
    {
        a = 1;
    }
    else b[1][1] = 2;
}
```

### Looping Test

```c
const int N = 10;
int main()
{
    int i = 0, sum = 0;
    while(1)
    {
        if(i == 0)
        {
            i = i + 1;
            continue;
        }
        if(i > N)
            break;
        else
        {
            sum = sum + i;
            i = i + 1;
        }
    }
    return sum;
}
```

### Function Calling Test

```c
int calc_sum(int N)
{
    int i = 0, sum = 0;
    while(1)
    {
        if(i == 0)
        {
            i = i + 1;
            continue;
        }
        if(i > N)
            break;
        else
        {
            sum = sum + i;
            i = i + 1;
        }
    }

    return sum;
}

int main()
{
    int x;
    scanf(x);
    printf(calc_sum(x));
    return 0;
}
```

### Global Variable Usage Test

```c
int a = 2, b = 3;
int M[2][2];

int main()
{
    scanf(b);

    int a[2];
    a[1] = b*2;
    b = b + 2;
    M[1][1] = b+3;
    int p = b + M[1][1] + a[1];
    printf(p);
    return 0;
}
```

After testing, **it has been confirmed that <u>all the above test cases produce the correct results</u>.**

