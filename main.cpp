#include <QCoreApplication>
#include <ast_node_controller.h>
#include <struct_adm.h>
#include <iostream>
int main(int argc, char *argv[])
{

    AST_Node_Controller* principal = new AST_Node_Controller();
        principal->principal_menu();
    QCoreApplication a(argc, argv);
    return 0;
}
