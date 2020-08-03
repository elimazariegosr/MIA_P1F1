/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "syntactic.yy" /* yacc.c:339  */

#include "scanner.h"
#include "ast_node.h"
#include "qdebug.h"
#include <iostream>
extern char *yytext;
extern AST_Node * root; // Raiz del arbol

int yyerror(const char* mens)
{

    std::cout << mens <<" "<<yytext<< std::endl;
    return 0;
}



#line 84 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    TK_MKDISK = 258,
    TK_RMDISK = 259,
    TK_FDISK = 260,
    TK_MOUNT = 261,
    TK_UNMOUNT = 262,
    TK_REP = 263,
    TK_EXEC = 264,
    TK_MKFS = 265,
    TK_LOGIN = 266,
    TK_LOGOUT = 267,
    TK_MKGRP = 268,
    TK_RMGRP = 269,
    TK_MKUSR = 270,
    TK_RMUSR = 271,
    TK_CHMOD = 272,
    TK_MKFILE = 273,
    TK_CAT = 274,
    TK_REM = 275,
    TK_EDIT = 276,
    TK_REN = 277,
    TK_MKDIR = 278,
    TK_CP = 279,
    TK_MV = 280,
    TK_FIND = 281,
    TK_CHOWN = 282,
    TK_CHGRP = 283,
    TK_PAUSE = 284,
    TK_SIZE = 285,
    TK_FIT = 286,
    TK_UNIT = 287,
    TK_PATH = 288,
    TK_TYPE = 289,
    TK_DELETE = 290,
    TK_NAME = 291,
    TK_ADD = 292,
    TK_ID = 293,
    TK_USR = 294,
    TK_PWD = 295,
    TK_GRP = 296,
    TK_UGO = 297,
    TK_R = 298,
    TK_P = 299,
    TK_CONT = 300,
    TK_FILE = 301,
    TK_DEST = 302,
    TK_EQUALS = 303,
    TK_IDENT = 304,
    TK_RUTA = 305,
    TK_CADENA = 306,
    TK_NUMBER = 307,
    TK_PARM_RUTA = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "syntactic.yy" /* yacc.c:355  */

char TEXT [256];
class AST_Node *Nodo_tmp;

