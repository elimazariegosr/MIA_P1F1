#ifndef LOGIN_H
#define LOGIN_H
#include <QCoreApplication>
#include <iostream>
#include <qdebug.h>
#include <ast_node.h>
#include <qlist.h>
#include <qstring.h>
#include <ctime>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <struct_adm.h>
#include <data_mount.h>
using namespace std;

class Login
{
public:
    Login();
    user login_(QList<AST_Node> * children, QList<Data_Mount>* list, Data_Mount *part_use);
    bool  compare_str(QString first, QString second){
        return QString::compare(first, second, Qt::CaseInsensitive) == 0;
    }
};

#endif // LOGIN_H
