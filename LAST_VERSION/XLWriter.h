#ifndef XLWRITER_H
#define XLWRITER_H
#include <QApplication>
#include "xlsxdocument.h"
#include <QDebug>
#include <iostream>
#include <string>
#include <vector>
#include <data.h>
#include <QtCore>
#include "xlsxconditionalformatting.h"

class XLWriter {
public:
    QXlsx::Document* doc;
    int toTrueCol(int);
    void write(QXlsx::Document*, int*, int, std::vector <QVariant>);
    void writeClassroom(QXlsx::Document*, int, QVariant);
    void formating (int, double, char);
    void createHeader(int, int);
    void createWeekdays(int, int);
    void createBachelorsMasters(int);
    void createPairData(int);
    void createShedule(int);
};

#endif