#line 183 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 214 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  167
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   216,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   245,
     247,   248,   251,   252,   253,   254,   257,   263,   265,   266,
     268,   269,   270,   271,   272,   273,   274,   275,   278,   280,
     281,   284,   285,   289,   295,   297,   298,   301,   302,   303,
     304,   307,   315,   318,   319,   322,   323,   326,   329,   330,
     333,   334,   335,   338,   341,   347,   353,   356,   357,   360,
     361,   362,   365,   371,   373,   374,   376,   377,   378,   382,
     384,   385,   387,   388,   389,   390,   394,   400,   408,   410,
     411,   414,   415,   418,   420,   421,   424,   425,   429,   431,
     432,   435,   436,   441,   443,   444,   447,   448,   452,   454,
     455,   458,   459,   463,   465,   466,   469,   470,   474,   476,
     477,   480,   481,   482,   486,   488,   489,   492,   493,   498,
     500,   501,   502,   503,   504,   506,   507,   509,   510,   512,
     513,   515,   516,   518,   519,   521,   523,   525,   527,   528,
     529,   531,   533,   535,   537
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MKDISK", "TK_RMDISK", "TK_FDISK",
  "TK_MOUNT", "TK_UNMOUNT", "TK_REP", "TK_EXEC", "TK_MKFS", "TK_LOGIN",
  "TK_LOGOUT", "TK_MKGRP", "TK_RMGRP", "TK_MKUSR", "TK_RMUSR", "TK_CHMOD",
  "TK_MKFILE", "TK_CAT", "TK_REM", "TK_EDIT", "TK_REN", "TK_MKDIR",
  "TK_CP", "TK_MV", "TK_FIND", "TK_CHOWN", "TK_CHGRP", "TK_PAUSE",
  "TK_SIZE", "TK_FIT", "TK_UNIT", "TK_PATH", "TK_TYPE", "TK_DELETE",
  "TK_NAME", "TK_ADD", "TK_ID", "TK_USR", "TK_PWD", "TK_GRP", "TK_UGO",
  "TK_R", "TK_P", "TK_CONT", "TK_FILE", "TK_DEST", "TK_EQUALS", "TK_IDENT",
  "TK_RUTA", "TK_CADENA", "TK_NUMBER", "TK_PARM_RUTA", "$accept", "INIT",
  "MKDISK", "MKDISK_LIST", "MKDISK_LIST_CONT", "RMDISK", "FDISK",
  "FDISK_LIST", "FDISK_LIST_CONT", "MOUNT", "MOUNT_LIST",
  "MOUNT_LIST_CONT", "UNMOUNT", "REP", "REP_LIST", "REP_LIST_CONT", "EXEC",
  "MKFS", "MKFS_LIST", "MKFS_LIST_CONT", "LOGIN", "LOGIN_LIST",
  "LOGIN_LIST_CONT", "LOGOUT", "MKGRP", "RMGRP", "MKUSR", "MKUSR_LIST",
  "MKUSR_LIST_CONT", "RMUSR", "CHMOD", "CHMOD_LIST", "CHMOD_LIST_CONT",
  "MKFILE", "MKFILE_LIST", "MKFILE_LIST_CONT", "CAT", "REM", "EDIT",
  "EDIT_LIST", "EDIT_LIST_CONT", "REN", "REN_LIST", "REN_LIST_CONT",
  "MKDIR", "MKDIR_LIST", "MKDIR_LIST_CONT", "CP", "CP_LIST",
  "CP_LIST_CONT", "MV", "MV_LIST", "MV_LIST_CONT", "FIND", "FIND_LIST",
  "FIND_LIST_CONT", "CHOWN", "CHOWN_LIST", "CHOWN_LIST_CONT", "CHGRP",
  "CHGRP_LIST", "CHGRP_LIST_CONT", "SIZE", "FIT", "UNIT", "PATH", "TYPE",
  "DELETE", "NAME", "ADD", "ID", "USR", "PWD", "GRP", "UGO", "R", "P",
  "CONT", "FILE_", "DEST", "PAUSE", "PARM_RUTA", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -24

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-24)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     182,    35,    -4,    40,    45,    -8,     5,    -4,    26,    49,
     -24,    18,    18,    51,    46,    19,     6,    17,    -4,     0,
      45,     4,    -5,    -5,    45,    16,    43,   -24,    93,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,    52,    69,    70,    71,
      35,   -24,   -24,   -24,   -24,   -24,   -24,    72,    73,    76,
      77,    40,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,    45,   -24,   -24,   -24,    79,   -24,    80,     5,   -24,
     -24,   -24,   -24,   -24,   -24,    26,   -24,   -24,   -24,    81,
      84,    49,   -24,   -24,   -24,   -24,   -24,   -24,    88,    51,
     -24,   -24,   -24,   -24,   -24,    89,   -24,    19,   -24,   -24,
     -24,   -24,   -24,    90,     6,   -24,   -24,   -24,   -24,   -24,
      94,   -24,   -24,     0,   -24,   -24,   -24,    45,   -24,   -24,
     -24,     4,   -24,   -24,   -24,    97,    -5,   -24,   -24,   -24,
      -5,   -24,   -24,   -24,    45,   -24,   -24,   -24,    16,   -24,
     -24,   -24,   -24,    43,   -24,   -24,   -24,   -24,    42,    47,
      50,    63,   -24,    98,   101,    56,    99,   -24,   -24,   104,
      96,   -24,   -24,    60,    61,   -24,    65,   -24,   102,   -24,
      53,   -24,   105,   -24,   -24,   -24,   108,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    19,    17,    18,    21,    22,    20,
      23,    24,    25,    26,    27,    28,     0,     0,     0,     0,
      29,    31,    32,    33,    34,    35,    36,     0,     0,     0,
       0,    37,    39,    40,    44,    41,    42,    43,    45,    46,
      47,    48,    50,    51,    52,     0,    53,     0,    54,    56,
      58,    57,    59,    60,    61,    62,    64,    66,    65,     0,
       0,    67,    69,    72,    70,    71,    74,    75,     0,    76,
      78,    79,    80,    81,    82,     0,   156,    83,    85,    86,
      87,    88,   157,     0,    89,    91,    94,    92,    93,    95,
       0,    96,    97,    98,   100,   101,   102,   103,   105,   106,
     107,   108,   110,   111,   112,     0,   113,   115,   116,   117,
     118,   120,   121,   122,   123,   125,   126,   127,   128,   130,
     131,   133,   132,   134,   136,   137,   138,     1,     0,     0,
       0,     0,    30,     0,     0,     0,     0,    38,    49,     0,
       0,    55,    63,     0,     0,    68,     0,    77,     0,    84,
       0,    90,     0,    99,   104,   109,     0,   114,   119,   124,
     129,   135,   139,   140,   141,   142,   143,   144,   146,   145,
     147,   148,   164,   150,   149,   152,   151,   154,   153,   155,
     159,   160,   158,   161,   162
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -24,   -24,   -24,   -24,    37,   -24,   -24,   -24,    91,   -24,
     -24,    78,   -24,   -24,   -24,    75,   -24,   -24,   -24,    66,
     -24,   -24,    59,   -24,   -24,   -24,   -24,   -24,    55,   -24,
     -24,   -24,    54,   -24,   -24,    41,   -24,   -24,   -24,   -24,
      33,   -24,   -24,    30,   -24,   -24,    27,   -24,   -24,    23,
     -24,   -24,    22,   -24,   -24,    28,   -24,   -24,    15,   -24,
     -24,     7,     9,    12,    24,    -2,     3,   -24,    20,   -24,
      48,    21,    -3,   -23,   -24,   -17,   -15,   -10,   -24,   -16,
     -24,   -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    60,    61,    30,    31,    71,    72,    32,
      81,    82,    33,    34,    88,    89,    35,    36,    95,    96,
      37,   101,   102,    38,    39,    40,    41,   109,   110,    42,
      43,   117,   118,    44,   124,   125,    45,    46,    47,   133,
     134,    48,   137,   138,    49,   141,   142,    50,   146,   147,
      51,   150,   151,    52,   154,   155,    53,   158,   159,    54,
     163,   164,    62,    63,    64,    65,    77,    78,    79,    80,
      92,   104,   105,   113,   120,   121,   128,   129,   131,   149,
      55,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    76,    83,   166,    90,    94,   144,   153,   162,   136,
     112,    97,    73,   119,   127,    74,   132,   135,   139,   143,
     148,   152,   156,   160,    84,   126,    91,    75,    59,    59,
      85,   106,   107,    59,   111,   114,    56,    59,    59,    59,
     140,    69,   145,    85,   157,   123,   161,   165,   122,    59,
     122,   123,    59,    86,    69,    99,    98,   103,    87,   116,
      67,   115,   116,   130,    85,    56,    57,    58,    59,    76,
      56,    57,    58,    59,    67,    68,    69,    70,    59,    83,
      73,    69,    99,    74,   108,    99,    90,    85,    99,   100,
      99,   100,   108,   167,   202,    75,   203,   172,    97,   204,
     168,    84,   220,   221,   222,   208,   112,   209,    91,   213,
     215,   214,   216,   205,   217,   119,   218,   169,   170,   171,
     173,   174,   127,   136,   175,   176,   144,   179,   180,   183,
     111,   135,   184,   126,   153,   139,   186,   188,   190,   143,
     166,   162,   192,    98,   148,   196,   212,   206,   152,   103,
     207,   210,   156,   211,   219,   223,   160,   140,   224,   178,
     185,   182,   177,   181,   187,   191,   193,   194,   195,   197,
     201,   189,   198,   200,   157,     0,     0,     0,     0,   161,
       0,     0,   199,     0,   165,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27
};

