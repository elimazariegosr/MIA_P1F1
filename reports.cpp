#include "reports.h"

Reports::Reports()
{

}
System_Controller sc;
QString value_tree = "";
QList<inodo> list_inodes;
QList<bloque_apuntador> list_blocks_a;
QList<bloque_archivo> list_blocks_f;
QList<bloque_carpeta> list_blocks_d;

super_bloque obt_superb(Data_Mount part_mount){
    FILE * disk;
    super_bloque sb;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        fseek(disk, part_mount.part_.part_start, SEEK_SET);
        fread(&sb, sizeof(super_bloque), 1, disk);
        fclose(disk);
     }
    return sb;
}
bloque_archivo obt_block_file(Data_Mount part_mount, int start){
    FILE * disk;
    bloque_archivo block;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        fseek(disk, start, SEEK_SET);
        fread(&block, sizeof(bloque_archivo), 1, disk);
        fclose(disk);
     }
    return block;
}

bitmap obt_bitmap(Data_Mount part_mount, int start){
    FILE * disk;
    bitmap bm;
    if(disk = fopen(part_mount.path.c_str(),"rb+")){
        fseek(disk, start, SEEK_SET);
        fread(&bm, sizeof(bitmap), 1, disk);
        fclose(disk);
     }
    return bm;
}


void Reports::comand_dot(string path){


       string name = "graph.dot";
       QString rep = path.c_str();
       path = rep.replace(".png", ".pdf").toStdString();
       mk.create_directory(QString::fromUtf8(path.c_str()));
       string comand = "dot -Tpdf " + name + " -o " + path;
       char outp[comand.size() + 1];
       strcpy(outp, comand.c_str());
       system(outp);

       qDebug() << "se genero correctamente el reporte" << QString::fromUtf8(path.c_str());
}

void Reports::generar_rep(QList<Data_Mount> *list,QList<AST_Node> *children)
{

    list_blocks_a.clear();
    list_blocks_d.clear();
    list_blocks_f.clear();
    list_inodes.clear();

    value_tree = "";
    string name = "", path = "" , id = "";
    QString ruta = "";
    for(int c = 0; c < children->size(); c++){
        if(mk.compare_str(children->at(c).node_type, "-name")){
            name= children->at(c).node_value.toStdString();
        }else if(mk.compare_str(children->at(c).node_type, "-path")){
            path = children->at(c).node_value.toStdString();
        }else if(mk.compare_str(children->at(c).node_type, "-id")){
            id = children->at(c).node_value.toStdString();
        }else if(mk.compare_str(children->at(c).node_type, "-ruta")){
            ruta = children->at(c).node_value;
        }
    }
    string name_p = "", path_disk = "";
    if(name != "" && path != "" && id != ""){
        for(int i = 0; i < list->size(); i++){
            if(list->at(i).id == id){
                mbr mkdisk;
                FILE * disk;
                disk = fopen(list->at(i).path.c_str(),"rb+");
                fseek(disk,0,SEEK_SET);
                fread(&mkdisk,sizeof (mbr),1,disk);
                fclose(disk);
                if(name == "mbr"){
                    mbr_report(mkdisk,mk.all_logic(list->at(i).path,' '));
                    comand_dot(path);        
                }else if(name == "disk"){
                    disk_report(mkdisk,mk.all_logic(list->at(i).path,' '));
                    comand_dot(path);
                }else if(name == "tree"){
                    tree_report(list->at(i));
                    comand_dot(path);
                }else if(name == "inode"){
                    inode_report(list->at(i));
                    comand_dot(path);
                }else if(name == "block"){
                    block_report(list->at(i));
                    comand_dot(path);
                }else if(name == "bm_inode"){
                    bm_inodo_report(list->at(i));
                    comand_dot(path);
                }else if(name == "bm_block"){
                    bm_block_report(list->at(i));
                    comand_dot(path);

                }else if(name == "Journaling"){
                    jour_report(list->at(i));
                    comand_dot(path);
                }else if(name == "sb"){
                    sb_report(list->at(i));
                    comand_dot(path);
                }else if(name == "ls"){
                    if(ruta != ""){
                        ruta = ruta.replace("/home/eli/","/home/");
                        ls_report(list->at(i),ruta);
                        comand_dot(path);

                    }
                }else if(name == "file"){
                   if(ruta != ""){
                       ruta = ruta.replace("/home/eli/","/home/");
                       file_report(list->at(i),ruta);
                       comand_dot(path);
                   }
                }else{
                    qDebug() << "no especifica el reporte";
                }
                i = list->size() + 1;
            }
        }
     }

}
bloque_apuntador block_indirect_root(int pos, string path){
    FILE * disk;
    bloque_apuntador block;
    if(disk = fopen(path.c_str(),"rb+")){
        fseek(disk,pos,SEEK_SET);
        fread(&block, sizeof(bloque_apuntador),1,disk);
        fclose(disk);
    }
    return block;

}
bloque_carpeta block_root(int pos, string path){
    FILE * disk;
    bloque_carpeta block;
    if(disk = fopen(path.c_str(),"rb+")){
        fseek(disk,pos,SEEK_SET);
        fread(&block, sizeof(bloque_carpeta),1,disk);
        fclose(disk);
    }
    return block;
}
bloque_archivo block_file(int pos, string path){
    FILE * disk;
    bloque_archivo block;
    if(disk = fopen(path.c_str(),"rb+")){
        fseek(disk,pos,SEEK_SET);
        fread(&block, sizeof(bloque_archivo),1,disk);
        fclose(disk);
    }
    return block;
}
inodo ob_current_inodo(int pos, string path){
    FILE * disk;
    inodo current;
    if(disk = fopen(path.c_str(),"rb+")){
        fseek(disk,pos,SEEK_SET);
        fread(&current, sizeof(inodo),1,disk);
        fclose(disk);
    }
    return current;
}

