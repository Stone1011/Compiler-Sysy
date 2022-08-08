%{
    #include <ctype.h>
    #include <stdio.h>
    #include "tree.h"
    int yylex();
    void yyerror(char * s);
    #define YYDEBUG 1
    extern char * KEYWORDS [];
    Node * root = NULL;
    char treePath[129];
    char tmpIdname[129];
    char tmpFuncName[129];

    int IsAsmMode;
    int isInFunc = 0;

    int breakPos[16];
    int breakNum = 0;
    int continuePos[16];
    int continueNum = 0;
%}

%union
{
    struct Node* node;
}

// Identifiers and Unknowns
%token <node> ID UNKNOWN
// Keywords
%token <node> BREAK CONST CONTINUE ELSE IF INT RETURN VOID WHILE SCANF PRINTF
// Number
%token <node> NUMBER
// Delimeters
%token <node> LEFT_BRACKET RIGHT_BRACKET LEFT_BIG RIGHT_BIG LEFT_MIDDLE RIGHT_MIDDLE SEMICOLON COMMA
// Operators
%token <node> ADD MINUS MULTI DIVIDE ASSIGN MOD BIGGER BIGGER_EQUAL SMALLER SMALLER_EQUAL EQUAL NOT AND_AND OR_OR POS NEG NOT_EQUAL

// priority
%right ASSIGN
%left OR_OR
%left AND_AND
%left ADD MINUS
%left MULTI DIVIDE
%right NOT
%left COMMA LEFT_BRACKET RIGHT_BRACKET LEFT_MIDDLE RIGHT_MIDDLE LEFT_BIG RIGHT_BIG
%nonassoc ELSE

%type <node> CompUnit Decl FuncDef ConstDecl ConstDef ConstExp ConstInitVal VarDecl VarDef Exp FuncFParams 
%type <node> FuncFParam Block BlockItem Stmt LVal Cond AddExp LOrExp PrimaryExp Number UnaryExp FuncRParams UnaryOp 
%type <node> MulExp RelExp EqExp LAndExp ConstDefList ConstArrayDim ArrayDim ArrayContent VarDefList ConstArrayContent
%type <node> BlockItems ConstArrayInitVal ArrayInitVal Start Unknown IdName
// Others: empty ones
%type <node> GenFuncHead GenVarHead SetLabel EnterStmt ExitStmt Jump BeforeFuncBlock
%%

Start : CompUnit {
			$$=newNode(START_TYPE);
			root = $$; addNode($$, $1);
			printf("-----*****-----\nAnalysis Done!\n-----*****-----\n");
			if(!IsAsmMode)generateGraph(root, treePath);
			else solidate();
		}
	;

CompUnit : CompUnit Decl {$$=newNode(COMP_UNIT_TYPE); addNode($$, $1, $2); }
         | CompUnit FuncDef {$$=newNode(COMP_UNIT_TYPE); addNode($$, $1, $2); }
         | Decl {$$=newNode(COMP_UNIT_TYPE); addNode($$, $1); }
         | FuncDef {$$=newNode(COMP_UNIT_TYPE); addNode($$, $1); isInFunc = 0;}
         ;

IdName : ID {$$=newNode(ID_NON_TERM_TYPE);
		strcpy($$->idname, $1->name);
		strcpy(tmpIdname, $1->name);
		addNode($$, $1);
		}
	;

// TODO: global? according to isInFunc.
Decl : ConstDecl {$$=newNode(DECL_TYPE); addNode($$, $1); }
     | VarDecl {$$=newNode(DECL_TYPE); addNode($$, $1); }
     ;

ConstDecl : CONST INT ConstDefList SEMICOLON {$$=newNode(CONST_DECL_TYPE); addNode($$, $1, $2, $3, $4); }
          ;

ConstDefList : ConstDefList COMMA ConstDef {$$=newNode(CONST_DEF_LIST_TYPE); addNode($$, $1, $2, $3); }
  | ConstDef {$$=newNode(CONST_DEF_LIST_TYPE); addNode($$, $1); }
  ;

