#include "mkdisk_controller.h"

MkDisk_Controller::MkDisk_Controller()
{

}
bool exist_first_logic(string path){
    FILE * file_mkdisk;
    emb logic;
    try{
        if(file_mkdisk = fopen(path.c_str(),"rb+")){
            fseek(file_mkdisk,sizeof(struct mbr),SEEK_SET);
            fread(&logic,sizeof(struct emb),1,file_mkdisk);
            fclose(file_mkdisk);
            if(logic.part_size > 0){
                return true;
            }

        }
    }catch(exception e){

    }
    return false;
}
//metodo que crea un directorio si no existe
void MkDisk_Controller::create_directory(QString dir){
    int result;
    QString path = "";
    QList<QString> dirs =dir.split("/");
    for(int d = 0; d < dirs.size()-1; d++){
        path += "/" + dirs.at(d);
    }
    result = mkdir(path.toStdString().c_str(),0777);
}

int search_free(mbr mbr_disk){
    for(int i = 0; i < 4; i++){
        if(mbr_disk.partitions[i].part_size == -1){
            return i;
        }
    }
    return 100;
}

int search_enable(mbr mbr_disk, char status){
    for(int i = 0; i < 4; i++){
        if(mbr_disk.partitions[i].part_status == status){
            return i;
        }
    }
    return 100;
}

int calculate_start(mbr mbr_disk){
    int suma = sizeof (mbr_disk);
    for(int i = 0; i < 4; i++){
        if(mbr_disk.partitions[i].part_size != -1){
            suma += mbr_disk.partitions[i].part_size;
        }
    }
    return suma;
}

int search_extend(mbr mbr_disk){
    int val = -1;
    for(int i = 0; i < 4; i++){
        if(mbr_disk.partitions[i].part_size != -1){
           if(mbr_disk.partitions[i].part_type == 'e' || mbr_disk.partitions[i].part_type == 'E'){
                if(mbr_disk.partitions[i].part_status == 'e'){
                    val = i;
                }
            }
        }
    }
    return val;
}

int search_partition_pe(mbr mbr_disk, string name, char status){
    for(int i = 0; i < 4; i++){
        if(status == ' '){
            if(mbr_disk.partitions[i].part_name == name){
                return  i;
            }
        }else if(status == 'e'){
            if(mbr_disk.partitions[i].part_name == name && mbr_disk.partitions[i].part_status == 'e'){
                return  i;
            }
        }else if(status == 'd'){
            if(mbr_disk.partitions[i].part_name == name && mbr_disk.partitions[i].part_status == 'd'){
                return  i;
            }
        }

    }
    return -1;
}



