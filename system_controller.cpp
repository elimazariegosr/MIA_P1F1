#include "system_controller.h"

System_Controller::System_Controller()
{

}

Data_Mount part_mount;
user sesion_sys;
QList<inodo> inodo_list;
QList<bloque_apuntador> ptr_list;
QList<bloque_archivo> file_list;
QList<bloque_carpeta> dir_list;

bool have_perm = true;

time_t data_time(){
    time_t now = time(0);
    return now;
}
//retorna 2 lectura y escritura
//retorna 1 lectura
//retorna 0 nada
int permiso(inodo c_inodo){
    if(strcmp(sesion_sys.n_user, "root") == 0){
        return 2;
    }
    switch (c_inodo.i_perm) {
    case 777:
        return 2;
        break;
    case 666:
        return 2;
        break;
    case 755:
        if(strcmp(sesion_sys.n_user, c_inodo.n_user) == 0){
            return 2;
        }else{
            return 1;
        }
        break;
    case 644:
        if(strcmp(sesion_sys.n_user, c_inodo.n_user) == 0){
            return 2;
        }else{
            return 1;
        }
        break;
    case 700 :
        if(strcmp(sesion_sys.n_user, c_inodo.n_user) == 0){
            return 2;
        }else{
            return 0;
        }
        break;
    case 600:
        if(strcmp(sesion_sys.n_user, c_inodo.n_user) == 0){
            return 2;
        }else{
            return 0;
        }
        break;
    }
    return 0;
}
//obtener la ultima posicion
int last_start(int value){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        super_bloque sb;
        fseek(disk, part_mount.part_.part_start, SEEK_SET);
        fread(&sb, sizeof(super_bloque), 1, disk);
        if(value != -1){
            sb.s_start = value;
            fseek(disk, part_mount.part_.part_start, SEEK_SET);
            fwrite(&sb, sizeof(super_bloque), 1, disk);
        }
        fclose(disk);
        return sb.s_start;
     }
    return -1;
}

// metodo que obtiene el superbloque
super_bloque obt_superb(super_bloque sb_aux, int value){
    FILE * disk;
    super_bloque sb;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        fseek(disk, part_mount.part_.part_start, SEEK_SET);
        fread(&sb, sizeof(super_bloque), 1, disk);
        if(value == 1){
            sb = sb_aux;
            fseek(disk, part_mount.part_.part_start, SEEK_SET);
            fwrite(&sb, sizeof(super_bloque), 1, disk);
        }
        fclose(disk);
     }
    return sb;
}

//metodo que incrementa la cantidad de inodos
void incremet_nodo(int val){
    super_bloque sb = obt_superb(sb,0);
    sb.s_inodes_count += val;
    obt_superb(sb,1);
}
//metodo que incrementa la cantidad de bloques
void incremet_block(int val){
    super_bloque sb = obt_superb(sb,0);
    if(sb.s_blockes_count + val >= 0){
        sb.s_blockes_count += val;
    }
    obt_superb(sb,1);
}

//metodo que obtiene un inodo en una posicion indicada
inodo obt_inodo(int ptr){
    FILE * disk;
    inodo tmp;
    if(disk = fopen(part_mount.path.c_str(), "rb+")){
        fseek(disk, ptr,SEEK_SET);
        fread(&tmp, sizeof(inodo), 1, disk);
        fclose(disk);
    }
    return tmp;
}

//metodo que guarda un inodo en una posicion indicada
inodo save_inodo(inodo tmp){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(), "rb+")){
        fseek(disk, tmp.i_start,SEEK_SET);
        fwrite(&tmp, sizeof(inodo), 1, disk);
        fclose(disk);
    }
}

//metodo que guarda un bloque directo
void save_direct_block(int ptr, bloque_carpeta tmp){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(), "rb+")){
        fseek(disk, ptr,SEEK_SET);
        fwrite(&tmp, sizeof(bloque_carpeta), 1, disk);
        fclose(disk);
    }
}

//metodo que obtiene un bloque directo
bloque_carpeta obt_direct_block(int ptr){
    FILE * disk;
    bloque_carpeta tmp;
    if(disk = fopen(part_mount.path.c_str(), "rb+")){
        fseek(disk, ptr,SEEK_SET);
        fread(&tmp, sizeof(bloque_carpeta), 1, disk);
        fclose(disk);
    }
    return tmp;
}
//
void save_ptr_block(int ptr, bloque_apuntador tmp){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(), "rb+")){
        fseek(disk, ptr,SEEK_SET);
        fwrite(&tmp, sizeof(bloque_apuntador), 1, disk);
        fclose(disk);
    }
}

//
bloque_apuntador obt_ptr_block(int ptr){
    FILE * disk;
    bloque_apuntador tmp;
    if(disk = fopen(part_mount.path.c_str(), "rb+")){
        fseek(disk, ptr,SEEK_SET);
        fread(&tmp, sizeof(bloque_apuntador), 1, disk);
        fclose(disk);
    }
    return tmp;
}

//
bloque_archivo obt_file_block(int ptr){
    FILE * disk;
    bloque_archivo tmp;
    if(disk = fopen(part_mount.path.c_str(), "rb+")){
        fseek(disk, ptr,SEEK_SET);
        fread(&tmp, sizeof(bloque_archivo), 1, disk);
        fclose(disk);
    }
    return tmp;
}


//
void delete_bitmap_inodo(int pos){
    if(pos >= 0 && pos < 999){
        super_bloque sb;
        bitmap bm_inodo;
        sb = obt_superb(sb,0);
        FILE * disk;
        if(disk = fopen(part_mount.path.c_str(), "rb+")){
            fseek(disk, sb.s_bm_inode_start,SEEK_SET);
            fread(&bm_inodo, sizeof(bitmap), 1, disk);
            bm_inodo.map[pos] = 0;
            fseek(disk, sb.s_bm_inode_start,SEEK_SET);
            fwrite(&bm_inodo, sizeof(bitmap), 1, disk);
            fclose(disk);
        }
    }
}

//
void delete_bitmap_block(int pos){
    if(pos >= 0 && pos < 999){
        super_bloque sb;
        bitmap bm_block;
        sb = obt_superb(sb,0);
        FILE * disk;
        if(disk = fopen(part_mount.path.c_str(), "rb+")){
            fseek(disk, sb.s_bm_block_start,SEEK_SET);
            fread(&bm_block, sizeof(bitmap), 1, disk);
            bm_block.map[pos] = 0;
            fseek(disk, sb.s_bm_block_start,SEEK_SET);
            fwrite(&bm_block, sizeof(bitmap), 1, disk);
            fclose(disk);
        }

    }
}


