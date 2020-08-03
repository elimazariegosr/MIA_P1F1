%{
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


%}
%defines "parser.h"
%output "parser.cpp"
%error-verbose
%locations

%union{
char TEXT [256];
class AST_Node *Nodo_tmp;
}
//terminales
%token<TEXT> TK_MKDISK;
%token<TEXT> TK_RMDISK;
%token<TEXT> TK_FDISK;
%token<TEXT> TK_MOUNT;
%token<TEXT> TK_UNMOUNT;
%token<TEXT> TK_REP;
%token<TEXT> TK_EXEC;


%token<TEXT> TK_MKFS;
%token<TEXT> TK_LOGIN;
%token<TEXT> TK_LOGOUT;
%token<TEXT> TK_MKGRP;
%token<TEXT> TK_RMGRP;
%token<TEXT> TK_MKUSR;
%token<TEXT> TK_RMUSR;
%token<TEXT> TK_CHMOD;
%token<TEXT> TK_MKFILE;
%token<TEXT> TK_CAT;
%token<TEXT> TK_REM;
%token<TEXT> TK_EDIT;
%token<TEXT> TK_REN;
%token<TEXT> TK_MKDIR;
%token<TEXT> TK_CP;
%token<TEXT> TK_MV;
%token<TEXT> TK_FIND;
%token<TEXT> TK_CHOWN;
%token<TEXT> TK_CHGRP;
%token<TEXT> TK_PAUSE;


%token<TEXT> TK_SIZE;
%token<TEXT> TK_FIT;
%token<TEXT> TK_UNIT;
%token<TEXT> TK_PATH;
%token<TEXT> TK_TYPE;
%token<TEXT> TK_DELETE;
%token<TEXT> TK_NAME;
%token<TEXT> TK_ADD;
%token<TEXT> TK_ID;

%token<TEXT> TK_USR;
%token<TEXT> TK_PWD;
%token<TEXT> TK_GRP;
%token<TEXT> TK_UGO;
%token<TEXT> TK_R;
%token<TEXT> TK_P;
%token<TEXT> TK_CONT;
%token<TEXT> TK_FILE;
%token<TEXT> TK_DEST;



%token<TEXT> TK_EQUALS;
%token<TEXT> TK_IDENT;
%token<TEXT> TK_RUTA;
%token<TEXT> TK_CADENA;
%token<TEXT> TK_NUMBER;
%token<TEXT> TK_PARM_RUTA;
//no terminales
%type<Nodo_tmp> INIT;

%type<Nodo_tmp> MKDISK;
%type<Nodo_tmp> MKDISK_LIST;
%type<Nodo_tmp> MKDISK_LIST_CONT;

%type<Nodo_tmp> RMDISK;

%type<Nodo_tmp> FDISK;
%type<Nodo_tmp> FDISK_LIST;
%type<Nodo_tmp> FDISK_LIST_CONT;

%type<Nodo_tmp> MOUNT;
%type<Nodo_tmp> MOUNT_LIST;
%type<Nodo_tmp> MOUNT_LIST_CONT;

%type<Nodo_tmp> UNMOUNT;

%type<Nodo_tmp> REP;
%type<Nodo_tmp> REP_LIST;
%type<Nodo_tmp> REP_LIST_CONT;

%type<Nodo_tmp> EXEC;

%type<Nodo_tmp> MKFS;
%type<Nodo_tmp> MKFS_LIST;
%type<Nodo_tmp> MKFS_LIST_CONT;

%type<Nodo_tmp> LOGIN;
%type<Nodo_tmp> LOGIN_LIST;
%type<Nodo_tmp> LOGIN_LIST_CONT;


%type<Nodo_tmp> MKUSR;
%type<Nodo_tmp> MKUSR_LIST;
%type<Nodo_tmp> MKUSR_LIST_CONT;


%type<Nodo_tmp> LOGOUT;
%type<Nodo_tmp> MKGRP;
%type<Nodo_tmp> RMGRP;



%type<Nodo_tmp> RMUSR;

%type<Nodo_tmp> CHMOD;
%type<Nodo_tmp> CHMOD_LIST;
%type<Nodo_tmp> CHMOD_LIST_CONT;


%type<Nodo_tmp> MKFILE;
%type<Nodo_tmp> MKFILE_LIST;
%type<Nodo_tmp> MKFILE_LIST_CONT;


%type<Nodo_tmp> CAT;
%type<Nodo_tmp> REM;


