          #include <iostream>
#include "LogicAnalysis.h"

void LogicAnalysis::checkMistakes(){
    for (int i = 0; i < this->classrooms.size(); i++){
        this->classrooms[i].checkLesson6_7();
    }
}


void LogicAnalysis::createClassrooms(std::vector <std::string> new_class_list, std::vector <Group> groups){// создаётся и заполняется массив classrooms для вывода в xlwriter
    for (int i = 0; i < new_class_list.size(); i++){
        for (int j = 0; j < groups.size(); j++){
            Classroom room;
            room.setDataOut(groups[j].getDays(), new_class_list[i], groups[j].getNameGroup(), groups[j].getNumOfPeople(), groups[j].getDepartment());
            room.setName(new_class_list[i]);
            this->classrooms.push_back(room);
        }
    }

    //checkMistakes();// вызов функции проверки на ошибки
}

void LogicAnalysis::runWriter(QString filename){
    QXlsx::Document writer;
    for (int i = 0; i < this->classrooms.size(); i++){
        classrooms[i].writeData(&writer, i);
        qDebug() << "runWriter";
    }
    writer.saveAs(filename);
}
// сделать проверку на ошибки