void delete_bits(){
    for(int i = 0; i < inodo_list.size(); i++){
        if(inodo_list.at(i).i_type == 1){
            for(int j = 0; j < 12; j++){
                if(inodo_list.at(i).i_block[j] != -1){
                        bloque_archivo block;
                        block = obt_file_block(inodo_list.at(i).i_block[j]);
                        file_list.append(block);
                }
            }
        }
        delete_bitmap_inodo(inodo_list.at(i).pos - 1);
    }
    for(int i = 0; i < ptr_list.size(); i++){
        delete_bitmap_block(ptr_list.at(i).pos - 1);
    }
    for(int i = 0; i < dir_list.size(); i++){
        delete_bitmap_block(dir_list.at(i).pos - 1);
    }
    for(int i = 0; i < file_list.size(); i++){
        delete_bitmap_block(file_list.at(i).pos - 1);
    }
}

    //
int add_bitmap_block(){
    int valor = -1;
    super_bloque sb;
    bitmap bm_block;
    sb = obt_superb(sb,0);
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(), "rb+")){
        fseek(disk, sb.s_bm_block_start,SEEK_SET);
        fread(&bm_block, sizeof(bitmap), 1, disk);
        for(int i = 0; i < 999; i++){
            if(bm_block.map[i] == 0){
                bm_block.map[i] = 1;
                valor = i;
                break;
            }else if (bm_block.map[i] == -1){
                bm_block.map[i] = 1;
                valor = i;
                break;
            }
        }
        fseek(disk, sb.s_bm_block_start,SEEK_SET);
        fwrite(&bm_block, sizeof(bitmap), 1, disk);
        fclose(disk);
    }
    return valor;
}

//
int add_bitmap_inodo(){
    int valor = -1;
    super_bloque sb;
    bitmap bm_inodo;
    sb = obt_superb(sb,0);
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(), "rb+")){
        fseek(disk, sb.s_bm_inode_start,SEEK_SET);
        fread(&bm_inodo, sizeof(bitmap), 1, disk);
        for(int i = 0; i < 999; i++){
            if(bm_inodo.map[i] == 0){
                bm_inodo.map[i] = 1;
                valor = i;
                break;
            }else if (bm_inodo.map[i] == -1){
                bm_inodo.map[i] = 1;
                valor = i;
                break;
            }
        }
        fseek(disk, sb.s_bm_inode_start,SEEK_SET);
        fwrite(&bm_inodo, sizeof(bitmap), 1, disk);
        fclose(disk);
    }
    return valor;
}

// ****************** INICIA MKFS- formateo de particion ***********************************
//metodo que busca los parametros de mkfs
void System_Controller::format_mkfs(QList<AST_Node> *children, QList<Data_Mount> * mount_list){

    QString id = "", type = "fast";
    string name = "", path = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type,"-id")){
            id = children->at(i).node_value;
        }else if(compare_str(children->at(i).node_type,"-type")){
            type = children->at(i).node_value;
        }
    }
    if(type != ""){
        if(compare_str(type, "full")){
            type = "full";
        }else if(compare_str(type, "fast")){
            type = "fast";
        }else{
            type = "";
            qDebug() << "Solo se permiten los valores fast o full";
        }
    }
    if(id == ""){
        qDebug() << "Falta valor para el parametro -id";
    }

    for(int i  = 0; i < mount_list->size(); i++){
        if(mount_list->at(i).id == id.toStdString()){
            name = mount_list->at(i).name;
            path = mount_list->at(i).path;
        }
    }
    if(name != "" && path != "" && type != ""){
        FILE * disk;
        mbr data_mbr;
        int part_start = 0;
        if(disk = fopen(path.c_str(),"rb+")){
            fseek(disk,0,SEEK_SET);
            fread(&data_mbr, sizeof(mbr),1,disk);
            for(int i  = 0; i < 4; i++){
                if(data_mbr.partitions[i].part_name == name){
                    part_start = data_mbr.partitions[i].part_start;
                }
            }
            if(part_start != 0){
                bitmap bitmap_inode;
                bitmap  bitmap_block;
                for(int i = 0; i < 999; i++){
                     bitmap_inode.map[i] = bitmap_block.map[i] = -1;
                }
                bitmap_block.map[0] = 1;
                bitmap_block.map[1] = 1;
                bitmap_inode.map[0] = 1;
                bitmap_inode.map[1] = 1;


                journal journaling;
                inodo first_inodo, second_inodo;
                bloque_archivo first_file;
                content content_;
                bloque_carpeta first_root;
                user new_user;
                user new_group;
                super_bloque sb;

                for (int i = 0; i < 333;i++){
                    sb.users_[i].id = -1;
                    sb.users_[i].type = 'X';
                }

                for(int i = 0; i < 15; i++){
                    first_inodo.i_block[i] = -1;
                    second_inodo.i_block[i] = -1;
                }


// ***************** creacion de grupo root *******************
                strcpy(new_group.grp,"Root");
                new_group.type = 'G';
                new_group.id = 1;


// ***************** creacion de usuario root ******************
                strcpy(new_user.n_user,"root");
                strcpy(new_user.n_pwd,"123");
                strcpy(new_user.grp,"Root");
                new_user.id = 1;
                new_user.type = 'U';

// *****************Superbloque/ agregando el grupo y el usuario root ******************

                sb.users_[0] = new_group;
                sb.users_[1] = new_user;

                sb.s_block_size = sizeof(super_bloque);
                sb.s_inode_size = sizeof(inodo);



                int start_sb = part_start;

// ***************** Escribiendo journaling ******************
                part_start += sizeof(super_bloque);
                fseek(disk, part_start, SEEK_SET);
                fwrite(&journaling,sizeof (journal),1,disk);

// ***************** Escribiendo bitmap de inodos ******************

                part_start += sizeof(journal);
                sb.s_bm_inode_start = part_start;
                fseek(disk, part_start, SEEK_SET);
                fwrite(&bitmap_inode,sizeof (bitmap),1,disk);

// ***************** Escribiendo bitmap de bloques ******************
                part_start += sizeof(bitmap);
                sb.s_bm_block_start = part_start;
                fseek(disk, part_start, SEEK_SET);
                fwrite(&bitmap_block,sizeof (bitmap),1,disk);

//***************** creacioon de primer inodo carpeta root ****************
                part_start += sizeof(bitmap);
                sb.s_inode_start = part_start;
                first_inodo.pos = 0;
                first_inodo.i_type = 0;
                first_inodo.i_uid = new_user.id;
                first_inodo.i_gid = new_group.id;
                first_inodo.i_start = part_start;
                first_inodo.i_perm = 777;
                strcpy(first_inodo.name_inodo, "/");
                first_inodo.i_atime = data_time();//Última fecha en que se leyó el inodo sin modificarlo
                first_inodo.i_ctime = data_time();//Fecha en la que se creó el inodo
                first_inodo.i_mtime = data_time();//Úlitma fecha en la que se modificó el inodo
                first_inodo.i_block[0] = part_start + sizeof(inodo);

                fseek(disk, part_start, SEEK_SET);
                fwrite(&first_inodo,sizeof (inodo),1,disk);

//***************** creacioon de primer bloque para la carpeta root ****************
                part_start += sizeof(inodo);
                sb.s_block_start = part_start;
                first_root.b_content[0].b_inodo = part_start + sizeof(bloque_carpeta);
                strcpy(first_root.b_content[0].b_name,"users.txt");
                first_root.pos = 0;

                fseek(disk, part_start, SEEK_SET);
                fwrite(&first_root,sizeof (bloque_carpeta),1,disk);

//***************** creacioon de inodo para el archivo users.txt ****************
                part_start += sizeof(bloque_carpeta);
                strcpy(second_inodo.name_inodo,"users.txt");
                second_inodo.pos = 1;
                second_inodo.i_type = 1;
                second_inodo.i_uid = new_user.id;
                second_inodo.i_gid = new_group.id;
                strcpy(second_inodo.n_user, "root");
                strcpy(second_inodo.grp, "Root");
                second_inodo.i_start = part_start;
                second_inodo.i_perm = 777;
                second_inodo.i_atime = data_time();//Última fecha en que se leyó el inodo sin modificarlo
                second_inodo.i_ctime = data_time();//Fecha en la que se creó el inodo
                second_inodo.i_mtime = data_time();//Úlitma fecha en la que se modificó el inodo
                second_inodo.i_block[0] = part_start + sizeof(inodo);
                fseek(disk, part_start, SEEK_SET);
                fwrite(&second_inodo,sizeof (inodo),1,disk);

//***************** creacioon de bloque para el contenido del archivo users.txr ****************
                part_start += sizeof(inodo);
                strcpy(first_file.b_content, "1,G,root\n 1,U,root,root,123\n");
                first_file.pos = 1;
                fseek(disk, part_start, SEEK_SET);
                fwrite(&first_file,sizeof (bloque_archivo),1,disk);

                part_start += sizeof(bloque_archivo);

                sb.s_start = part_start;
                sb.s_blockes_count = 2;
                sb.s_inodes_count = 2;
                sb.s_free_blocks_count = 0;
                sb.s_free_inodes_count = 0;
                sb.s_first_blo = sb.s_firts_ino = 0;

                sb.s_umtime = data_time();
                sb.s_mtime = data_time();

                fseek(disk, start_sb, SEEK_SET);
                fwrite(&sb,sizeof (super_bloque),1,disk);

                fclose(disk);
                qDebug() << "Se formateo correctamente la particion";
            }
        }else{
            qDebug() << "No se puede abrir el archivo";
        }
    }else{
        qDebug() << "No se puede formatear la particion";
    }
}
// ********************* FINALIZA MKFS **************************************************************

