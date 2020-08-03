/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 23 "syntactic.yy" /* yacc.c:1909  */

char TEXT [256];
class AST_Node *Nodo_tmp;

#line 113 "parser.h" /* yacc.c:1909  */
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
