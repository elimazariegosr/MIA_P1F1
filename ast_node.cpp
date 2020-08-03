#include "ast_node.h"

AST_Node::AST_Node()
{

}
AST_Node::AST_Node(QString type, QString value, QList<AST_Node> * children){
    this->node_type = type.replace("\"","");
    this->node_value = value.replace("\"","").replace("/home/eli/","/home/").replace("/home/","/home/eli/");
    this->node_children = children;
}
AST_Node::AST_Node(QString value){
    this->node_value = value;
}