// ********************* INICIA MKDIR ***************************************************************
//metodo que recorre el AST_Node(children) y busca los parametros del comando mkdir
void System_Controller::mkdir_command(QList<AST_Node> *children, user session, Data_Mount part){
    QString path_dir = "";
    sesion_sys = session;
    part_mount = part;
    bool is_p = false;
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type, "-path")){
            path_dir = children->at(i).node_value;
        }else if(compare_str(children->at(i).node_type, "-p")){
            is_p = true;
        }
    }
    if(path_dir != ""){

        path_dir = path_dir.replace("/home/eli/", "/home/");
        QList<QString> dirs = path_dir.split("/");
        dirs[0] = "/";
        create_dir(dirs, is_p,0, false);
    }
}

//buscando apuntador libre, retorna la posicion de 0 A 11
int searh_free_direct(inodo current_inodo){
    for(int i = 0; i <  12; i++){
        if(current_inodo.i_block[i] == -1){
            return i;
        }
    }
    return -1;
}
//buscando primer nodo, retorna un inodo ****** ROOT ************
    int first_inode(){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        super_bloque sb;
        fseek(disk, part_mount.part_.part_start, SEEK_SET);
        fread(&sb,sizeof(super_bloque),1,disk);
        fclose(disk);
        return sb.s_inode_start;
    }
}
//Metodo que crea un bloque simple indirecto
int create_sidirect_block(inodo c_inodo, int pos){
    int c_ptr = last_start(-1);
    bloque_apuntador block;
    block.pos = add_bitmap_block();

    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        //escribiendo el bloque
        for(int i = 0; i < 16; i++){block.b_pointers[i] = -1;}
        fseek(disk, c_ptr, SEEK_SET);
        fwrite(&block, sizeof(bloque_apuntador),1,disk);
        c_inodo.i_block[pos] = c_ptr;
        fseek(disk, c_inodo.i_start,SEEK_SET);
        fwrite(&c_inodo, sizeof(inodo),1,disk);
        fclose(disk);
        c_ptr += sizeof(bloque_apuntador);
        last_start(c_ptr);
        return c_inodo.i_block[pos];
    }
    return -1;
}


//Metodo que crea un bloque directo en un espacio libre, retorna su puntero...
int create_direct_block(inodo c_inodo){
    int start = searh_free_direct(c_inodo);
    bloque_carpeta new_block;
    new_block.pos = add_bitmap_block();
    if(start != -1){
        int c_ptr = last_start(-1);
        FILE * disk;
        if(disk = fopen(part_mount.path.c_str(),"rb+")){
            fseek(disk, c_ptr,SEEK_SET);
            fwrite(&new_block, sizeof(bloque_carpeta),1, disk);
            c_inodo.i_block[start] = c_ptr;
            fseek(disk,c_inodo.i_start,SEEK_SET);
            fwrite(&c_inodo, sizeof(inodo),1,disk);
            fclose(disk);
            c_ptr += sizeof(bloque_carpeta);
            last_start(c_ptr);
            return c_inodo.i_block[start];
        }
        fclose(disk);
    }
    return -1;
}

//metodo que busca una posicion libre dentro de un bloque de apuntadores, lee el bloque en la posicion ptr
int search_free_dindirect(int ptr){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        bloque_apuntador block;
        bloque_apuntador aux;
        fseek(disk,ptr,SEEK_SET);
        fread(&block,sizeof(bloque_apuntador),1,disk);
        for(int i = 0; i < 16; i++){
            if(block.b_pointers[i] != -1){
                fseek(disk,block.b_pointers[i], SEEK_SET);
                fread(&aux, sizeof(bloque_apuntador),1,disk);
                for(int j = 0; j < 16; j++){
                    if(aux.b_pointers[j] == -1){
                        fclose(disk);
                        return block.b_pointers[i];
                    }
                }
            }
        }
    }
    fclose(disk);
    return -1;

}

//metodo que busca un espacio libre en el puntero simple directo
int search_free_sindirect(int ptr){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        bloque_apuntador block;
        fseek(disk,ptr,SEEK_SET);
        fread(&block,sizeof(bloque_apuntador),1,disk);
        fclose(disk);
        for(int i = 0; i < 16; i++){
            if(block.b_pointers[i] == -1){
                return ptr;
            }
        }
    }
    return -1;
}

