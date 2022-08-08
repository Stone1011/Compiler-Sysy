%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "tree.h"
// #define VERBOSE 1
int num_lines = 1, num_chars = 1;
int in_comments = 0, in_one_comments = 0;

// void print(int line, int chars, char type)
// {
// 	printf("%s: %c, (%d, %d)\n", yytext, type, line, chars);
// }

const char * keywordsNames [] = {
	"break",
	"const",
	"continue",
	"else",
	"if",
	"int",
	"return",
	"void",
	"while",
	"scanf",
	"printf"
};
int keywords [] = {BREAK, CONST, CONTINUE, ELSE, IF, INT, RETURN, VOID, WHILE, SCANF, PRINTF};
Type keywordsEnum [] = {BREAK_TYPE, CONST_TYPE, CONTINUE_TYPE, ELSE_TYPE, IF_TYPE, INT_TYPE, RETURN_TYPE, VOID_TYPE, WHILE_TYPE};

const char * delimetersNames [] = {"(", ")", "{", "}", "[", "]", ";", ","};
int delimeters [] = {LEFT_BRACKET, RIGHT_BRACKET, LEFT_BIG, RIGHT_BIG, LEFT_MIDDLE, RIGHT_MIDDLE, SEMICOLON, COMMA};
Type delimetersEnum [] = {LEFT_BRACKET_TYPE, RIGHT_BRACKET_TYPE, LEFT_BIG_TYPE, RIGHT_BIG_TYPE, LEFT_MIDDLE_TYPE, RIGHT_MIDDLE_TYPE, SEMICOLON_TYPE, COMMA_TYPE};

const char * operatorsNames[] = {
	"+", "-", "*", "/", "=", "%", ">", ">=", "<", "<=", "==", "!", "&&", "||", "+", "-", "!="
};
int operators [] = {
	ADD, MINUS, MULTI, DIVIDE, ASSIGN, MOD, BIGGER, BIGGER_EQUAL, SMALLER, SMALLER_EQUAL, EQUAL, NOT, AND_AND, OR_OR, POS, NEG, NOT_EQUAL
};
Type operatorsEnum [] = {
	ADD_TYPE, MINUS_TYPE, MULTI_TYPE, DIVIDE_TYPE, ASSIGN_TYPE, MOD_TYPE, 
	BIGGER_TYPE, BIGGER_EQUAL_TYPE, SMALLER_TYPE, SMALLER_EQUAL_TYPE, EQUAL_TYPE, 
	NOT_TYPE, AND_AND_TYPE, OR_OR_TYPE, POS_TYPE, NEG_TYPE, NOT_EQUAL_TYPE
};

int handleKeyword()
{
	#ifdef VERBOSE
	printf("K %s ", yytext);
	#endif
	for(int i = 0; i < sizeof(keywordsNames) / sizeof(keywordsNames[0]); i++)
	{
		if(strcmp(yytext, keywordsNames[i]) == 0)
		{
			yylval.node = newNode(keywordsEnum[i]);
			#ifdef VERBOSE
			printf("%s\n", keywordsNames[i]);
			#endif
			return keywords[i];
		}
	}
}

int handleIden()
{
	#ifdef VERBOSE
	printf("I %s\n", yytext);
	#endif
	yylval.node = newNode(IDENTIFIER_TYPE);
	strcpy(yylval.node->name, yytext);
	// printf(" %s\n", yylval.node->name);
	return ID;
}

int handleConst()
{
	#ifdef VERBOSE
	printf("C %s\n", yytext);
	#endif
	yylval.node = newNode(NUMBER_TYPE);
	if(yytext[0] == '0')
	{
		if(yytext[1] == 'x' || yytext[1] == 'X')
		{
			sscanf(yytext+2, "%x", &(yylval.node->value));
		}
		else
		{
			sscanf(yytext+1, "%o", &(yylval.node->value));
		}
	}
	else
		sscanf(yytext, "%d", &(yylval.node->value));
	// strcpy(yylval.node->name, yytext);
	return NUMBER;
}

int handleDeli()
{
	#ifdef VERBOSE
	printf("D %s\n", yytext);
	#endif
	for(int i = 0; i < sizeof(delimetersNames) / sizeof(delimetersNames[0]); i++)
	{
		if(strcmp(yytext, delimetersNames[i]) == 0)
		{
			yylval.node = newNode(delimetersEnum[i]);
			return delimeters[i];
		}
	}
}

int handleOper()
{
	#ifdef VERBOSE
	printf("O %s\n", yytext);
	#endif
	for(int i = 0; i < sizeof(operatorsNames) / sizeof(operatorsNames[0]); i++)
	{
		if(strcmp(yytext, operatorsNames[i]) == 0)
		{
			yylval.node = newNode(operatorsEnum[i]);
			return operators[i];
		}
	}
}

int handleUndef()
{
	#ifdef VERBOSE
	printf("T %s\n", yytext);
	#endif
	yylval.node = newNode(UNKNOWN_TYPE);
	strcpy(yylval.node->name, yytext);
	return UNKNOWN;
}
%}

%option noyywrap

Newline \n|"\r\n"
Keyword "break"|"const"|"continue"|"else"|"if"|"int"|"return"|"void"|"while"|"scanf"|"printf"
Operator "+"|"-"|"*"|"/"|"="|"%"|">="|">"|"<="|"<"|"=="|"!"|"\|\|"|"&&"|"!="
Digit [0-9]
Digit8 [0-7]
Digit16 [0-9abcdef]|[0-9ABCDEF]
Integer ((([1-9]{Digit}*)|0)([uUlL]|"ul"|"lu"|"Ul"|"uL"|"Lu"|"lU"|"UL"|"LU")?)
Integer8 (0([1-7]{Digit8}*)([uUlL]|"ul"|"lu"|"Ul"|"uL"|"Lu"|"lU"|"UL"|"LU")?)
Integer16 ((0[xX](([1-9abcdef])|[1-9ABCDEF])){Digit16}*(([uUlL]|"ul"|"lu"|"Ul"|"uL"|"Lu"|"lU"|"UL"|"LU")?))
InstantNum ({Integer}|{Integer8}|{Integer16})
Letter [a-zA-Z]
Identifier ({Letter}|_)({Letter}|_|{Digit})*
Delimeter ("("|")"|"{"|"}"|"["|"]"|";"|",")
Blank ([\f\t\v ]+)

%%
"//"	{if(!in_comments)in_one_comments = 1; num_chars += yyleng;}
"/*"	{if(!in_one_comments)in_comments = 1; num_chars += yyleng; /*print(num_lines, num_chars, 'T');*/}
"*/"	{if(!in_one_comments){if(!in_comments) {return handleUndef();} else in_comments = 0;} num_chars += yyleng; }
{Keyword}	{if(!in_comments && !in_one_comments){return handleKeyword(); }num_chars+=yyleng;}
{Identifier}	{if(!in_comments && !in_one_comments){return handleIden(); }num_chars+=yyleng;}
{InstantNum}	{if(!in_comments && !in_one_comments){return handleConst(); }num_chars+=yyleng;}
{Delimeter}	{if(!in_comments && !in_one_comments){ return handleDeli(); }num_chars+=yyleng;}
{Operator}	{if(!in_comments && !in_one_comments){ return handleOper(); }num_chars+=yyleng;}
{Newline}	{++num_lines; num_chars=1; in_one_comments = 0;}
{Blank}	{num_chars+=yyleng;}
.	{++num_chars; if(!in_comments && !in_one_comments){ return handleUndef();}}
<<EOF>> {return 0;}
%%
