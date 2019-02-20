#ifndef DATA_H
#define DATA_H
#include "XLReader.h"
#include "XLWriter.h"
#include "xlsxdocument.h"
#include <string>
#include <vector>

class Parity {
protected:
    QVariant teacher, lesson_type, subject;
};

class ParityIn : public Parity {
private:
    QVariant classroom;
    std::vector <QVariant> data;
public:
    std::string getClassroom();
    std::vector <QVariant> getData();
    void setData(std::vector <QVariant>, int*);
};

class ParityOut : public Parity {
private:
    QVariant max_amount_people, group_name;
    int max_amount_people_int = 0;
    int a = 0, b = 0, c = 0;//счётчики
    std::string teacher_str, lesson_type_str, subject_str, group_name_str;
    std::vector <QVariant> data_out;
public:
    bool check_subject = 0, check_teacher = 0, check_group_name = 0, check6_7 = 0;
    std::vector <bool> check_data;
    void setData(std::vector <QVariant>, std::string, QVariant, QVariant, QVariant, QVariant);
    std::string getSubjectToCheck();
    void writeData(QXlsx::Document*, int*, int);
};

class LessonNumber {
private:
    std::vector <ParityIn> parity_in;
    std::vector <ParityOut> parity_out;
public:
    bool check_par1 = 0, check_par2 = 0;
    std::vector <std::string> getClassroom();
    void setData(std::vector <std::vector <QVariant>>, int*);
    void setDataOut(std::vector <ParityIn>, std::string, QVariant, QVariant, QVariant, QVariant);
    std::vector <ParityIn> getParity_in();
    bool empty_1();
    bool empty_2();
    void writeData(QXlsx::Document*, int*, int);
};

class Day {
private:
    std::vector <LessonNumber> lessons;
public: 
    std::vector <std::string> getClassrooms();
    void setData(int, std::vector <std::vector <QVariant>>, int*);
    void setDataOut(std::vector <LessonNumber>, std::string, QVariant, QVariant, QVariant, QVariant);
    std::vector <LessonNumber>getLessons();
    void checkLesson6_7();
    void writeData(QXlsx::Document*, int*, int);
};

class Group {
private:
    QVariant name_group, department;
    unsigned int num_of_people;
    std::vector <Day> days;
public:
    int row = 0;
    std::vector <std::vector <QVariant>> data;
    void setName(int, QXlsx::Document*);
    void setData(int, int, QXlsx::Document*);
    bool empty();
    std::vector <std::string> str_classroom;
    std::vector <std::string> getClassrooms();
    QVariant getNameGroup();
    QVariant getDepartment();
    unsigned int getNumOfPeople();
    std::vector <Day> getDays();
};

class Classroom {
private:
    QVariant name_room;
    std::vector <Day> days;
public:
    int row = 2;
    void setName(std::string);
    void setDataOut(std::vector <Day>, std::string, QVariant, QVariant, QVariant);
    void checkLesson6_7();
    QVariant getName();
    void writeData(QXlsx::Document*, int);
};
#endif