void recusive_tree(inodo c_inodo, QString file,string path){
    if(c_inodo.name_inodo != ""){
        list_inodes.append(c_inodo);
        char* dt = ctime(&c_inodo.i_mtime);

        value_tree = value_tree+  "n" + std::to_string(c_inodo.i_start).c_str()
                + "[label=< <TABLE><TR><TD>NOMBRE</TD><TD>"
                + c_inodo.name_inodo + "</TD></TR>\n<TR><TD>i_uid</TD><TD>"
                + c_inodo.n_user + "</TD></TR>\n<TR><TD>I_gid</TD><TD>"
                + c_inodo.grp + "</TD></TR>\n<TR><TD>i_size</TD><TD>"
                + std::to_string(c_inodo.i_size).c_str() + "</TD></TR>\n"
                + "<TR><TD>PERMISO</TD><TD>" + std::to_string(c_inodo.i_perm).c_str() + "</TD></TR>"
                + "<TR><TD>i_atime</TD><TD>" + dt + "</TD></TR>\n"
                + "<TR><TD>i_ctime</TD><TD>" + dt + "</TD></TR>\n"
                + "<TR><TD>i_mtime</TD><TD>" + dt + "</TD></TR>\n";
        for(int i = 0; i < 15; i++){
            if(i < 12){
            value_tree = value_tree + "<TR><TD>Directo "+std::to_string(i + 1).c_str()
                    +"</TD><TD PORT=\"p"+std::to_string(i).c_str()+"\">"
                    + std::to_string(c_inodo.i_block[i]).c_str() + "</TD></TR>\n";
            }else{
                value_tree = value_tree + "<TR><TD>INDIRECTO "+std::to_string((i + 1) - 12).c_str()
                        +"</TD><TD PORT=\"p"+std::to_string(i).c_str()+"\">"
                        + std::to_string(c_inodo.i_block[i]).c_str() + "</TD></TR>\n";
            }
        }
        value_tree = value_tree + "</TABLE>>]\n";

        for(int i = 0; i < 12; i++){
            if(c_inodo.i_block[i] > 0){

                value_tree = value_tree + "n" +std::to_string(c_inodo.i_start).c_str()
                        + ":p"+std::to_string(i).c_str()
                        +"-> n" + std::to_string(c_inodo.i_block[i]).c_str() + ";\n";
                if(c_inodo.i_type == 0){
                    bloque_carpeta block = block_root(c_inodo.i_block[i],path);
                    value_tree = value_tree + "n" + std::to_string(c_inodo.i_block[i]).c_str()
                            + "[label =< <TABLE><TR><TD>Bloque Carpeta</TD></TR>\n";

                    int val = -1;
                    for(int j = 0; j < 4; j++){

                        if(val == -1){
                            val = block.b_content[j].b_inodo;
                        }
                        value_tree = value_tree + "<TR><TD PORT=\"p"+std::to_string(j).c_str()+"\">"
                                + std::to_string(block.b_content[j].b_inodo).c_str()
                                + "</TD></TR>/n";
                    }
                    if(val != -1){
                        list_blocks_d.append(block);
                    }
                    value_tree = value_tree + "</TABLE>>]\n";


                    for(int j = 0; j < 4; j++){
                        if(block.b_content[j].b_inodo > 0){
                            inodo aux = ob_current_inodo(block.b_content[j].b_inodo, path);
                            value_tree = value_tree + "n" + std::to_string(c_inodo.i_block[i]).c_str()
                                    + ":p" +std::to_string(j).c_str() +" -> n" + std::to_string(aux.i_start).c_str()  + "\n";

                            recusive_tree(aux,file,path);
                        }
                    }
                }else{
                    bloque_archivo block =block_file(c_inodo.i_block[i], path);
                    list_blocks_f.append(block);
                    value_tree = value_tree + "n" + std::to_string(c_inodo.i_block[i]).c_str()
                            + "[label =< <TABLE><TR><TD>Bloque Archivo</TD></TR>\n"
                            + "<TR><TD>" + block.b_content + "</TD></TR>\n</TABLE>>]";
                }
            }
        }
        if(c_inodo.i_block[12] != -1){
            bloque_apuntador block = block_indirect_root(c_inodo.i_block[12],path);
            value_tree = value_tree + "n" + std::to_string(c_inodo.i_block[12]).c_str()
                    + "[label =< <TABLE><TR><TD>Bloque Apuntador</TD></TR>\n";

            int val = -1;
            for(int i = 0; i < 16; i++){
                if(val == -1){
                    val = block.b_pointers[i];
                }
                value_tree = value_tree + "<TR><TD PORT=\"p"+std::to_string(i).c_str()+"\">"
                        + std::to_string(block.b_pointers[i]).c_str()
                        + "</TD></TR>/n";
            }
            if(val != -1){
                list_blocks_a.append(block);
            }
            value_tree = value_tree + "</TABLE>>]\n";

            value_tree = value_tree + "n"+ std::to_string(c_inodo.i_start).c_str() +" :p12-> n"
                    + std::to_string(c_inodo.i_block[12]).c_str() + ";\n";
            for(int i = 0; i < 16; i++){
                if(block.b_pointers[i] != -1){
                    inodo aux = ob_current_inodo(block.b_pointers[i], path);
                    value_tree = value_tree + "n" + std::to_string(c_inodo.i_block[12]).c_str()
                            +":p" + std::to_string(i).c_str()
                            + "->n"+ std::to_string(aux.i_start).c_str()  + ";\n";
                    recusive_tree(aux,file,path);
                }
            }
        }

        if(c_inodo.i_block[13] != -1){
            bloque_apuntador block = block_indirect_root(c_inodo.i_block[13],path);
            value_tree = value_tree + "n" + std::to_string(c_inodo.i_block[13]).c_str()
                    + "[label =< <TABLE><TR><TD>Bloque Apuntador</TD></TR>\n";
            int val = -1;
            for(int i = 0; i < 16; i++){
                if(val == -1){
                    val = block.b_pointers[i];
                }
                value_tree = value_tree + "<TR><TD PORT=\"p"+std::to_string(i).c_str()+"\">"
                        + std::to_string(block.b_pointers[i]).c_str()
                        + "</TD></TR>/n";
            }

            if(val != -1){
                list_blocks_a.append(block);
            }
            value_tree = value_tree + "</TABLE>>]\n";

            value_tree = value_tree + "n"+ std::to_string(c_inodo.i_start).c_str() +" :p13-> n"
                    + std::to_string(c_inodo.i_block[13]).c_str() + ";\n";

            for(int i = 0; i < 16; i++){
                if(block.b_pointers[i] != -1){
                    value_tree = value_tree + "n" + std::to_string(c_inodo.i_block[13]).c_str()
                            +":p" + std::to_string(i).c_str()
                            + "->n"+ std::to_string(block.b_pointers[i]).c_str()  + ";\n";

                    bloque_apuntador block_aux = block_indirect_root(block.b_pointers[i],path);
                    value_tree = value_tree + "n" + std::to_string(block.b_pointers[i]).c_str()
                            + "[label =< <TABLE><TR><TD>Bloque Apuntador</TD></TR>\n";

                    val = -1;
                    for(int j = 0; j < 16; j++){

                        if(val == -1){
                            val = block_aux.b_pointers[j];
                        }
                        value_tree = value_tree + "<TR><TD PORT=\"p"+std::to_string(j).c_str()+"\">"
                                + std::to_string(block_aux.b_pointers[j]).c_str()
                                + "</TD></TR>/n";
                    }
                    if(val != -1){
                        list_blocks_a.append(block_aux);
                    }
                    value_tree = value_tree + "</TABLE>>]\n";

                    for(int j = 0; j < 16; j++){
                        if(block_aux.b_pointers[j] != -1){
                            inodo aux = ob_current_inodo(block_aux.b_pointers[j], path);
                            value_tree = value_tree + "n" + std::to_string(block.b_pointers[i]).c_str()
                                    +":p" + std::to_string(j).c_str()
                                    + "->n"+ std::to_string(aux.i_start).c_str()  + ";\n";
                            recusive_tree(aux,file,path);
                        }
                    }
                }
            }
        }
    }
}