%type<Nodo_tmp> EDIT;
%type<Nodo_tmp> EDIT_LIST;
%type<Nodo_tmp> EDIT_LIST_CONT;


%type<Nodo_tmp> REN;
%type<Nodo_tmp> REN_LIST;
%type<Nodo_tmp> REN_LIST_CONT;


%type<Nodo_tmp> MKDIR;
%type<Nodo_tmp> MKDIR_LIST;
%type<Nodo_tmp> MKDIR_LIST_CONT;


%type<Nodo_tmp> CP;
%type<Nodo_tmp> CP_LIST;
%type<Nodo_tmp> CP_LIST_CONT;


%type<Nodo_tmp> MV;
%type<Nodo_tmp> MV_LIST;
%type<Nodo_tmp> MV_LIST_CONT;

%type<Nodo_tmp> FIND;
%type<Nodo_tmp> FIND_LIST;
%type<Nodo_tmp> FIND_LIST_CONT;


%type<Nodo_tmp> CHOWN;
%type<Nodo_tmp> CHOWN_LIST;
%type<Nodo_tmp> CHOWN_LIST_CONT;


%type<Nodo_tmp> CHGRP;
%type<Nodo_tmp> CHGRP_LIST;
%type<Nodo_tmp> CHGRP_LIST_CONT;


%type<Nodo_tmp> SIZE;
%type<Nodo_tmp> FIT;
%type<Nodo_tmp> UNIT;
%type<Nodo_tmp> PATH;
%type<Nodo_tmp> TYPE;
%type<Nodo_tmp> DELETE;
%type<Nodo_tmp> NAME;
%type<Nodo_tmp> ADD;
%type<Nodo_tmp> ID;

%type<Nodo_tmp> USR;
%type<Nodo_tmp> PWD;
%type<Nodo_tmp> GRP;
%type<Nodo_tmp> R;
%type<Nodo_tmp> P;
%type<Nodo_tmp> CONT;
%type<Nodo_tmp> FILE_;
%type<Nodo_tmp> DEST;
%type<Nodo_tmp> PAUSE;
%type<Nodo_tmp> UGO;
%type<Nodo_tmp> PARM_RUTA;





%start INIT
%%

INIT:   MKDISK{root = $1;}
    |   RMDISK{root = $1;}
    |   FDISK{root = $1;}
    |   MOUNT{root = $1;}
    |   UNMOUNT{root = $1;}
    |   REP{root = $1;}
    |   EXEC{root = $1;}
    |   MKFS{root = $1;}
    |   LOGIN{root = $1;}
    |   LOGOUT{root = $1;}
    |   MKGRP{root = $1;}
    |   RMGRP{root = $1;}
    |   MKUSR{root = $1;}
    |   RMUSR{root = $1;}
    |   CHMOD{root = $1;}
    |   CAT{root = $1;}
    |   REM{root = $1;}
    |   MKFILE{root = $1;}
    |   MKDIR{root = $1;}
    |   EDIT{root = $1;}
    |   REN{root = $1;}
    |   CP{root = $1;}
    |   MV{root = $1;}
    |   FIND{root = $1;}
    |   CHOWN{root = $1;}
    |   CHGRP{root = $1;}
    |   PAUSE{root = $1;}
;

MKDISK: TK_MKDISK MKDISK_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

MKDISK_LIST: MKDISK_LIST MKDISK_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   MKDISK_LIST_CONT {$$->node_children->append(*$1);}
;

MKDISK_LIST_CONT: SIZE{$$ = ($1);}
    |   FIT{$$ = ($1);}
    |   UNIT{$$ = ($1);}
    |   PATH{$$ = ($1);}
;

RMDISK: TK_RMDISK PATH{
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*$2);
    $$ = new AST_Node($1,$1,children);}
;

FDISK: TK_FDISK FDISK_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

FDISK_LIST: FDISK_LIST FDISK_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   FDISK_LIST_CONT {$$->node_children->append(*$1);};

FDISK_LIST_CONT: SIZE{$$ = ($1);}
    |   UNIT{$$ = ($1);}
    |   PATH{$$ = ($1);}
    |   TYPE{$$ = ($1);}
    |   FIT{$$ = ($1);}
    |   DELETE{$$ = ($1);}
    |   NAME{$$ = ($1);}
    |   ADD{$$ = ($1);}
;

MOUNT: TK_MOUNT MOUNT_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

