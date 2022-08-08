#ifndef TREE_H
#define TREE_H

#define CHILD_CNT 32
#include <string.h>

enum VarType
{
    Const,
    Normal,
    ConstArray,
    Array,
    GlobalNormal,
    GlobalArray
};

enum Registers
{
    RBP,
    RSP,
    EDI,
    ESI,
    R8,
    R9,
    R10,
    R11,
    EAX,
    EBX,
    ECX,
    EDX,
//    RDI,
//    RSI
};

typedef enum Type
{
    // Non-terminals
    // CompUnit
    START_TYPE,
    COMP_UNIT_TYPE,
    OTHER_COMP_TYPE,
    // Const Declaration and Defination
    DECL_TYPE,
    CONST_DECL_TYPE,
    CONST_DEF_TYPE,
    CONST_EXP_TYPE,
    CONST_INIT_VAL_TYPE,
    // Variable Declaration and Defination
    VAR_DECL_TYPE,
    VAR_DEF_TYPE,
    VAR_INIT_VALUE,
    // Array Addressing
    OOB_TYPE,
    // Functions
    FUNC_TYPE,
    FUNC_F_PARAMS_TYPE,
    FUNC_R_PARAMS_TYPE,
    FUNC_DEF_TYPE,
    // Block
    BLOCK_TYPE,
    BLOCK_ITEM_TYPE,
    // Statement
    STMT_TYPE,
    // Values
    L_VAL_TYPE,
    COND_TYPE,
    EXP_TYPE,
    ADD_EXP_TYPE,
    L_OR_OR_EXP_TYPE,
    PRIMARY_EXP_TYPE,
    UNARY_EXP_TYPE,
    UNARY_OP_TYPE,
    MULTI_EXP_TYPE,
    REL_EXP_TYPE,
    EQUAL_EXP_TYPE,
    L_AND_AND_EXP_TYPE,
    //Specials
    FUNC_F_PARAM_TYPE,
    BLOCK_ITEMS_TYPE,
    CONST_DEF_LIST_TYPE,
    ARRAY_DIM_TYPE,
    CONST_ARRAY_DIM_TYPE,
    ARRAY_CONTENT_TYPE,
    VAR_DEF_LIST_TYPE,
    CONST_ARRAY_CONTENT_TYPE,
    CONST_ARRAY_INIT_VAL_TYPE,
    ARRAY_INIT_VAL_TYPE,
    UNKNOWN_NON_TERM_TYPE,
    NUMBER_NON_TERM_TYPE,
    ID_NON_TERM_TYPE,
    // Terminals
    // Keywords
    INT_TYPE,
    VOID_TYPE,
    IF_TYPE,
    ELSE_TYPE,
    BREAK_TYPE,
    CONTINUE_TYPE,
    RETURN_TYPE,
    CONST_TYPE,
    WHILE_TYPE,
    // Delimeters: "("|")"|"{"|"}"|"["|"]"|";"|","
    LEFT_BRACKET_TYPE,
    RIGHT_BRACKET_TYPE,
    LEFT_BIG_TYPE,
    RIGHT_BIG_TYPE,
    LEFT_MIDDLE_TYPE,
    RIGHT_MIDDLE_TYPE,
    SEMICOLON_TYPE,
    COMMA_TYPE,
    // Operators: "+"|"-"|"*"|"/"|"="|"%"|">"|"<"|"=="|"!"|"\|\|"|"&&"
    ADD_TYPE,
    MINUS_TYPE,
    MULTI_TYPE,
    DIVIDE_TYPE,
    ASSIGN_TYPE,
    MOD_TYPE,
    BIGGER_TYPE,
    BIGGER_EQUAL_TYPE,
    SMALLER_TYPE,
    SMALLER_EQUAL_TYPE,
    EQUAL_TYPE,
    NOT_TYPE,
    AND_AND_TYPE,
    OR_OR_TYPE,
    POS_TYPE,
    NEG_TYPE,
    NOT_EQUAL_TYPE,
    // Identifiers
    IDENTIFIER_TYPE,
    // Constants
    NUMBER_TYPE,
    // Unknowns
    UNKNOWN_TYPE,
    // Extra
    EXTRA_TYPE
} Type;

const char * getTypeName(Type type);

typedef struct Node
{
    Type type;
    char name[65];
    // int line;
    int value;

    int isNum;
    char idname[65];
    int idvalue;
    int dim;
    int dim1, dim2; // for array. means m[dim1] or m[dim1][dim2]
    int dim1type, dim2type; // the type of dim1 and dim2 in ArrayDim
    int offset; // Must be register

    int truelist[16];
    int falselist[16];
    int truelen = 0, falselen = 0;
    int isneg = 0;

    struct Node* father;
    int child_cnt;
    struct Node* children[CHILD_CNT];
} Node;

void addNode(Node * father, Node * a, Node * b = NULL,
             Node * c = NULL, Node * d = NULL, Node * e = NULL);

Node * newNode(Type type);
void appendNode(Node * father, Node * son);
void generateGraph(Node * root, const char * a);

int insertVarList(char * name, VarType type, int value = NULL
        , int dim = NULL, int dim1 = NULL, int dim2 = NULL);

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

void out(Node * a); // 跳出的无条件跳转
int genJmp();

void testZero(Node * a);
void genTrueFalseZero(Node * a, int isneg = NULL); // 在比较后使用，仅仅生成两个链

void testCompare(Node * a, Node * b);
void genTrueFalseCompare(Node * a, char type, int equal = NULL);

void modifyAsm(int line, int target, int isbreak = NULL); //把第line行回填上target行，判断是否是break
void cpylist(Node * tar, Node * from);
int mergelist(int * des, int deslen, int * from, int fromlen); // des = des 并 from

void backpatch(Node * a, int truetarget = -1, int falsetarget = -1);

void genReturn(Node * a);

void insertFuncList(char * name);
void addParam(char * funcName, char * varName, VarType type,
              int dim = NULL, int dimContent = NULL);
void processParams(char * funcName);

void call(char * funcName);
//void popParams(char * funcName);

void addToWaitPush(Node * node); // 采取等待队列的方法
void pushParams();
void popVarList(); // 弹出符号表

void genPrintf(Node * a);
void genScanf(Node * a);

void enterStmt();
void exitStmt();

#endif