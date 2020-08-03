#ifndef AST_NODE_H
#define AST_NODE_H
#include <QCoreApplication>
#include <iostream>
#include <qdebug.h>
#include <QList>

class AST_Node
{
public:
    QString node_type = "";
    QString node_value = "";
    QList<AST_Node> * node_children = new QList<AST_Node>();
    AST_Node();
    AST_Node(QString type, QString value, QList<AST_Node>* children);
    AST_Node(QString value);


};

#endif // AST_NODE_H