void Reports::tree_report(Data_Mount mount){
    int start = mount.part_.part_start;
    ofstream file;
    file.open("graph.dot",ios::out);
    if(!file.fail()){
        file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
        file << "rankdir=LR;";
        file << "node[shape=plaintext];";
        FILE * disk;
        if(disk = fopen(mount.path.c_str(),"rb+")){
            super_bloque sb;
            inodo current_inodo;
            fseek(disk, start, SEEK_SET);
            fread(&sb,sizeof(super_bloque), 1,disk);
            start = sb.s_inode_start;
            fseek(disk,start, SEEK_SET);
            fread(&current_inodo,sizeof(inodo),1,disk);
            fclose(disk);
            recusive_tree(current_inodo,"",mount.path);
            value_tree = value_tree.replace(".", "");
            file << value_tree.toStdString();
            file << "\n}";
            file.close();
            value_tree = "";
        }

    }

}
void Reports::mbr_report(mbr mbr_disk, QList<emb> list){
    ofstream file;
    file.open("graph.dot",ios::out);
    if(!file.fail()){
        file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
        file << "graph [ratio=fill];\n";
        file << "node [label=\"\\N\", fontsize=15, shape=plaintext];";
        file << "graph [bb=\"0,0,352,154\"];";
        file << "arset [label=<\n";

        file << "<TABLE><TR><TD>NOMBRE</TD><TD>VALOR</TD></TR>\n";
        file << "<TR><TD>mbr_size</TD><TD>" << std::to_string(mbr_disk.mbr_tamano) <<"</TD></TR>\n";
        file << "<TR><TD>mbr_disk_signature</TD><TD>" << std::to_string(mbr_disk.mbr_disk_signature) <<"</TD></TR>\n";
        file << "<TR><TD>Disk_fit</TD><TD>" << std::to_string(mbr_disk.disk_fit) <<"</TD></TR>\n";

        for(int i = 0; i < 4;i++){
            if(mbr_disk.partitions[i].part_size > 0){
                file << "<TR><TD>part_status_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           mbr_disk.partitions[i].part_status <<"</TD></TR>\n";
                file << "<TR><TD>part_type_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           mbr_disk.partitions[i].part_type<<"</TD></TR>\n";
                file << "<TR><TD>part_fit_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           mbr_disk.partitions[i].part_fit <<"</TD></TR>\n";
                file << "<TR><TD>part_size_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           std::to_string(mbr_disk.partitions[i].part_size) <<"</TD></TR>\n";
                file << "<TR><TD>part_start_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           std::to_string(mbr_disk.partitions[i].part_start) <<"</TD></TR>\n";
                file << "<TR><TD>part_name_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           mbr_disk.partitions[i].part_name <<"</TD></TR>\n";
            }
        }

        file << "</TABLE>>,]; ";

        /*for(int i = 0; i < list.size(); i++){
            if(list.at(i).part_size > 0){
                file << "arset"<<std::to_string(i) <<" [label=<\n";

                file << "<TABLE><TR><TD>NOMBRE</TD><TD>VALOR</TD></TR>\n";

                file << "<TR><TD>part_status_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           list.at(i).part_status <<"</TD></TR>\n";
                file << "<TR><TD>part_fit_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           list.at(i).part_fit <<"</TD></TR>\n";
                file << "<TR><TD>part_start_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           std::to_string(list.at(i).part_start) <<"</TD></TR>\n";
                file << "<TR><TD>part_size_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           std::to_string(list.at(i).part_size) <<"</TD></TR>\n";
                file << "<TR><TD>part_next_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           std::to_string(list.at(i).part_next) <<"</TD></TR>\n";
                file << "<TR><TD>part_name_"<<std::to_string(i + 1) <<"</TD><TD>" <<
                           list.at(i).part_name<<"</TD></TR>\n";

                file << "</TABLE>>,]; ";
            }
        }*/
        file <<"\n}";
        file.close();
    }
}


