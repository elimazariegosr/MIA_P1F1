#ifndef AST_NODE_CONTROLLER_H
#define AST_NODE_CONTROLLER_H

#include <QCoreApplication>
#include <iostream>
#include <qdebug.h>
#include <ast_node.h>
#include <qlist.h>
#include <qstring.h>
#include <parser.h>
#include <scanner.h>
#include <ctime>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mkdisk_controller.h>
#include <data_mount.h>
#include <data_mount_controller.h>
#include <reports.h>
#include <system_controller.h>
#include <login.h>
#include <user_controller.h>
using namespace std;


class AST_Node_Controller
{
public:
    AST_Node_Controller();

    void principal_menu();
    bool compare_str(QString, QString);

};

#endif // AST_NODE_CONTROLLER_H
