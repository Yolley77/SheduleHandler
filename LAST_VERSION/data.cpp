#include <iostream>
#include "data.h"
// функции setDate нужны для удобного заполнения массива нужным нам способом(получается вложенность циклов,
// которая получается из разных классов и их векторов)
// my_size - размет массивов бакалавров или магистров
// k - определитель бакалавров и магистров(0 - бакалавр, 1 - магистр)




//GROUP



void Group::setName(int my_size, QXlsx::Document* schedule){
    XLReaderBachelor reader;
    this->name_group = reader.getName(my_size, schedule);
}

void Group::setData(int my_size, int k, QXlsx::Document* schedule){//получаем имя группы, кафедру и число человек + всё остальное
    if (k == 0){
        XLReaderBachelor reader;
        this->name_group = reader.getName(my_size, schedule);
        this->department = reader.getDepartment(my_size, schedule);
        this->num_of_people = reader.getNumberOfPeople(my_size, schedule);
        this->data = reader.read(my_size, schedule);
    }else if (k == 1){
        XLReaderMaster reader;
        this->name_group = reader.getName(my_size, schedule);
        this->department = reader.getDepartment(my_size, schedule);
        this->num_of_people = reader.getNumberOfPeople(my_size, schedule);
        this->data = reader.read(my_size, schedule);
    }
    for (int i = 0; i < 6; i++){
        Day day;
        day.setData(k, data, &row);
        this->days.push_back(day);
    }
    row = 0;
}

bool Group::empty(){//для  проверки, есть ли дальше группа в файле (то есть нужно ли дальше считывать или нет)
    if(name_group.toString().toStdString().empty()){
        return 1;
    }else {
        return 0;
    }
}

QVariant Group::getNameGroup(){
    return this->name_group;
}

QVariant Group::getDepartment(){
    return this->department;
}

unsigned int Group::getNumOfPeople(){
    return this->num_of_people;
}


std::vector <std::string> Group::getClassrooms(){//получение списка аудиторий
    for (int i = 0; i < this->days.size(); i++){
        std::vector <std::string> vec;
        vec = this->days[i].getClassrooms();
        for (int j = 0; j < vec.size(); j ++){
            str_classroom.push_back(vec[j]);
        }
    }
    return this->str_classroom;
}

std::vector <Day> Group::getDays(){
    return this->days;
}

// END GROUP





// CLASSROOM

void Classroom::setName(std::string name){
    this->name_room = QString::fromStdString(name);
}

void Classroom::setDataOut(std::vector <Day> days_by_group, std::string classroom, QVariant group_name_by_group, QVariant amount_people, QVariant department){
    for(int i = 0; i < days_by_group.size(); i++){
        Day day;
        day.setDataOut(days_by_group[i].getLessons(), classroom, this->name_room, group_name_by_group, amount_people, department);
        this->days.push_back(day);
    }
}

void Classroom::checkLesson6_7(){
    for (int i = 0; i < this->days.size(); i++){
        days[i].checkLesson6_7();
    }
}

QVariant Classroom::getName(){
    return this->name_room;
}

void Classroom::writeData(QXlsx::Document *file, int col){
    XLWriter writer;
    if(col % 3 == 0){
        writer.doc = file;
        int a = (col / 3) * 21 + 1;
        writer.createShedule(a);
    }
    writer.writeClassroom(file, col, this->name_room);
    for(int i = 0; i < this->days.size(); i++){
        days[i].writeData(file, &row, col);
    }
}

// END CLASSROOM




//DAY

std::vector <std::string> Day::getClassrooms(){
    std::vector <std::string> str_classroom;
    for (int i = 0; i < lessons.size(); i++){
        std::vector <std::string> vec;
        vec = this->lessons[i].getClassroom();
        for (int j = 0; j < vec.size(); j ++){
            str_classroom.push_back(vec[j]);
        }
    }
    return str_classroom;
}

void Day::setData(int k, std::vector <std::vector <QVariant>> data, int* row){
    if (k == 0){
        for (int i = 0; i < 6; i++){
            LessonNumber lesson;
            lesson.setData(data, row);
            this->lessons.push_back(lesson);
        }
    }else if (k == 1){
        for (int i = 0; i < 2; i++){
            LessonNumber lesson;
            lesson.setData(data, row);
            this->lessons.push_back(lesson);
        }
    }
}

void Day::setDataOut(std::vector <LessonNumber> lessons_by_group, std::string classroom, QVariant name_room, QVariant group_name_by_group, QVariant amount_people, QVariant department){
    for (int i = 0; i < lessons_by_group.size(); i++){
        LessonNumber lesson;
        lesson.setDataOut(lessons_by_group[i].getParity_in(), classroom, name_room, group_name_by_group, amount_people, department);
        this->lessons.push_back(lesson);
    }
}

