#include "ast_node_controller.h"
#include "mkdisk_controller.h"
AST_Node_Controller::AST_Node_Controller()
{

}
QTextStream qtin(stdin);
extern AST_Node * root = new AST_Node();//root principal
QList<Data_Mount> list_mount;
user sesion;
Data_Mount part_use;

bool is_session(){
    return sesion.id != -1;
}
void journaling(string command){
    FILE * disk;
    if(disk = fopen(part_use.path.c_str(), "rb+")){
        journal jnl;
        int ptr = part_use.part_.part_start + sizeof(super_bloque);
        fseek(disk, ptr, SEEK_SET);
        fread(&jnl, sizeof(journal), 1, disk);

        for(int i = 0; i < 999; i++){
            if(jnl.value[i].fs == -1){
                time_t now = time(0);
                jnl.value[i].fs = 3;
                strcpy(jnl.value[i].part_name, part_use.part_.part_name);
                strcpy(jnl.value[i].user, sesion.n_user);
                strcpy(jnl.value[i].action, command.c_str());
                jnl.value[i].tiem = now;
                break;
            }
        }
        fseek(disk, ptr, SEEK_SET);
        fwrite(&jnl, sizeof(journal), 1, disk);
        fclose(disk);
    }
}

//busca las diferentes raices que pueden venir en los comandos insertados
void search_root(){
    MkDisk_Controller mk;
    Data_Mount_Controller dm;
    System_Controller sm;
    Reports rep;
    User_Controller us;
    Login lg;
    if(mk.compare_str(root->node_type,"pause")){ //si es mkdisk
        QString ent = qtin.readLine();
    }else if(mk.compare_str(root->node_type,"mkdisk")){ //si es mkdisk
        qDebug() << "Mkdisk";
        mk.create_disk(root->node_children);
    }else if(mk.compare_str(root->node_type,"rmdisk")){//si root es rmdisk
        qDebug() << "rkdisk";
        mk.remove_disk(root->node_children);
    }else if(mk.compare_str(root->node_type, "fdisk")){//si root es fdisk
        qDebug() << "fdisk";
        mk.create_partition(root->node_children);
    }else if(mk.compare_str(root->node_type, "mount")){//si root es mount
        dm.moount(&list_mount, root->node_children);
    }else if(mk.compare_str(root->node_type, "unmount")){//si disk es rep
        dm.unmount(&list_mount,root->node_children);
    }else if(mk.compare_str(root->node_type, "rep")){//si disk es rep
        rep.generar_rep(&list_mount, root->node_children);
    }else if(mk.compare_str(root->node_type, "mkfs")){//si disk es rep
        sm.format_mkfs(root->node_children,&list_mount);
    }else if(mk.compare_str(root->node_type, "login")){//login
        if(!is_session()){
            sesion = lg.login_(root->node_children,&list_mount, &part_use);
            if(is_session()){
                qDebug() << "Usuario: "<< sesion.n_user  << " logeado exitosamente";
                journaling("login");

            }else{
                qDebug() << "Usuario: "<< sesion.n_user  << " no esta dentro del sistema";

            }
        }else{
            qDebug() << "Ya existe una sesion";
        }
    }else{
        if(is_session()){
            if(mk.compare_str(root->node_type, "logout")){//logout
                user aux;
                sesion = aux;
            }else if(mk.compare_str(root->node_type, "mkfile")){//si disk es rep
                sm.mkfile_command(root->node_children,sesion,part_use);
                journaling("mkfile");
            }else if(mk.compare_str(root->node_type, "mkdir")){//si disk es rep
                sm.mkdir_command(root->node_children,sesion,part_use);
                journaling("mkdir");
            }else if(mk.compare_str(root->node_type, "mkgrp")){//si disk es rep
                if(strcmp(sesion.n_user, "root") == 0){
                    us.mkgrp_command(root->node_children,sesion,part_use);
                    journaling("mkgrp");

                }else{
                    qDebug() << "Para poder crear grupos debe ser usuario root";
                }
            }else if(mk.compare_str(root->node_type, "mkusr")){//si disk es rep
                if(strcmp(sesion.n_user, "root") == 0){
                    us.mkusr_command(root->node_children,sesion,part_use);
                    journaling("mkusr");
                }else{
                    qDebug() << "Para poder crear usuarios debe ser usuario root";
                }
            }else if(mk.compare_str(root->node_type, "rmusr")){//si disk es rep
                if(strcmp(sesion.n_user, "root") == 0){
                    us.rmusr_command(root->node_children,sesion,part_use);
                    journaling("rmusr");
                }else{
                    qDebug() << "Para poder eliminar usuarios debe ser usuario root";
                }
            }else if(mk.compare_str(root->node_type, "rmgrp")){//si disk es rep
                if(strcmp(sesion.n_user, "root") == 0){
                    us.rmgrp_command(root->node_children,sesion,part_use);
                    journaling("rmgrp");
                }else{
                    qDebug() << "Para poder eliminar grupos debe ser usuario root";
                }
            }else if(mk.compare_str(root->node_type, "cat")){//si disk es rep
                sm.cat_command(root->node_children,sesion,part_use);
                journaling("cat");
            }else if(mk.compare_str(root->node_type, "find")){//si disk es rep
                sm.find_command(root->node_children,sesion,part_use);
                journaling("find");
            }else if(mk.compare_str(root->node_type, "edit")){//si disk es rep
                sm.edit_command(root->node_children,sesion,part_use);
                journaling("edit");
            }else if(mk.compare_str(root->node_type, "rem")){//si disk es rep
                sm.remove_command(root->node_children,sesion,part_use);
                journaling("rem");
            }else if(mk.compare_str(root->node_type, "ren")){//si disk es rep
                sm.ren_command(root->node_children,sesion,part_use);
                journaling("ren");
            }else if(mk.compare_str(root->node_type, "chgrp")){//si disk es rep
                if(strcmp(sesion.n_user, "root") == 0){
                    us.chgrp_command(root->node_children,sesion,part_use);
                    journaling("chgrp");
                }else{
                    qDebug() << "Para poder crear usuarios debe ser usuario root";
                 }
            }else if(mk.compare_str(root->node_type, "chmod")){//si disk es rep
                sm.chmod_command(root->node_children,sesion,part_use);
                journaling("chmod");
            }else if(mk.compare_str(root->node_type, "chown")){//si disk es rep
                sm.chown_command(root->node_children,sesion,part_use);
                journaling("chown");
            }else if(mk.compare_str(root->node_type, "edit")){//si disk es rep
                sm.edit_command(root->node_children,sesion,part_use);
                journaling("edit");
            }else if(mk.compare_str(root->node_type, "rem")){//si disk es rep
                sm.remove_command(root->node_children,sesion,part_use);
                journaling("rem");
            }else if(mk.compare_str(root->node_type, "ren")){//si disk es rep
                sm.ren_command(root->node_children,sesion,part_use);
                journaling("ren");
            }else if(mk.compare_str(root->node_type, "mv")){//si disk es rep
                sm.mv_command(root->node_children,sesion,part_use);
                journaling("ren");
            }else if(mk.compare_str(root->node_type, "cp")){//si disk es rep
                sm.ren_command(root->node_children,sesion,part_use);
                journaling("ren");
            }


        }else{
            qDebug() << "Debe iniciar sesion antes de ejecutar el comando";
        }
    }
}


