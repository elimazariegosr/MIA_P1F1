#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H
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
#include <data_mount_controller.h>
#include <system_controller.h>

class User_Controller
{
public:
    User_Controller();
    void mkgrp_command(QList<AST_Node> * children, user session, Data_Mount part);
    void mkusr_command(QList<AST_Node> * children, user session, Data_Mount part);
    void rmgrp_command(QList<AST_Node> * children, user session, Data_Mount part);
    void rmusr_command(QList<AST_Node> * children, user session, Data_Mount part);
    void chgrp_command(QList<AST_Node> * children, user session, Data_Mount part);

    bool  compare_str(QString first, QString second){
        return QString::compare(first, second, Qt::CaseInsensitive) == 0;
    }
};

#endif // USER_CONTROLLER_H