// TODO: Const Array
ConstDef : IdName ConstArrayDim ASSIGN ConstArrayInitVal { //TODO: Need to be done
 		$$=newNode(CONST_DEF_TYPE); addNode
		($$, $1, $2, $3, $4);
		}
    | IdName ASSIGN ConstInitVal
    		{
    		$$=newNode(CONST_DEF_TYPE);
    		addNode($$, $1, $2, $3);
    		insertVarList($1->idname, Const, $3->idvalue);
    		}
    | IdName {
    		$$=newNode(CONST_DEF_TYPE);
    		addNode($$, $1);
    		insertVarList($1->idname, Const, 0);
    		printf("Warning: Const Decl without initial value.\n");
    	}
    ;

ConstArrayDim : ConstArrayDim LEFT_MIDDLE ConstExp RIGHT_MIDDLE
		{
			$$=newNode(CONST_ARRAY_DIM_TYPE);
			addNode($$, $1, $2, $3, $4);
			$$->dim = $1->dim;
			$$->dim ++;
			$$->dim1 = $1->dim1;
			if($3->isNum == 1)
                        {
                          	$$->dim2 = $3->idvalue;
                        }
                        else if($3->isNum == 0)
                        {
                          	int valid;
                          	int r = findConstValue($3, &valid);
                          	if(valid)
                          	{
                          		$$->dim2 = r;
                          	}
                          	else
                        	{
                 			printf("Syntax Error. Array Decl should use const var.\n");
                          		exit(5);
                          	}
                        }
                        else
                        {
                        	printf("Syntax Error. Array Decl.\n");
                        	exit(5);
                        }
		}
  		| LEFT_MIDDLE ConstExp RIGHT_MIDDLE
  		{
  			$$=newNode(CONST_ARRAY_DIM_TYPE);
  			addNode($$, $1, $2, $3);
  			$$->dim = 1;
  			if($2->isNum == 1)
  			{
  				$$->dim1 = $2->idvalue;
  			}
  			else if($2->isNum == 0)
  			{
  				int valid;
  				int r = findConstValue($2, &valid);
  				if(valid)
  				{
  					$$->dim1 = r;
  				}
  				else
  				{
  					printf("Syntax Error. Array Decl should use const var.\n");
  					exit(5);
  				}
  			}
  			else
  			{
  				printf("Syntax Error. Array Decl.\n");
  				exit(5);
  			}
  		}
  ;

ArrayDim : ArrayDim LEFT_MIDDLE Exp RIGHT_MIDDLE
	{
		$$=newNode(ARRAY_DIM_TYPE);
		addNode($$, $1, $2, $3, $4);

		$$->dim = $1->dim + 1;
		$$->dim1 = $1->dim1;
		$$->dim1type = $1->dim1type;
		if($3->isNum == 0)
                {
                  	Registers r = transferToReg($3->idname);
                  	$$->dim2 = r;
                  	$$->dim2type = 2;
                }
                else if($3->isNum == 1)
                {
                  	$$->dim2 = $3->idvalue;
                  	$$->dim2type = 1;
                }
                else if($3->isNum == 2)
                {
                  	$$->dim2 = $3->idvalue;
                  	$$->dim2type = 2;
                }
	}
  | LEFT_MIDDLE Exp RIGHT_MIDDLE
  	{
  		$$=newNode(ARRAY_DIM_TYPE);
  		addNode($$, $1, $2, $3);

  		if($2->isNum == 0)
  		{
  			Registers r = transferToReg($2->idname);
  			$$->dim = 1;
  			$$->dim1 = r;
  			$$->dim1type = 2;
  		}
  		else if($2->isNum == 1)
  		{
  			$$->dim = 1;
  			$$->dim1 = $2->idvalue;
  			$$->dim1type = 1;
  		}
  		else if($2->isNum == 2)
  		{
  			$$->dim = 1;
  			$$->dim1 = $2->idvalue;
  			$$->dim1type = 2;
  		}
  	}
  ;

// Todo
ConstInitVal : ConstExp {$$=newNode(CONST_INIT_VAL_TYPE); addNode($$, $1); $$->idvalue = $1->idvalue;
			$$->isNum = $1->isNum; if(!($1->isNum))printf("ERROR in const init val. Not done\n"); }
             ;

ConstArrayInitVal : LEFT_BIG RIGHT_BIG {$$=newNode(CONST_ARRAY_INIT_VAL_TYPE); addNode($$, $1, $2); }
             | LEFT_BIG ConstArrayContent RIGHT_BIG {$$=newNode(CONST_ARRAY_INIT_VAL_TYPE); addNode($$, $1, $2, $3); }
             ;

