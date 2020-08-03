#include "login.h"

Login::Login()
{

}

user Login::login_(QList<AST_Node> *children,QList<Data_Mount>* list, Data_Mount* part_use){
    string id = "", path = "", part_name = "";
    user aux;
    char  user_name [10] = "", user_pwd [10] = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type, "-usr")){
            strcpy(user_name, children->at(i).node_value.toStdString().c_str());
        }else if(compare_str(children->at(i).node_type, "-pwd")){
            strcpy(user_pwd, children->at(i).node_value.toStdString().c_str());
        }else if(compare_str(children->at(i).node_type, "-id")){
            id = children->at(i).node_value.toStdString();
        }
    }
    if(user_name == ""){}
    if(user_pwd == ""){}
    if(id == ""){}

    if(user_name != "" && user_pwd != "" && id != ""){
        for(int i = 0; i < list->size(); i++){
            if(list->at(i).id == id){
                path = list->at(i).path;
                part_name = list->at(i).name;
                part_use->count = list->at(i).count;
                part_use->id = list->at(i).id;
                part_use->name = list->at(i).name;
                part_use->path = list->at(i).path;
                part_use->part_ = list->at(i).part_;
                break;
            }
        }
        FILE * disk;
        mbr mbr_disk;
        super_bloque sb;
        int part_start = 0;

        if(disk = fopen(path.c_str(),"rb+")){
            fseek(disk,0,SEEK_SET);
            //obtenes el disco
            fread(&mbr_disk,sizeof (mbr), 1,disk);
            for(int i = 0; i < 4; i++){
                if(mbr_disk.partitions[i].part_name == part_name){
                    part_start = mbr_disk.partitions[i].part_start;
                }
            }
            fseek(disk, part_start,SEEK_SET);
            fread(&sb,sizeof(super_bloque),1,disk);

//********************** 333 numero estatico de usuarios que se pueden guardar

            for(int i = 0; i < 333; i++){
                if(sb.users_[i].type == 'U'){
                    if(qstrcmp(sb.users_[i].n_pwd,user_pwd) == 0 &&
                        qstrcmp(sb.users_[i].n_user, user_name) == 0){

                            return sb.users_[i];
                    }
                }
            }
        }

    }
    return aux;
}