void Reports::disk_report(mbr mbr_disk,QList<emb> list){

    ofstream file;
    file.open("graph.dot",ios::out);
    if(!file.fail())

    {

        file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
        file << "graph [ratio=fill];\n";
        file << "node [label=\"\\N\", fontsize=15, shape=plaintext];";
        file << "graph [bb=\"0,0,352,154\"];";
        file << "arset [label=<\n";

        double size_disk = mbr_disk.mbr_tamano;
        double size_free_disk = mbr_disk.mbr_tamano_available;
        file << "<TABLE><TR><TD>MBR</TD>";
        for(int i = 0; i < 4; i++){
            double size_p = mbr_disk.partitions[i].part_size;
            double size_free = mbr_disk.partitions[i].part_size_available;

            double p_part = (size_p / size_disk) * 100;
            double p_free = (size_free / size_disk) * 100;

            if(size_p > 0){
                if(mbr_disk.partitions[i].part_type != 'e' && mbr_disk.partitions[i].part_type != 'E'){
                    if(mbr_disk.partitions[i].part_status == 'e'){

                        if((size_p - size_free) == 0){
                            file << "<TD> Primaria: <BR></BR>" << mbr_disk.partitions[i].part_name << " <BR></BR>" << std::to_string(int(p_part)) << "% del Disco </TD>\n";
                        }else{
                             p_part = ((size_p - size_free) /size_disk) * 100;
                             file << "<TD> Primaria: <BR></BR>" << mbr_disk.partitions[i].part_name << " <BR></BR>" << std::to_string(int(p_part)) << "% del Disco </TD>\n";
                             if((size_p - size_free) != size_p){
                                 file << "<TD>Libre <BR></BR>" << std::to_string(int(p_free)) << "% del Disco </TD>\n";
                             }
                        }

                    }else{
                    file << "<TD>Libre \n" << std::to_string(int(p_part)) << "% del Disco </TD>\n";
                    }
                }else{
                    file << "<TD> \n";
                        file << "<TABLE><TR><TD>EXTENDIDA: " << mbr_disk.partitions[i].part_name << "</TD></TR><TR>\n";
                        for(int i = 0; i < list.size(); i++){
                            file << "<TD>EMB</TD>\n";
                            if(list.at(i).part_size > 0){
                                double l_part = (list.at(i).part_size / size_disk) * 100;
                                double l_free = (list.at(i).part_size_available / size_disk) * 100;

                                if(list.at(i).part_status == 'e'){
                                    if((list.at(i).part_size - list.at(i).part_size_available) == 0){
                                        file << "<TD> Logica:<BR></BR> " << list.at(i).part_name << " <BR></BR>" << std::to_string(int(l_part)) << "% del Disco </TD>\n";
                                    }else{
                                         l_part = ((list.at(i).part_size - list.at(i).part_size_available) /size_disk) * 100;
                                         file << "<TD> Logica: <BR></BR>" << list.at(i).part_name << "<BR></BR>" << std::to_string(int(l_part)) << "% del Disco </TD>\n";
                                         if((size_p - size_free) != size_p){
                                             file << "<TD>Libre <BR></BR>" << std::to_string(int(l_free))<< "% del Disco </TD>\n";
                                         }
                                    }
                                }else{
                                    file << "<TD>Libre <BR></BR>" << std::to_string(int(l_part)) <<  "% del Disco </TD>\n";

                                }

                            }

                        }

                        if((size_p - size_free) != size_p){
                            file << "<TD>Libre <BR></BR>" << std::to_string(int(p_free)) << "% del Disco </TD>\n";
                        }

                        file << "</TR></TABLE></TD>\n";
                }

            }
                }
        int p_free_disk = (size_free_disk / size_disk) * 100;
        if(size_free_disk > 0){
            file << "<TD>Libre " << std::to_string(p_free_disk) << "% del Disco </TD>\n";
        }
        file << "</TR></TABLE>>,];}";
        file.close();

    }
}
void call_recursive(Data_Mount mount){
    int start = mount.part_.part_start;
    FILE * disk;
    if(disk = fopen(mount.path.c_str(),"rb+")){
        super_bloque sb;
        inodo current_inodo;
        fseek(disk, start, SEEK_SET);
        fread(&sb,sizeof(super_bloque), 1,disk);
        start = sb.s_inode_start;
        fseek(disk,start, SEEK_SET);
        fread(&current_inodo,sizeof(inodo),1,disk);
        fclose(disk);
        recusive_tree(current_inodo,"",mount.path);
    }
}

