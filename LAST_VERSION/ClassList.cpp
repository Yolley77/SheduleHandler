#include <iostream>
#include "ClassList.h"
#include <QDebug>

std::vector <std::string> ClassList::mySort(std::vector <std::string> list){// сортирует и удаляет аудитории
    std::vector <std::string> room_list;
    room_list = list;
    int size_vec = room_list.size();
    for (int i = 0; i < size_vec; i++) {
        int k = i;
        for(int j = i + 1; j < size_vec; j++){
            if (strcmp(room_list[j].c_str(), room_list[k].c_str()) < 0) {
                k = j;
            }
        }
        std::swap(room_list[i], room_list[k]);
    }
    for (int i = 0; i < size_vec - 1; i++){
        if ((room_list[i] == room_list[i + 1]) || room_list[i].empty()){
            for (int j = i; j < size_vec - 1; j++){
                room_list[j] = room_list[j + 1];
            }
            i--;
            size_vec--;
        }
    }
    room_list.resize(size_vec);
    return room_list;
}

void ClassList::createGroups(std::vector <std::string> names_of_files_bachelor, std::vector <std::string> names_of_files_master){
                                    // создаётся массив групп для дальнейшего сохранения данных
                                    //нужно сделать имена файлов для передачи
    if (!names_of_files_bachelor.empty()){
        for (int i = 0; i < names_of_files_bachelor.size(); i++){
            Group group;
            int s = 0;
            QXlsx::Document schedule(names_of_files_bachelor[i].c_str());
            group.setName(1, &schedule);
            while (!group.empty()){
               s++;
               group.setData(s, 0, &schedule);
               this->groups.push_back(group);
               group.setName(s + 1, &schedule);
            }
        }

    }
    if (!names_of_files_master.empty()){
        for (int i = 0; i < names_of_files_master.size(); i++){
            Group group;
            int s = 0;
            QXlsx::Document schedule(names_of_files_bachelor[i].c_str());
            group.setName(1, &schedule);
            while (!group.empty()){
                s++;
                group.setData(s, 1, &schedule);
                this->groups.push_back(group);
                group.setName(s + 1, &schedule);
            }
        }

    }
}

std::vector <std::string> ClassList::getClassList(){ // передача всего списка аудиторий, который есть в интерфейс

    std::vector <std::string> class_list;
    for (int i = 0; i < this->groups.size(); i++){
        std::vector <std::string> vec;
        vec = groups[i].getClassrooms();
        for (int j = 0; j < vec.size(); j++){
            class_list.push_back(vec[j]);
        }
    }
    std::vector <std::string> sort_class_list;
    sort_class_list = ClassList::mySort(class_list);

    return sort_class_list;
}

void ClassList::setNewClassList(std::vector <std::string> class_list){ //получение списка аудиторий, которые нужно вывести
    this->new_class_list = class_list;
}

void ClassList::convert(QString filename){ // передача списка аудиторий для дальнейшей обработки (предположительно классу LogicAnalisys)
    LogicAnalysis analisys;
    analisys.createClassrooms(this->new_class_list, this->groups);
    analisys.runWriter(filename);
}