//Metodo que calcula el size del disco, dependiendo si es en kilo o mega
int calculate_size(char dim, int val){
    if(dim == 'B' || dim == 'b'){//Bytes default
        return  val;
    }else if(dim == 'K' || dim == 'k'){//Kilobytes
        return val * 1024;
    }else if(dim == 'M' || dim == 'm'){//Megabytes
       return val * 1024 * 1024;
    }
    return -1;
}
//metodo que crea el archivo binario que simulara el disco
void MkDisk_Controller::create_disk(QList<AST_Node> *children){
    bool is_size = false, is_path = false, is_fit = false, is_unit = false;
    int  size = 0;
    QString fit_init = "", unit_init = "", path_raid = "";
    char fit = 'f', unit  = 'm';
    string path = "";
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);

    for(int c = 0; c < children->size(); c++){
        if(compare_str(children->at(c).node_type,"-size")){
            is_size = true;
            size = children->at(c).node_value.toInt();
        }else if(compare_str(children->at(c).node_type,"-fit")){
            fit_init = children->at(c).node_value;
            is_fit = true;
        }else if(compare_str(children->at(c).node_type,"-unit")){
            unit_init = children->at(c).node_value;
            is_unit = true;
        }else if(compare_str(children->at(c).node_type,"-path")){
            is_path = true;
            path = children->at(c).node_value.toStdString();
            path_raid = children->at(c).node_value;
            create_directory(children->at(c).node_value);
        }
    }    
    if(is_fit){
        if((compare_str(fit_init,"bf") || compare_str(fit_init,"ff") || compare_str(fit_init,"wf"))){
            fit = fit_init.toStdString().at(0);
        }else{
            fit = ' ';
            qDebug()<< "Para el parametro -fit no existe el valor: "<< fit_init;
        }
    }
    if(is_unit){
        if((compare_str(unit_init,"b") ||  compare_str(unit_init,"m") || compare_str(unit_init,"k"))){
            unit = unit_init.toStdString().at(0);
        }else{
            unit = ' ';
            qDebug()<< "Para el parametro -unit no existe el valor: "<< unit_init;
        }
    }
    size = calculate_size(unit,size);
    if(size <= 0){qDebug()<< "No se puede crear el disco, el parametro -size <= 0";}
    if(!is_path){qDebug()<< "No se puede crear el disco, falta el parametro -path";}
    if(!is_size){qDebug()<< "No se puede crear el disco, falta el parametro -size";}


    if(is_size && is_path && size > 0 && fit != ' ' && unit != ' '){
        int random = rand();
        mbr data;
        data.disk_fit = fit;
        data.mbr_tamano = data.mbr_tamano_available = size;
        //data.mbr_fecha_creacion = nowLocal;
        data.mbr_disk_signature = random;
        FILE * disk =fopen(path.c_str(),"wb");
        if(disk == NULL){
            qDebug()<<"Error";
        }
            fseek(disk,size,SEEK_SET);
            fwrite("",1,1,disk);
            fclose(disk);

            disk=fopen(path.c_str(),"rb+");
            fseek(disk,0,SEEK_SET);
            fwrite(&data,sizeof(struct mbr),1,disk);

            emb logic;
            logic.part_status = ' ';
            logic.part_size = -1;
            logic.part_size_available = -1;
            logic.part_next = -1;

            fseek(disk, sizeof(mbr), SEEK_SET);
            fwrite(&logic,sizeof (emb),1,disk);
            fclose(disk);

            path_raid.replace(".disk", "raid.disk");

            disk = fopen(path_raid.toStdString().c_str(), "wb");fseek(disk,size,SEEK_SET);
            fwrite("",1,1,disk);
            fclose(disk);

            disk=fopen(path.c_str(),"rb+");
            fseek(disk,0,SEEK_SET);
            fwrite(&data,sizeof(struct mbr),1,disk);
            fclose(disk);

    }else{
        qDebug() << "No fue posible crear el disco";
    }

}

void MkDisk_Controller::remove_disk(QList<AST_Node> *children){
    QString dir = "";
    for (int c = 0; c < children->size(); c++) {
        if(compare_str(children->at(c).node_type,"-path")){
            dir = children->at(c).node_value;
        }
    }
    if(dir != ""){
        FILE * del;
        if(del = fopen(dir.toStdString().c_str(), "rb")){
            qDebug() << "Desea eliminar el disco   (y/n)";
            QTextStream qtin(stdin);
            QString ent = qtin.readLine();
            if(ent == "y"){
                remove(dir.toStdString().c_str());
                qDebug() << "se elimino correctamente el disco";

            }
        }else{
            qDebug() << "No se elimino correctamente el disco";
        }
    }

}
void set_zero(string path){
    FILE * file_delete;
    emb logic;
    if(file_delete = fopen(path.c_str(), "rb+")){
        int val  = sizeof(mbr);
        int sig = 0;
        while(sig != -1){
            fseek(file_delete, val, SEEK_SET);
            fread(&logic,sizeof(struct emb),1,file_delete);
            sig = logic.part_next;

            logic.part_status = ' ';
            logic.part_size = -1;
            logic.part_size_available = -1;
            logic.part_next = -1;

            fseek(file_delete, val, SEEK_SET);
            fwrite(&logic,sizeof (emb),1,file_delete);
            val = val + sizeof(emb);
        }
        fclose(file_delete);

   }else{
        qDebug() << "No se pudo abrir el disco";
    }
}