void rec_inode_list(){
    for(int i = 0; i < list_inodes.size(); i++){
        char* dt = ctime(&list_inodes.at(i).i_mtime);

        value_tree = value_tree+  "\nn" + std::to_string(i).c_str()
                + "[label=< <TABLE><TR><TD>NOMBRE</TD><TD>"
                + list_inodes.at(i).name_inodo + "</TD></TR>\n<TR><TD>i_uid</TD><TD>"
                + list_inodes.at(i).n_user + "</TD></TR>\n<TR><TD>I_gid</TD><TD>"
                + list_inodes.at(i).grp + "</TD></TR>\n<TR><TD>i_size</TD><TD>"
                + std::to_string(list_inodes.at(i).i_size).c_str() + "</TD></TR>\n"
                + "<TR><TD>PERMISO</TD><TD>" + std::to_string(list_inodes.at(i).i_perm).c_str() + "</TD></TR>"
                + "<TR><TD>i_atime</TD><TD>" + dt + "</TD></TR>\n"
                + "<TR><TD>i_ctime</TD><TD>" + dt + "</TD></TR>\n"
                + "<TR><TD>i_mtime</TD><TD>" + dt + "</TD></TR>\n";
        for(int j = 0; j < 15; j++){
            if(j < 12){
            value_tree = value_tree + "<TR><TD>Directo "+std::to_string(j + 1).c_str()
                    +"</TD><TD>" + std::to_string(list_inodes.at(i).i_block[j]).c_str() + "</TD></TR>\n";
            }else{
                value_tree = value_tree + "<TR><TD>INDIRECTO "+std::to_string((j + 1) - 12).c_str()
                        +"</TD><TD PORT=\"p"+std::to_string(j).c_str()+"\">"
                        + std::to_string(list_inodes.at(i).i_block[j]).c_str() + "</TD></TR>\n";
            }
        }
        value_tree = value_tree + "</TABLE>>]\n";

        value_tree  = value_tree + "n"+ std::to_string(i).c_str() + " -> n" + std::to_string(i + 1).c_str();
    }
}
void Reports::inode_report(Data_Mount mount){
    call_recursive(mount);
    value_tree = "";
    rec_inode_list();
    ofstream file;
    file.open("graph.dot",ios::out);
    if(!file.fail()){
        file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
        file << "rankdir=LR;";
        file << "node[shape=plaintext];";
        value_tree = value_tree.replace(".", "");
        file << value_tree.toStdString();
        file << "\n}";
        file.close();
        value_tree = "";
    }
}

