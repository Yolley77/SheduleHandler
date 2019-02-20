#ifndef CLASSlIST_H
#define CLASSlIST_H
#include "data.h"
#include "LogicAnalysis.h"
#include "XLReader.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <QApplication>
#include <QDebug>
class ClassList{
private:
    std::vector <Group> groups;
    // возвращается в интерфейс
    std::vector <std::string> new_class_list;
public:
    void createGroups(std::vector <std::string>, std::vector <std::string>);
    std::vector <std::string> mySort(std::vector <std::string>);
    std::vector <std::string> getClassList();
    void setNewClassList(std::vector <std::string>);
    void convert(QString);
};

#endif