std::vector <LessonNumber>Day::getLessons(){
    return this->lessons;
}

void Day::checkLesson6_7(){
    if (!(this->lessons[5].empty_1()) && !(this->lessons[6].empty_1())){
           this->lessons[5].check_par1 = 1;
           this->lessons[6].check_par1 = 1;
    }
    if (!(this->lessons[5].empty_2()) && !(this->lessons[6].empty_2())){
           this->lessons[5].check_par2 = 1;
           this->lessons[6].check_par2 = 1;
    }
}

void Day::writeData(QXlsx::Document *file, int* row, int col){
    for (int i = 0; i < this->lessons.size(); i ++){
        lessons[i].writeData(file, row, col);

    }
}

//END DAY






//LESSON NUMBER


std::vector <std::string> LessonNumber::getClassroom(){
    std::vector <std::string> str_classroom;
    str_classroom.push_back(this->parity_in[0].getClassroom());
    str_classroom.push_back(this->parity_in[1].getClassroom());
    return str_classroom;
}

void LessonNumber::setDataOut(std::vector <ParityIn> parities_by_group, std::string classroom, QVariant name_room, QVariant group_name_by_group, QVariant amount_people, QVariant department){
    for (int i = 0; i < parities_by_group.size(); i++){
        ParityOut parity;
        parity.setData(parities_by_group[i].getData(), classroom, name_room, group_name_by_group, amount_people, department);
        this->parity_out.push_back(parity);
    }
}

void LessonNumber::setData(std::vector <std::vector <QVariant>> data, int* row){
    for (int i = 0; i < 2; i++){
        std::vector <QVariant> str;
        str = data[(*row)];
        ParityIn parity;
        parity.setData(str, row);
        this->parity_in.push_back(parity);
    }
}


std::vector <ParityIn> LessonNumber::getParity_in(){
    return this->parity_in;
}

bool LessonNumber::empty_1(){
    if (parity_out[0].getSubjectToCheck().empty()){
        return 1;
    } else{
        return 0;
    }
}

bool LessonNumber::empty_2(){
    if (parity_out[1].getSubjectToCheck().empty()){
        return 1;
    } else{
        return 0;
    }
}

void LessonNumber::writeData(QXlsx::Document *file, int* row, int col){
    for (int i = 0; i < this->parity_out.size(); i ++){
        parity_out[i].writeData(file, row, col);

    }
}

//END LESSON NUMBER



//PARITY IN


std::string ParityIn::getClassroom(){
    return (this->data[3].toString().toStdString());
}

std::vector <QVariant> ParityIn::getData(){
    return this->data;
}

void ParityIn::setData(std::vector <QVariant> data, int* row){// здесь идёт связь с XLReader
    (*row)++;
    this->data = data;
}

// END PARITY IN






// PARITY OUT

void ParityOut::setData(std::vector <QVariant> data, std::string classroom, QVariant name_room, QVariant group_name_by_group, QVariant amount_people, QVariant department){// если ошибка с пробелами, то смотреть сюда;
    if (data[3].toString().toStdString() == classroom){
        std::string helper;
        helper = data[0].toString().toStdString() + " ";
        this->subject_str += helper;
        this->a++;
        if (a > 1){
            check_subject = 1;
        }
        helper = data[1].toString().toStdString() + " ";
        this->lesson_type_str += helper;

        helper = data[2].toString().toStdString() + " ";
        this->teacher_str += helper;
        this->b++;
        if (b > 1){
            check_teacher = 1;
        }
        helper = group_name_by_group.toString().toStdString() + "(";
        this->group_name_str += helper;
        this->c++;
        if (c > 1){
            check_group_name = 1;
        }
        helper = department.toString().toStdString() + ") ";
        this->group_name_str += helper;

        int help;
        help = amount_people.toInt();
        this->max_amount_people_int += help;

        this->subject = QString::fromStdString(subject_str);
        this->lesson_type = QString::fromStdString(lesson_type_str);
        this->teacher = QString::fromStdString(teacher_str);

        this->group_name = QString::fromStdString(group_name_str);
        QVariant a(max_amount_people_int);
        this->max_amount_people = a;
    }

}

std::string ParityOut::getSubjectToCheck(){
    return this->subject.toString().toStdString();
}

void  ParityOut::writeData(QXlsx::Document *file, int* row, int col){

    XLWriter writer;
    this->data_out.push_back(this->subject);
    this->data_out.push_back(this->lesson_type);
    this->data_out.push_back(this->teacher);
    this->data_out.push_back(this->group_name);
    this->data_out.push_back(this->max_amount_people);

    this->check_data.push_back(this->check_subject);
    this->check_data.push_back(this->check_teacher);
    this->check_data.push_back(this->check_group_name);

    writer.write(file, row, col, data_out);

}

// END PARITY OUT