void rec_block_list(){
    int j =0;
    for(int i = 0; i < list_blocks_d.size(); i++){
        value_tree = value_tree + "\nn" + std::to_string(i).c_str()
                + "[label =< <TABLE><TR><TD>Bloque Carpeta</TD></TR>\n";
        for(int k = 0; k < 4; k++){

            value_tree = value_tree + "<TR><TD>"
                    + std::to_string(list_blocks_d.at(i).b_content[k].b_inodo).c_str()
                    + "</TD></TR>/n";
        }
        value_tree = value_tree + "</TABLE>>]\n";
        value_tree  = value_tree + "\nn"+ std::to_string(i).c_str() + " -> n" + std::to_string(i + 1).c_str();
        j++;
    }

    for(int i = 0; i < list_blocks_a.size(); i++){
        value_tree = value_tree + "\nn" + std::to_string(j).c_str()
                + "[label =< <TABLE><TR><TD>Bloque Apuntador</TD></TR>\n";

        for(int k = 0; k < 16; k++){

            value_tree = value_tree + "<TR><TD>"
                    + std::to_string(list_blocks_a.at(i).b_pointers[k]).c_str()
                    + "</TD></TR>/n";
        }
        value_tree = value_tree + "</TABLE>>]\n";
        value_tree  = value_tree + "\nn"+ std::to_string(j).c_str() + " -> n" + std::to_string(j + 1).c_str();
        j++;
    }

    for(int i = 0; i < list_blocks_f.size(); i++){
        value_tree = value_tree + "\nn" + std::to_string(j).c_str()
                + "[label =< <TABLE><TR><TD>Bloque Archivo</TD></TR>\n"
                + "<TR><TD>" + list_blocks_f.at(i).b_content + "</TD></TR>\n</TABLE>>]";

        value_tree  = value_tree + "\nn"+ std::to_string(j).c_str() + " -> n" + std::to_string(j + 1).c_str();
        j++;
    }
}