void delete_pe(string path, string name){
    mbr mbr_disk;
    FILE * file_mkdisk;
    int part;
    if((file_mkdisk = fopen(path.c_str(),"rb+"))){
        fseek(file_mkdisk,0,SEEK_SET);
        //obtenes el disco
        fread(&mbr_disk,sizeof (mbr), 1,file_mkdisk);
        part = search_partition_pe(mbr_disk, name, 'e');
        if(part != -1){
            qDebug() << "Desea eliminar la particion   (y/n)";
            QTextStream qtin(stdin);
            QString ent = qtin.readLine();
            if(ent == "y"){
                mbr_disk.partitions[part].part_size_available =mbr_disk.partitions[part].part_size;
                mbr_disk.partitions[part].part_status = 'd';

                fseek(file_mkdisk,0,SEEK_SET);//puntero en la posicion 0
                fwrite(&mbr_disk,sizeof (mbr),1,file_mkdisk);
                fclose(file_mkdisk);
                if(mbr_disk.partitions[part].part_type == 'e'){
                    set_zero(path);
                }
                qDebug() << "Se elimino la particion ";
            }else{
                qDebug() << "No se elimino la particion ";
            }
        }else{
            qDebug() << "No se encontro la particion";
        }
    }else{
         qDebug() << "No se pudo abrir el disco";
    }
    fclose(file_mkdisk);

}

void MkDisk_Controller::add_logic(string path, int add, string name){
    if(exist_first_logic(path)){
        int logic = search_logic(path,name,'e');
        if(logic != -1){
            emb emb_logic;
            FILE * file_logic;

            if((file_logic = fopen(path.c_str(),"rb+"))){
                fseek(file_logic,logic,SEEK_SET);
                fread(&emb_logic,sizeof (emb), 1,file_logic);

                if(add > 0){
                    if(emb_logic.part_size_available + add <= emb_logic.part_size){
                        emb_logic.part_size_available +=add;
                    }else{
                        qDebug() << "No se puede agregar, sobrepasa el size total";
                    }
                }else{

                    if(emb_logic.part_size_available + add >= 0){
                        emb_logic.part_size_available -=emb_logic.part_size_available + add;
                    }else{
                        qDebug() << "No se puede quitar, resultado < 0";

                    }
                }
                fseek(file_logic,logic,SEEK_SET);
                fwrite(&emb_logic,sizeof (emb), 1,file_logic);
                fclose(file_logic);

            }
        }
    }
}


void add_pe(string path, int add, string name){
    mbr mbr_disk;
    FILE * file_mkdisk;

    if((file_mkdisk = fopen(path.c_str(),"rb+"))){
        fseek(file_mkdisk,0,SEEK_SET);
        fread(&mbr_disk,sizeof (mbr), 1,file_mkdisk);

        int px = search_partition_pe(mbr_disk, name,'e');
        if(px != -1){
            if(add > 0){
                if(mbr_disk.partitions[px].part_size_available + add <= mbr_disk.partitions[px].part_size){
                    mbr_disk.partitions[px].part_size_available +=add;
                }else{
                    qDebug() << "No se puede agregar, sobrepasa el size total";
                }
            }else{

                if(mbr_disk.partitions[px].part_size_available + add >= 0){
                    mbr_disk.partitions[px].part_size_available -= mbr_disk.partitions[px].part_size_available + add;
                }else{
                    qDebug() << "No se puede quitar, resultado < 0";
                }
            }
            fseek(file_mkdisk,0,SEEK_SET);
            fwrite(&mbr_disk,sizeof (mbr), 1,file_mkdisk);
        }

    }
    fclose(file_mkdisk);
}