static const yytype_int16 yycheck[] =
{
       2,     3,     4,    26,     6,     7,    21,    23,    25,    19,
      13,     8,     3,    15,    16,     3,    18,    19,    20,    21,
      22,    23,    24,    25,     4,    16,     6,     3,    33,    33,
      38,    11,    12,    33,    13,    14,    30,    33,    33,    33,
      20,    36,    47,    38,    24,    45,    25,    26,    44,    33,
      44,    45,    33,     5,    36,    39,     8,     9,    53,    43,
      34,    42,    43,    46,    38,    30,    31,    32,    33,    71,
      30,    31,    32,    33,    34,    35,    36,    37,    33,    81,
      71,    36,    39,    71,    41,    39,    88,    38,    39,    40,
      39,    40,    41,     0,    52,    71,    49,    60,    95,    49,
      48,    81,    49,    50,    51,    49,   109,    51,    88,    49,
      49,    51,    51,    50,    49,   117,    51,    48,    48,    48,
      48,    48,   124,   133,    48,    48,   141,    48,    48,    48,
     109,   133,    48,   124,   150,   137,    48,    48,    48,   141,
     163,   158,    48,    95,   146,    48,    50,    49,   150,   101,
      49,    52,   154,    49,    52,    50,   158,   137,    50,    81,
     101,    95,    71,    88,   109,   124,   133,   137,   141,   146,
     163,   117,   150,   158,   154,    -1,    -1,    -1,    -1,   158,
      -1,    -1,   154,    -1,   163,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    55,    56,
      59,    60,    63,    66,    67,    70,    71,    74,    77,    78,
      79,    80,    83,    84,    87,    90,    91,    92,    95,    98,
     101,   104,   107,   110,   113,   134,    30,    31,    32,    33,
      57,    58,   116,   117,   118,   119,   119,    34,    35,    36,
      37,    61,    62,   116,   117,   118,   119,   120,   121,   122,
     123,    64,    65,   119,   122,    38,   124,    53,    68,    69,
     119,   122,   124,   135,   119,    72,    73,   120,   124,    39,
      40,    75,    76,   124,   125,   126,   122,   122,    41,    81,
      82,   125,   126,   127,   125,    42,    43,    85,    86,   119,
     128,   129,    44,    45,    88,    89,   116,   119,   130,   131,
      46,   132,   119,    93,    94,   119,   131,    96,    97,   119,
     122,    99,   100,   119,   130,    47,   102,   103,   119,   133,
     105,   106,   119,   133,   108,   109,   119,   122,   111,   112,
     119,   125,   129,   114,   115,   125,   127,     0,    48,    48,
      48,    48,    58,    48,    48,    48,    48,    62,    65,    48,
      48,    69,    73,    48,    48,    76,    48,    82,    48,    86,
      48,    89,    48,    94,    97,   100,    48,   103,   106,   109,
     112,   115,    52,    49,    49,    50,    49,    49,    49,    51,
      52,    49,    50,    49,    51,    49,    51,    49,    51,    52,
      49,    50,    51,    50,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      57,    57,    58,    58,    58,    58,    59,    60,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    64,
      64,    65,    65,    66,    67,    68,    68,    69,    69,    69,
      69,    70,    71,    72,    72,    73,    73,    74,    75,    75,
      76,    76,    76,    77,    78,    79,    80,    81,    81,    82,
      82,    82,    83,    84,    85,    85,    86,    86,    86,    87,
      88,    88,    89,    89,    89,    89,    90,    91,    92,    93,
      93,    94,    94,    95,    96,    96,    97,    97,    98,    99,
      99,   100,   100,   101,   102,   102,   103,   103,   104,   105,
     105,   106,   106,   107,   108,   108,   109,   109,   110,   111,
     111,   112,   112,   112,   113,   114,   114,   115,   115,   116,
     117,   118,   119,   120,   121,   122,   122,   123,   124,   125,
     125,   126,   126,   127,   127,   128,   129,   130,   131,   131,
     131,   132,   133,   134,   135
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     2,     2,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     2,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     2,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     3,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 216 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1577 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 217 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1583 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 218 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1589 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 219 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1595 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 220 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1601 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 221 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1607 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 222 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1613 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 223 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1619 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 224 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1625 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 225 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1631 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 226 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1637 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 227 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1643 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 228 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1649 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 229 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1655 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 230 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1661 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 231 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1667 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 232 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1673 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 233 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1679 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 234 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1685 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 235 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1691 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 236 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1697 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 237 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1703 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 238 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1709 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 239 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1715 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 240 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 241 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1727 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 242 "syntactic.yy" /* yacc.c:1646  */
    {root = (yyvsp[0].Nodo_tmp);}
#line 1733 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 245 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 1739 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 247 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1745 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 248 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1751 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 251 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1757 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 252 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1763 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 253 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1769 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 254 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1775 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 257 "syntactic.yy" /* yacc.c:1646  */
    {
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*(yyvsp[0].Nodo_tmp));
    (yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),children);}