void Reports::block_report(Data_Mount mount){
    call_recursive(mount);
    value_tree = "";
    rec_block_list();
    ofstream file;
    file.open("graph.dot",ios::out);
    if(!file.fail()){
        file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
        file << "rankdir=LR;";
        file << "node[shape=plaintext];";
        value_tree = value_tree.replace(".", "");
        file << value_tree.toStdString();
        file << "\n}";
        file.close();
        value_tree = "";
    }
}

void gen_bitmap(bitmap bm){
    value_tree = "bm[label=\"";
    int contador = 0;
    for(int i = 0; i < 999; i++){
        if(bm.map[i] != -1){
            if(contador < 20){
                value_tree = value_tree + std::to_string(bm.map[i]).c_str() +"  ";
                contador++;
            }else{
                value_tree = value_tree + "\n";
                contador = 0;
            }
        }else{
            break;
        }
    }
    value_tree = value_tree + "\"];";
}
void Reports::bm_inodo_report(Data_Mount mount){
    super_bloque sb = obt_superb(mount);
    bitmap bm = obt_bitmap(mount, sb.s_bm_inode_start);
    gen_bitmap(bm);
    ofstream file;
    file.open("graph.dot",ios::out);
    if(!file.fail()){
        file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
        file << "rankdir=LR;";
        file << "node[shape=plaintext];";
        file << value_tree.toStdString();
        file << "\n}";
        file.close();
        value_tree = "";
    }
}
void Reports::bm_block_report(Data_Mount mount){
    super_bloque sb = obt_superb(mount);
    bitmap bm = obt_bitmap(mount, sb.s_bm_block_start);
    gen_bitmap(bm);
    ofstream file;
    file.open("graph.dot",ios::out);
    if(!file.fail()){
        file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
        file << "rankdir=LR;";
        file << "node[shape=plaintext];";
        file << value_tree.toStdString();
        file << "\n}";
        file.close();
        value_tree = "";
    }
}
void Reports::sb_report(Data_Mount mount){
    super_bloque sb = obt_superb(mount);
    ofstream file;
    file.open("graph.dot",ios::out);
    if(!file.fail()){
        file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
        file << "rankdir=LR;";
        file << "node[shape=plaintext];";
        file << "sb[label = < <TABLE><TR><TD>NOMBRE</TD><TD>VALOR</TD></TR>\n";
        file << "<TR><TD>s_inodes_count</TD><TD>" << std::to_string(sb.s_inodes_count) << "</TD></TR>\n";
        file << "<TR><TD>s_blocks_count</TD><TD>" << std::to_string(sb.s_blockes_count) << "</TD></TR>\n";
        file << "<TR><TD>s_free_blocks_count</TD><TD>" << std::to_string(sb.s_free_blocks_count) << "</TD></TR>\n";
        file << "<TR><TD>s_free_inodes_count</TD><TD>" << std::to_string(sb.s_free_inodes_count) << "</TD></TR>\n";
        char* dt = ctime(&sb.s_mtime);

        file << "<TR><TD>s_mtime</TD><TD>" << dt << "</TD></TR>\n";
        file << "<TR><TD>s_umtime</TD><TD>" << dt << "</TD></TR>\n";
        file << "<TR><TD>s_mnt_count</TD><TD>" << dt << "</TD></TR>\n";
        file << "<TR><TD>s_magic</TD><TD>" << std::to_string(sb.s_magic) << "</TD></TR>\n";
        file << "<TR><TD>s_inode_size</TD><TD>" << std::to_string(sb.s_inode_size) << "</TD></TR>\n";
        file << "<TR><TD>s_block_size</TD><TD>" << std::to_string(sb.s_block_size) << "</TD></TR>\n";
        file << "<TR><TD>s_first_ino</TD><TD>" << std::to_string(sb.s_firts_ino) << "</TD></TR>\n";
        file << "<TR><TD>s_first_blo</TD><TD>" << std::to_string(sb.s_first_blo) << "</TD></TR>\n";
        file << "<TR><TD>s_bm_inode_start</TD><TD>" << std::to_string(sb.s_bm_inode_start) << "</TD></TR>\n";
        file << "<TR><TD>s_bm_block_start</TD><TD>" << std::to_string(sb.s_bm_block_start) << "</TD></TR>\n";
        file << "<TR><TD>s_inode_start</TD><TD>" << std::to_string(sb.s_inode_start) << "</TD></TR>\n";
        file << "<TR><TD>s_block_start</TD><TD>" << std::to_string(sb.s_block_start) << "</TD></TR>\n";
        file << "</TABLE>>]";
        file << "\n}";
        file.close();
    }

}

