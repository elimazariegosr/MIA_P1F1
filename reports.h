#ifndef REPORTS_H
#define REPORTS_H
#include <struct_adm.h>
#include <data_mount.h>
#include<mkdisk_controller.h>


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
#include <mkdisk_controller.h>
#include <data_mount.h>
#include<fstream>
#include<system_controller.h>
using namespace std;
class Reports
{
public:
    Reports();

    MkDisk_Controller mk;
    void generar_rep(QList<Data_Mount> *list,QList<AST_Node> * children);
    void disk_report(mbr mbr_disk, QList<emb> list);
    void mbr_report(mbr mbr_disk, QList<emb> list);
    //void recusive_tree(inodo current_inodo, QString file, string path);
    void tree_report(Data_Mount mount);
    void inode_report(Data_Mount mount);
    void block_report(Data_Mount mount);
    void bm_block_report(Data_Mount mount);
    void bm_inodo_report(Data_Mount mount);
    void sb_report(Data_Mount mount);
    void jour_report(Data_Mount mount);
    void file_report(Data_Mount mount, QString path);
    void ls_report(Data_Mount mount, QString path);
    void comand_dot(string dir);

};

#endif // REPORTS_H
