#ifndef LOGICANALYSIS_H
#define LOGICANALYSIS_H
#include <QApplication>
#include <QDebug>
#include <vector>
#include <string>
#include "data.h"
#include "xlsxdocument.h"
#include "XLWriter.h"

class LogicAnalysis {
private:
    std::vector <Classroom> classrooms;
    XLWriter writer;
public:
    void checkMistakes();
    void createClassrooms(std::vector <std::string>, std::vector <Group>);
    void runWriter(QString);
};

#endif