void Reports::jour_report(Data_Mount mount){
    FILE * disk;
    if(disk = fopen(mount.path.c_str(), "rb+")){
        journal jl;
        int ptr = mount.part_.part_start + sizeof(super_bloque);
        fseek(disk,ptr, SEEK_SET);
        fread(&jl, sizeof(journal), 1, disk);
        fclose(disk);

        ofstream file;
        file.open("graph.dot",ios::out);
        if(!file.fail()){
            file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
            file << "rankdir=LR;";
            file << "node[shape=plaintext];";
            file << "jour[label = < <TABLE><TR><TD>TIME</TD><TD>USER</TD><TD>PART_NAME</TD><TD>OPERATION</TD><TD>FS</TD></TR>\n";
            for(int i = 0; i < 999; i++){
                if(jl.value[i].fs != -1){
                    char* dt = ctime(&jl.value[i].tiem);

                    file << "<TR><TD> " << dt << "</TD><TD>"
                        << jl.value[i].user << "</TD><TD>"
                        << jl.value[i].part_name <<  "</TD><TD>"
                        << jl.value[i].action <<  "</TD><TD>Ext3</TD></TR>";
                }
            }
            file << "</TABLE>>]";
            file << "\n}";
            file.close();
        }
    }
}

void Reports::ls_report(Data_Mount mount, QString path){

    QList<QString> dirs = path.split("/");
    dirs[0] = "/";
    int ptr = sc.call_create_dir(mount, dirs);
    if(ptr != -1){
        inodo c_inodo = ob_current_inodo(ptr, mount.path);
        recusive_tree(c_inodo,"",mount.path);
        ofstream file;
        file.open("graph.dot",ios::out);
        if(!file.fail()){
            file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
            file << "rankdir=LR;";
            file << "node[shape=plaintext];";
            file << "ls[label = < <TABLE><TR><TD>PERMISOS</TD><TD>OWNER</TD><TD>GRUPO</TD><TD>SIZE</TD><TD>FECHA</TD><TD>TIPO</TD><TD>NOMBRE</TD></TR>\n";

            for(int i = 0; i < list_inodes.size(); i++){
                char* dt = ctime(&list_inodes.at(i).i_ctime);
                file << "<TR><TD>" << std::to_string(list_inodes.at(i).i_perm) << "</TD>";
                file << "<TD>" << list_inodes.at(i).n_user << "</TD>";
                file << "<TD>" << list_inodes.at(i).grp << "</TD>";
                file << "<TD>" << std::to_string(list_inodes.at(i).i_size) << "</TD>";
                file << "<TD>" << dt << "</TD>";
                file << "<TD>" << std::to_string(list_inodes.at(i).i_type) << "</TD>";
                file << "<TD>" << list_inodes.at(i).name_inodo << "</TD></TR>";
            }
            file << "</TABLE>>]";
            file << "\n}";
            file.close();
        }
    }
}

void Reports:: file_report(Data_Mount mount, QString path){
    QList<QString> dirs = path.split("/");
    dirs[0] = "/";
    int ptr = sc.call_create_dir(mount, dirs);
    if(ptr != -1){
        inodo c_inodo = ob_current_inodo(ptr, mount.path);
        ofstream file;
        file.open("graph.dot",ios::out);
        if(!file.fail()){
            file << "digraph Grafica{\nbgcolor=deepskyblue;\n";
            file << "rankdir=LR;";
            file << "node[shape=plaintext];";
            file << "bm[label=\"";
            for(int i = 0; i <12; i++){
                if(c_inodo.i_block[i] != -1){
                    bloque_archivo block = obt_block_file(mount,c_inodo.i_block[i]);
                    file << block.b_content;
                }
            }
            file << "\"]";
            file << "\n}";
            file.close();

        }

    }
}
