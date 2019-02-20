#include <iostream>
#include "XLWriter.h"

int XLWriter::toTrueCol(int col){
    int true_col = -4;
    for (int i = 0; i < col; i ++){
        if (i % 3 == 0){
            true_col += 6;
        }
        true_col += 5;
    }
    return true_col;
}





void XLWriter::write(QXlsx::Document *file, int* row, int col, std::vector <QVariant> data){
    (*row)++;
    col = XLWriter::toTrueCol(col);
    for (int i = 0; i < 5; i++){
        (*file).write ((*row), col + i, data[i]);

    }
}

void XLWriter::writeClassroom(QXlsx::Document *file, int col, QVariant name_room){
    col = XLWriter::toTrueCol(col);
    (*file).write(1, col, name_room);
}




void XLWriter::formating (int column, double width, char side) {
    for(int i = 0; i < 6; i++) {            // Форматирование ячеек
        QXlsx::Format bachTop;
        QXlsx::Format bachBottom;

        bachTop.setBorderStyle(QXlsx::Format::BorderThin);
        bachTop.setTopBorderStyle(QXlsx::Format::BorderMedium);
        bachTop.setHorizontalAlignment(QXlsx::Format::AlignHCenter);

        bachBottom.setBorderStyle(QXlsx::Format::BorderThin);
        bachBottom.setVerticalAlignment(QXlsx::Format::AlignVCenter);
        bachBottom.setBottomBorderStyle(QXlsx::Format::BorderMedium);

        doc->setColumnWidth(column, width);

        QXlsx::Format mag_1;
        QXlsx::Format mag_2;
        QXlsx::Format mag_3;
        QXlsx::Format mag_4;
        mag_1.setBorderStyle(QXlsx::Format::BorderThin);
        mag_2.setBorderStyle(QXlsx::Format::BorderThin);
        mag_3.setBorderStyle(QXlsx::Format::BorderThin);
        mag_4.setBorderStyle(QXlsx::Format::BorderThin);

        mag_1.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
        mag_2.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
        mag_3.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
        mag_4.setHorizontalAlignment(QXlsx::Format::AlignHCenter);

        mag_1.setVerticalAlignment(QXlsx::Format::AlignVCenter);
        mag_2.setVerticalAlignment(QXlsx::Format::AlignVCenter);
        mag_3.setVerticalAlignment(QXlsx::Format::AlignVCenter);
        mag_4.setVerticalAlignment(QXlsx::Format::AlignVCenter);

        mag_1.setTopBorderStyle(QXlsx::Format::BorderThick);
        mag_2.setBottomBorderStyle(QXlsx::Format::BorderMedium);
        mag_4.setBottomBorderStyle(QXlsx::Format::BorderThick);

        switch (side) {
        case 'r':
            bachTop.setRightBorderStyle(QXlsx::Format::BorderThick);
            bachBottom.setRightBorderStyle(QXlsx::Format::BorderThick);
            mag_1.setRightBorderStyle(QXlsx::Format::BorderThick);
            mag_2.setRightBorderStyle(QXlsx::Format::BorderThick);
            mag_3.setRightBorderStyle(QXlsx::Format::BorderThick);
            mag_4.setRightBorderStyle(QXlsx::Format::BorderThick);
            break;
        case 't':
            bachTop.setTopBorderStyle(QXlsx::Format::BorderThick);
            bachBottom.setTopBorderStyle(QXlsx::Format::BorderThick);
            mag_1.setTopBorderStyle(QXlsx::Format::BorderThick);
            mag_2.setTopBorderStyle(QXlsx::Format::BorderThick);
            mag_3.setTopBorderStyle(QXlsx::Format::BorderThick);
            mag_4.setTopBorderStyle(QXlsx::Format::BorderThick);
            break;
        default: break;
        }

        for(int j = 0; j < 6; j++) {
            doc->write(3+j*2+i*16, column, "", bachTop);
            doc->write(4+j*2+i*16, column, "", bachBottom);
        }

        doc->write(15+i*16, column, "", mag_1);
        doc->write(16+i*16, column, "", mag_2);
        doc->write(17+i*16, column, "", mag_3);
        doc->write(18+i*16, column, "", mag_4);
    }
}