MOUNT_LIST: MOUNT_LIST MOUNT_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   MOUNT_LIST_CONT {$$->node_children->append(*$1);}
;

MOUNT_LIST_CONT: PATH{$$ = ($1);}
    |   NAME{$$ = ($1);}
;


UNMOUNT: TK_UNMOUNT ID{
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*$2);
    $$ = new AST_Node($1,$1,children);
};

REP: TK_REP REP_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

REP_LIST: REP_LIST REP_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   REP_LIST_CONT {$$->node_children->append(*$1);}
;

REP_LIST_CONT: NAME{$$ = ($1);}
    |   PATH{$$ = ($1);}
    |   ID{$$ = ($1);}
    |   PARM_RUTA {$$ = ($1);}
;

EXEC:TK_EXEC PATH {

    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*$2);
    $$ = new AST_Node($1,$1,children);
};


MKFS: TK_MKFS MKFS_LIST{$$ = new AST_Node($1,$1,$2->node_children);}
;

MKFS_LIST: MKFS_LIST MKFS_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   MKFS_LIST_CONT {$$->node_children->append(*$1);}
;

MKFS_LIST_CONT: ID{$$ = ($1);}
    |   TYPE{$$ = ($1);}
;

LOGIN: TK_LOGIN LOGIN_LIST{$$ = new AST_Node($1,$1,$2->node_children);}
;

LOGIN_LIST: LOGIN_LIST LOGIN_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
 |   LOGIN_LIST_CONT {$$->node_children->append(*$1);}
;

LOGIN_LIST_CONT: USR{$$ = ($1);}
 |   PWD{$$ = ($1);}
 |   ID{$$ = ($1);}
;

LOGOUT: TK_LOGOUT {$$ = new AST_Node($1,$1,new QList<AST_Node>());};


MKGRP: TK_MKGRP NAME{
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*$2);
    $$ = new AST_Node($1,$1,children);}
;

RMGRP: TK_RMGRP NAME{
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*$2);
    $$ = new AST_Node($1,$1,children);}
;

MKUSR: TK_MKUSR MKUSR_LIST{$$ = new AST_Node($1,$1,$2->node_children);}
;

MKUSR_LIST: MKUSR_LIST MKUSR_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   MKUSR_LIST_CONT {$$->node_children->append(*$1);}
;

MKUSR_LIST_CONT: USR{$$ = ($1);}
    |   PWD{$$ = ($1);}
    |   GRP{$$ = ($1);}
;

RMUSR: TK_RMUSR USR{
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*$2);
    $$ = new AST_Node($1,$1,children);}
;

CHMOD: TK_CHMOD CHMOD_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

CHMOD_LIST: CHMOD_LIST CHMOD_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   CHMOD_LIST_CONT {$$->node_children->append(*$1);};

CHMOD_LIST_CONT: PATH{$$ = ($1);}
    |   UGO{$$ = ($1);}
    |   R{$$ = ($1);}
;


MKFILE: TK_MKFILE MKFILE_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

MKFILE_LIST: MKFILE_LIST MKFILE_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   MKFILE_LIST_CONT {$$->node_children->append(*$1);};

MKFILE_LIST_CONT: PATH{$$ = ($1);}
    |   P{$$ = ($1);}
    |   SIZE{$$ = ($1);}
    |   CONT{$$ = ($1);}
;


CAT: TK_CAT FILE_{
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*$2);
    $$ = new AST_Node($1,$1,children);}
;

REM: TK_REM PATH{
    QList<AST_Node> * children = new QList<AST_Node>();
    children->append(*$2);
    $$ = new AST_Node($1,$1,children);}
;



EDIT: TK_EDIT EDIT_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

EDIT_LIST: EDIT_LIST EDIT_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   EDIT_LIST_CONT {$$->node_children->append(*$1);}
;

EDIT_LIST_CONT: PATH{$$ = ($1);}
    |   CONT{$$ = ($1);}
;

REN: TK_REN REN_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

REN_LIST: REN_LIST REN_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   REN_LIST_CONT {$$->node_children->append(*$1);}
;

REN_LIST_CONT: PATH{$$ = ($1);}
    |   NAME{$$ = ($1);}
;


MKDIR: TK_MKDIR MKDIR_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

MKDIR_LIST: MKDIR_LIST MKDIR_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   MKDIR_LIST_CONT {$$->node_children->append(*$1);}
;

MKDIR_LIST_CONT: PATH{$$ = ($1);}
    |   P{$$ = ($1);}