//Metodo que crea un apuntador indirecto dentro de otro indirecto(leido en la posicion "pos")
int create_dindirect_block(int pos){
    int c_ptr = last_start(-1);
    bloque_apuntador block, new_block;
    new_block.pos = add_bitmap_block();

    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        //escribiendo el bloque
        int x = -1;
        fseek(disk, pos, SEEK_SET);
        fread(&block, sizeof(bloque_apuntador),1,disk);
        for(int i = 0; i < 16; i++){
            new_block.b_pointers[i] = -1;
            if(block.b_pointers[i] == -1){
                if(x == -1){
                    x = i;
                }
            }
        }
        if(x != -1){
            block.b_pointers[x] = c_ptr;
            fseek(disk, pos, SEEK_SET);
            fwrite(&block, sizeof(bloque_apuntador),1,disk);
            fseek(disk, c_ptr, SEEK_SET);
            fwrite(&new_block, sizeof(bloque_apuntador),1,disk);
            fclose(disk);
            c_ptr +=sizeof(bloque_apuntador);
            last_start(c_ptr);
            return block.b_pointers[x];
        }

    }
    fclose(disk);
    return -1;
}



//buscando bloque con espacio libre, retorna el puntero del bloque
int search_block_free(inodo c_inodo){
    for(int i = 0; i < 12; i++){
        if(c_inodo.i_block[i] != -1){
            FILE * disk;
            bloque_carpeta block;
            if(disk = fopen(part_mount.path.c_str(),"rb+")){
                fseek(disk, c_inodo.i_block[i],SEEK_SET);
                fread(&block,sizeof(bloque_carpeta),1,disk);
                fclose(disk);
                for(int j = 0; j < 4; j++){
                    if(block.b_content[j].b_inodo == -1){
                        return c_inodo.i_block[i];
                    }
                }
            }
        }
    }
    return -1;
}

// busca el nombre de una carpeta en un bloque indirecto simple
int search_root_sindirect(int ptr_block, string name){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        fseek(disk, ptr_block, SEEK_SET);
        bloque_apuntador simple_ptr;
        fread(&simple_ptr, sizeof(bloque_apuntador), 1,disk);
        for(int i = 0;i < 16; i++){
            if(simple_ptr.b_pointers[i] != -1){
                inodo c_inodo;
                fseek(disk, simple_ptr.b_pointers[i], SEEK_SET);
                fread(&c_inodo, sizeof(inodo),1,disk);
                if(c_inodo.name_inodo == name){
                    fclose(disk);
                    return simple_ptr.b_pointers[i];
                }
            }
        }
    }
    return -1;
}
// busca el nombre de una carpeta en un bloque doble indirecto
int search_root_dindirect(int ptr_block, string name){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        fseek(disk, ptr_block, SEEK_SET);

        bloque_apuntador simple_ptr;
        fread(&simple_ptr, sizeof(bloque_apuntador), 1,disk);
        fclose(disk);
        for(int i = 0;i < 16; i++){
            if(simple_ptr.b_pointers[i] != -1){
                int ptr = search_root_sindirect(simple_ptr.b_pointers[i],name);
                if(ptr != -1){
                    return ptr;
                }
            }
        }
    }
    return -1;
}


// busca una carpeta en especifico de un inodo de tipo carpeta padre, retorna el apuntador del inodo
int search_root(inodo c_inodo, string name){
    for(int i = 0; i < 12; i++){
        if(c_inodo.i_block[i] != -1){
            FILE * disk;
            bloque_carpeta block;
            if(disk = fopen(part_mount.path.c_str(),"rb+")){
                fseek(disk, c_inodo.i_block[i],SEEK_SET);
                fread(&block,sizeof(bloque_carpeta),1,disk);
                fclose(disk);
                for (int j = 0; j < 4; j++) {
                    if(block.b_content[j].b_inodo != -1){
                        inodo c_inodo = obt_inodo(block.b_content[j].b_inodo);
                        if(c_inodo.name_inodo == name){
                            return c_inodo.i_start;
                        }
                    }

                }
            }
        }
    }

    // bloques indirectos...
    //simple indirercto
    int ptr = -1;
    if(c_inodo.i_block[12] != -1){
       ptr =  search_root_sindirect(c_inodo.i_block[12],name);
    }
    if(c_inodo.i_block[13] != -1){
       ptr =  search_root_dindirect(c_inodo.i_block[13],name);
    }
    return ptr;
}
//crea un inodo con un bloque directo
void create_inodo_with_path_block(int c_ptr, string name, int tipo){
    inodo new_inodo;
    bloque_carpeta new_block;
    new_block.pos = add_bitmap_block();
    new_inodo.pos = add_bitmap_inodo();;


    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        for(int i = 0; i < 15; i++){new_inodo.i_block[i] = -1;}
        //****************** agregando valores al nuevo inodo carpeta *************************

        strcpy(new_inodo.name_inodo,name.c_str());
        new_inodo.i_atime = data_time();
        new_inodo.i_ctime = data_time();
        new_inodo.i_mtime = data_time();
        new_inodo.i_size = 0;
        new_inodo.i_perm = 777;
        strcpy(new_inodo.grp,sesion_sys.grp);
        strcpy(new_inodo.n_user,sesion_sys.n_user);
        new_inodo.i_type = tipo;
        new_inodo.i_block[0] = c_ptr + sizeof(inodo);//agregando su primer block
        new_inodo.i_start = c_ptr;
        fseek(disk, c_ptr,SEEK_SET);
        fwrite(&new_inodo, sizeof(inodo),1,disk);//escribiendo el nuevo inodo

        // ****************** creando bloque para nuevo inodo ********************************
        c_ptr += sizeof(inodo);//incrementando la posicion
        fseek(disk,c_ptr,SEEK_SET);
        fwrite(&new_block, sizeof(bloque_carpeta),1,disk);
        fclose(disk);
        c_ptr += sizeof(bloque_carpeta);//posicion final

        last_start(c_ptr);//guardando posicion final
        incremet_nodo(1);
        incremet_block(1);
    }
}
//crea carpeta en bloque indirecto
void create_path_indirect_block(int start, string name, int c_ptr, int tipo){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        bloque_apuntador block;
        // ***************** leyendo el bloque carpeta**************************
        fseek(disk,start,SEEK_SET);
        fread(&block,sizeof(bloque_apuntador),1,disk);

        // ****************** agregando el nuevo inodo al bloque anterior **********************
        for(int i = 0; i < 16; i++){
            if(block.b_pointers[i] == -1){
             block.b_pointers[i] = c_ptr;
                break;
            }
        }
        // ****************** escribiendo block, ya que se agrego el nuevo inodo *********
        fseek(disk,start,SEEK_SET);
        fwrite(&block, sizeof(bloque_apuntador),1,disk);
        fclose(disk);
        create_inodo_with_path_block(c_ptr,name,tipo);
    }
}
//crear carpeta en bloque directo
void create_path_direct_block(int start, string name, int c_ptr, int tipo){
    FILE * disk;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        bloque_carpeta block;
        // ***************** leyendo el bloque carpeta**************************
        fseek(disk,start,SEEK_SET);
        fread(&block,sizeof(bloque_carpeta),1,disk);

        // ****************** agregando el nuevo inodo al bloque anterior **********************
        for(int i = 0; i < 4; i++){
            if(block.b_content[i].b_inodo == -1){
                block.b_content[i].b_inodo = c_ptr;
                strcpy(block.b_content[i].b_name, name.c_str());
                break;
            }
        }
        // ****************** escribiendo block, ya que se agrego el nuevo inodo *********
        fseek(disk,start,SEEK_SET);
        fwrite(&block, sizeof(bloque_carpeta),1,disk);
        fclose(disk);
        create_inodo_with_path_block(c_ptr,name, tipo);
    }
}