void XLWriter::createHeader(int row, int column) {
    doc->setRowHeight(1, 99, 50); // Высота всех строк в документе
    for (int i = 0; i < 6; i++) {
        doc->setColumnWidth(column + i, 8.85);
    }
    for(int i = 0; i < 3; i++) { // Ширина колонки задаётся с поправкой  -0.71, вид занятий и ещё чёто
        doc->setColumnWidth(8+i*5, 8.85);
        doc->setColumnWidth(11+i*5, 8.85);
    }
    for(int i = 0; i < 2; i++) {
        QXlsx::CellRange cells_1(row, column+i, row+1, column+i);
        QXlsx::Format headers_1;
        headers_1.setBorderStyle(QXlsx::Format::BorderThin);
        headers_1.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
        headers_1.setVerticalAlignment(QXlsx::Format::AlignVCenter);
        doc->mergeCells(cells_1, headers_1);

        switch (i) {
        case 0:
            doc->write(row, column, "День недели");
            break;
        case 1:
            doc->write(row, column+1, "Форма обучения");
            break;
        }
    }
    QXlsx::CellRange cells_2(row, column+2, row, column+5);
    QXlsx::Format headers_2;
    headers_2.setBorderStyle(QXlsx::Format::BorderThin);
    headers_2.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    headers_2.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    headers_2.setRightBorderStyle(QXlsx::Format::BorderThick);
    doc->mergeCells(cells_2, headers_2);
    doc->write(row, column+2, "Аудитория");

    QXlsx::Format headers_3;
    headers_3.setBorderStyle(QXlsx::Format::BorderThin);
    headers_3.setBottomBorderStyle(QXlsx::Format::BorderThick);
    headers_3.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    headers_3.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    doc->write(row+1, column+2, "№ пары", headers_3);
    doc->write(row+1, column+3, "Нач. занятий", headers_3);
    doc->write(row+1, column+4, "Оконч. занятий", headers_3);

    headers_3.setRightBorderStyle(QXlsx::Format::BorderThick);
    doc->write(row+1, column+5, "Неделя", headers_3);

    for(int i = 0; i < 3; i++) {
        QXlsx::CellRange cells_4(row, column+6+i*5, row, column+10+i*5);
        QXlsx::Format headers_4;
        headers_4.setBorderStyle(QXlsx::Format::BorderThin);
        headers_4.setRightBorderStyle(QXlsx::Format::BorderThick);
        headers_4.setVerticalAlignment(QXlsx::Format::AlignVCenter);
        headers_4.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
        doc->mergeCells(cells_4, headers_4);

        QXlsx::Format headers_5;
        headers_5.setBorderStyle(QXlsx::Format::BorderThin);
        headers_5.setBottomBorderStyle(QXlsx::Format::BorderThick);
        headers_5.setVerticalAlignment(QXlsx::Format::AlignVCenter);
        headers_5.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
        doc->write(row+1, column+6+i*5, "Предмет", headers_5);
        doc->write(row+1, column+7+i*5, "Вид занятий", headers_5);
        doc->write(row+1, column+8+i*5, "ФИО преподавателя", headers_5);
        doc->write(row+1, column+9+i*5, "Учебные группы", headers_5);
        headers_5.setRightBorderStyle(QXlsx::Format::BorderThick);
        doc->write(row+1, column+10+i*5, "Макс. число человек", headers_5);
    }
}


void XLWriter::createWeekdays(int row, int column) {
    for(int i = 0; i < 6; i++) {            // объединение ячеек под дни недели
        QXlsx::CellRange cells(row+i*16, column, row+15+i*16, column);
        QXlsx::Format weekdays;
        weekdays.setBorderStyle(QXlsx::Format::BorderThick);
        weekdays.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
        weekdays.setVerticalAlignment(QXlsx::Format::AlignVCenter);
        doc->mergeCells(cells, weekdays);
        switch(i) {
            case 0: doc->write(row+i*16, column, "ПОНЕДЕЛЬНИК"); break;
            case 1: doc->write(row+i*16, column, "ВТОРНИК"); break;
            case 2: doc->write(row+i*16, column, "СРЕДА"); break;
            case 3: doc->write(row+i*16, column, "ЧЕТВЕРГ"); break;
            case 4: doc->write(row+i*16, column, "ПЯТНИЦА"); break;
            case 5: doc->write(row+i*16, column, "СУББОТА"); break;
        }
    }
}

