%option case-insensitive
%option yylineno
%{
#include <cstdlib>
#include "parser.h"
#include <QString>
#include <stdio.h>
#include <iostream>
#include <iostream>
int yylex();
void yyerror(const char *s);

int linea=0;
int columna = 1;

%}

%option header-file="scanner.h"
%option outfile="scanner.cpp"
%option noyywrap
%option nounput

letra [a-zñA-ZÑ]+
numero "-"?[0-9]+

id {letra}({letra}|{numero}|"_"|".")*
ruta  ("/"{letra}({letra}|{numero}|"_")*)+("."{letra}({letra}|{numero}|"_")*)?|"\""("/"({letra}({letra}|{numero}|"_"|" ")+)*)+("."{letra}({letra}|{numero}|"_")*)?"\""
cadena "\""[^"\""]*"\""

comen "#"[^"\n"]*

%x COM COMM

%%
INITIAL
{
"//" {  BEGIN COM; }
"/*" {  BEGIN COMM; }

{comen}    { /*Se ignoran*/ std::cout << yytext << std::endl;}



"mkdisk"    {strcpy(yylval.TEXT, yytext); return TK_MKDISK;}
"rmdisk"    {strcpy(yylval.TEXT, yytext); return TK_RMDISK;}
"fdisk"     {strcpy(yylval.TEXT, yytext); return TK_FDISK;}
"mount"     {strcpy(yylval.TEXT, yytext); return TK_MOUNT;}
"unmount"   {strcpy(yylval.TEXT, yytext); return TK_UNMOUNT;}
"rep"       {strcpy(yylval.TEXT, yytext); return TK_REP;}
"exec"      {strcpy(yylval.TEXT, yytext); return TK_EXEC;}


"mkfs"      {strcpy(yylval.TEXT, yytext); return TK_MKFS;}
"login"     {strcpy(yylval.TEXT, yytext); return TK_LOGIN;}
"logout"    {strcpy(yylval.TEXT, yytext); return TK_LOGOUT;}
"mkgrp"     {strcpy(yylval.TEXT, yytext); return TK_MKGRP;}
"rmgrp"     {strcpy(yylval.TEXT, yytext); return TK_RMGRP;}
"mkusr"     {strcpy(yylval.TEXT, yytext); return TK_MKUSR;}
"rmusr"     {strcpy(yylval.TEXT, yytext); return TK_RMUSR;}
"chmod"     {strcpy(yylval.TEXT, yytext); return TK_CHMOD;}
"mkfile"    {strcpy(yylval.TEXT, yytext); return TK_MKFILE;}
"cat"       {strcpy(yylval.TEXT, yytext); return TK_CAT;}
"rem"       {strcpy(yylval.TEXT, yytext); return TK_REM;}
"edit"      {strcpy(yylval.TEXT, yytext); return TK_EDIT;}
"ren"       {strcpy(yylval.TEXT, yytext); return TK_REN;}
"mkdir"     {strcpy(yylval.TEXT, yytext); return TK_MKDIR;}
"cp"        {strcpy(yylval.TEXT, yytext); return TK_CP;}
"mv"        {strcpy(yylval.TEXT, yytext); return TK_MV;}
"find"      {strcpy(yylval.TEXT, yytext); return TK_FIND;}
"chown"     {strcpy(yylval.TEXT, yytext); return TK_CHOWN;}
"chgrp"     {strcpy(yylval.TEXT, yytext); return TK_CHGRP;}
"pause"     {strcpy(yylval.TEXT, yytext); return TK_PAUSE;}



"-size"     {strcpy(yylval.TEXT, yytext); return TK_SIZE;}
"-fit"      {strcpy(yylval.TEXT, yytext); return TK_FIT;}
"-unit"     {strcpy(yylval.TEXT, yytext); return TK_UNIT;}
"-path"     {strcpy(yylval.TEXT, yytext); return TK_PATH;}
"-type"     {strcpy(yylval.TEXT, yytext); return TK_TYPE;}
"-delete"   {strcpy(yylval.TEXT, yytext); return TK_DELETE;}
"-name"     {strcpy(yylval.TEXT, yytext); return TK_NAME;}
"-add"      {strcpy(yylval.TEXT, yytext); return TK_ADD;}
"-id"       {strcpy(yylval.TEXT, yytext); return TK_ID;}


"-usr"      {strcpy(yylval.TEXT, yytext); return TK_USR;}
"-pwd"      {strcpy(yylval.TEXT, yytext); return TK_PWD;}
"-grp"      {strcpy(yylval.TEXT, yytext); return TK_GRP;}
"-ugo"      {strcpy(yylval.TEXT, yytext); return TK_UGO;}
"-r"        {strcpy(yylval.TEXT, yytext); return TK_R;}
"-p"        {strcpy(yylval.TEXT, yytext); return TK_P;}
"-cont"     {strcpy(yylval.TEXT, yytext); return TK_CONT;}
"-file"     {strcpy(yylval.TEXT, yytext); return TK_FILE;}
"-dest"     {strcpy(yylval.TEXT, yytext); return TK_DEST;}
"-ruta"     {strcpy(yylval.TEXT, yytext); return TK_PARM_RUTA;}




"="         {strcpy(yylval.TEXT, yytext); return TK_EQUALS; }
{id}        {strcpy(yylval.TEXT, yytext); return TK_IDENT;}
{ruta}      {strcpy(yylval.TEXT, yytext); return TK_RUTA;}
{cadena}    {strcpy(yylval.TEXT, yytext); return TK_CADENA;}



{numero}    {  strcpy(yylval.TEXT, yytext); return TK_NUMBER;}


"\t"        {
                    strcpy(yylval.TEXT, yytext);
            }
[[:blank:]]
"\n"
.           {
                    strcpy(yylval.TEXT, yytext);
            }
}
<COMM>"*/" { BEGIN INITIAL; }
<COMM>"\n" {linea++;};
<COMM>.;
<COMM><<EOF>> { yyerror("unclosed comment"); }
<COM>"\n" { linea++; columna = 0; BEGIN INITIAL; };
<COM>.;
 %%