//crea una carpeta en el nodo actual, es decir crea una carpeta hija en el nodo padre (current_inodo)
int create_current_dir(inodo current_inodo, string name, int tipo){
    int start =  search_block_free(current_inodo);// obtiene un espacio vacio en un bloque
    if(start == -1){
        start = create_direct_block(current_inodo);
    }

    int c_ptr = last_start(-1);//obtiene el ultimo puntero
    int start_inodo = start;
    int inode_r = c_ptr;
    if(start != -1){
        create_path_direct_block(start, name, c_ptr, tipo);
    }else{
        //indirectos...
        //create_simple_indirecto
        if(current_inodo.i_block[12] != -1){
            start = search_free_sindirect(current_inodo.i_block[12]);
        }else{
            // craete simple indirecto
            start = create_sidirect_block(current_inodo,12);
        }
        if(start == -1){
            // probar con doble indirecto
            if(current_inodo.i_block[13] != -1){
                start = search_free_dindirect(current_inodo.i_block[13]);
                if(start == -1){
                    start = create_dindirect_block(current_inodo.i_block[13]);
                }
            }else{
                start = create_sidirect_block(current_inodo,13);
                start = create_dindirect_block(start);
            }
        }
        if(start != -1){
            c_ptr = last_start(-1);
            create_path_indirect_block(start,name,c_ptr, tipo);
        }

    }
    return inode_r;
}

//Metodo que recorre los directorios, busca el dir padre, y crea el directorio hijo
//recibe las carpetas en una lista de string que se separo por el cacarter /
int System_Controller::create_dir(QList<QString> dirs, bool is_p, int tipo, bool is_cat){
    string path = "";
    int contador = 0;

    int first_ptr = first_inode();
    bool create = true;
    inodo current_inodo;
    if(dirs.last() == ""){
        dirs.removeLast();        
    }
    if(dirs.size() < 2){
        current_inodo = obt_inodo(first_ptr);
        if(dirs.last().toStdString() == current_inodo.name_inodo){
            return first_ptr;
        }
    }
    while(contador < dirs.size() - 1){
        FILE * disk;
        if(disk = fopen(part_mount.path.c_str(),"rb+")){
            fseek(disk, first_ptr,SEEK_SET);
            fread(&current_inodo,sizeof(inodo), 1,disk);
            fclose(disk);
            if(current_inodo.name_inodo == dirs.at(contador).toStdString()){
                if(contador + 1 < dirs.size() -1){
                    first_ptr = search_root(current_inodo,dirs.at(contador + 1).toStdString());
                    // si first_ptr es -1 significa que no existe la carpeta padre...
                    if(first_ptr == -1){
                        //validamos si viene el parametro -p
                        if(is_p){
                            //crearemos la carpeta padre..
                            if(permiso(current_inodo) == 2){
                                first_ptr =  create_current_dir(current_inodo, dirs.at(contador + 1).toStdString(),0);
                                qDebug() <<"Se creo la carpeta padre: " << dirs.at(contador + 1);
                            }else{
                                qDebug() <<"No tiene permiso de escritura";
                                return -1;
                            }


                        }else{
                            qDebug() << "No existe la carpeta padre: " << dirs.at(contador + 1);
                            create = false;
                            break;
                        }
                    }
                }
                contador++;
            }else{
                break;
            }
        }else{
            break;
        }
    }
    if(create){
        int buscado = search_root(current_inodo,dirs.last().toStdString());
        if(buscado == -1){
            if(!is_cat){
                if(permiso(current_inodo) == 2){
                    int new_inodo = create_current_dir(current_inodo, dirs.last().toStdString(), tipo);
                    qDebug() <<"Se creo correctamente: " << dirs.last();
                    return new_inodo;
                }else{
                    qDebug() <<"No tiene permiso de escritura";
                    return -1;
                }

            }else{
                qDebug() <<"No existe: " << dirs.last() << " En la ruta dada";

            }
        }else{
            qDebug() <<"Se encontro : " << dirs.last() << " dentro de " << current_inodo.name_inodo;
            return buscado;
        }
    }
    return -1;
}

// *****************************  FINALIZA MKDIR ***************************************************************

// *****************************  INICIA MKFILE  ***************************************************************

void System_Controller::mkfile_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_sys = session;
    part_mount = part;
    QString path = "", cont = "";
    int size = 0;
    bool is_p = false;


    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type,"-path")){
            path = children->at(i).node_value;
        }else if(compare_str(children->at(i).node_type,"-p")){
            is_p = true;
        }else if(compare_str(children->at(i).node_type,"-size")){
            size = children->at(i).node_value.toInt();
        }else if(compare_str(children->at(i).node_type,"-cont")){
            cont = children->at(i).node_value;
        }
    }
    if(path != "" && size >= 0){
        if(cont != ""){
            ifstream file;
            string line = "";
            file.open(cont.toStdString(),ios::in);
            cont = "";
            if(!file.fail()){
                while(!file.eof()){
                    getline(file, line);
                    if(line != ""){
                        cont += line.c_str();
                    }
                    line = "";
                }
            }
            size = cont.size();
        }
        path = path.replace("/home/eli/", "/home/");
        QList<QString> dirs = path.split("/");
        dirs[0] = "/";
        create_file(dirs, is_p, cont,size);
    }
}

void System_Controller::create_file(QList<QString> dirs, bool is_p, QString cont, int size){
    QString name_file = dirs.last();
    int dir = create_dir(dirs, is_p, 1, false);
    int c_ptr = last_start(-1);
    if(dir != -1){

        FILE * disk;
        if(disk = fopen(part_mount.path.c_str(), "rb+")){
            inodo aux;

            fseek(disk, dir, SEEK_SET);
            fread(&aux, sizeof(inodo),1,disk);
            aux.i_size = size;
            for(int i = 0; i < 15; i++){
                aux.i_block[i] = -1;
            }
            int contador = 0;
            int b_aux = 0;
            if(cont.size() == 0){
                for(int i = 0 ; i < size; i++){
                    cont += " ";
                }
            }

            bloque_archivo block;

            for(int i = 0; i < size; i++){
                if(contador < 64){
                    block.b_content[contador] = cont.toStdString().at(i);
                    contador++;
                }
                if(contador >= 64 || i >= size - 1){
                    contador = 0;
                    fseek(disk, c_ptr, SEEK_SET);
                    fwrite(&block, sizeof(bloque_archivo), 1, disk);
                    if(b_aux < 15){
                        aux.i_block[b_aux] = c_ptr;
                    }
                    c_ptr += sizeof(bloque_archivo);
                    b_aux++;
                    bloque_archivo pp;
                    block = pp;
                }
            }
            fseek(disk,aux.i_start, SEEK_SET);
            fwrite(&aux, sizeof(inodo), 1, disk);
            fclose(disk);
            last_start(c_ptr);
        }
    }

}