#line 1784 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 263 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 1790 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 265 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1796 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 266 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1802 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 268 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1808 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 269 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1814 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 270 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1820 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 271 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1826 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 272 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1832 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 273 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1838 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 274 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1844 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 275 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 278 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 1856 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 280 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1862 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 281 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1868 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 284 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1874 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 285 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1880 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 289 "syntactic.yy" /* yacc.c:1646  */
    {
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*(yyvsp[0].Nodo_tmp));
    (yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),children);
}
#line 1890 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 295 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 1896 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 297 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1902 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 298 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1908 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 301 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1914 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 302 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1920 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 303 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1926 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 304 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1932 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 307 "syntactic.yy" /* yacc.c:1646  */
    {

    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*(yyvsp[0].Nodo_tmp));
    (yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),children);
}
#line 1943 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 315 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 1949 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 318 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1955 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 319 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1961 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 322 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1967 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 323 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1973 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 326 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 1979 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 329 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1985 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 330 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 1991 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 333 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 1997 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 334 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2003 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 335 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2009 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 338 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[0].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2015 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 341 "syntactic.yy" /* yacc.c:1646  */
    {
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*(yyvsp[0].Nodo_tmp));
    (yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),children);}
#line 2024 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 347 "syntactic.yy" /* yacc.c:1646  */
    {
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*(yyvsp[0].Nodo_tmp));
    (yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),children);}