//metodo para crear una particion primaria
void MkDisk_Controller::create_partition(QList<AST_Node> *children){

    char type = 'p', unit = 'b', fit  = 'w';
    int size = 0, add = 0;
    bool is_size = false, is_path = false, is_name = false, is_fit= false, is_unit = false , is_type = false;
    QString fit_init = "", unit_init = "", type_init = "",p_delete = "";
    string path = "",  name = "";
    for(int c = 0;c < children->size(); c++){
        if(compare_str(children->at(c).node_type,"-size")){
            is_size = true;
            size = children->at(c).node_value.toInt();
        }else if(compare_str(children->at(c).node_type,"-unit")){
            unit_init = children->at(c).node_value;
            is_unit = true;
        }else if(compare_str(children->at(c).node_type,"-path")){
            is_path = true;
            path = children->at(c).node_value.toStdString();
        }else if(compare_str(children->at(c).node_type,"-type")){
            type_init = children->at(c).node_value;
            is_type = true;
        }else if(compare_str(children->at(c).node_type,"-fit")){
            fit_init = children->at(c).node_value;
            is_fit = true;
        }else if(compare_str(children->at(c).node_type,"-delete")){
            p_delete = children->at(c).node_value;
        }else if(compare_str(children->at(c).node_type,"-name")){
            name = children->at(c).node_value.toStdString();
            is_name = true;
        }else if(compare_str(children->at(c).node_type,"-add")){
            add = children->at(c).node_value.toInt();
        }
    }
    if(p_delete != ""){
        if(!compare_str(p_delete,"fast") && !compare_str(p_delete,"full")){
            qDebug()<< "Para el parametro -delete no existe el valor: "<< p_delete;
            p_delete = "";
        }
    }

    if(is_fit){
        if((compare_str(fit_init,"bf") || compare_str(fit_init,"ff") || compare_str(fit_init,"wf"))){
            fit = fit_init.toStdString().at(0);
        }else{
            fit = ' ';
            qDebug()<< "Para el parametro -fit no existe el valor: "<< fit_init;
        }
    }

    if(is_unit){
        if((compare_str(unit_init,"b") || compare_str(unit_init,"k") || compare_str(unit_init,"m"))){
            unit = unit_init.toStdString().at(0);
        }else{
            unit = ' ';
            qDebug()<< "Para el parametro -unit no existe el valor: "<< unit_init;
        }
    }

    if(is_type){
        if((compare_str(type_init,"p") || compare_str(type_init,"l") || compare_str(type_init,"e"))){
            type = type_init.toStdString().at(0);
        }else{
            type = ' ';
            qDebug()<< "Para el parametro -type no existe el valor: "<< type_init;
        }
    }

    if(!is_size && p_delete == "" && add == 0){qDebug()<< "No se puede crear la particion, falta el parametro -size";}
    if(!is_name){qDebug()<< "No se puede crear la particion, falta el parametro -name";}
    if(!is_path){qDebug()<< "No se puede crear la particion, falta el parametro -path";}
    if(size <= 0 && p_delete == "" && add == 0){qDebug()<< "No se puede crear la particion, el parametro -size <= 0";}

    bool status = false;
    if(add != 0){//agregando o quitando tamanio
        if(is_path && is_name && unit != ' '){
            add = calculate_size(unit, add);
            add_logic(path,add,name);
            add_pe(path,add,name);

        }
    } if(p_delete != "" && is_name && is_path){//eliminando particion
         delete_pe(path,name);
         delete_logic(path,name);
    }
    if(p_delete == "" && add == 0 && is_size && is_name && is_path && size >0 && type != ' ' && unit != ' ' && fit != ' '){//creando particion
        size = calculate_size(unit,size);
        if(type == 'p' || type == 'P'){
            create_pe_partition(fit,size,type,name,path);
        }else if(type == 'e' || type == 'E'){
            create_pe_partition(fit,size,type,name,path);
        }else if(type == 'l' || type == 'L'){
            create_logic_partition(fit,size,name,path);
        }
    }else if(p_delete =="" || add == 0){

        qDebug() << "No fue posible crear la particion";
    }

}


