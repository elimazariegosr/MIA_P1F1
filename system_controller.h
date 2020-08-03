#ifndef SYSTEM_CONTROLLER_H
#define SYSTEM_CONTROLLER_H
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
#include <fstream>
using namespace std;

class System_Controller
{
public:
    System_Controller();

    //void journaling();

    void mkdir_command(QList<AST_Node> * children, user session, Data_Mount part);
    void mkfile_command(QList<AST_Node> * children, user session, Data_Mount part);
    void cat_command(QList<AST_Node> * children, user session, Data_Mount part);
    void find_command(QList<AST_Node> * children, user session, Data_Mount part);
    void ren_command(QList<AST_Node> * children, user session, Data_Mount part);
    void edit_command(QList<AST_Node> * children, user session, Data_Mount part);
    void remove_command(QList<AST_Node> * children, user session, Data_Mount part);
    void chown_command(QList<AST_Node> * children, user session, Data_Mount part);
    void chmod_command(QList<AST_Node> * children, user session, Data_Mount part);
    void cp_command(QList<AST_Node> * children, user session, Data_Mount part);
    void mv_command(QList<AST_Node> * children, user session, Data_Mount part);

    void remove_ino(QList<QString> dirs);
    void rename_ino(QList<QString> dirs, string name);
    void show_cat(QList<QString> dirs);
    void find_esp(QList<QString> dirs, string name);
    int create_dir(QList<QString> dirs, bool is_p, int tipo, bool is_cat);
    void create_file(QList<QString> dirs, bool is_p, QString cont, int size);
    void change_inodo(QList<QString> dirs, bool is_r, int ugo, string usr);
    void move_inodo(QList<QString> dirs, QList<QString> dris_dest);
    void format_mkfs(QList<AST_Node> * children, QList<Data_Mount> * mount_list);

    bool  compare_str(QString first, QString second){
        return QString::compare(first, second, Qt::CaseInsensitive) == 0;
    }

    int call_create_dir(Data_Mount part,QList<QString> dirs);
    void call_create_file(user session, Data_Mount part,QList<QString> dirs, bool is_p, QString cont, int size);

};

#endif // SYSTEM_CONTROLLER_H