void System_Controller::call_create_file(user session, Data_Mount part, QList<QString> dirs, bool is_p, QString cont, int size){
    sesion_sys = session;
    part_mount = part;
    create_file(dirs,is_p,cont,size);
}

void System_Controller::cat_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_sys = session;
    part_mount = part;
    QString path = "";

    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type,"-file")){
            path = children->at(i).node_value;
        }
    }
    if(path != ""){
        path = path.replace("/home/eli/", "/home/");
        QList<QString> dirs = path.split("/");
        dirs[0] = "/";
        show_cat(dirs);

    }else{
        qDebug() << "Falta parametro -file";
    }
}

void System_Controller::show_cat(QList<QString> dirs){
    int ptr_inodo = create_dir(dirs,false,1,true);
    if(ptr_inodo != -1){
        FILE * disk;

        if(disk = fopen(part_mount.path.c_str(), "rb+")){
            inodo aux;
            fseek(disk, ptr_inodo, SEEK_SET);
            fread(&aux, sizeof(inodo),1,disk);
            int per =permiso(aux);
            if(per == 2 || per == 1){

                for(int i = 0; i < 12; i++){
                    if(aux.i_block[i] != -1){
                        QString value = "";
                        bloque_archivo block;
                        fseek(disk, aux.i_block[i], SEEK_SET);
                        fread(&block, sizeof(bloque_archivo),1,disk);
                        for(int j = 0; j < 64; j++){
                            value = value + block.b_content[j];

                        }
                        value = value.replace("71", "G").replace("85","U");
                        qDebug() << value.toStdString().c_str();
                    }
                }
            }else{
                qDebug() << "No tiene permisos de lectura";
            }
            fclose(disk);
        }
    }
}


void System_Controller::find_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_sys = session;
    part_mount = part;
    QString path = "", name = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type,"-path")){
            path = children->at(i).node_value;
        }else if(compare_str(children->at(i).node_type,"-name")){
            name = children->at(i).node_value;
        }
    }

    if(path != "" && name != ""){
        path = path.replace("/home/eli/", "/home/");
        QList<QString> dirs= path.split("/");

        dirs[0] = "/";
        find_esp(dirs,name.toStdString());
    }
}


bool recursive_find(inodo c_inodo, string name, QString bar){
    bool encontrado = false;
    if(c_inodo.name_inodo != ""){
        if(c_inodo.i_type == 0){
            if(c_inodo.i_block[0] != -1){
                bloque_carpeta pr = obt_direct_block(c_inodo.i_block[0]);
                if(pr.b_content[0].b_inodo != -1){
                    qDebug()<< bar.toStdString().c_str() <<"_" << c_inodo.name_inodo;
                }
            }
        }
        for(int i = 0; i < 12; i++){
        if(c_inodo.i_block[i] > 0){
                bloque_carpeta block = obt_direct_block(c_inodo.i_block[i]);
                for(int j = 0; j < 4; j++){
                    if(block.b_content[j].b_inodo > 0){
                        inodo aux = obt_inodo(block.b_content[j].b_inodo);
                        if(aux.i_type == 0){
                            encontrado =  recursive_find(aux, name, bar + " |");
                        }else{
                            if(aux.name_inodo == name){
                                if(aux.name_inodo != ""){
                                    qDebug() << bar.toStdString().c_str()<< "Archivo Encontrado: "<<aux.name_inodo ;
                                }
                                encontrado = false;
                            }
                        }
                       if(encontrado){
                           if(aux.name_inodo != ""){
                               qDebug() << bar.toStdString().c_str()<< "Carpeta Encontrada: "<<aux.name_inodo ;
                           }
                        }
                    }
                }
            }

        }
        // search indirectos
        if(c_inodo.i_block[12] != -1){
           bloque_apuntador ptr =  obt_ptr_block(c_inodo.i_block[12]);
           for(int i = 0; i < 16; i++){
               if(ptr.b_pointers[i] != -1){
                   inodo aux = obt_inodo(ptr.b_pointers[i]);
                   if(aux.i_type == 0){
                       encontrado =  recursive_find(aux, name, bar + " |");
                   }else{
                       if(aux.name_inodo == name){
                           if(aux.name_inodo != ""){
                               qDebug() << bar.toStdString().c_str()<< "Archivo Encontrado: "<<aux.name_inodo ;
                           }
                           encontrado = false;
                       }
                   }
                  if(encontrado){
                      if(aux.name_inodo != ""){
                          qDebug() << bar.toStdString().c_str()<< "Carpeta Encontrada: "<<aux.name_inodo ;
                      }
                   }
               }
           }
        }
        if(c_inodo.i_block[13] != -1){
           bloque_apuntador ptr =  obt_ptr_block(c_inodo.i_block[13]);




           for(int i = 0; i < 16; i++){
               if(ptr.b_pointers[i] != -1){
                   bloque_apuntador ptr_aux = obt_ptr_block(ptr.b_pointers[i]);
                   for(int j = 0; j < 16; j++){
                        if(ptr_aux.b_pointers[j] != -1){
                            inodo aux = obt_inodo(ptr_aux.b_pointers[j]);
                            if(aux.i_type == 0){
                                encontrado =  recursive_find(aux, name, bar + " |");
                            }else{
                                if(aux.name_inodo == name){
                                    if(aux.name_inodo != ""){
                                        qDebug() << bar.toStdString().c_str()<< "Archivo Encontrado: "<<aux.name_inodo ;
                                    }
                                    encontrado = false;
                                }
                            }
                           if(encontrado){
                               if(aux.name_inodo != ""){
                                   qDebug() << bar.toStdString().c_str()<< "Carpeta Encontrada: "<<aux.name_inodo ;
                               }
                            }
                        }
                   }
               }
           }
        }


        if(c_inodo.name_inodo == name){
            return true;
        }
    }
    return false;
}

void System_Controller::find_esp(QList<QString> dirs, string name){
    int root = create_dir(dirs,false,0,true);

    if(root != -1){
        inodo i_root = obt_inodo(root);
        recursive_find(i_root,name,"|");
    }
}

void System_Controller::ren_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_sys = session;
    part_mount = part;
    QString path = "", name = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type,"-path")){
            path = children->at(i).node_value;
        }else if(compare_str(children->at(i).node_type,"-name")){
            name = children->at(i).node_value;
        }
    }

    if(path != "" && name != ""){
        path = path.replace("/home/eli/", "/home/");
        QList<QString> dirs= path.split("/");
        dirs[0] = "/";

        int ptr = create_dir(dirs,false,0,true);
        if(ptr != -1){
            inodo c_inodo = obt_inodo(ptr);
            if(permiso(c_inodo) == 2){
                rename_ino(dirs,name.toStdString());

            }else{
                qDebug() << "No tiene permisos de escritura";
            }
        }
    }
}