int set_primary_extend(mbr mbr_disk, char sett, int size){
    part tmp;
    part list_aux[4];
    int valor = -1;
    for(int i = 0; i < 4; i++){
        if(mbr_disk.partitions[i].part_status == 'd'){
            strcpy(list_aux[i].part_name,mbr_disk.partitions[i].part_name);
            list_aux[i].part_size = mbr_disk.partitions[i].part_size;
        }
    }
    if(sett == 'f' || sett == 'F'){
        for(int i = 0; i < 4; i++){
            if(mbr_disk.partitions[i].part_status =='d'){
                if(mbr_disk.partitions[i].part_size >= size){
                    return i;
                }
            }

        }
    }else{
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(list_aux[j].part_size > list_aux[j + 1].part_size){
                    tmp = list_aux[j];
                    list_aux[j] = list_aux[j + 1];
                    list_aux[j + 1] = tmp;
                }
            }
        }
        tmp.part_size = -1;

        if(sett == 'b' || sett == 'B'){
            for(int i = 0; i < 4; i++){
                if(list_aux[i].part_size >= size){
                    tmp = list_aux[i];
                    i =4;
                }
            }
        }else{
            for(int i = 3; i >=0; i--){
                if(list_aux[i].part_size >= size){
                    tmp = list_aux[i];
                    i =-1;
                }
            }
        }

        if(tmp.part_size != -1){
            valor = search_partition_pe(mbr_disk,tmp.part_name, ' ');
        }
    }
    return valor;
}


//metodo para crear particion primaria o extendida
void MkDisk_Controller::create_pe_partition(char fit, int size, char type,string name,string path){
    mbr mbr_disk;
    FILE * file_mkdisk;
    bool create = false;

    if((file_mkdisk = fopen(path.c_str(),"rb+"))){
        // te colocas en la posicion 0->SEEK_SET
        fseek(file_mkdisk,0,SEEK_SET);
        //obtenes el disco
        fread(&mbr_disk,sizeof (mbr), 1,file_mkdisk);

        int p_work = search_free(mbr_disk);//buscando una libre
        if(p_work == 100){
            p_work = search_enable(mbr_disk,'d');//buscando particion deshabilitada
            if(p_work != 100){
                p_work = search_partition_pe(mbr_disk,name,'e');
                if(p_work == -1){
                    p_work = set_primary_extend(mbr_disk,fit,size);
                    if(p_work != -1){
                        mbr_disk.partitions[p_work].part_size_available -= size;
                        mbr_disk.partitions[p_work].part_status = 'e';
                        strcpy(mbr_disk.partitions[p_work].part_name,name.c_str());
                        create  =true;
                    }else{
                         qDebug() << "No se puede crear la particion, no hay particion donde trabajar";
                        create = false;
                    }
                }else{
                    qDebug() << "Ya existe la particion";
                    create = false;
                }

               }else{
                qDebug() << "No se puede crear la particion, numero maximo creado";
            }
        }else{
            if(search_partition_pe(mbr_disk,name,'e') != -1){
                create = false;
                qDebug() << "Ya existe la particion";
            }else{
                if(mbr_disk.mbr_tamano_available >= size){
                    int start = calculate_start(mbr_disk);
                    mbr_disk.partitions[p_work].part_fit = fit;
                    mbr_disk.partitions[p_work].part_status = 'e';
                    mbr_disk.partitions[p_work].part_size = mbr_disk.partitions[p_work].part_size_available = size;
                    mbr_disk.partitions[p_work].part_start = start;
                    mbr_disk.mbr_tamano_available -=size;
                    strcpy( mbr_disk.partitions[p_work].part_name,name.c_str());
                    create = true;
                    if(type == 'e' || type == 'E' ){//validar qeue no haya mas de 1 extendida
                        if(search_extend(mbr_disk) == -1){
                            create = true;
                        }else{
                            create = false;
                            qDebug() << "No es posible crear la particion, ya existe una extendida";
                        }
                    }
                    mbr_disk.partitions[p_work].part_type = type;

                }else{
                    qDebug() << "No hay espacio suficiente para crear la particion";
                    create = false;
                }

            }


        }
        if(create){
            fseek(file_mkdisk,0,SEEK_SET);//puntero en la posicion 0
            fwrite(&mbr_disk,sizeof (mbr),1,file_mkdisk);
            fclose(file_mkdisk);
        }
    }else{
        qDebug() << "No fue posible abrir el disco";
    }
}


