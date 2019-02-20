#include "mainwindow.h"
#include <QApplication>
#include "xlsxdocument.h"
#include "XLReader.h"
#include "XLWriter.h"
#include <QDebug>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
       MainWindow w;
       w.show();

       return a.exec();
}


