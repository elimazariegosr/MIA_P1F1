#include "data_mount.h"

Data_Mount::Data_Mount()
{

}
Data_Mount::Data_Mount(string id, string path, string name, part part_){
    this->id = id;
    this->path = path;
    this->name = name;
    this->part_ = part_;
}
