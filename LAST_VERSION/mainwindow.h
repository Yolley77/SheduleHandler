#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ClassList.h"
#include <QMainWindow>
#include <vector>
#include <QApplication>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::vector <std::string> bachelors;
    std::vector <std::string> masters;
    std::vector <std::string> classrooms;
    ClassList classes;

private slots:
    void on_action_triggered();

    void on_action_2_triggered();

    void on_AddFile_2_clicked();

    void on_AddFile_3_clicked();

    std::vector <std::string> deletingRepetitions(std::vector <std::string> a);

    void on_ShowAudiences_clicked();

    void on_Generation_clicked();

    void on_DeleteFile_2_clicked();

    void on_DeleteFile_3_clicked();

    void on_Clear_2_clicked();

    void on_Clear_3_clicked();

    void on_SelectAll_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
