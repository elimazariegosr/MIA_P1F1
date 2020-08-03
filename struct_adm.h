#ifndef STRUCT_ADM_H
#define STRUCT_ADM_H


#include <ctime>
#include <time.h>
#include <sys/stat.h>
class Struct_Adm
{

public:
    Struct_Adm();

};
struct part  {
    char part_status = 'e';
    char part_type = ' ';
    char part_fit = 'w';
    int part_start = 0;
    int part_size = -1;
    int part_size_available = 0;
    char part_name [16] = "";
    int id_part = 0;

};
struct emb{
    char part_status = 'e';
    char part_fit = 'w';
    int part_start = 0;
    int part_size = 0;
    int part_next = 0;
    int part_size_available = 0;
    char part_name [16] = "";
};
struct mbr{
    int mbr_tamano = -1;
    int mbr_tamano_available = -1;
    //time_t mbr_fecha_creacion;
    int mbr_disk_signature = -1;
    char disk_fit = 'f';
    part partitions[4];//0 1
};


struct inodo
{
    int pos = 0;
    char name_inodo [10] = "";
    int i_uid = -1;//id del user
    int i_gid = -1;//id del grupo
    char n_user[10] = "";
    char grp [10] = "";
    int i_size = -1;
    time_t i_atime;
    time_t i_ctime;
    time_t i_mtime;
    int i_type = -1;
    int i_perm = -1;
    int i_start = -1;
    int i_block[15];//0-11(directos), 12 simple indirecto, 13 doble indirecto y 14 triple indirecto
};

struct content{
    char b_name [12] = "";
    int b_inodo = -1;
};

struct bloque_carpeta
{
    int pos = 0;
    char name_block [12];
    content b_content[4];
    //bloque_archivo ba;
};

struct bloque_archivo
{
    int pos = 0;
    char b_content[64] = "";
};

struct bloque_apuntador
{
    int pos = 0;
    int b_pointers[16];
};
struct bitmap
{
    int map[999];
};
struct user{
    int id = -1;
    char n_user[10] = "";
    char n_pwd[10] = "";
    char type = 'X';
    char grp [10] = "";
};

struct cont_journal{
    time_t tiem;
    char user [10] = "";
    char part_name [25] = "";
    char action [25] = "";
    int fs = -1;
};

struct journal
{
    cont_journal value [999];
};


struct super_bloque
{
    int s_filesystem_type = -1;
    int s_inodes_count = -1;
    int s_blockes_count = -1;
    int s_free_blocks_count = -1;
    int s_free_inodes_count = -1;
    time_t s_mtime;
    time_t s_umtime;
    int s_mnt_count = -1;
    int s_magic = 0xEF53;
    int s_inode_size = -1;
    int s_block_size = -1;
    int s_firts_ino = -1;
    int s_first_blo = -1;
    int s_bm_inode_start = -1;
    int s_bm_block_start = -1;
    int s_inode_start = -1;
    int s_block_start = -1;
    user users_[333];
    int s_start = -1;//ultimo start
};
#endif // STRUCT_ADM_H

