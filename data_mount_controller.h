#ifndef DATA_MOUNT_CONTROLLER_H
#define DATA_MOUNT_CONTROLLER_H
#include <data_mount.h>
#include<mkdisk_controller.h>
#include<struct_adm.h>


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
using namespace std;
class Data_Mount_Controller
{
public:
    MkDisk_Controller mk;
    Data_Mount_Controller();
    void moount(QList<Data_Mount> *list,QList<AST_Node> * children);
    void unmount(QList<Data_Mount> *list,QList<AST_Node> * children);
};

#endif // DATA_MOUNT_CONTROLLER_H