ConstArrayContent : ConstArrayContent COMMA ConstInitVal {$$=newNode(CONST_ARRAY_CONTENT_TYPE); addNode($$, $1, $2, $3); }
  | ConstInitVal {$$=newNode(CONST_ARRAY_CONTENT_TYPE); addNode($$, $1); }
  ;

VarDecl : INT VarDefList SEMICOLON {$$=newNode(VAR_DECL_TYPE); addNode($$, $1, $2, $3); }
        ;

VarDefList : VarDefList COMMA VarDef {$$=newNode(VAR_DEF_LIST_TYPE); addNode($$, $1, $2, $3); }
  | VarDef {$$=newNode(VAR_DEF_LIST_TYPE); addNode($$, $1); }
  ;

VarDef : IdName {$$=newNode(VAR_DEF_TYPE);
		addNode($$, $1);
		if(isInFunc)
			insertVarList($1->idname, Normal);
		else
			insertVarList($1->idname, GlobalNormal);
		}
        | IdName GenVarHead ASSIGN ConstInitVal {$$=newNode(VAR_DEF_TYPE);
         	addNode($$, $1, $3, $4);
         	if(isInFunc)
         		genAssign($1, $4);
         	else
         	{
         		insertVarList(tmpIdname, GlobalNormal, $4->idvalue);
         	}
         	}
        | IdName ConstArrayDim
        {
        	$$=newNode(VAR_DEF_TYPE);
        	addNode($$, $1, $2);
        	if(isInFunc)
        		insertVarList($1->idname, Array, NULL, $2->dim, $2->dim1, $2->dim2);
        	else
                	insertVarList($1->idname, GlobalArray, NULL, $2->dim, $2->dim1, $2->dim2);
        }
        | IdName ConstArrayDim ASSIGN ArrayInitVal {$$=newNode(VAR_DEF_TYPE); addNode($$, $1, $2, $3, $4);
        						printf("Cannot generate ASM code for now...\n");}
        ;

GenVarHead :
	{
		if(isInFunc)
			insertVarList(tmpIdname, Normal);
		$$ = newNode(EXTRA_TYPE);
		strcpy($$->idname, tmpIdname);
	}

ArrayInitVal : LEFT_BIG RIGHT_BIG {$$=newNode(ARRAY_INIT_VAL_TYPE); addNode($$, $1, $2); }
             | LEFT_BIG ArrayContent RIGHT_BIG {$$=newNode(ARRAY_INIT_VAL_TYPE); addNode($$, $1, $2, $3); }
             ;

ArrayContent : ArrayContent COMMA ConstInitVal {$$=newNode(ARRAY_CONTENT_TYPE); addNode($$, $1, $2, $3); }
  | ConstInitVal { $$=newNode(ARRAY_CONTENT_TYPE); addNode($$, $1);}
  ;

// TODO: Func Def
FuncDef : INT IdName GenFuncHead LEFT_BRACKET FuncFParams RIGHT_BRACKET BeforeFuncBlock Block
		{
		$$=newNode(FUNC_DEF_TYPE);
		addNode($$, $1, $2, $4, $5, $6);
		addNode($$, $8);
		popVarList();
		}
        | INT IdName GenFuncHead LEFT_BRACKET RIGHT_BRACKET BeforeFuncBlock Block
        	{
        	$$=newNode(FUNC_DEF_TYPE);
        	addNode($$, $1, $2, $4, $5, $7);
        	popVarList();
        	}
        | VOID IdName GenFuncHead LEFT_BRACKET FuncFParams RIGHT_BRACKET BeforeFuncBlock Block
        	{
        	$$=newNode(FUNC_DEF_TYPE);
        	addNode($$, $1, $2, $4, $5, $6);
        	addNode($$, $8);
        	popVarList();
        	}
        | VOID IdName GenFuncHead LEFT_BRACKET RIGHT_BRACKET BeforeFuncBlock Block
        	{
        	$$=newNode(FUNC_DEF_TYPE);
        	addNode($$, $1, $2, $4, $5, $7);
        	popVarList();
        	}
        ;

BeforeFuncBlock :
	{
		processParams(tmpFuncName);
	}

GenFuncHead :
	{
		genFuncHead(tmpIdname);
		insertFuncList(tmpIdname);
		$$ = newNode(EXTRA_TYPE);
		strcpy($$->idname, tmpIdname);
		strcpy(tmpFuncName, tmpIdname);
		isInFunc = 1;
	}