int last_logic(string path){
    FILE * file_mkdisk;
    emb logic;
    int val = sizeof(struct mbr);
    while(logic.part_next != -1){
        file_mkdisk = fopen(path.c_str(),"rb+");
        fseek(file_mkdisk,val ,SEEK_SET);
        fread(&logic,sizeof(struct emb),1,file_mkdisk);
        fclose(file_mkdisk);
        val += sizeof(struct emb);
    }
    val -=sizeof(struct emb);
    return val;
}

int MkDisk_Controller::search_logic(string path, string name, char status){
    FILE * file_mkdisk;
    int val = sizeof(struct mbr);
    emb logic;
    while(logic.part_next != -1){
        file_mkdisk = fopen(path.c_str(),"rb+");
        fseek(file_mkdisk,val ,SEEK_SET);
        fread(&logic,sizeof(struct emb),1,file_mkdisk);
        fclose(file_mkdisk);
        if(logic.part_name == name && status == ' '){
            return val;
        }else if(status == 'e'){
            if(logic.part_name == name && logic.part_status == 'e'){
                return val;
            }
        }if(status == 'd'){
            if(logic.part_name == name && logic.part_status == 'd'){
                return val;
            }
        }
        val += sizeof(struct emb);
    }
    return -1;
}

int MkDisk_Controller::set_logics(QList<emb> list, char fit, int size, string path){
    QList<emb> tmp;
    string name= "";
    for(int i = 0; i < list.size(); i++){
        tmp.append(list.at(i));
    }
    if(fit == 'f' || fit=='F'){
        for(int i = 0; i < list.size(); i++){
            if(list.at(i).part_size >= size){
                name = list.at(i).part_name;
            }
        }
    }else{
        emb aux;
        for (int i = 0; i < tmp.size(); i++) {
            for (int j = 0; j < tmp.size() - 1; j++) {
                if(tmp.at(j).part_size > tmp.at(j + 1).part_size){
                    aux = tmp[j];
                    tmp[j] = tmp[j + 1];
                    tmp[j + 1] = aux;
                }
            }
        }
        if(fit == 'b' || fit == 'B'){
            for (int j = 0; j < tmp.size(); j++) {
                if(tmp.at(j).part_size >= size){
                    name = list.at(j).part_name;
                }
            }
        }else{
            for (int j = tmp.size() - 1; j >= 0; j--) {
                if(tmp.at(j).part_size >= size){
                    name = list.at(j).part_name;
                }
            }
        }
    }
    if(name != ""){
        return search_logic(path,name,' ');
    }
    return -1;
}

QList<emb> MkDisk_Controller:: all_logic(string path, char status){
    QList<emb> list;
    if(exist_first_logic(path)){
        FILE * file_mkdisk;
        int val = sizeof(struct mbr);
        emb logic;
        while(logic.part_next != -1){
            file_mkdisk = fopen(path.c_str(),"rb+");
            fseek(file_mkdisk,val ,SEEK_SET);
            fread(&logic,sizeof(struct emb),1,file_mkdisk);
            fclose(file_mkdisk);
            if(status == ' ' && logic.part_size > 0){
                list.append(logic);
            }
            if(logic.part_status == status){
                list.append(logic);
            }


            val += sizeof(struct emb);
        }
    }

    return list;
}

void MkDisk_Controller::delete_logic(string path, string name){
    int init_search = search_logic(path,name,'e');
    if(init_search != -1){
        FILE * file_delete;
        emb logic;
        if(file_delete = fopen(path.c_str(), "rb+")){
            qDebug() << "Desea eliminar la particion   (y/n)";
            QTextStream qtin(stdin);
            QString ent = qtin.readLine();
            if(ent == "y"){
                fseek(file_delete, init_search, SEEK_SET);
                fread(&logic,sizeof(struct emb),1,file_delete);
                logic.part_status = 'd';
                logic.part_size_available = logic.part_size;

                fseek(file_delete, init_search, SEEK_SET);
                fwrite(&logic,sizeof (emb),1,file_delete);

            }
            fclose(file_delete);


       }else{
            qDebug() << "No se pudo abrir el disco";
        }

    }else{
        qDebug() << "No se encontro la particion logica";
    }
}

