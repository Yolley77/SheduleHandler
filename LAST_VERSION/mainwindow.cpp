#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <qurl>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ListWidget = расписание бакалавриата
//ListWidget_2 = расписание магистратуры

void MainWindow::on_action_triggered()//Справка
{
    QString c = ("1. Добавьте файлы расписаний с помощью кнопок \"Добавить файл\".\n"
                 "2. Нажмите кнопку \"Показать аудитории\" и выберите аудитории, расписание на которые желаете получить. \n"
                 "3. Нажмите кнопку \"Сгенерировать файл\" для получения расписания на выбранные аудитории.");
    QMessageBox::information(this, "Справка", c);
    qApp->setStyleSheet("QMessageBox { color: white;}");
}


void MainWindow::on_action_2_triggered()//Выход из программы
{
    QMessageBox::StandardButton ex = QMessageBox::question(this, "Выход", "Вы действительно хотите выйти?", QMessageBox::Yes | QMessageBox::No);
    if (ex == QMessageBox::Yes){
        QApplication::exit();
    }
}


std::vector <std::string> MainWindow::deletingRepetitions(std::vector <std::string> a) { //Удаление одинаковых элементов в векторе
    for(unsigned int i = 0; i < a.size()-1; i++) {
        for (unsigned int j = i + 1; j < a.size(); j++) {
            if(a[i] == a[j]) {
                a.erase(a.begin()+j);
            }
        }
    }
    return a;
}


void MainWindow::on_AddFile_2_clicked() //Добавление файлов с расписанием бакалавров
{
    ui->listWidget->clear();
    QStringList path = QFileDialog::getOpenFileNames(0, "Выбор файла", QDir::homePath(), "*.xlsx");
    for(int i = 0; i < path.size(); i ++) {
        bachelors.push_back(path[i].toStdString());
    }
    bachelors = deletingRepetitions(bachelors);
    for(unsigned int i = 0; i < bachelors.size(); i ++) {
        QString q = QString::fromStdString(bachelors[i]);
        ui->listWidget->addItem(q);
    }
}


void MainWindow::on_AddFile_3_clicked() // Добавление файлов с расписанием магистров
{
    ui->listWidget_2->clear();
    QStringList path = QFileDialog::getOpenFileNames(0, "Выбор файла", QDir::homePath(), "*.xlsx");
    for(int i = 0; i < path.size(); i ++) {
        masters.push_back(path[i].toStdString());
    }
    masters = deletingRepetitions(masters);
    for(unsigned int i = 0; i < masters.size(); i ++) {
        QString q = QString::fromStdString(masters[i]);
        ui->listWidget_2->addItem(q);
    }
}



void MainWindow::on_ShowAudiences_clicked() // Показ всех аудиторий (чтобы выбрать из них нужные)
{
    ui->Audiences->clear();
    std::vector <std::string> audiences;
    classes.createGroups(bachelors, masters);
    audiences = classes.getClassList();
    for(unsigned i = 0; i < audiences.size(); i++) {
        QString qstr = QString::fromStdString(audiences[i]);
        QListWidgetItem *item = new QListWidgetItem(qstr, ui->Audiences);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }

}


void MainWindow::on_Generation_clicked() //Генерация файла расписания
{
    int cnt = ui->Audiences->count()-1;
    for (int i = 0; i < cnt; i++) {
        QListWidgetItem *it = ui->Audiences->item(i);
        if(it->checkState()) {
            classrooms.push_back(it->text().toStdString());
        }
    }
    classes.setNewClassList(classrooms);
    QString filename = QFileDialog::getSaveFileName(0, "Сохранение файла", QDir::homePath(),"Excell (*.xlsx)");
    classes.convert(filename);
}


void MainWindow::on_DeleteFile_2_clicked()//Удаление файла из списка расписания бакалавриата
{
    QMessageBox::StandardButton del = QMessageBox::question(this, "Удаление из списка", "Вы действительно хотите удалить файл из списка?", QMessageBox::Yes | QMessageBox::No);
    if (del == QMessageBox::Yes){
        if(ui->listWidget->currentItem() != 0) {
            int cnt = ui->listWidget->count() - 1;
            int c;
            for (int i = 0; i < cnt; i++) {
                if (ui->listWidget->currentItem() == ui->listWidget->item(i)) {
                    c = i;
                }
            }
            bachelors.erase(bachelors.begin() + c);
            delete ui->listWidget->currentItem();
        }
    }
}


void MainWindow::on_DeleteFile_3_clicked()//Удаление файла из списка расписания магистратуры
{
    QMessageBox::StandardButton del = QMessageBox::question(this, "Удаление из списка", "Вы действительно хотите удалить файл из списка?", QMessageBox::Yes | QMessageBox::No);
    if (del == QMessageBox::Yes){
        if(ui->listWidget_2->currentItem() != 0) {
            int cnt = ui->listWidget_2->count() - 1;
            int c;
            for (int i = 0; i < cnt; i++) {
                if (ui->listWidget_2->currentItem() == ui->listWidget_2->item(i)) {
                    c = i;
                }
            }
            masters.erase(masters.begin() + c);
            delete ui->listWidget_2->currentItem();
        }
    }
}


void MainWindow::on_Clear_2_clicked()//Очистка списка расписания бакалавриата
{
    QMessageBox::StandardButton del = QMessageBox::question(this, "Удаление из списка", "Вы действительно хотите очистить список?", QMessageBox::Yes | QMessageBox::No);
    if (del == QMessageBox::Yes){
        bachelors.resize(0);
        ui->listWidget->clear();
    }
}


void MainWindow::on_Clear_3_clicked()//Очистка списка расписания магистратуры
{
    QMessageBox::StandardButton del = QMessageBox::question(this, "Удаление из списка", "Вы действительно хотите очистить список?", QMessageBox::Yes | QMessageBox::No);
    if (del == QMessageBox::Yes){
        masters.resize(0);
        ui->listWidget_2->clear();
    }
}


void MainWindow::on_SelectAll_stateChanged(int arg1) // Кнопка Выбрать все
{
    if (arg1) {
        int cnt = ui->Audiences->count();
        for(int i = 0; i < cnt; i++) {
            QListWidgetItem *it = ui->Audiences->item(i);
            it->setCheckState(Qt::Checked);
        }
    }
    else {
        int cnt = ui->Audiences->count();
        for(int i = 0; i < cnt; i++) {
            QListWidgetItem *it = ui->Audiences->item(i);
            it->setCheckState(Qt::Unchecked);
        }
    }
}
