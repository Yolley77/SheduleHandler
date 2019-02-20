#include <iostream>
#include "XLReader.h"

int XLReader::toTrueCol(int col){
    int true_col = -3;
    for (int i = 0; i < col; i ++){
        if (i % 3 == 0){
            true_col += 5;
        }
        true_col += 4;
    }
    return true_col;
}

std::vector <std::vector <QVariant>> XLReaderBachelor::read(int col, QXlsx::Document* schedule){
    std::vector <std::vector <QVariant>> data_of_lesson;
    col = toTrueCol(col);
    for (int row = 4; row <= 75; row++){
        std::vector <QVariant> str;
        for (int j = 0; j < 4 ; j++){
            str.push_back((*schedule).read(row, col + j ));
        }
        data_of_lesson.push_back(str);
    }
    return data_of_lesson;
}


std::vector <std::vector <QVariant>> XLReaderMaster::read(int col, QXlsx::Document* schedule){
    std::vector <std::vector <QVariant>> data_of_lesson;
    col = toTrueCol(col);
    for (int row = 4; row <= 87; row+=3){
        std::vector <QVariant> str;
        for (int j = 0; j < 4 ; j++){
            str.push_back((*schedule).read(row, col + j ));
        }
        data_of_lesson.push_back(str);
    }
    return data_of_lesson;
}

QVariant XLReader::getName(int col, QXlsx::Document* schedule){
    QVariant name;
    col = toTrueCol(col);
    name = (*schedule).read(2, col);
    return name;
}

QVariant XLReader::getDepartment(int col, QXlsx::Document* schedule){
    QVariant department;
    col = toTrueCol(col);
    department = (*schedule).read(2, col + 2);
    return department;
}

int XLReader::getNumberOfPeople(int col, QXlsx::Document* schedule){
    QVariant number_of_people;
    int num;
    col = toTrueCol(col);
    number_of_people = (*schedule).read(2, col + 3);
    num = number_of_people.toInt();
    return num;
}