void System_Controller::rename_ino(QList<QString> dirs, string name){

    int n_ptr = create_dir(dirs,false,0,true);
    dirs.removeLast();
    dirs.append(name.c_str());
    int c_ptr = create_dir(dirs,false,0,true);


    if(n_ptr != -1){
        if(c_ptr == -1){
            inodo c_nodo = obt_inodo(n_ptr);
            strcpy(c_nodo.name_inodo, name.c_str());

            FILE * disk;
            if(disk = fopen(part_mount.path.c_str(), "rb+")){
                fseek(disk, n_ptr,SEEK_SET);
                fwrite(&c_nodo, sizeof(inodo), 1, disk);
                fclose(disk);
                qDebug() << "Se renombro correctamente";
            }

        }else{
            qDebug() << "Ya existe, no se puede renombrar";

        }
    }else{
        qDebug() << "No existe el path";
    }
}

void System_Controller::edit_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_sys = session;
    part_mount = part;
    QString path = "", cont = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type,"-path")){
            path = children->at(i).node_value;
        }else if(compare_str(children->at(i).node_type,"-cont")){
            cont = children->at(i).node_value;
        }
    }

    if(path != "" && cont != ""){
        path = path.replace("/home/eli/", "/home/");
        QList<QString> dirs= path.split("/");
        dirs[0] = "/";
        int ptr = create_dir(dirs,false,0,true);
        if(ptr != -1){
            inodo c_inodo = obt_inodo(ptr);
            if(permiso(c_inodo) == 2){
                create_file(dirs, false, cont,cont.size());
                qDebug() << "Se modifico correctamente";

            }else{
                qDebug() << "No tiene permisos de escritura y lectura";
            }
        }
    }else{
        qDebug() << "Faltan parametros";
    }
}

void System_Controller:: remove_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_sys = session;
    part_mount = part;
    QString path = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type,"-path")){
            path = children->at(i).node_value;
        }
    }
    if(path != ""){
        path = path.replace("/home/eli/", "/home/");
        QList<QString> dirs = path.split("/");
        dirs[0] = "/";
        remove_ino(dirs);
        if(have_perm){
            delete_bits();
        }
    }else{
        qDebug() << "falta parametro -path";
    }

}

void perm_action(inodo c_inodo){
    if(c_inodo.name_inodo != ""){
        inodo_list.append(c_inodo);
        if(permiso(c_inodo) != 2){
            have_perm = false;
        }
        for(int i = 0; i < 12; i++){
        if(c_inodo.i_block[i] > 0){
                bloque_carpeta block = obt_direct_block(c_inodo.i_block[i]);
                dir_list.append(block);
                for(int j = 0; j < 4; j++){
                    if(block.b_content[j].b_inodo > 0){
                        inodo aux = obt_inodo(block.b_content[j].b_inodo);
                        if(aux.i_type == 0){
                            perm_action(aux);
                        }else{
                            inodo_list.append(aux);
                            if(permiso(aux) != 2){
                                have_perm = false;
                            }
                        }

                    }
                }
            }

        }
        // search indirectos
        if(c_inodo.i_block[12] != -1){
           bloque_apuntador ptr =  obt_ptr_block(c_inodo.i_block[12]);
           ptr_list.append(ptr);
           for(int i = 0; i < 16; i++){
               if(ptr.b_pointers[i] != -1){
                   inodo aux = obt_inodo(ptr.b_pointers[i]);
                   if(aux.i_type == 0){
                       perm_action(aux);
                   }else{
                       if(permiso(aux) != 2){
                           have_perm = false;
                       }
                       inodo_list.append(aux);
                   }

               }
           }
        }
        if(c_inodo.i_block[13] != -1){
           bloque_apuntador ptr =  obt_ptr_block(c_inodo.i_block[13]);
           ptr_list.append(ptr);
           for(int i = 0; i < 16; i++){
               if(ptr.b_pointers[i] != -1){
                   bloque_apuntador ptr_aux = obt_ptr_block(ptr.b_pointers[i]);
                   ptr_list.append(ptr_aux);
                   for(int j = 0; j < 16; j++){
                        if(ptr_aux.b_pointers[j] != -1){
                            inodo aux = obt_inodo(ptr_aux.b_pointers[j]);
                            if(aux.i_type == 0){
                                perm_action(aux);
                            }else{
                                if(permiso(aux) != 2){
                                    have_perm = false;
                                }
                                inodo_list.append(aux);
                            }
                        }
                   }
               }
           }
        }
    }
}




void System_Controller::remove_ino(QList<QString> dirs){
    int n_ptr = create_dir(dirs,false,0,true);
    dirs.removeLast();
    int r_ptr = create_dir(dirs,false,0,true);
    bool eliminado = false;
    have_perm = true;
    inodo_list.clear();
    ptr_list.clear();
    dir_list.clear();
    file_list.clear();
    if(n_ptr != -1 && r_ptr != -1){
        inodo c_nodo = obt_inodo(n_ptr);
        inodo f_nodo = obt_inodo(r_ptr);

        if(permiso(c_nodo) == 2){
            for(int i = 0; i < 12; i++){
                if(f_nodo.i_block[i] != -1){
                    bloque_carpeta block = obt_direct_block(f_nodo.i_block[i]);
                    for(int j = 0; j < 4; j++){
                        if(block.b_content[j].b_inodo != -1){
                            inodo aux_inodo = obt_inodo(block.b_content[j].b_inodo);
                            if(strcmp(aux_inodo.name_inodo, c_nodo.name_inodo) == 0){
                                perm_action(aux_inodo);

                                if(have_perm){
                                    block.b_content[j].b_inodo = -1;
                                    strcpy(block.b_content[j].b_name , "");
                                    save_direct_block(f_nodo.i_block[i],block);
                                    i=12;
                                    eliminado = true;

                                }
                                break;
                            }
                        }
                    }
                }
            }
            if(f_nodo.i_block[12]  != -1){
                bloque_apuntador ptr = obt_ptr_block(f_nodo.i_block[12]);
                for(int i = 0; i < 16; i++){
                    if(ptr.b_pointers[i] != -1){
                        inodo aux_inodo = obt_inodo(ptr.b_pointers[i]);
                        if(strcmp(aux_inodo.name_inodo, c_nodo.name_inodo) == 0){
                            perm_action(aux_inodo);
                            if(have_perm){
                                ptr.b_pointers[i] = -1;
                                save_ptr_block(f_nodo.i_block[12],ptr);
                                eliminado = true;
                            }
                             break;
                        }
                    }
                }
            }
            if(f_nodo.i_block[13]  != -1){
                bloque_apuntador ptr = obt_ptr_block(f_nodo.i_block[13]);
                for(int i = 0; i < 16; i++){
                    if(ptr.b_pointers[i] != -1){
                        bloque_apuntador ptr_aux = obt_ptr_block(ptr.b_pointers[i]);
                        for(int j = 0; j < 16; j++){
                            if(ptr_aux.b_pointers[j] != -1){
                                inodo aux_inodo = obt_inodo(ptr_aux.b_pointers[j]);
                                if(strcmp(aux_inodo.name_inodo, c_nodo.name_inodo) == 0){
                                    perm_action(aux_inodo);
                                    if(have_perm){
                                        ptr_aux.b_pointers[j] = -1;
                                        save_ptr_block(ptr.b_pointers[i],ptr_aux);
                                        i = 16;
                                        eliminado = true;
                                    }
                                    break;
                                }

                            }
                        }
                    }
                }
            }
        }else{
            qDebug() << "El ususario no tiene permisos de escritura";
        }

    }else{
        qDebug() << "No se puede eliminars";
    }
    if(eliminado){
        qDebug () << "Se elimino correctamente " ;

    }else{
        qDebug () << "No se elimino correctamente " ;
        if(!have_perm){
            qDebug () << "No tiene permisos" ;

        }
    }
}

