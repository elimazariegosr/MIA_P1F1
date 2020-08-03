#ifndef DATA_MOUNT_H
#define DATA_MOUNT_H
#include <struct_adm.h>

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

class Data_Mount
{
public:
    Data_Mount();
    Data_Mount(string id,string path, string name, part part_);
    string id;
    string path;
    string name;
    int letter;
    int count = 0;
    part part_;
};

#endif // DATA_MOUNT_H
