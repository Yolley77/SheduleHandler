#ifndef XLREADER_H
#define XLREADER_H
#include <QApplication>
#include "xlsxdocument.h"
#include <QDebug>
#include <iostream>
#include <string>

class XLReader {
public:
    int k;
    QVariant group, num_of_people;
    int toTrueCol(int);
    virtual std::vector <std::vector <QVariant>> read(int, QXlsx::Document*) = 0; // будет считываться данные о паре по чётной и нечётной недели в массив (1ые 4 эл-та нечётная неделя, следующия 4 - чётная)
    QVariant getName(int, QXlsx::Document*);
    QVariant getDepartment(int, QXlsx::Document*);
    int getNumberOfPeople(int, QXlsx::Document*);

};

class XLReaderBachelor : public XLReader{ // класс для считывания файлов бакалавров
public:
    std::vector <std::vector <QVariant>> read(int, QXlsx::Document*);
};

class XLReaderMaster : public XLReader{ // класс для считывания файлов магистров
public:
    std::vector <std::vector <QVariant>> read(int, QXlsx::Document*);
};

#endif
