/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    UNKNOWN = 259,
    BREAK = 260,
    CONST = 261,
    CONTINUE = 262,
    ELSE = 263,
    IF = 264,
    INT = 265,
    RETURN = 266,
    VOID = 267,
    WHILE = 268,
    SCANF = 269,
    PRINTF = 270,
    NUMBER = 271,
    LEFT_BRACKET = 272,
    RIGHT_BRACKET = 273,
    LEFT_BIG = 274,
    RIGHT_BIG = 275,
    LEFT_MIDDLE = 276,
    RIGHT_MIDDLE = 277,
    SEMICOLON = 278,
    COMMA = 279,
    ADD = 280,
    MINUS = 281,
    MULTI = 282,
    DIVIDE = 283,
    ASSIGN = 284,
    MOD = 285,
    BIGGER = 286,
    BIGGER_EQUAL = 287,
    SMALLER = 288,
    SMALLER_EQUAL = 289,
    EQUAL = 290,
    NOT = 291,
    AND_AND = 292,
    OR_OR = 293,
    POS = 294,
    NEG = 295,
    NOT_EQUAL = 296
  };
#endif
/* Tokens.  */
#define ID 258
#define UNKNOWN 259
#define BREAK 260
#define CONST 261
#define CONTINUE 262
#define ELSE 263
#define IF 264
#define INT 265
#define RETURN 266
#define VOID 267
#define WHILE 268
#define SCANF 269
#define PRINTF 270
#define NUMBER 271
#define LEFT_BRACKET 272
#define RIGHT_BRACKET 273
#define LEFT_BIG 274
#define RIGHT_BIG 275
#define LEFT_MIDDLE 276
#define RIGHT_MIDDLE 277
#define SEMICOLON 278
#define COMMA 279
#define ADD 280
#define MINUS 281
#define MULTI 282
#define DIVIDE 283
#define ASSIGN 284
#define MOD 285
#define BIGGER 286
#define BIGGER_EQUAL 287
#define SMALLER 288
#define SMALLER_EQUAL 289
#define EQUAL 290
#define NOT 291
#define AND_AND 292
#define OR_OR 293
#define POS 294
#define NEG 295
#define NOT_EQUAL 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "grammar.y"

    struct Node* node;

#line 143 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