FuncFParams : FuncFParams COMMA FuncFParam {$$=newNode(FUNC_F_PARAMS_TYPE); addNode($$, $1, $2, $3); }
            | FuncFParam {$$=newNode(FUNC_F_PARAMS_TYPE); addNode($$, $1);}
            ;

// important
FuncFParam : INT IdName
		{
		 	$$=newNode(FUNC_F_PARAM_TYPE);
		 	addNode($$, $1, $2);
		 	addParam(tmpFuncName, $2->idname, Normal);
		}
           | INT IdName LEFT_MIDDLE RIGHT_MIDDLE
           	{
           		printf("Still working on it."); exit(13);
           		$$=newNode(FUNC_F_PARAM_TYPE);
           		addNode($$, $1, $2, $3, $4);
           		addParam(tmpFuncName, $2->idname, Array, 1);
           	}
           | INT IdName LEFT_MIDDLE RIGHT_MIDDLE ArrayDim
           	{
           		printf("Still working on it."); exit(13);
           		$$=newNode(FUNC_F_PARAM_TYPE);
           		addNode($$, $1, $2, $3, $4, $5);
           		addParam(tmpFuncName, $2->idname, Array, 2, $5->dim1);
           	}
           ;

Block : LEFT_BIG BlockItems RIGHT_BIG {$$=newNode(BLOCK_TYPE); addNode($$, $1, $2, $3); }
        | LEFT_BIG RIGHT_BIG {$$=newNode(BLOCK_TYPE); addNode($$, $1, $2);}
      ;

BlockItems : BlockItems BlockItem { $$=newNode(BLOCK_ITEMS_TYPE); addNode($$, $1, $2);}
  | BlockItem {$$=newNode(BLOCK_ITEMS_TYPE); addNode($$, $1); }
  ;

BlockItem : Decl {$$=newNode(BLOCK_ITEM_TYPE); addNode($$, $1); }
          | Stmt {$$=newNode(BLOCK_ITEM_TYPE); addNode($$, $1); }
          ;

SetLabel : {
		$$ = newNode(EXTRA_TYPE);
		$$->idvalue = getNextI();
	}
	;

EnterStmt : { enterStmt(); }
	;

ExitStmt : {
		$$ = newNode(EXTRA_TYPE);
		$$->idvalue = getNextI();
		exitStmt();
	}
	;

Jump : {
		$$ = newNode(EXTRA_TYPE);
		out($$);
		$$->idvalue = getNextI();
	}
	;

Stmt : LVal ASSIGN Exp SEMICOLON
	{
		$$=newNode(STMT_TYPE);
		addNode($$, $1, $2, $3, $4);
		genAssign($1, $3);
	}
     | Exp SEMICOLON {$$=newNode(STMT_TYPE); addNode($$, $1, $2); }
     | SEMICOLON {$$=newNode(STMT_TYPE); addNode($$, $1); }
     | Block {$$=newNode(STMT_TYPE); addNode($$, $1); }
     | IF LEFT_BRACKET Cond RIGHT_BRACKET SetLabel EnterStmt Stmt ExitStmt SetLabel
     	{
     		$$=newNode(STMT_TYPE);
     		addNode($$, $1, $2, $3, $4, $7);
     		backpatch($3, $5->idvalue, $9->idvalue);
     	}
     | IF LEFT_BRACKET Cond RIGHT_BRACKET SetLabel EnterStmt Stmt ExitStmt SetLabel Jump ELSE
     	SetLabel EnterStmt Stmt ExitStmt SetLabel
     	{
     		$$=newNode(STMT_TYPE);
     		addNode($$, $1, $2, $3, $4, $7);
     		addNode($$, $11, $14);
     		backpatch($3, $5->idvalue, $12->idvalue);
     		backpatch($10, $16->idvalue);
     	}
     | WHILE SetLabel LEFT_BRACKET Cond RIGHT_BRACKET SetLabel EnterStmt Stmt ExitStmt Jump
     	{
     		$$=newNode(STMT_TYPE);
     		addNode($$, $1, $3, $4, $5, $8);
     		backpatch($4, $6->idvalue, $10->idvalue);
     		backpatch($10, $2->idvalue);
     		// 只支持一层里有break和continue，否则会报错
     		// 应该用栈存
     		// 不支持break的循环中定义局部变量，否则会出错
     		// break
     		for(int i = 0; i < breakNum; i++)
     		{
     			modifyAsm(breakPos[i], $10->idvalue, 1);
     		}
     		breakNum = 0;
     		// continue
     		for(int i = 0; i < continueNum; i++)
     		{
     			modifyAsm(continuePos[i], $9->idvalue);
     		}
     		continueNum = 0;
     	}
     | BREAK SEMICOLON
     	{
     		$$=newNode(STMT_TYPE);
     		addNode($$, $1, $2);
     		int k = genJmp();
     		breakPos[breakNum ++] = k;
     	}
     | CONTINUE SEMICOLON {
     	$$=newNode(STMT_TYPE);
     	addNode($$, $1, $2);
     	int k = genJmp();
     	continuePos[continueNum ++] = k;
     	}
     | RETURN SEMICOLON
     	{
     		$$=newNode(STMT_TYPE);
     		addNode($$, $1, $2);
     		genReturn();
     	}
     | RETURN Exp SEMICOLON
     	{
     		$$=newNode(STMT_TYPE);
     		addNode($$, $1, $2, $3);
     		genReturn($2);
     	}
     | SCANF LEFT_BRACKET Exp RIGHT_BRACKET SEMICOLON
     	{
     		genScanf($3);
     	}
     | PRINTF LEFT_BRACKET Exp RIGHT_BRACKET SEMICOLON
          {
          	genPrintf($3);
          }
     ;

