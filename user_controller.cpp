#include "user_controller.h"

User_Controller::User_Controller()
{

}
Data_Mount pm_user_c;
user sesion_user_c;
//obtener la ultima posicion
int last_start_uc(int value){
    FILE * disk;
    if(disk = fopen(pm_user_c.path.c_str(),"rb+")){
        super_bloque sb;
        fseek(disk, pm_user_c.part_.part_start, SEEK_SET);
        fread(&sb, sizeof(super_bloque), 1, disk);
        if(value != -1){
            sb.s_start = value;
            fseek(disk, pm_user_c.part_.part_start, SEEK_SET);
            fwrite(&sb, sizeof(super_bloque), 1, disk);
        }
        fclose(disk);
        return sb.s_start;
     }
    return -1;
}

int search_usr_grp(string usr, string grp){
    FILE * disk;
    if(disk = fopen(pm_user_c.path.c_str(), "rb+")){
        super_bloque sb;
        fseek(disk, pm_user_c.part_.part_start, SEEK_SET);
        fread(&sb, sizeof(super_bloque), 1, disk);
        fclose(disk);
        for(int i = 0; i < 333; i++){
            if(sb.users_[i].id != -1 && sb.users_[i].type != 'X'){
                if(grp != ""){
                    if(sb.users_[i].grp == grp){
                        return i;
                    }
                }else if(usr != ""){
                    if(sb.users_[i].n_user == usr){
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}
int count_type(char type){
    FILE * disk;
    if(disk = fopen(pm_user_c.path.c_str(), "rb+")){
        super_bloque sb;
        fseek(disk, pm_user_c.part_.part_start, SEEK_SET);
        fread(&sb, sizeof(super_bloque), 1, disk);
        fclose(disk);
        int count = 1;
        for(int i = 0; i < 333; i++){
            if(sb.users_[i].id != -1 && sb.users_[i].type != 'X'){
                if(sb.users_[i].type == type){
                    count++;
                }
            }
        }
        return count;
    }
}

void create_blocks(super_bloque sb){
    System_Controller sm;
    QString path = "/users.txt";
    QList<QString> dirs = path.split("/");
    dirs[0] = "/";
    string cont = "";
    for(int i = 0; i < 333; i++){
        if(sb.users_[i].id != -1 && sb.users_[i].type != 'X'){
            if(sb.users_[i].type == 'G'){
                cont += std::to_string(sb.users_[i].id)
                        + ", " + std::to_string(sb.users_[i].type)
                        +", "  + sb.users_[i].grp +"\n";
            }else if(sb.users_[i].type == 'U'){
                cont += std::to_string(sb.users_[i].id)
                        + ", " + std::to_string(sb.users_[i].type)
                        +", "  + sb.users_[i].grp
                        +", "  + sb.users_[i].n_user
                        +", "  + sb.users_[i].n_pwd + "\n";
            }
        }
    }
    FILE * disk;
    if(disk = fopen(pm_user_c.path.c_str(), "rb+")){
        fseek(disk, pm_user_c.part_.part_start, SEEK_SET);
        fwrite(&sb, sizeof(super_bloque), 1, disk);
        fclose(disk);
        QString value = QString::fromUtf8(cont.c_str());
        sm.call_create_file(sesion_user_c,pm_user_c,dirs,false,value,cont.size());
    }
}

void insert_data(user data){
    int id = count_type(data.type);
    data.id = id;
    FILE * disk;

    if(disk = fopen(pm_user_c.path.c_str(), "rb+")){
        super_bloque sb;
        fseek(disk, pm_user_c.part_.part_start, SEEK_SET);
        fread(&sb, sizeof(super_bloque), 1, disk);
        fclose(disk);
        for(int i = 0; i < 333; i++){
            if(sb.users_[i].id == -1 && sb.users_[i].type == 'X'){
                sb.users_[i] = data;
                break;
            }
        }
        create_blocks(sb);
    }
}

void rm_data(string usr, string grp){
    FILE * disk;
    if(disk = fopen(pm_user_c.path.c_str(), "rb+")){
        super_bloque sb;
        fseek(disk, pm_user_c.part_.part_start, SEEK_SET);
        fread(&sb, sizeof(super_bloque), 1, disk);
        fclose(disk);
        for(int i = 0; i < 333; i++){
            if(sb.users_[i].id != -1 && sb.users_[i].type != 'X'){
                if(grp != ""){
                    if(sb.users_[i].grp == grp){
                        sb.users_[i].id = -1;
                    }
                }else if(usr != ""){
                    if(sb.users_[i].n_user == usr){
                        sb.users_[i].id = -1;
                    }
                }
            }
        }

        create_blocks(sb);
    }
}
void User_Controller::mkgrp_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_user_c = session;
    pm_user_c = part;
    string name_grp = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type, "-name")){
            name_grp = children->at(i).node_value.toStdString();
        }
    }

    if(name_grp != ""){
        if(search_usr_grp("", name_grp) == -1){
            user grp;
            grp.type = 'G';
            strcpy(grp.grp, name_grp.c_str());
            insert_data(grp);
        }else{
            qDebug() << "ya existe el grupo";
        }
    }
}

void User_Controller::rmgrp_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_user_c = session;
    pm_user_c = part;
    string name_grp = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type, "-name")){
            name_grp = children->at(i).node_value.toStdString();
        }
    }

    if(name_grp != ""){
        if(search_usr_grp("", name_grp) != -1){
            rm_data("",name_grp);
        }else{
            qDebug() << "no existe el grupo";
        }
    }
}