#line 2033 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 353 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2039 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 356 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2045 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 357 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2051 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 360 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2057 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 361 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2063 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 362 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2069 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 365 "syntactic.yy" /* yacc.c:1646  */
    {
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*(yyvsp[0].Nodo_tmp));
    (yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),children);}
#line 2078 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 371 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2084 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 373 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2090 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 374 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2096 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 376 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2102 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 377 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2108 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 378 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2114 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 382 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2120 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 384 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2126 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 385 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2132 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 387 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2138 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 388 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2144 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 389 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2150 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 390 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2156 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 394 "syntactic.yy" /* yacc.c:1646  */
    {
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*(yyvsp[0].Nodo_tmp));
    (yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),children);}
#line 2165 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 400 "syntactic.yy" /* yacc.c:1646  */
    {
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*(yyvsp[0].Nodo_tmp));
    (yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),children);}
#line 2174 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 408 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2180 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 410 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2186 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 411 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2192 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 414 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2198 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 415 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2204 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 418 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2210 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 420 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2216 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 421 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2222 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 424 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2228 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 425 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2234 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 429 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2240 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 431 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2246 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 432 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2252 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 435 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2258 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 436 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2264 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 441 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2270 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 443 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2276 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 444 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2282 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 447 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2288 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 448 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2294 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 452 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2300 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 454 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2306 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 455 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2312 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 458 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2318 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 459 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2324 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 463 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2330 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 465 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2336 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 466 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2342 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 469 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2348 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 470 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2354 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 474 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2360 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 476 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2366 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 477 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2372 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 480 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2378 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 481 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2384 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 482 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2390 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 486 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),(yyvsp[0].Nodo_tmp)->node_children);}
#line 2396 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 488 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = (yyvsp[-1].Nodo_tmp); (yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2402 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 489 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp)->node_children->append(*(yyvsp[0].Nodo_tmp));}
#line 2408 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 492 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2414 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 493 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = ((yyvsp[0].Nodo_tmp));}
#line 2420 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 498 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2426 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 500 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2432 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 501 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2438 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 502 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2444 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 503 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2450 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 504 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2456 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 506 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2462 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 507 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2468 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 509 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2474 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 510 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2480 "parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 512 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2486 "parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 513 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2492 "parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 515 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2498 "parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 516 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2504 "parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 518 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 519 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2516 "parser.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 521 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2522 "parser.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 523 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[0].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2528 "parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 525 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[0].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2534 "parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 527 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2540 "parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 528 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2546 "parser.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 529 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2552 "parser.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 531 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 533 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2564 "parser.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 535 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[0].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2570 "parser.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 537 "syntactic.yy" /* yacc.c:1646  */
    {(yyval.Nodo_tmp) = new AST_Node((yyvsp[-2].TEXT),(yyvsp[0].TEXT),new QList<AST_Node>());}
#line 2576 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2580 "parser.cpp" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 539 "syntactic.yy" /* yacc.c:1906  */