Exp : AddExp {
		$$=newNode(EXP_TYPE);
		addNode($$, $1);
		$$->idvalue = $1->idvalue;
		strcpy($$->idname, $1->idname);
		$$->isNum = $1->isNum;
	}
    | Unknown {$$=newNode(EXP_TYPE); addNode($$, $1); }
    ;

Cond : LOrExp
	{
		$$=newNode(COND_TYPE);
		addNode($$, $1);
		$$->isNum = $1->isNum;
		cpylist($$, $1);
	}
     ;

// TODO: LVal Array
LVal : IdName
	{
		$$=newNode(L_VAL_TYPE);
		addNode($$, $1);
		$$->isNum = 0;
		strcpy($$->idname, $1->idname);
	}
     | IdName ArrayDim
     	{
     		$$=newNode(L_VAL_TYPE);
     		addNode($$, $1, $2);

     		$$->isNum = 3; // Array
     		strcpy($$->idname, $1->idname);
     		int type;
     		$$->offset = calcOffsetAndFreeReg($1, $2, &type);
     		if(type == 1)
     		{
     			Registers r = transferToReg($$->offset);
     			$$->offset = r;
     		}
     	}
     ;

// Todo: change LVal Array to register
// Todo: bracket, change to register
PrimaryExp : LEFT_BRACKET Exp RIGHT_BRACKET
	{
		$$=newNode(PRIMARY_EXP_TYPE);
		addNode($$, $1, $2, $3);
		// TODO
	}
           | LVal {
           		$$=newNode(PRIMARY_EXP_TYPE);
           		addNode($$, $1);

			if($1->isNum == 0)
			{
				$$->isNum = 0;
                                strcpy($$->idname, $1->idname);
			}
			else if($1->isNum == 3)
			{
				$$->isNum = 2;
				$$->idvalue = arrayTransferToRegAndFree($1->idname, $1->offset);
			}
		}
           | Number {$$=newNode(PRIMARY_EXP_TYPE);
           	addNode($$, $1);
           	$$->idvalue = $1->idvalue;
           	$$->isNum = 1;}
           ;

Number : NUMBER {$$=newNode(NUMBER_NON_TERM_TYPE); addNode($$, $1);
			$$->idvalue = $1->value; $$->isNum = 1;}
       ;