void MkDisk_Controller::create_logic_partition(char fit, int size,string name, string path){
    FILE * file_mbr;
    mbr mbr_disk;
    emb logic;
    int init_logic = 0;
    if(file_mbr = fopen(path.c_str(),"rb+")){
        fseek(file_mbr,0,SEEK_SET);
        //obtenes el disco
        fread(&mbr_disk,sizeof (mbr), 1,file_mbr);
        fclose(file_mbr);
        int ext = search_extend(mbr_disk);

        bool create = false;
        if(ext != -1){
            if(search_logic(path,name,'e') == -1){
                int size_ext = mbr_disk.partitions[ext].part_size;
                int size_av_ext = mbr_disk.partitions[ext].part_size_available;
                logic.part_fit = fit;
                logic.part_next = -1;
                logic.part_size = size;
                logic.part_status = 'e';
                logic.part_size_available = size;
                strcpy(logic.part_name,name.c_str());
                if(!exist_first_logic(path)){
                    if(size_av_ext >= size){
                        init_logic = sizeof (mbr);
                        logic.part_start = mbr_disk.partitions[ext].part_start;
                        mbr_disk.partitions[ext].part_size_available -= size;
                        create = true;
                    }else{
                        qDebug() << "No hay espacio disponible";
                    }

                }else{

                    QList<emb> list_all_logic = all_logic(path,'d');
                    if(list_all_logic.size() > 0){
                        //aplicaremos ajustes
                        init_logic = set_logics(list_all_logic,fit,size,path);
                        FILE * file_set;
                        emb emb_set;
                        file_set = fopen(path.c_str(),"rb+");
                        fseek(file_set,init_logic,SEEK_SET);
                        fread(&emb_set,sizeof (emb), 1,file_set);
                        fclose(file_set);
                        emb_set.part_size_available -= size;
                        emb_set.part_status = 'e';
                        strcpy(emb_set.part_name,name.c_str());

                        file_set = fopen(path.c_str(),"rb+");
                        fseek(file_set,init_logic,SEEK_SET);
                        fwrite(&emb_set,sizeof (emb), 1,file_set);
                        fclose(file_set);

                        create = false;
                    }else{
                        //agregando ultima
                        int last_ptr = last_logic(path);
                        if(size_av_ext >= size){
                            FILE * file_ls;
                            emb emb_ls;
                            file_ls = fopen(path.c_str(),"rb+");
                            fseek(file_ls,last_ptr,SEEK_SET);
                            fread(&emb_ls,sizeof (emb), 1,file_ls);
                            fclose(file_ls);

                            emb_ls.part_next = emb_ls.part_size;
                            file_ls = fopen(path.c_str(),"rb+");
                            fseek(file_ls,last_ptr,SEEK_SET);
                            fwrite(&emb_ls,sizeof (emb), 1,file_ls);
                            fclose(file_ls);
                            init_logic = last_ptr + sizeof (emb);

                            logic.part_start = emb_ls.part_start + emb_ls.part_size;
                            mbr_disk.partitions[ext].part_size_available -= size;
                            create = true;

                        }
                    }
                }
                if(create){
                    FILE * file_add;
                    file_add = fopen(path.c_str(),"rb+");
                    fseek(file_add,init_logic,SEEK_SET);
                    fwrite(&logic,sizeof (emb), 1,file_add);
                    fclose(file_add);

                    file_mbr = fopen(path.c_str(),"rb+");
                    fseek(file_mbr,0,SEEK_SET);
                    fwrite(&mbr_disk,sizeof (mbr), 1,file_mbr);
                    fclose(file_mbr);

                }else{
                    qDebug() << "No se puedo crear";
                }
            }else{
                qDebug() << "Ya existe una particion con ese nombre";
            }

        }else{
            qDebug() << "No existe la particion extendida";
        }
    }else{
        qDebug() << "No se puede abrir el archivo";
    }
}