void XLWriter::createBachelorsMasters(int column) {
    for(int i = 0; i < 6; i++) {            // объединение под бакалавриат/магистратуру
        QXlsx::CellRange bachCells(3+i*16, column, 14+i*16, column);
        QXlsx::CellRange magCells(15+i*16, column, 18+i*16, column);
        QXlsx::Format educationType;
        educationType.setBorderStyle(QXlsx::Format::BorderThick);
        educationType.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
        educationType.setVerticalAlignment(QXlsx::Format::AlignVCenter);
        doc->mergeCells(bachCells, educationType);
        doc->write(3+i*16, column, "Бакалавриат");
        doc->mergeCells(magCells, educationType);
        doc->write(15+i*16, column, "Магистратура");
    }
}

void XLWriter::createPairData(int column) {
    for(int i = 0; i < 6; i++) {           // объединение номер, начало, конец пары, чётность

         QXlsx::Format bachPairs;
         bachPairs.setBorderStyle(QXlsx::Format::BorderThin);
         bachPairs.setTopBorderStyle(QXlsx::Format::BorderMedium);
         bachPairs.setBottomBorderStyle(QXlsx::Format::BorderMedium);
         bachPairs.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
         bachPairs.setVerticalAlignment(QXlsx::Format::AlignVCenter);

         QXlsx::Format magPairs_1;
         QXlsx::Format magPairs_2;
         magPairs_1.setBorderStyle(QXlsx::Format::BorderThin);
         magPairs_2.setBorderStyle(QXlsx::Format::BorderThin);
         magPairs_1.setTopBorderStyle(QXlsx::Format::BorderThick);
         magPairs_1.setBottomBorderStyle(QXlsx::Format::BorderMedium);
         magPairs_2.setTopBorderStyle(QXlsx::Format::BorderMedium);
         magPairs_2.setBottomBorderStyle(QXlsx::Format::BorderThick);
         magPairs_1.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
         magPairs_1.setVerticalAlignment(QXlsx::Format::AlignVCenter);
         magPairs_2.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
         magPairs_2.setVerticalAlignment(QXlsx::Format::AlignVCenter);

         QXlsx::Format bachParityI;
         QXlsx::Format bachParityII;
         bachParityI.setBorderStyle(QXlsx::Format::BorderThin);
         bachParityI.setTopBorderStyle(QXlsx::Format::BorderMedium);
         bachParityI.setRightBorderStyle(QXlsx::Format::BorderThick);
         bachParityI.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
         bachParityI.setVerticalAlignment(QXlsx::Format::AlignVCenter);
         bachParityII.setBorderStyle(QXlsx::Format::BorderThin);
         bachParityII.setRightBorderStyle(QXlsx::Format::BorderThick);
         bachParityII.setBottomBorderStyle(QXlsx::Format::BorderMedium);
         bachParityII.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
         bachParityII.setVerticalAlignment(QXlsx::Format::AlignVCenter);

         QXlsx::Format magParityI_1;
         QXlsx::Format magParityI_2;
         QXlsx::Format magParityII_1;
         QXlsx::Format magParityII_2;

         magParityI_1.setBorderStyle(QXlsx::Format::BorderThin);
         magParityI_2.setBorderStyle(QXlsx::Format::BorderThin);
         magParityII_1.setBorderStyle(QXlsx::Format::BorderThin);
         magParityII_2.setBorderStyle(QXlsx::Format::BorderThin);

         magParityI_1.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
         magParityI_1.setVerticalAlignment(QXlsx::Format::AlignVCenter);
         magParityI_2.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
         magParityI_2.setVerticalAlignment(QXlsx::Format::AlignVCenter);
         magParityII_1.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
         magParityII_1.setVerticalAlignment(QXlsx::Format::AlignVCenter);
         magParityII_2.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
         magParityII_2.setVerticalAlignment(QXlsx::Format::AlignVCenter);

         magParityI_1.setTopBorderStyle(QXlsx::Format::BorderThick);
         magParityI_1.setRightBorderStyle(QXlsx::Format::BorderThick);
         magParityI_2.setBottomBorderStyle(QXlsx::Format::BorderMedium);
         magParityI_2.setRightBorderStyle(QXlsx::Format::BorderThick);
         magParityII_1.setRightBorderStyle(QXlsx::Format::BorderThick);
         magParityII_2.setBottomBorderStyle(QXlsx::Format::BorderThick);
         magParityII_2.setRightBorderStyle(QXlsx::Format::BorderThick);

         for(int j = 0; j < 6; j++) {           // Запись для бакалавриата
             QXlsx::CellRange pairNumCells(3+j*2+i*16, column, 4+j*2+i*16, column);
             doc->mergeCells(pairNumCells, bachPairs);
             doc->write(3+j*2+i*16, column, j+1);

             QXlsx::CellRange pairBeginCells(3+j*2+i*16, column+1, 4+j*2+i*16, column+1);
             doc->mergeCells(pairBeginCells, bachPairs);
             switch(j) {
                 case 0: doc->write(3+j*2+i*16, column+1, "9-00"); break;
                 case 1: doc->write(3+j*2+i*16, column+1, "10-40"); break;
                 case 2: doc->write(3+j*2+i*16, column+1, "13-00"); break;
                 case 3: doc->write(3+j*2+i*16, column+1, "14-40"); break;
                 case 4: doc->write(3+j*2+i*16, column+1, "16-20"); break;
                 case 5: doc->write(3+j*2+i*16, column+1, "18-00"); break;
             }

             QXlsx::CellRange pairEndCells(3+j*2+i*16, column+2, 4+j*2+i*16, column+2);
             doc->mergeCells(pairEndCells, bachPairs);
             switch(j) {
                 case 0: doc->write(3+j*2+i*16, column+2, "10-30"); break;
                 case 1: doc->write(3+j*2+i*16, column+2, "12-10"); break;
                 case 2: doc->write(3+j*2+i*16, column+2, "14-30"); break;
                 case 3: doc->write(3+j*2+i*16, column+2, "16-10"); break;
                 case 4: doc->write(3+j*2+i*16, column+2, "17-50"); break;
                 case 5: doc->write(3+j*2+i*16, column+2, "19-30"); break;
             }
         }

         for(int j = 0; j < 2; j++) {           //Запись для магистратуры
             QXlsx::CellRange magPairNumCells(15+j*2+i*16, column, 16+j*2+i*16, column);
             QXlsx::CellRange magPairBeginCells(15+j*2+i*16, column+1, 16+j*2+i*16, column+1);
             QXlsx::CellRange madPairEndCells(15+j*2+i*16, column+2, 16+j*2+i*16, column+2);
             if(j == 0) {
                 doc->mergeCells(magPairNumCells, magPairs_1);
                 doc->write(15+j*2+i*16, column, 7+j);

                 doc->mergeCells(magPairBeginCells, magPairs_1);
                 doc->write(15+j*2+i*16, column+1, "18-30");

                 doc->mergeCells(madPairEndCells, magPairs_1);
                 doc->write(15+j*2+i*16, column+2, "20-00");
             }
             else {
                 doc->mergeCells(magPairNumCells, magPairs_2);
                 doc->write(15+j*2+i*16, column, 7+j);

                 doc->mergeCells(magPairBeginCells, magPairs_2);
                 doc->write(15+j*2+i*16, column+1, "20-10");

                 doc->mergeCells(madPairEndCells, magPairs_2);
                 doc->write(15+j*2+i*16, column+2, "21-40");
             }

         }

         for(int j = 0; j < 6; j++) {           // Запись чётности недели для бакалавров и магистров
             doc->write(3+j*2+i*16, column+3, "I", bachParityI);
             doc->write(4+j*2+i*16, column+3, "II", bachParityII);
         }

         doc->write(15+i*16, column+3, "I", magParityI_1);
         doc->write(16+i*16, column+3, "II", magParityI_2);
         doc->write(17+i*16, column+3, "I", magParityII_1);
         doc->write(18+i*16, column+3, "II", magParityII_2);

    }
}

void XLWriter::createShedule(int column) {
    createHeader(1, column);
    createWeekdays(3, column);
    createBachelorsMasters(column+1);
    createPairData(column+2);

    for (int i = 0; i < 3; i++) {
        formating(column+6+i*5, 66.28, ' ');
        formating(column+7+i*5, 8.85, ' ');
        formating(column+8+i*5, 28.71, ' ');
        formating(column+9+i*5, 35.00, ' ');
        formating(column+10+i*5, 8.85, 'r');
    }
}

