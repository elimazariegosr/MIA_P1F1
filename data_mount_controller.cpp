#include "data_mount_controller.h"

Data_Mount_Controller::Data_Mount_Controller()
{

}
int count_create = 0;
bool exist_mount(QList<Data_Mount> *list, string path, string name){
    for (int l = 0; l < list->size(); l++) {
        return list->at(l).name == name && list->at(l).path == path;
    }
    return false;
}

Data_Mount exist_disk_mount (QList<Data_Mount> *list, string path){
    Data_Mount val;
    val.letter = -1;
    for (int l = 0; l < list->size(); l++) {
        if(list->at(l).path == path){
            val = list->at(l);
        }
    }
    return val;
}
part search_pe(mbr mbr_disk, string name){
    part pp;
    pp.part_start = -2;
    for(int i = 0; i < 4; i++){
        if(mbr_disk.partitions[i].part_name == name){
            return mbr_disk.partitions[i];
        }
    }
    return pp;
}

void Data_Mount_Controller::unmount(QList<Data_Mount> *list,QList<AST_Node> * children){
    string id = "";
    for(int c = 0; c < children->size(); c++){
        if(mk.compare_str(children->at(c).node_type, "-id")){
            id = children->at(c).node_value.toStdString();
        }
    }
    if(id != ""){
        bool del = false;
        for(int l = 0; l < list->size(); l++){
            if(list->at(l).id == id){
                list->removeAt(l);
                del = true;
                break;
            }
        }
        if(!del){
            qDebug() << "No se encontro el nombre buscado";
        }
    }else{
        qDebug() << "parametro invalido";
    }
}

void Data_Mount_Controller::moount(QList<Data_Mount> *list,QList<AST_Node>* children){

    bool is_name = false, is_path = false;
    string name = "",path = "";
    for(int c = 0; c < children->size(); c++){
        if(mk.compare_str(children->at(c).node_type, "-name")){
            is_name = true;
            name = children->at(c).node_value.toStdString();
        }else if(mk.compare_str(children->at(c).node_type, "-path")){
            is_path = true;
            path = children->at(c).node_value.toStdString();
        }
    }
    if(is_path && is_name){
        Data_Mount dc = exist_disk_mount(list,path);
        char letters [100]= "abcdefghijklmnopqrstuvwxyz";
        QString id = "vd";
        int letter = 0;
        int count = 0;
        if(dc.letter != -1){
            count = dc.count + 1;
            letter   = dc.letter;
            id = id + letters[dc.letter];
            id = id + QVariant(count).toString();
        }else{
            id = id + letters[count_create];
            id = id + QVariant(1).toString();
            count = 1;
            letter = count_create;
            count_create++;
        }

        qDebug() << id;



        mbr mbr_disk;
        FILE * file_mkdisk;
        part part_;

        if((file_mkdisk = fopen(path.c_str(),"rb+"))){
            // te colocas en la posicion 0->SEEK_SET

            fseek(file_mkdisk,0,SEEK_SET);
            //obtenes el disco
            fread(&mbr_disk,sizeof (mbr), 1,file_mkdisk);

            part_ = search_pe(mbr_disk,name);

                if(!exist_mount(list,path,name)){
                    if(part_.part_start != -2){
                        Data_Mount* data = new Data_Mount(id.toStdString(),path,name,part_);
                        data->letter = letter;
                        data->count = count;
                        list->append(*data);
                        qDebug() << "Se monto correctamente";
                        QString mont =  "rep -path=" + QString::fromUtf8(data->path.c_str()) + " -id=" + QString::fromUtf8(data->id.c_str());
                        qDebug() << mont;
                    }else{
                        // vamos a buscar logicas...
                       int logic =  mk.search_logic(path,name,'e');
                       emb emb_logic;
                       fseek(file_mkdisk,logic,SEEK_SET);
                       fread(&emb_logic,sizeof(emb),1,file_mkdisk);
                       if(emb_logic.part_name == name){
                           Data_Mount* data = new Data_Mount(id.toStdString(),path,name,part_);
                           data->letter = letter;
                           data->count = count;
                           list->append(*data);
                           qDebug() << "Se monto correctamente";
                           QString mont =  "rep -path=" + QString::fromUtf8(data->path.c_str()) + " -id=" + QString::fromUtf8(data->id.c_str());
                           qDebug() << mont;
                       }else{
                           qDebug() << "No existe la particion buscada";
                        }
                    }
                }else{
                    qDebug() << "Ya esta montada la particion";
                }


        }else{
            qDebug() << "No es posible abrir el archivo";
        }
        fclose(file_mkdisk);
    }
}