void User_Controller::mkusr_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_user_c = session;
    pm_user_c = part;
    qDebug() << pm_user_c.name.c_str();
    string usr = "", pwd = "", grp = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type, "-usr")){
            usr = children->at(i).node_value.toStdString();
        }else if(compare_str(children->at(i).node_type, "-pwd")){
            pwd = children->at(i).node_value.toStdString();
        }else if(compare_str(children->at(i).node_type, "-grp")){
            grp = children->at(i).node_value.toStdString();
        }
    }
    if(usr.size() > 10){
        usr = "";
        qDebug() << "parametro -usr sobrepasa los 10 caracteres";
    }
    if(pwd.size() > 10){
        pwd = "";
        qDebug() << "parametro -pwd sobrepasa los 10 caracteres";
    }
    if(grp.size() > 10){
        grp = "";
        qDebug() << "parametro -grp sobrepasa los 10 caracteres";

    }
    if(usr != "" && pwd != "" && grp != ""){
        if(search_usr_grp(usr,"") == -1){
            if(search_usr_grp("", grp) != -1){
                user new_user;
                strcpy(new_user.grp, grp.c_str());
                strcpy(new_user.n_user, usr.c_str());
                strcpy(new_user.n_pwd, pwd.c_str());
                new_user.type = 'U';
                insert_data(new_user);
            }else{
                qDebug() << "No existe el grupo";
            }
        }else{
            qDebug() << "Ya existe un usuario registrado con ese nombre";
        }
    }else {
        qDebug() << "Por falta de parametros no se puede crear el usuario";
    }
}

void User_Controller::rmusr_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_user_c = session;
    pm_user_c = part;
    string usr = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type, "-usr")){
            usr = children->at(i).node_value.toStdString();
        }
    }
    if(usr.size() > 10){
        usr = "";
        qDebug() << "parametro -usr sobrepasa los 10 caracteres";
    }
    if(usr != ""){
        if(search_usr_grp(usr,"") != -1){
            rm_data(usr,"");
        }else{
           qDebug() << "No existe el usuario";
        }

    }else {
        qDebug() << "Por falta de parametros no se puede crear el usuario";
    }
}

void change_grp(string usr, string grp){
    int i_usr = search_usr_grp(usr,"");
    int i_grp = search_usr_grp("", grp);

    if(i_usr != -1){
        if(i_grp != -1){
           super_bloque sb;
           FILE * disk;
           if(disk = fopen(pm_user_c.path.c_str(), "rb+")){
               fseek(disk, pm_user_c.part_.part_start, SEEK_SET);
               fread(&sb, sizeof(super_bloque), 1,disk);
               fclose(disk);
               strcpy(sb.users_[i_usr].grp, sb.users_[i_grp].grp);
               create_blocks(sb);
               qDebug() << "Se cambio exitosamente el grupo del usuario: " << usr.c_str();
           }
        }else{
            qDebug() << "No existe el grupo: " <<grp.c_str();
        }
    }else{
        qDebug() << "No existe el usuario: " << usr.c_str();
    }

}

void User_Controller::chgrp_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_user_c = session;
    pm_user_c = part;
    qDebug() << pm_user_c.name.c_str();
    string usr = "",  grp = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type, "-usr")){
            usr = children->at(i).node_value.toStdString();
        }else if(compare_str(children->at(i).node_type, "-grp")){
            grp = children->at(i).node_value.toStdString();
        }
    }
    if(usr.size() > 10){
        usr = "";
        qDebug() << "parametro -usr sobrepasa los 10 caracteres";
    }
    if(grp.size() > 10){
        grp = "";
        qDebug() << "parametro -grp sobrepasa los 10 caracteres";
    }

    if(grp != "" && usr !=""){
        change_grp(usr,grp);
    }
}