user exist_usr(string usr){
    super_bloque sb = obt_superb(sb,0);
    user us;
    for(int i = 0; i < 333; i++){
        if(sb.users_[i].id != -1 && sb.users_[i].type != 'X'){
            if(sb.users_[i].n_user == usr){
                return sb.users_[i];
            }
        }
    }
    return us;
}

void ch_generic(inodo c_inodo, int ugo, string usr){
    int pem = permiso(c_inodo);
    if(pem == 2){
        if(ugo != -1){
            c_inodo.i_perm = ugo;
            save_inodo(c_inodo);
            qDebug() << "se cambio el permiso de: " << c_inodo.name_inodo;
        }else if(usr != ""){
            user us = exist_usr(usr);
            if(us.id != -1 && us.type !='X'){
                strcpy(c_inodo.n_user, us.n_user);
                strcpy(c_inodo.grp, us.grp);
                save_inodo(c_inodo);
                qDebug() << "se cambio el uid de: " << c_inodo.name_inodo;

            }
        }
    }

}

void recursive_change(inodo c_inodo, int ugo, string usr){
    if(c_inodo.name_inodo != ""){
        ch_generic(c_inodo,ugo,usr);
        for(int i = 0; i < 12; i++){
        if(c_inodo.i_block[i] > 0){
                bloque_carpeta block = obt_direct_block(c_inodo.i_block[i]);
                for(int j = 0; j < 4; j++){
                    if(block.b_content[j].b_inodo > 0){
                        inodo aux = obt_inodo(block.b_content[j].b_inodo);
                        if(aux.i_type == 0){
                            recursive_change(aux, ugo, usr);
                        }else{
                            ch_generic(aux,ugo,usr);
                        }

                    }
                }
            }

        }
        // search indirectos
        if(c_inodo.i_block[12] != -1){
           bloque_apuntador ptr =  obt_ptr_block(c_inodo.i_block[12]);
           for(int i = 0; i < 16; i++){
               if(ptr.b_pointers[i] != -1){
                   inodo aux = obt_inodo(ptr.b_pointers[i]);
                   if(aux.i_type == 0){
                       recursive_change(aux, ugo, usr);
                   }else{
                        ch_generic(aux,ugo,usr);
                   }

               }
           }
        }
        if(c_inodo.i_block[13] != -1){
           bloque_apuntador ptr =  obt_ptr_block(c_inodo.i_block[13]);
           for(int i = 0; i < 16; i++){
               if(ptr.b_pointers[i] != -1){
                   bloque_apuntador ptr_aux = obt_ptr_block(ptr.b_pointers[i]);
                   for(int j = 0; j < 16; j++){
                        if(ptr_aux.b_pointers[j] != -1){
                            inodo aux = obt_inodo(ptr_aux.b_pointers[j]);
                            if(aux.i_type == 0){
                               recursive_change(aux, ugo,usr);
                            }else{
                                ch_generic(aux,ugo,usr);
                            }

                        }
                   }
               }
           }
        }
    }
}

void System_Controller::change_inodo(QList<QString> dirs, bool is_r, int ugo, string usr){
    int ptr = create_dir(dirs,false,0,true);

    if(ptr != -1){
        inodo c_inodo = obt_inodo(ptr);
        if(is_r){
            recursive_change(c_inodo,ugo,usr);
        }else{
            ch_generic(c_inodo,ugo,usr);
        }
    }else{
        qDebug() << "No existe el path";
    }

}

void System_Controller::chown_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_sys = session;
    part_mount = part;
    string us;
    QString path = "";
    bool is_r = false;
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type,"-path")){
            path = children->at(i).node_value;
        }else if(compare_str(children->at(i).node_type,"-usr")){
            us = children->at(i).node_value.toStdString();
        }else if(compare_str(children->at(i).node_type,"-r")){
            is_r = true;
        }
    }
    if(path != "" && us != ""){
        path = path.replace("/home/eli/", "/home/");
        QList<QString> dirs = path.split("/");
        dirs[0] = "/";
        change_inodo(dirs,is_r,-1,us);
    }
}

void System_Controller:: chmod_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_sys = session;
    part_mount = part;
    int ugo = -1;
    QString path = "";
    bool is_r;
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type,"-path")){
            path = children->at(i).node_value;
        }else if(compare_str(children->at(i).node_type,"-ugo")){
            ugo = children->at(i).node_value.toInt();
        }else if(compare_str(children->at(i).node_type,"-r")){
            is_r = true;
        }
    }
    if(path != "" && ugo != -1){
        path = path.replace("/home/eli/", "/home/");
        QList<QString> dirs = path.split("/");
        dirs[0] = "/";
        change_inodo(dirs,is_r,ugo,"");
    }
}

int System_Controller::call_create_dir(Data_Mount part, QList<QString> dirs){
    part_mount = part;
    return create_dir(dirs,false,0,true);
}

void System_Controller:: move_inodo(QList<QString> dirs, QList<QString> dris_dest){
    have_perm = true;
    int origin = create_dir(dirs,false,0,true);
    int dest = create_dir(dris_dest,false,0,true);
    if(origin != -1 && dest != -1){
        inodo  c_inodo  = obt_inodo(origin);
        inodo  ci_dest = obt_inodo(dest);

        dris_dest.append("new");
        remove_ino(dirs);
        if(have_perm){
            int niu = create_dir(dris_dest,false,0,false);
            c_inodo.i_start = niu;
            save_inodo(c_inodo);
        }else{
            qDebug() << "No se pudo mover";
        }

    }


}

void System_Controller::mv_command(QList<AST_Node> *children, user session, Data_Mount part){
    sesion_sys = session;
    part_mount = part;
    QString path = "", dest = "";
    for(int i = 0; i < children->size(); i++){
        if(compare_str(children->at(i).node_type,"-path")){
            path = children->at(i).node_value;
        }else if(compare_str(children->at(i).node_type,"-dest")){
            dest = children->at(i).node_value;
        }
    }
    if(path != "" && dest != ""){
        path = path.replace("/home/eli/", "/home/");
        QList<QString> dirs = path.split("/");
        dirs[0] = "/";
        dest = dest.replace("/home/eli/", "/home/");
        QList<QString> dirs_dest = dest.split("/");
        dirs_dest[0] = "/";
        move_inodo(dirs,dirs_dest);
    }else{
        qDebug() << "Faltan parametros";
    }
}