// TODO: Function Mismatch?
UnaryExp : PrimaryExp
		{
		$$=newNode(UNARY_EXP_TYPE);
		addNode($$, $1);
		if($1->isNum == 1 || $1->isNum == 2){
			$$->idvalue = $1->idvalue;
		}
		else if($1->isNum == 0)
		{
			strcpy($$->idname, $1->idname);
		}
		$$->isNum = $1->isNum;
		$$->isneg = $1->isneg;
		}
         | IdName LEFT_BRACKET RIGHT_BRACKET
         {
         	$$=newNode(UNARY_EXP_TYPE);
         	addNode($$, $1, $2, $3);

         	call($1->idname);
         	$$->isNum = 2; $$->idvalue = EAX;
         }
         | IdName LEFT_BRACKET FuncRParams RIGHT_BRACKET
         {
         	$$=newNode(UNARY_EXP_TYPE);
         	addNode($$, $1, $2, $3, $4);

         	pushParams();
         	call($1->idname);
         	// popParams($1->idname);
         	$$->isNum = 2; $$->idvalue = EAX;
         }
         | UnaryOp UnaryExp
         {
         	$$=newNode(UNARY_EXP_TYPE);
         	addNode($$, $1, $2);
         	$$->isNum = $2->isNum;
         	$$->idvalue = $2->idvalue;
         	strcpy($$->idname, $2->idname);
         	$$->isneg += $1->isneg;
         }
         ;

// TODO
UnaryOp : POS {$$=newNode(UNARY_OP_TYPE); addNode($$, $1); }
        | NEG {$$=newNode(UNARY_OP_TYPE); addNode($$, $1); }
        | NOT
        {
        	$$=newNode(UNARY_OP_TYPE);
        	addNode($$, $1);
        	$$->isneg ++;
        }
        ;

FuncRParams : FuncRParams COMMA Exp {$$=newNode(FUNC_R_PARAMS_TYPE); addNode($$, $1, $2, $3); }
            | Exp
            {
            	$$=newNode(FUNC_R_PARAMS_TYPE);
            	addNode($$, $1);
            	addToWaitPush($1);
            }
            ;

MulExp : UnaryExp
		{
			$$=newNode(MULTI_EXP_TYPE);
			addNode($$, $1);
			$$->isNum = $1->isNum;
			if($$->isNum == 1){$$->idvalue = $1->idvalue;}
			else if($$->isNum == 0)
			{
				strcpy($$->idname, $1->idname);
			}
			else if($$->isNum == 2)
			{
				$$->idvalue = $1->idvalue;
			}

			$$->isneg = $1->isneg;
		}
       | MulExp MULTI UnaryExp
       	{
       		$$=newNode(MULTI_EXP_TYPE);
       		addNode($$, $1, $2, $3);
       		$$->idvalue = genMulti($1, $3);
       		$$->isNum = 2;
       	}
       | MulExp DIVIDE UnaryExp {$$=newNode(MULTI_EXP_TYPE); addNode($$, $1, $2, $3); }
       | MulExp MOD UnaryExp {$$=newNode(MULTI_EXP_TYPE); addNode($$, $1, $2, $3); }
       ;

// Todo
AddExp : MulExp
	{
		$$=newNode(ADD_EXP_TYPE);
		addNode($$, $1);
		$$->isNum = $1->isNum;
		if($$->isNum == 1 || $$->isNum == 2)$$->idvalue = $1->idvalue;
		else if($$->isNum == 0)
		{
			strcpy($$->idname, $1->idname);
		}

		$$->isneg = $1->isneg;
	}
       | AddExp ADD MulExp
       	{
       		$$=newNode(ADD_EXP_TYPE);
       		addNode($$, $1, $2, $3);
       		$$->idvalue = genAdd($1, $3);
       		$$->isNum = 2;
       	}
       | AddExp MINUS MulExp
       	{
       		$$=newNode(ADD_EXP_TYPE);
       		addNode($$, $1, $2, $3);
       		$$->idvalue = genMinus($1, $3);
       		$$->isNum = 2;
       	}
       ;

RelExp : AddExp {
			$$=newNode(REL_EXP_TYPE);
			addNode($$, $1);
			$$->isNum = $1->isNum;
			$$->idvalue = $1->idvalue;
			strcpy($$->idname, $1->idname);
			$$->isneg = $1->isneg;
		}
       | AddExp SMALLER AddExp
       		{
       			$$=newNode(REL_EXP_TYPE);
       			addNode($$, $1, $2, $3);
       			$$->isNum = 4;
       			testCompare($1, $3);
       			genTrueFalseCompare($$, 'l');
       		}
       | AddExp BIGGER AddExp
       		{
       			$$=newNode(REL_EXP_TYPE);
       			addNode($$, $1, $2, $3);
       			$$->isNum = 4;
                        testCompare($1, $3);
                        genTrueFalseCompare($$, 'g');
       		}
       | AddExp SMALLER_EQUAL AddExp
       		{
       			$$=newNode(REL_EXP_TYPE);
       			addNode($$, $1, $2, $3);
       			$$->isNum = 4;
                        testCompare($1, $3);
                        genTrueFalseCompare($$, 'l', 1);
       		}
       | AddExp BIGGER_EQUAL AddExp
       		{
       			$$=newNode(REL_EXP_TYPE);
       			addNode($$, $1, $2, $3);
       			$$->isNum = 4;
                        testCompare($1, $3);
                        genTrueFalseCompare($$, 'g', 1);
       		}
       ;