;



CP: TK_CP CP_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

CP_LIST: CP_LIST CP_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   CP_LIST_CONT {$$->node_children->append(*$1);}
;

CP_LIST_CONT: PATH{$$ = ($1);}
    |   DEST{$$ = ($1);}
;


MV: TK_MV MV_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

MV_LIST: MV_LIST MV_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   MV_LIST_CONT {$$->node_children->append(*$1);}
;

MV_LIST_CONT: PATH{$$ = ($1);}
    |   DEST{$$ = ($1);}
;


FIND: TK_FIND FIND_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

FIND_LIST: FIND_LIST FIND_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   FIND_LIST_CONT {$$->node_children->append(*$1);}
;

FIND_LIST_CONT: PATH{$$ = ($1);}
    |   NAME{$$ = ($1);}
;


CHOWN: TK_CHOWN CHOWN_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

CHOWN_LIST: CHOWN_LIST CHOWN_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   CHOWN_LIST_CONT {$$->node_children->append(*$1);}
;

CHOWN_LIST_CONT: PATH{$$ = ($1);}
    |   R{$$ = ($1);}
    |   USR{$$ = ($1);}
;


CHGRP: TK_CHGRP CHGRP_LIST{$$ = new AST_Node($1,$1,$2->node_children);};

CHGRP_LIST: CHGRP_LIST CHGRP_LIST_CONT {$$ = $1; $$->node_children->append(*$2);}
    |   CHGRP_LIST_CONT {$$->node_children->append(*$1);}
;

CHGRP_LIST_CONT: USR{$$ = ($1);}
    |   GRP{$$ = ($1);}
;



SIZE: TK_SIZE TK_EQUALS TK_NUMBER{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

FIT: TK_FIT TK_EQUALS TK_IDENT{$$ = new AST_Node($1,$3,new QList<AST_Node>());};
UNIT: TK_UNIT TK_EQUALS TK_IDENT{$$ = new AST_Node($1,$3,new QList<AST_Node>());};
PATH: TK_PATH TK_EQUALS TK_RUTA{$$ = new AST_Node($1,$3,new QList<AST_Node>());};
TYPE: TK_TYPE TK_EQUALS TK_IDENT{$$ = new AST_Node($1,$3,new QList<AST_Node>());};
DELETE: TK_DELETE TK_EQUALS TK_IDENT{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

NAME: TK_NAME TK_EQUALS TK_CADENA{$$ = new AST_Node($1,$3,new QList<AST_Node>());}
    |   TK_NAME TK_EQUALS TK_IDENT{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

ADD: TK_ADD TK_EQUALS TK_NUMBER{$$ = new AST_Node($1,$3,new QList<AST_Node>());};
ID: TK_ID TK_EQUALS TK_IDENT{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

USR: TK_USR TK_EQUALS TK_CADENA{$$ = new AST_Node($1,$3,new QList<AST_Node>());}
    |   TK_USR TK_EQUALS TK_IDENT{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

PWD: TK_PWD TK_EQUALS TK_CADENA{$$ = new AST_Node($1,$3,new QList<AST_Node>());}
    |   TK_PWD TK_EQUALS TK_IDENT{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

GRP: TK_GRP TK_EQUALS TK_CADENA{$$ = new AST_Node($1,$3,new QList<AST_Node>());}
    |   TK_GRP TK_EQUALS TK_IDENT{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

UGO: TK_UGO TK_EQUALS TK_NUMBER{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

R: TK_R {$$ = new AST_Node($1,$1,new QList<AST_Node>());};

P: TK_P {$$ = new AST_Node($1,$1,new QList<AST_Node>());};

CONT: TK_CONT TK_EQUALS TK_CADENA{$$ = new AST_Node($1,$3,new QList<AST_Node>());}
    |   TK_CONT TK_EQUALS TK_IDENT{$$ = new AST_Node($1,$3,new QList<AST_Node>());}
    |   TK_CONT TK_EQUALS TK_RUTA{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

FILE_: TK_FILE TK_EQUALS TK_RUTA{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

DEST: TK_DEST TK_EQUALS TK_RUTA{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

PAUSE: TK_PAUSE{$$ = new AST_Node($1,$1,new QList<AST_Node>());};

PARM_RUTA: TK_PARM_RUTA TK_EQUALS TK_RUTA{$$ = new AST_Node($1,$3,new QList<AST_Node>());};

%%