void cmd_exec(QList<AST_Node>* children){
    MkDisk_Controller mk;
    QString path = "";
    for (int c = 0; c < children->size(); c++) {
        if(mk.compare_str(children->at(c).node_type, "-path")){
            path = children->at(c).node_value;
        }
    }
    if(path != ""){
        ifstream file;
        string line = "";
        file.open(path.toStdString(),ios::in);
        if(!file.fail()){
            while(!file.eof()){
                getline(file, line);
                if(line != ""){
                    QString line_rep = "";
                    line_rep = line.c_str();
                    line_rep.replace("\r","");
                    YY_BUFFER_STATE bf = yy_scan_string(line_rep.toStdString().c_str());
                    if(yyparse() == 0){
                        search_root();
                    }

                }
                line = "";
            }
        }
    }

}
//menu principal
void AST_Node_Controller:: principal_menu(){
/*    QString asd = "1,G,root\n 1,U,root,root,123\n";
    qDebug() << asd.size();*/

    MkDisk_Controller mk;
    while(true){

        qDebug() << "**************************************************************";
        qDebug() << "PROYECTO 1 - FASE 1 - 201709426";
        qDebug() << "**************************************************************";
        QString ent = qtin.readLine();
        YY_BUFFER_STATE bf = yy_scan_string(ent.toUtf8().constData());
        if(yyparse() == 0){

            if(mk.compare_str(root->node_type,"exec")){ //si es mkdisk
                cmd_exec(root->node_children);
            }else{
                search_root();
            }
        }
        qDebug() << "**************************************************************";
    }
}
