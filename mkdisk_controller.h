#ifndef MKDISK_CONTROLLER_H
#define MKDISK_CONTROLLER_H
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
using namespace std;


class MkDisk_Controller
{

public:
    MkDisk_Controller();
    void remove_disk(QList<AST_Node> *children);
    void create_directory(QString dir);
    void create_disk(QList<AST_Node> *children);
    void create_partition(QList<AST_Node> *children);
    void create_pe_partition(char  fit, int size, char type, string name, string path);
    void create_logic_partition(char fit, int size,string name, string path);
    int available(mbr mbr_disk);
    int set_logics(QList<emb> list, char fit, int size, string path);
    int search_logic(string path, string name,char status);
    void delete_logic(string path, string name);
    void add_logic(string path, int add, string name);
    QList<emb> all_logic(string path, char status);
    bool  compare_str(QString first, QString second){
        return QString::compare(first, second, Qt::CaseInsensitive) == 0;
    }
};

#endif // MKDISK_CONTROLLER_Hfst
