/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

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

#line 92 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 230 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    66,    67,    68,    69,    72,    80,    81,
      84,    87,    88,    92,    96,   102,   110,   141,   172,   197,
     225,   229,   230,   233,   234,   237,   240,   241,   244,   251,
     260,   269,   274,   281,   282,   285,   286,   290,   297,   303,
     310,   319,   324,   333,   334,   338,   344,   351,   360,   361,
     364,   365,   368,   369,   372,   378,   381,   388,   395,   401,
     402,   403,   404,   410,   419,   441,   448,   454,   460,   466,
     470,   476,   483,   486,   496,   503,   522,   528,   543,   549,
     554,   568,   576,   586,   598,   599,   600,   608,   609,   617,
     634,   641,   642,   646,   659,   666,   675,   683,   691,   699,
     707,   718,   737,   745,   755,   762,   774,   781,   793,   802
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "UNKNOWN", "BREAK", "CONST",
  "CONTINUE", "ELSE", "IF", "INT", "RETURN", "VOID", "WHILE", "SCANF",
  "PRINTF", "NUMBER", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_BIG",
  "RIGHT_BIG", "LEFT_MIDDLE", "RIGHT_MIDDLE", "SEMICOLON", "COMMA", "ADD",
  "MINUS", "MULTI", "DIVIDE", "ASSIGN", "MOD", "BIGGER", "BIGGER_EQUAL",
  "SMALLER", "SMALLER_EQUAL", "EQUAL", "NOT", "AND_AND", "OR_OR", "POS",
  "NEG", "NOT_EQUAL", "$accept", "Start", "CompUnit", "IdName", "Decl",
  "ConstDecl", "ConstDefList", "ConstDef", "ConstArrayDim", "ArrayDim",
  "ConstInitVal", "ConstArrayInitVal", "ConstArrayContent", "VarDecl",
  "VarDefList", "VarDef", "GenVarHead", "ArrayInitVal", "ArrayContent",
  "FuncDef", "BeforeFuncBlock", "GenFuncHead", "FuncFParams", "FuncFParam",
  "Block", "BlockItems", "BlockItem", "SetLabel", "EnterStmt", "ExitStmt",
  "Jump", "Stmt", "Exp", "Cond", "LVal", "PrimaryExp", "Number",
  "UnaryExp", "UnaryOp", "FuncRParams", "MulExp", "AddExp", "RelExp",
  "EqExp", "LAndExp", "LOrExp", "ConstExp", "Unknown", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF (-197)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-58)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     184,    11,    33,    33,    59,   184,  -197,  -197,  -197,  -197,
      33,  -197,    53,    99,  -197,  -197,  -197,  -197,  -197,    -9,
     110,  -197,   127,    -7,    43,    45,  -197,    33,    62,   127,
      72,  -197,    33,  -197,     7,  -197,  -197,  -197,    31,  -197,
    -197,  -197,  -197,   127,   203,   121,    87,   127,   116,   127,
      74,   128,  -197,   138,  -197,  -197,   145,  -197,  -197,   162,
     121,  -197,    37,     7,   155,  -197,   127,   127,   127,   127,
     127,  -197,   173,    47,  -197,  -197,    33,  -197,    95,  -197,
    -197,   141,   122,  -197,  -197,  -197,  -197,   174,   175,     7,
    -197,  -197,  -197,   203,   203,  -197,  -197,  -197,    78,   181,
     186,  -197,   202,   186,  -197,  -197,  -197,   112,  -197,     7,
    -197,   192,  -197,   127,   194,   101,  -197,   186,  -197,  -197,
     186,  -197,   127,  -197,  -197,  -197,   197,   201,   209,   217,
      33,   224,  -197,   218,   219,  -197,  -197,  -197,  -197,   168,
    -197,  -197,   214,   210,  -197,  -197,  -197,   155,  -197,  -197,
     127,  -197,   215,   226,     7,     7,  -197,  -197,  -197,     7,
     208,    63,   158,  -197,   207,   211,  -197,   127,   230,   232,
     228,  -197,   127,   127,   127,   127,   127,   127,  -197,  -197,
     234,   231,   233,  -197,  -197,   121,   121,   121,   121,  -197,
    -197,   127,   127,  -197,  -197,  -197,   206,  -197,   207,  -197,
    -197,   206,  -197,  -197,   245,  -197,   247,  -197,  -197,  -197,
     206,  -197,  -197,  -197
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     5,     8,     9,     6,
       0,     7,    28,     0,    27,    42,     1,     3,     4,    15,
       0,    12,     0,    30,     0,     0,    25,     0,     0,     0,
       0,    10,     0,    79,     0,    86,    84,    85,    74,    77,
      80,    78,    89,     0,    93,   108,     0,     0,     0,     0,
       0,    28,    26,     0,    14,    20,     0,    11,   109,     0,
      71,    72,     0,     0,    75,    83,     0,     0,     0,     0,
       0,    17,     0,     0,    31,    29,     0,    41,     0,    44,
      41,     0,     0,    13,    76,    81,    88,     0,     0,     0,
      90,    91,    92,    94,    95,    16,    33,    36,     0,    45,
       0,    41,     0,     0,    41,    21,    24,     0,    82,     0,
      19,     0,    34,     0,     0,     0,    38,     0,    43,    40,
       0,    22,     0,    87,    18,    35,    46,     0,     0,     0,
       0,     0,    54,     0,     0,    49,    60,    52,    61,     0,
      51,    53,     0,    77,    37,    39,    23,    47,    65,    66,
       0,    67,     0,     0,     0,     0,    48,    50,    59,     0,
       0,    96,   101,   104,   106,    73,    68,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,    54,    54,
       0,     0,     0,    58,    55,    98,   100,    97,    99,   102,
     103,     0,     0,    54,    69,    70,     0,   105,   107,    55,
      56,     0,    54,    56,    62,    57,     0,    64,    54,    55,
       0,    56,    54,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,  -197,    -1,    32,  -197,  -197,   225,   239,   133,
     -44,  -197,  -197,  -197,  -197,   235,  -197,  -197,  -197,   256,
     -36,   250,   213,   165,    86,  -197,   129,  -163,  -196,   -43,
      64,  -130,   -28,   103,  -111,  -197,  -197,   -10,  -197,  -197,
     -51,   -22,    24,    80,    81,  -197,    -5,  -197
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    38,   137,     7,    20,    21,    23,    64,
      54,    83,   107,     8,    13,    14,    24,    74,    98,     9,
     100,    25,    78,    79,   138,   139,   140,   153,   196,   202,
     206,   141,   142,   160,    39,    40,    41,    42,    43,    87,
      44,    60,   162,   163,   164,   165,    55,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    12,    15,   201,   143,    75,    59,    45,   184,    19,
      11,    58,    22,   210,    47,   191,   192,    46,    93,    94,
      29,    10,    48,    33,    34,    45,    51,    45,   143,    97,
     199,    19,     6,    65,    86,    88,    11,    17,   106,   204,
      11,    58,    72,    35,   103,   209,    36,    37,    62,   213,
      11,    45,    63,    33,    34,    85,    90,    91,    92,    16,
      45,   111,    50,    33,    34,   117,   200,    96,   120,   125,
     -42,   203,    49,    35,    22,    99,    36,    37,   146,    53,
     211,   123,   -32,    35,    76,   143,    36,    37,    69,    70,
     143,    45,    77,    47,   172,   173,   174,   175,   112,   143,
      45,    56,   113,   152,    11,    58,   127,     1,   128,    71,
     129,   130,   131,   101,   132,   133,   134,    33,    34,   102,
     115,   135,    26,    27,   136,    11,   168,   169,   161,    51,
      11,   170,   121,    31,    32,    73,   122,    35,    33,    34,
      36,    37,   105,    33,    34,   161,    69,    70,    76,    22,
     185,   186,   187,   188,   161,   161,    80,   -32,    35,   104,
     205,    36,    37,    35,    82,   102,    36,    37,   212,   161,
     161,    11,    58,   127,     1,   128,    89,   129,   130,   131,
      84,   132,   133,   134,    33,    34,   116,   115,   156,   119,
       1,   136,   108,   176,     2,    95,     3,   110,   109,   177,
     189,   190,   114,   144,    35,   115,   145,    36,    37,    11,
      58,   127,    76,   128,   124,   129,   126,   131,    63,   132,
     133,   134,    33,    34,   148,   115,   171,    11,    58,   136,
      66,    67,   149,    68,   150,   154,   155,   158,   166,   159,
      33,    34,    35,   167,   178,    36,    37,   151,   181,   179,
     182,   183,   193,   -57,   194,   208,   195,    57,    30,   147,
      35,    18,    52,    36,    37,    28,    81,   118,   157,   207,
     180,   197,     0,   198
};