// TODO
EqExp : RelExp
	{
		$$=newNode(EQUAL_EXP_TYPE);
		addNode($$, $1);
		if($1->isNum != 4)
		{
			$$->isNum = $1->isNum;
			$$->idvalue = $1->idvalue;
			strcpy($$->idname, $1->idname);
                	testZero($1);
                	genTrueFalseZero($$, $1->isneg);
                	$$->isNum = 4;
                }
                else
                {
                	$$->isNum = 4;
                	cpylist($$, $1);
                }
	}
      | RelExp EQUAL RelExp
      	{
      		$$=newNode(EQUAL_EXP_TYPE);
      		addNode($$, $1, $2, $3);
      		$$->isNum = 4;
                testCompare($1, $3);
                genTrueFalseCompare($$, 'e');
      	}
      | RelExp NOT_EQUAL RelExp
      	{
      		$$=newNode(EQUAL_EXP_TYPE);
      		addNode($$, $1, $2, $3);
      		$$->isNum = 4;
      		testCompare($1, $3);
      		genTrueFalseCompare($$, 'n', 1);
      	}
      ;

LAndExp : EqExp
	{
		$$=newNode(L_AND_AND_EXP_TYPE);
		addNode($$, $1);
		$$->isNum = $1->isNum;
		cpylist($$, $1);
	}
        | LAndExp AND_AND SetLabel EqExp
        {
        	$$=newNode(L_AND_AND_EXP_TYPE);
        	addNode($$, $1, $2, $4);

        	$$->isNum = 4;
        	backpatch($1, $3->idvalue);
        	cpylist($$, $4);
        	$$->falselen = mergelist($$->falselist, $$->falselen, $1->falselist, $1->falselen);
        }
        ;

LOrExp : LAndExp
	{
		$$=newNode(L_OR_OR_EXP_TYPE);
		addNode($$, $1);
		$$->isNum = $1->isNum;
		cpylist($$, $1);
	}
       | LOrExp OR_OR SetLabel LAndExp
       	{
       		$$=newNode(L_OR_OR_EXP_TYPE);
       		addNode($$, $1, $2, $4);

       		$$->isNum = 4;
       		backpatch($1, -1, $3->idvalue);
       		cpylist($$, $4);
       		$$->truelen = mergelist($$->truelist, $$->truelen, $1->truelist, $1->truelen);
       	}
       ;

ConstExp : AddExp {
			$$=newNode(CONST_EXP_TYPE);
			addNode($$, $1);
			$$->idvalue = $1->idvalue;
			strcpy($$->idname, $1->idname);
			$$->isNum = $1->isNum;
		}
         ;

Unknown : UNKNOWN {fprintf(stderr, "Undefined symbol (%s)", $1->name); exit(9);}

%%

void yyerror(char * s)
{
    fprintf(stderr, "%s\n", s);
}

int main(int argc, char * argv[])
{
	// Open File
	FILE * fp = NULL;
	if(argc > 3 && strcmp(argv[1], "-dot") == 0)
	{
		fp = freopen(argv[2], "r", stdin);
    strcpy(treePath, argv[3]);
		if(fp == NULL)
		{
			printf("Cannot open file.\n");
			exit(1);
		}
		IsAsmMode = 0;
	}
	else if(argc > 3 && strcmp(argv[1], "-s") == 0)
	{
		fp = freopen(argv[2], "r", stdin);
		if(fp == NULL)
		{
			printf("Cannot open src file.\n");
			exit(1);
		}
		setGenerator(argv[3]);
		IsAsmMode = 1;
	}
  else
  {
  	fp = freopen("./Test/test.sy", "r", stdin);
        if(fp == NULL)
        {
        	printf("Cannot open src file.\n");
        	exit(1);
        }
        setGenerator("./Output/test.s");
        IsAsmMode = 1;
  }
	
	// Begin YACC parser
	yyparse();
	return 0;
} 