static const yytype_int16 yycheck[] =
{
      22,     2,     3,   199,   115,    49,    34,    29,   171,    10,
       3,     4,    21,   209,    21,   178,   179,    22,    69,    70,
      29,    10,    29,    16,    17,    47,    27,    49,   139,    73,
     193,    32,     0,    43,    62,    63,     3,     5,    82,   202,
       3,     4,    47,    36,    80,   208,    39,    40,    17,   212,
       3,    73,    21,    16,    17,    18,    66,    67,    68,     0,
      82,    89,    17,    16,    17,   101,   196,    20,   104,   113,
      17,   201,    29,    36,    21,    76,    39,    40,   122,    17,
     210,   109,    29,    36,    10,   196,    39,    40,    25,    26,
     201,   113,    18,    21,    31,    32,    33,    34,    20,   210,
     122,    29,    24,   131,     3,     4,     5,     6,     7,    22,
       9,    10,    11,    18,    13,    14,    15,    16,    17,    24,
      19,    20,    23,    24,    23,     3,   154,   155,   150,   130,
       3,   159,    20,    23,    24,    19,    24,    36,    16,    17,
      39,    40,    20,    16,    17,   167,    25,    26,    10,    21,
     172,   173,   174,   175,   176,   177,    18,    29,    36,    18,
     203,    39,    40,    36,    19,    24,    39,    40,   211,   191,
     192,     3,     4,     5,     6,     7,    21,     9,    10,    11,
      18,    13,    14,    15,    16,    17,   100,    19,    20,   103,
       6,    23,    18,    35,    10,    22,    12,    22,    24,    41,
     176,   177,    21,   117,    36,    19,   120,    39,    40,     3,
       4,     5,    10,     7,    22,     9,    22,    11,    21,    13,
      14,    15,    16,    17,    23,    19,    18,     3,     4,    23,
      27,    28,    23,    30,    17,    17,    17,    23,    23,    29,
      16,    17,    36,    17,    37,    39,    40,    23,    18,    38,
      18,    23,    18,     8,    23,     8,    23,    32,    19,   126,
      36,     5,    27,    39,    40,    15,    53,   102,   139,   205,
     167,   191,    -1,   192
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    10,    12,    43,    44,    46,    47,    55,    61,
      10,     3,    45,    56,    57,    45,     0,    46,    61,    45,
      48,    49,    21,    50,    58,    63,    23,    24,    63,    29,
      50,    23,    24,    16,    17,    36,    39,    40,    45,    76,
      77,    78,    79,    80,    82,    83,    88,    21,    29,    29,
      17,    45,    57,    17,    52,    88,    29,    49,     4,    74,
      83,    89,    17,    21,    51,    79,    27,    28,    30,    25,
      26,    22,    88,    19,    59,    52,    10,    18,    64,    65,
      18,    64,    19,    53,    18,    18,    74,    81,    74,    21,
      79,    79,    79,    82,    82,    22,    20,    52,    60,    45,
      62,    18,    24,    62,    18,    20,    52,    54,    18,    24,
      22,    74,    20,    24,    21,    19,    66,    62,    65,    66,
      62,    20,    24,    74,    22,    52,    22,     5,     7,     9,
      10,    11,    13,    14,    15,    20,    23,    46,    66,    67,
      68,    73,    74,    76,    66,    66,    52,    51,    23,    23,
      17,    23,    74,    69,    17,    17,    20,    68,    23,    29,
      75,    83,    84,    85,    86,    87,    23,    17,    74,    74,
      74,    18,    31,    32,    33,    34,    35,    41,    37,    38,
      75,    18,    18,    23,    69,    83,    83,    83,    83,    84,
      84,    69,    69,    18,    23,    23,    70,    85,    86,    69,
      73,    70,    71,    73,    69,    71,    72,    72,     8,    69,
      70,    73,    71,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    45,    46,    46,
      47,    48,    48,    49,    49,    49,    50,    50,    51,    51,
      52,    53,    53,    54,    54,    55,    56,    56,    57,    57,
      57,    57,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    62,    63,    64,    64,    65,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    70,    71,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    76,    76,    77,    77,    77,    78,
      79,    79,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    84,    84,    84,    84,
      84,    85,    85,    85,    86,    86,    87,    87,    88,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       4,     3,     1,     4,     3,     1,     4,     3,     4,     3,
       1,     2,     3,     3,     1,     3,     3,     1,     1,     4,
       2,     4,     0,     2,     3,     3,     1,     8,     7,     8,
       7,     0,     0,     3,     1,     2,     4,     5,     3,     2,
       2,     1,     1,     1,     0,     0,     0,     0,     4,     2,
       1,     1,     9,    16,    10,     2,     2,     2,     3,     5,
       5,     1,     1,     1,     1,     2,     3,     1,     1,     1,
       1,     3,     4,     2,     1,     1,     1,     3,     1,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 57 "grammar.y"
                 {
			(yyval.node)=newNode(START_TYPE);
			root = (yyval.node); addNode((yyval.node), (yyvsp[0].node));
			printf("-----*****-----\nAnalysis Done!\n-----*****-----\n");
			if(!IsAsmMode)generateGraph(root, treePath);
			else solidate();
		}
#line 1574 "y.tab.c"
    break;

  case 3:
#line 66 "grammar.y"
                         {(yyval.node)=newNode(COMP_UNIT_TYPE); addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1580 "y.tab.c"
    break;

  case 4:
#line 67 "grammar.y"
                            {(yyval.node)=newNode(COMP_UNIT_TYPE); addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1586 "y.tab.c"
    break;

  case 5:
#line 68 "grammar.y"
                {(yyval.node)=newNode(COMP_UNIT_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 1592 "y.tab.c"
    break;

  case 6:
#line 69 "grammar.y"
                   {(yyval.node)=newNode(COMP_UNIT_TYPE); addNode((yyval.node), (yyvsp[0].node)); isInFunc = 0;}
#line 1598 "y.tab.c"
    break;

  case 7:
#line 72 "grammar.y"
            {(yyval.node)=newNode(ID_NON_TERM_TYPE);
		strcpy((yyval.node)->idname, (yyvsp[0].node)->name);
		strcpy(tmpIdname, (yyvsp[0].node)->name);
		addNode((yyval.node), (yyvsp[0].node));
		}
#line 1608 "y.tab.c"
    break;

  case 8:
#line 80 "grammar.y"
                 {(yyval.node)=newNode(DECL_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 1614 "y.tab.c"
    break;

  case 9:
#line 81 "grammar.y"
               {(yyval.node)=newNode(DECL_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 1620 "y.tab.c"
    break;

  case 10:
#line 84 "grammar.y"
                                             {(yyval.node)=newNode(CONST_DECL_TYPE); addNode((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1626 "y.tab.c"
    break;

  case 11:
#line 87 "grammar.y"
                                           {(yyval.node)=newNode(CONST_DEF_LIST_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1632 "y.tab.c"
    break;

  case 12:
#line 88 "grammar.y"
             {(yyval.node)=newNode(CONST_DEF_LIST_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 1638 "y.tab.c"
    break;

  case 13:
#line 92 "grammar.y"
                                                         { //TODO: Need to be done
 		(yyval.node)=newNode(CONST_DEF_TYPE); addNode
		((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
		}
#line 1647 "y.tab.c"
    break;

  case 14:
#line 97 "grammar.y"
                {
    		(yyval.node)=newNode(CONST_DEF_TYPE);
    		addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    		insertVarList((yyvsp[-2].node)->idname, Const, (yyvsp[0].node)->idvalue);
    		}
#line 1657 "y.tab.c"
    break;

  case 15:
#line 102 "grammar.y"
             {
    		(yyval.node)=newNode(CONST_DEF_TYPE);
    		addNode((yyval.node), (yyvsp[0].node));
    		insertVarList((yyvsp[0].node)->idname, Const, 0);
    		printf("Warning: Const Decl without initial value.\n");
    	}
#line 1668 "y.tab.c"
    break;

  case 16:
#line 111 "grammar.y"
                {
			(yyval.node)=newNode(CONST_ARRAY_DIM_TYPE);
			addNode((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
			(yyval.node)->dim = (yyvsp[-3].node)->dim;
			(yyval.node)->dim ++;
			(yyval.node)->dim1 = (yyvsp[-3].node)->dim1;
			if((yyvsp[-1].node)->isNum == 1)
                        {
                          	(yyval.node)->dim2 = (yyvsp[-1].node)->idvalue;
                        }
                        else if((yyvsp[-1].node)->isNum == 0)
                        {
                          	int valid;
                          	int r = findConstValue((yyvsp[-1].node), &valid);
                          	if(valid)
                          	{
                          		(yyval.node)->dim2 = r;
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
#line 1703 "y.tab.c"
    break;

  case 17:
#line 142 "grammar.y"
                {
  			(yyval.node)=newNode(CONST_ARRAY_DIM_TYPE);
  			addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
  			(yyval.node)->dim = 1;
  			if((yyvsp[-1].node)->isNum == 1)
  			{
  				(yyval.node)->dim1 = (yyvsp[-1].node)->idvalue;
  			}
  			else if((yyvsp[-1].node)->isNum == 0)
  			{
  				int valid;
  				int r = findConstValue((yyvsp[-1].node), &valid);
  				if(valid)
  				{
  					(yyval.node)->dim1 = r;
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
#line 1736 "y.tab.c"
    break;

  case 18:
#line 173 "grammar.y"
        {
		(yyval.node)=newNode(ARRAY_DIM_TYPE);
		addNode((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

		(yyval.node)->dim = (yyvsp[-3].node)->dim + 1;
		(yyval.node)->dim1 = (yyvsp[-3].node)->dim1;
		(yyval.node)->dim1type = (yyvsp[-3].node)->dim1type;
		if((yyvsp[-1].node)->isNum == 0)
                {
                  	Registers r = transferToReg((yyvsp[-1].node)->idname);
                  	(yyval.node)->dim2 = r;
                  	(yyval.node)->dim2type = 2;
                }
                else if((yyvsp[-1].node)->isNum == 1)
                {
                  	(yyval.node)->dim2 = (yyvsp[-1].node)->idvalue;
                  	(yyval.node)->dim2type = 1;
                }
                else if((yyvsp[-1].node)->isNum == 2)
                {
                  	(yyval.node)->dim2 = (yyvsp[-1].node)->idvalue;
                  	(yyval.node)->dim2type = 2;
                }
	}
#line 1765 "y.tab.c"
    break;

  case 19:
#line 198 "grammar.y"
        {
  		(yyval.node)=newNode(ARRAY_DIM_TYPE);
  		addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

  		if((yyvsp[-1].node)->isNum == 0)
  		{
  			Registers r = transferToReg((yyvsp[-1].node)->idname);
  			(yyval.node)->dim = 1;
  			(yyval.node)->dim1 = r;
  			(yyval.node)->dim1type = 2;
  		}
  		else if((yyvsp[-1].node)->isNum == 1)
  		{
  			(yyval.node)->dim = 1;
  			(yyval.node)->dim1 = (yyvsp[-1].node)->idvalue;
  			(yyval.node)->dim1type = 1;
  		}
  		else if((yyvsp[-1].node)->isNum == 2)
  		{
  			(yyval.node)->dim = 1;
  			(yyval.node)->dim1 = (yyvsp[-1].node)->idvalue;
  			(yyval.node)->dim1type = 2;
  		}
  	}
#line 1794 "y.tab.c"
    break;

  case 20:
#line 225 "grammar.y"
                        {(yyval.node)=newNode(CONST_INIT_VAL_TYPE); addNode((yyval.node), (yyvsp[0].node)); (yyval.node)->idvalue = (yyvsp[0].node)->idvalue;
			(yyval.node)->isNum = (yyvsp[0].node)->isNum; if(!((yyvsp[0].node)->isNum))printf("ERROR in const init val. Not done\n"); }
#line 1801 "y.tab.c"
    break;

  case 21:
#line 229 "grammar.y"
                                       {(yyval.node)=newNode(CONST_ARRAY_INIT_VAL_TYPE); addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1807 "y.tab.c"
    break;

  case 22:
#line 230 "grammar.y"
                                                    {(yyval.node)=newNode(CONST_ARRAY_INIT_VAL_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1813 "y.tab.c"
    break;

  case 23:
#line 233 "grammar.y"
                                                         {(yyval.node)=newNode(CONST_ARRAY_CONTENT_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1819 "y.tab.c"
    break;

  case 24:
#line 234 "grammar.y"
                 {(yyval.node)=newNode(CONST_ARRAY_CONTENT_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 1825 "y.tab.c"
    break;

  case 25:
#line 237 "grammar.y"
                                   {(yyval.node)=newNode(VAR_DECL_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1831 "y.tab.c"
    break;

  case 26:
#line 240 "grammar.y"
                                     {(yyval.node)=newNode(VAR_DEF_LIST_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1837 "y.tab.c"
    break;

  case 27:
#line 241 "grammar.y"
           {(yyval.node)=newNode(VAR_DEF_LIST_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 1843 "y.tab.c"
    break;

  case 28:
#line 244 "grammar.y"
                {(yyval.node)=newNode(VAR_DEF_TYPE);
		addNode((yyval.node), (yyvsp[0].node));
		if(isInFunc)
			insertVarList((yyvsp[0].node)->idname, Normal);
		else
			insertVarList((yyvsp[0].node)->idname, GlobalNormal);
		}
#line 1855 "y.tab.c"
    break;

  case 29:
#line 251 "grammar.y"
                                                {(yyval.node)=newNode(VAR_DEF_TYPE);
         	addNode((yyval.node), (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
         	if(isInFunc)
         		genAssign((yyvsp[-3].node), (yyvsp[0].node));
         	else
         	{
         		insertVarList(tmpIdname, GlobalNormal, (yyvsp[0].node)->idvalue);
         	}
         	}
#line 1869 "y.tab.c"
    break;

  case 30:
#line 261 "grammar.y"
        {
        	(yyval.node)=newNode(VAR_DEF_TYPE);
        	addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node));
        	if(isInFunc)
        		insertVarList((yyvsp[-1].node)->idname, Array, NULL, (yyvsp[0].node)->dim, (yyvsp[0].node)->dim1, (yyvsp[0].node)->dim2);
        	else
                	insertVarList((yyvsp[-1].node)->idname, GlobalArray, NULL, (yyvsp[0].node)->dim, (yyvsp[0].node)->dim1, (yyvsp[0].node)->dim2);
        }
#line 1882 "y.tab.c"
    break;

  case 31:
#line 269 "grammar.y"
                                                   {(yyval.node)=newNode(VAR_DEF_TYPE); addNode((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
        						printf("Cannot generate ASM code for now...\n");}
#line 1889 "y.tab.c"
    break;

  case 32:
#line 274 "grammar.y"
        {
		if(isInFunc)
			insertVarList(tmpIdname, Normal);
		(yyval.node) = newNode(EXTRA_TYPE);
		strcpy((yyval.node)->idname, tmpIdname);
	}
#line 1900 "y.tab.c"
    break;

  case 33:
#line 281 "grammar.y"
                                  {(yyval.node)=newNode(ARRAY_INIT_VAL_TYPE); addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1906 "y.tab.c"
    break;

  case 34:
#line 282 "grammar.y"
                                               {(yyval.node)=newNode(ARRAY_INIT_VAL_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1912 "y.tab.c"
    break;

  case 35:
#line 285 "grammar.y"
                                               {(yyval.node)=newNode(ARRAY_CONTENT_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1918 "y.tab.c"
    break;

  case 36:
#line 286 "grammar.y"
                 { (yyval.node)=newNode(ARRAY_CONTENT_TYPE); addNode((yyval.node), (yyvsp[0].node));}
#line 1924 "y.tab.c"
    break;

  case 37:
#line 291 "grammar.y"
                {
		(yyval.node)=newNode(FUNC_DEF_TYPE);
		addNode((yyval.node), (yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node));
		addNode((yyval.node), (yyvsp[0].node));
		popVarList();
		}
#line 1935 "y.tab.c"
    break;

  case 38:
#line 298 "grammar.y"
                {
        	(yyval.node)=newNode(FUNC_DEF_TYPE);
        	addNode((yyval.node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
        	popVarList();
        	}
#line 1945 "y.tab.c"
    break;

  case 39:
#line 304 "grammar.y"
                {
        	(yyval.node)=newNode(FUNC_DEF_TYPE);
        	addNode((yyval.node), (yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node));
        	addNode((yyval.node), (yyvsp[0].node));
        	popVarList();
        	}
#line 1956 "y.tab.c"
    break;

  case 40:
#line 311 "grammar.y"
                {
        	(yyval.node)=newNode(FUNC_DEF_TYPE);
        	addNode((yyval.node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
        	popVarList();
        	}
#line 1966 "y.tab.c"
    break;

  case 41:
#line 319 "grammar.y"
        {
		processParams(tmpFuncName);
	}
#line 1974 "y.tab.c"
    break;

  case 42:
#line 324 "grammar.y"
        {
		genFuncHead(tmpIdname);
		insertFuncList(tmpIdname);
		(yyval.node) = newNode(EXTRA_TYPE);
		strcpy((yyval.node)->idname, tmpIdname);
		strcpy(tmpFuncName, tmpIdname);
		isInFunc = 1;
	}
#line 1987 "y.tab.c"
    break;

  case 43:
#line 333 "grammar.y"
                                           {(yyval.node)=newNode(FUNC_F_PARAMS_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1993 "y.tab.c"
    break;

  case 44:
#line 334 "grammar.y"
                         {(yyval.node)=newNode(FUNC_F_PARAMS_TYPE); addNode((yyval.node), (yyvsp[0].node));}
#line 1999 "y.tab.c"
    break;

  case 45:
#line 339 "grammar.y"
                {
		 	(yyval.node)=newNode(FUNC_F_PARAM_TYPE);
		 	addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node));
		 	addParam(tmpFuncName, (yyvsp[0].node)->idname, Normal);
		}
#line 2009 "y.tab.c"
    break;

  case 46:
#line 345 "grammar.y"
                {
           		printf("Still working on it."); exit(13);
           		(yyval.node)=newNode(FUNC_F_PARAM_TYPE);
           		addNode((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
           		addParam(tmpFuncName, (yyvsp[-2].node)->idname, Array, 1);
           	}
#line 2020 "y.tab.c"
    break;

  case 47:
#line 352 "grammar.y"
                {
           		printf("Still working on it."); exit(13);
           		(yyval.node)=newNode(FUNC_F_PARAM_TYPE);
           		addNode((yyval.node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
           		addParam(tmpFuncName, (yyvsp[-3].node)->idname, Array, 2, (yyvsp[0].node)->dim1);
           	}
#line 2031 "y.tab.c"
    break;

  case 48:
#line 360 "grammar.y"
                                      {(yyval.node)=newNode(BLOCK_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2037 "y.tab.c"
    break;

  case 49:
#line 361 "grammar.y"
                             {(yyval.node)=newNode(BLOCK_TYPE); addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2043 "y.tab.c"
    break;

  case 50:
#line 364 "grammar.y"
                                  { (yyval.node)=newNode(BLOCK_ITEMS_TYPE); addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2049 "y.tab.c"
    break;

  case 51:
#line 365 "grammar.y"
              {(yyval.node)=newNode(BLOCK_ITEMS_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 2055 "y.tab.c"
    break;

  case 52:
#line 368 "grammar.y"
                 {(yyval.node)=newNode(BLOCK_ITEM_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 2061 "y.tab.c"
    break;

  case 53:
#line 369 "grammar.y"
                 {(yyval.node)=newNode(BLOCK_ITEM_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 2067 "y.tab.c"
    break;

  case 54:
#line 372 "grammar.y"
           {
		(yyval.node) = newNode(EXTRA_TYPE);
		(yyval.node)->idvalue = getNextI();
	}
#line 2076 "y.tab.c"
    break;

  case 55:
#line 378 "grammar.y"
            { enterStmt(); }
#line 2082 "y.tab.c"
    break;

  case 56:
#line 381 "grammar.y"
           {
		(yyval.node) = newNode(EXTRA_TYPE);
		(yyval.node)->idvalue = getNextI();
		exitStmt();
	}
#line 2092 "y.tab.c"
    break;

  case 57:
#line 388 "grammar.y"
       {
		(yyval.node) = newNode(EXTRA_TYPE);
		out((yyval.node));
		(yyval.node)->idvalue = getNextI();
	}
#line 2102 "y.tab.c"
    break;

  case 58:
#line 396 "grammar.y"
        {
		(yyval.node)=newNode(STMT_TYPE);
		addNode((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
		genAssign((yyvsp[-3].node), (yyvsp[-1].node));
	}
#line 2112 "y.tab.c"
    break;

  case 59:
#line 401 "grammar.y"
                     {(yyval.node)=newNode(STMT_TYPE); addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2118 "y.tab.c"
    break;

  case 60:
#line 402 "grammar.y"
                 {(yyval.node)=newNode(STMT_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 2124 "y.tab.c"
    break;

  case 61:
#line 403 "grammar.y"
             {(yyval.node)=newNode(STMT_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 2130 "y.tab.c"
    break;

  case 62:
#line 405 "grammar.y"
        {
     		(yyval.node)=newNode(STMT_TYPE);
     		addNode((yyval.node), (yyvsp[-8].node), (yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-2].node));
     		backpatch((yyvsp[-6].node), (yyvsp[-4].node)->idvalue, (yyvsp[0].node)->idvalue);
     	}
#line 2140 "y.tab.c"
    break;

  case 63:
#line 412 "grammar.y"
        {
     		(yyval.node)=newNode(STMT_TYPE);
     		addNode((yyval.node), (yyvsp[-15].node), (yyvsp[-14].node), (yyvsp[-13].node), (yyvsp[-12].node), (yyvsp[-9].node));
     		addNode((yyval.node), (yyvsp[-5].node), (yyvsp[-2].node));
     		backpatch((yyvsp[-13].node), (yyvsp[-11].node)->idvalue, (yyvsp[-4].node)->idvalue);
     		backpatch((yyvsp[-6].node), (yyvsp[0].node)->idvalue);
     	}
#line 2152 "y.tab.c"
    break;

  case 64:
#line 420 "grammar.y"
        {
     		(yyval.node)=newNode(STMT_TYPE);
     		addNode((yyval.node), (yyvsp[-9].node), (yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-2].node));
     		backpatch((yyvsp[-6].node), (yyvsp[-4].node)->idvalue, (yyvsp[0].node)->idvalue);
     		backpatch((yyvsp[0].node), (yyvsp[-8].node)->idvalue);
     		// 只支持一层里有break和continue，否则会报错
     		// 应该用栈存
     		// 不支持break的循环中定义局部变量，否则会出错
     		// break
     		for(int i = 0; i < breakNum; i++)
     		{
     			modifyAsm(breakPos[i], (yyvsp[0].node)->idvalue, 1);
     		}
     		breakNum = 0;
     		// continue
     		for(int i = 0; i < continueNum; i++)
     		{
     			modifyAsm(continuePos[i], (yyvsp[-1].node)->idvalue);
     		}
     		continueNum = 0;
     	}
#line 2178 "y.tab.c"
    break;

  case 65:
#line 442 "grammar.y"
        {
     		(yyval.node)=newNode(STMT_TYPE);
     		addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node));
     		int k = genJmp();
     		breakPos[breakNum ++] = k;
     	}
#line 2189 "y.tab.c"
    break;

  case 66:
#line 448 "grammar.y"
                          {
     	(yyval.node)=newNode(STMT_TYPE);
     	addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node));
     	int k = genJmp();
     	continuePos[continueNum ++] = k;
     	}
#line 2200 "y.tab.c"
    break;

  case 67:
#line 455 "grammar.y"
        {
     		(yyval.node)=newNode(STMT_TYPE);
     		addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node));
     		genReturn();
     	}
#line 2210 "y.tab.c"
    break;

  case 68:
#line 461 "grammar.y"
        {
     		(yyval.node)=newNode(STMT_TYPE);
     		addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
     		genReturn((yyvsp[-1].node));
     	}
#line 2220 "y.tab.c"
    break;

  case 69:
#line 467 "grammar.y"
        {
     		genScanf((yyvsp[-2].node));
     	}
#line 2228 "y.tab.c"
    break;

  case 70:
#line 471 "grammar.y"
          {
          	genPrintf((yyvsp[-2].node));
          }
#line 2236 "y.tab.c"
    break;

  case 71:
#line 476 "grammar.y"
             {
		(yyval.node)=newNode(EXP_TYPE);
		addNode((yyval.node), (yyvsp[0].node));
		(yyval.node)->idvalue = (yyvsp[0].node)->idvalue;
		strcpy((yyval.node)->idname, (yyvsp[0].node)->idname);
		(yyval.node)->isNum = (yyvsp[0].node)->isNum;
	}
#line 2248 "y.tab.c"
    break;

  case 72:
#line 483 "grammar.y"
              {(yyval.node)=newNode(EXP_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 2254 "y.tab.c"
    break;

  case 73:
#line 487 "grammar.y"
        {
		(yyval.node)=newNode(COND_TYPE);
		addNode((yyval.node), (yyvsp[0].node));
		(yyval.node)->isNum = (yyvsp[0].node)->isNum;
		cpylist((yyval.node), (yyvsp[0].node));
	}
#line 2265 "y.tab.c"
    break;

  case 74:
#line 497 "grammar.y"
        {
		(yyval.node)=newNode(L_VAL_TYPE);
		addNode((yyval.node), (yyvsp[0].node));
		(yyval.node)->isNum = 0;
		strcpy((yyval.node)->idname, (yyvsp[0].node)->idname);
	}
#line 2276 "y.tab.c"
    break;

  case 75:
#line 504 "grammar.y"
        {
     		(yyval.node)=newNode(L_VAL_TYPE);
     		addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node));

     		(yyval.node)->isNum = 3; // Array
     		strcpy((yyval.node)->idname, (yyvsp[-1].node)->idname);
     		int type;
     		(yyval.node)->offset = calcOffsetAndFreeReg((yyvsp[-1].node), (yyvsp[0].node), &type);
     		if(type == 1)
     		{
     			Registers r = transferToReg((yyval.node)->offset);
     			(yyval.node)->offset = r;
     		}
     	}
#line 2295 "y.tab.c"
    break;

  case 76:
#line 523 "grammar.y"
        {
		(yyval.node)=newNode(PRIMARY_EXP_TYPE);
		addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
		// TODO
	}
#line 2305 "y.tab.c"
    break;

  case 77:
#line 528 "grammar.y"
                  {
           		(yyval.node)=newNode(PRIMARY_EXP_TYPE);
           		addNode((yyval.node), (yyvsp[0].node));

			if((yyvsp[0].node)->isNum == 0)
			{
				(yyval.node)->isNum = 0;
                                strcpy((yyval.node)->idname, (yyvsp[0].node)->idname);
			}
			else if((yyvsp[0].node)->isNum == 3)
			{
				(yyval.node)->isNum = 2;
				(yyval.node)->idvalue = arrayTransferToRegAndFree((yyvsp[0].node)->idname, (yyvsp[0].node)->offset);
			}
		}
#line 2325 "y.tab.c"
    break;

  case 78:
#line 543 "grammar.y"
                    {(yyval.node)=newNode(PRIMARY_EXP_TYPE);
           	addNode((yyval.node), (yyvsp[0].node));
           	(yyval.node)->idvalue = (yyvsp[0].node)->idvalue;
           	(yyval.node)->isNum = 1;}
#line 2334 "y.tab.c"
    break;

  case 79:
#line 549 "grammar.y"
                {(yyval.node)=newNode(NUMBER_NON_TERM_TYPE); addNode((yyval.node), (yyvsp[0].node));
			(yyval.node)->idvalue = (yyvsp[0].node)->value; (yyval.node)->isNum = 1;}
#line 2341 "y.tab.c"
    break;

  case 80:
#line 555 "grammar.y"
                {
		(yyval.node)=newNode(UNARY_EXP_TYPE);
		addNode((yyval.node), (yyvsp[0].node));
		if((yyvsp[0].node)->isNum == 1 || (yyvsp[0].node)->isNum == 2){
			(yyval.node)->idvalue = (yyvsp[0].node)->idvalue;
		}
		else if((yyvsp[0].node)->isNum == 0)
		{
			strcpy((yyval.node)->idname, (yyvsp[0].node)->idname);
		}
		(yyval.node)->isNum = (yyvsp[0].node)->isNum;
		(yyval.node)->isneg = (yyvsp[0].node)->isneg;
		}
#line 2359 "y.tab.c"
    break;

  case 81:
#line 569 "grammar.y"
         {
         	(yyval.node)=newNode(UNARY_EXP_TYPE);
         	addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

         	call((yyvsp[-2].node)->idname);
         	(yyval.node)->isNum = 2; (yyval.node)->idvalue = EAX;
         }
#line 2371 "y.tab.c"
    break;

  case 82:
#line 577 "grammar.y"
         {
         	(yyval.node)=newNode(UNARY_EXP_TYPE);
         	addNode((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

         	pushParams();
         	call((yyvsp[-3].node)->idname);
         	// popParams($1->idname);
         	(yyval.node)->isNum = 2; (yyval.node)->idvalue = EAX;
         }
#line 2385 "y.tab.c"
    break;

  case 83:
#line 587 "grammar.y"
         {
         	(yyval.node)=newNode(UNARY_EXP_TYPE);
         	addNode((yyval.node), (yyvsp[-1].node), (yyvsp[0].node));
         	(yyval.node)->isNum = (yyvsp[0].node)->isNum;
         	(yyval.node)->idvalue = (yyvsp[0].node)->idvalue;
         	strcpy((yyval.node)->idname, (yyvsp[0].node)->idname);
         	(yyval.node)->isneg += (yyvsp[-1].node)->isneg;
         }
#line 2398 "y.tab.c"
    break;

  case 84:
#line 598 "grammar.y"
              {(yyval.node)=newNode(UNARY_OP_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 2404 "y.tab.c"
    break;

  case 85:
#line 599 "grammar.y"
              {(yyval.node)=newNode(UNARY_OP_TYPE); addNode((yyval.node), (yyvsp[0].node)); }
#line 2410 "y.tab.c"
    break;

  case 86:
#line 601 "grammar.y"
        {
        	(yyval.node)=newNode(UNARY_OP_TYPE);
        	addNode((yyval.node), (yyvsp[0].node));
        	(yyval.node)->isneg ++;
        }
#line 2420 "y.tab.c"
    break;

  case 87:
#line 608 "grammar.y"
                                    {(yyval.node)=newNode(FUNC_R_PARAMS_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2426 "y.tab.c"
    break;

  case 88:
#line 610 "grammar.y"
            {
            	(yyval.node)=newNode(FUNC_R_PARAMS_TYPE);
            	addNode((yyval.node), (yyvsp[0].node));
            	addToWaitPush((yyvsp[0].node));
            }
#line 2436 "y.tab.c"
    break;

  case 89:
#line 618 "grammar.y"
                {
			(yyval.node)=newNode(MULTI_EXP_TYPE);
			addNode((yyval.node), (yyvsp[0].node));
			(yyval.node)->isNum = (yyvsp[0].node)->isNum;
			if((yyval.node)->isNum == 1){(yyval.node)->idvalue = (yyvsp[0].node)->idvalue;}
			else if((yyval.node)->isNum == 0)
			{
				strcpy((yyval.node)->idname, (yyvsp[0].node)->idname);
			}
			else if((yyval.node)->isNum == 2)
			{
				(yyval.node)->idvalue = (yyvsp[0].node)->idvalue;
			}

			(yyval.node)->isneg = (yyvsp[0].node)->isneg;
		}
#line 2457 "y.tab.c"
    break;

  case 90:
#line 635 "grammar.y"
        {
       		(yyval.node)=newNode(MULTI_EXP_TYPE);
       		addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
       		(yyval.node)->idvalue = genMulti((yyvsp[-2].node), (yyvsp[0].node));
       		(yyval.node)->isNum = 2;
       	}
#line 2468 "y.tab.c"
    break;

  case 91:
#line 641 "grammar.y"
                                {(yyval.node)=newNode(MULTI_EXP_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2474 "y.tab.c"
    break;

  case 92:
#line 642 "grammar.y"
                             {(yyval.node)=newNode(MULTI_EXP_TYPE); addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2480 "y.tab.c"
    break;

  case 93:
#line 647 "grammar.y"
        {
		(yyval.node)=newNode(ADD_EXP_TYPE);
		addNode((yyval.node), (yyvsp[0].node));
		(yyval.node)->isNum = (yyvsp[0].node)->isNum;
		if((yyval.node)->isNum == 1 || (yyval.node)->isNum == 2)(yyval.node)->idvalue = (yyvsp[0].node)->idvalue;
		else if((yyval.node)->isNum == 0)
		{
			strcpy((yyval.node)->idname, (yyvsp[0].node)->idname);
		}

		(yyval.node)->isneg = (yyvsp[0].node)->isneg;
	}
#line 2497 "y.tab.c"
    break;

  case 94:
#line 660 "grammar.y"
        {
       		(yyval.node)=newNode(ADD_EXP_TYPE);
       		addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
       		(yyval.node)->idvalue = genAdd((yyvsp[-2].node), (yyvsp[0].node));
       		(yyval.node)->isNum = 2;
       	}
#line 2508 "y.tab.c"
    break;

  case 95:
#line 667 "grammar.y"
        {
       		(yyval.node)=newNode(ADD_EXP_TYPE);
       		addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
       		(yyval.node)->idvalue = genMinus((yyvsp[-2].node), (yyvsp[0].node));
       		(yyval.node)->isNum = 2;
       	}
#line 2519 "y.tab.c"
    break;

  case 96:
#line 675 "grammar.y"
                {
			(yyval.node)=newNode(REL_EXP_TYPE);
			addNode((yyval.node), (yyvsp[0].node));
			(yyval.node)->isNum = (yyvsp[0].node)->isNum;
			(yyval.node)->idvalue = (yyvsp[0].node)->idvalue;
			strcpy((yyval.node)->idname, (yyvsp[0].node)->idname);
			(yyval.node)->isneg = (yyvsp[0].node)->isneg;
		}
#line 2532 "y.tab.c"
    break;

  case 97:
#line 684 "grammar.y"
                {
       			(yyval.node)=newNode(REL_EXP_TYPE);
       			addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
       			(yyval.node)->isNum = 4;
       			testCompare((yyvsp[-2].node), (yyvsp[0].node));
       			genTrueFalseCompare((yyval.node), 'l');
       		}
#line 2544 "y.tab.c"
    break;

  case 98:
#line 692 "grammar.y"
                {
       			(yyval.node)=newNode(REL_EXP_TYPE);
       			addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
       			(yyval.node)->isNum = 4;
                        testCompare((yyvsp[-2].node), (yyvsp[0].node));
                        genTrueFalseCompare((yyval.node), 'g');
       		}
#line 2556 "y.tab.c"
    break;

  case 99:
#line 700 "grammar.y"
                {
       			(yyval.node)=newNode(REL_EXP_TYPE);
       			addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
       			(yyval.node)->isNum = 4;
                        testCompare((yyvsp[-2].node), (yyvsp[0].node));
                        genTrueFalseCompare((yyval.node), 'l', 1);
       		}
#line 2568 "y.tab.c"
    break;

  case 100:
#line 708 "grammar.y"
                {
       			(yyval.node)=newNode(REL_EXP_TYPE);
       			addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
       			(yyval.node)->isNum = 4;
                        testCompare((yyvsp[-2].node), (yyvsp[0].node));
                        genTrueFalseCompare((yyval.node), 'g', 1);
       		}
#line 2580 "y.tab.c"
    break;

  case 101:
#line 719 "grammar.y"
        {
		(yyval.node)=newNode(EQUAL_EXP_TYPE);
		addNode((yyval.node), (yyvsp[0].node));
		if((yyvsp[0].node)->isNum != 4)
		{
			(yyval.node)->isNum = (yyvsp[0].node)->isNum;
			(yyval.node)->idvalue = (yyvsp[0].node)->idvalue;
			strcpy((yyval.node)->idname, (yyvsp[0].node)->idname);
                	testZero((yyvsp[0].node));
                	genTrueFalseZero((yyval.node), (yyvsp[0].node)->isneg);
                	(yyval.node)->isNum = 4;
                }
                else
                {
                	(yyval.node)->isNum = 4;
                	cpylist((yyval.node), (yyvsp[0].node));
                }
	}
#line 2603 "y.tab.c"
    break;

  case 102:
#line 738 "grammar.y"
        {
      		(yyval.node)=newNode(EQUAL_EXP_TYPE);
      		addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      		(yyval.node)->isNum = 4;
                testCompare((yyvsp[-2].node), (yyvsp[0].node));
                genTrueFalseCompare((yyval.node), 'e');
      	}
#line 2615 "y.tab.c"
    break;

  case 103:
#line 746 "grammar.y"
        {
      		(yyval.node)=newNode(EQUAL_EXP_TYPE);
      		addNode((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      		(yyval.node)->isNum = 4;
      		testCompare((yyvsp[-2].node), (yyvsp[0].node));
      		genTrueFalseCompare((yyval.node), 'n', 1);
      	}
#line 2627 "y.tab.c"
    break;

  case 104:
#line 756 "grammar.y"
        {
		(yyval.node)=newNode(L_AND_AND_EXP_TYPE);
		addNode((yyval.node), (yyvsp[0].node));
		(yyval.node)->isNum = (yyvsp[0].node)->isNum;
		cpylist((yyval.node), (yyvsp[0].node));
	}
#line 2638 "y.tab.c"
    break;

  case 105:
#line 763 "grammar.y"
        {
        	(yyval.node)=newNode(L_AND_AND_EXP_TYPE);
        	addNode((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));

        	(yyval.node)->isNum = 4;
        	backpatch((yyvsp[-3].node), (yyvsp[-1].node)->idvalue);
        	cpylist((yyval.node), (yyvsp[0].node));
        	(yyval.node)->falselen = mergelist((yyval.node)->falselist, (yyval.node)->falselen, (yyvsp[-3].node)->falselist, (yyvsp[-3].node)->falselen);
        }
#line 2652 "y.tab.c"
    break;

  case 106:
#line 775 "grammar.y"
        {
		(yyval.node)=newNode(L_OR_OR_EXP_TYPE);
		addNode((yyval.node), (yyvsp[0].node));
		(yyval.node)->isNum = (yyvsp[0].node)->isNum;
		cpylist((yyval.node), (yyvsp[0].node));
	}
#line 2663 "y.tab.c"
    break;

  case 107:
#line 782 "grammar.y"
        {
       		(yyval.node)=newNode(L_OR_OR_EXP_TYPE);
       		addNode((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));

       		(yyval.node)->isNum = 4;
       		backpatch((yyvsp[-3].node), -1, (yyvsp[-1].node)->idvalue);
       		cpylist((yyval.node), (yyvsp[0].node));
       		(yyval.node)->truelen = mergelist((yyval.node)->truelist, (yyval.node)->truelen, (yyvsp[-3].node)->truelist, (yyvsp[-3].node)->truelen);
       	}
#line 2677 "y.tab.c"
    break;

  case 108:
#line 793 "grammar.y"
                  {
			(yyval.node)=newNode(CONST_EXP_TYPE);
			addNode((yyval.node), (yyvsp[0].node));
			(yyval.node)->idvalue = (yyvsp[0].node)->idvalue;
			strcpy((yyval.node)->idname, (yyvsp[0].node)->idname);
			(yyval.node)->isNum = (yyvsp[0].node)->isNum;
		}
#line 2689 "y.tab.c"
    break;

  case 109:
#line 802 "grammar.y"
                  {fprintf(stderr, "Undefined symbol (%s)", (yyvsp[0].node)->name); exit(9);}
#line 2695 "y.tab.c"
    break;


#line 2699 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 804 "grammar.y"


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
