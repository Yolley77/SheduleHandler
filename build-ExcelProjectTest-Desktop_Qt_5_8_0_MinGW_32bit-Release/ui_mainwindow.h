/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QListWidget *listWidget_2;
    QPushButton *Generation;
    QPushButton *ShowAudiences;
    QPushButton *DeleteFile_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QListWidget *listWidget;
    QPushButton *Clear_2;
    QPushButton *AddFile_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *Audiences;
    QCheckBox *SelectAll;
    QVBoxLayout *verticalLayout_2;
    QPushButton *DeleteFile_3;
    QPushButton *Clear_3;
    QPushButton *AddFile_3;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(779, 645);
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(51, 51, 51);\n"
"color: rgb(231, 231, 231);"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(231, 231, 231);"));

        verticalLayout_4->addWidget(label_3, 0, Qt::AlignHCenter);

        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setStyleSheet(QLatin1String("color: rgb(51, 51, 51);\n"
"background-color: rgb(231, 231, 231);"));

        verticalLayout_4->addWidget(listWidget_2);


        gridLayout->addLayout(verticalLayout_4, 5, 1, 1, 2);

        Generation = new QPushButton(centralWidget);
        Generation->setObjectName(QStringLiteral("Generation"));
        Generation->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Generation->sizePolicy().hasHeightForWidth());
        Generation->setSizePolicy(sizePolicy);
        Generation->setStyleSheet(QLatin1String("background-color: rgb(70, 70, 70);\n"
"color: rgb(231, 231, 231);"));

        gridLayout->addWidget(Generation, 10, 0, 1, 3);

        ShowAudiences = new QPushButton(centralWidget);
        ShowAudiences->setObjectName(QStringLiteral("ShowAudiences"));
        sizePolicy.setHeightForWidth(ShowAudiences->sizePolicy().hasHeightForWidth());
        ShowAudiences->setSizePolicy(sizePolicy);
        ShowAudiences->setStyleSheet(QLatin1String("background-color: rgb(70, 70, 70);\n"
"color: rgb(231, 231, 231);"));

        gridLayout->addWidget(ShowAudiences, 9, 0, 1, 1);

        DeleteFile_2 = new QPushButton(centralWidget);
        DeleteFile_2->setObjectName(QStringLiteral("DeleteFile_2"));
        sizePolicy.setHeightForWidth(DeleteFile_2->sizePolicy().hasHeightForWidth());
        DeleteFile_2->setSizePolicy(sizePolicy);
        DeleteFile_2->setStyleSheet(QLatin1String("background-color: rgb(70, 70, 70);\n"
"color: rgb(231, 231, 231);"));

        gridLayout->addWidget(DeleteFile_2, 2, 1, 2, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(231, 231, 231);"));

        verticalLayout_3->addWidget(label_2, 0, Qt::AlignHCenter);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(0, 192));
        listWidget->setStyleSheet(QLatin1String("color: rgb(51, 51, 51);\n"
"background-color: rgb(231, 231, 231);"));

        verticalLayout_3->addWidget(listWidget);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 2);

        Clear_2 = new QPushButton(centralWidget);
        Clear_2->setObjectName(QStringLiteral("Clear_2"));
        sizePolicy.setHeightForWidth(Clear_2->sizePolicy().hasHeightForWidth());
        Clear_2->setSizePolicy(sizePolicy);
        Clear_2->setStyleSheet(QLatin1String("background-color: rgb(70, 70, 70);\n"
"color: rgb(231, 231, 231);"));

        gridLayout->addWidget(Clear_2, 2, 2, 2, 1);

        AddFile_2 = new QPushButton(centralWidget);
        AddFile_2->setObjectName(QStringLiteral("AddFile_2"));
        sizePolicy.setHeightForWidth(AddFile_2->sizePolicy().hasHeightForWidth());
        AddFile_2->setSizePolicy(sizePolicy);
        AddFile_2->setAutoFillBackground(false);
        AddFile_2->setStyleSheet(QLatin1String("background-color: rgb(70, 70, 70);\n"
"color: rgb(231, 231, 231);"));

        gridLayout->addWidget(AddFile_2, 1, 1, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(231, 231, 231);"));

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        Audiences = new QListWidget(centralWidget);
        Audiences->setObjectName(QStringLiteral("Audiences"));
        Audiences->setStyleSheet(QLatin1String("color: rgb(51, 51, 51);\n"
"background-color: rgb(231, 231, 231);\n"
"border-color: rgb(86, 86, 86);"));

        verticalLayout->addWidget(Audiences);

        SelectAll = new QCheckBox(centralWidget);
        SelectAll->setObjectName(QStringLiteral("SelectAll"));
        SelectAll->setStyleSheet(QStringLiteral("color: rgb(231, 231, 231);"));

        verticalLayout->addWidget(SelectAll);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        verticalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 8, 1);

        DeleteFile_3 = new QPushButton(centralWidget);
        DeleteFile_3->setObjectName(QStringLiteral("DeleteFile_3"));
        sizePolicy.setHeightForWidth(DeleteFile_3->sizePolicy().hasHeightForWidth());
        DeleteFile_3->setSizePolicy(sizePolicy);
        DeleteFile_3->setStyleSheet(QLatin1String("background-color: rgb(70, 70, 70);\n"
"color: rgb(231, 231, 231);"));

        gridLayout->addWidget(DeleteFile_3, 9, 1, 1, 1);

        Clear_3 = new QPushButton(centralWidget);
        Clear_3->setObjectName(QStringLiteral("Clear_3"));
        sizePolicy.setHeightForWidth(Clear_3->sizePolicy().hasHeightForWidth());
        Clear_3->setSizePolicy(sizePolicy);
        Clear_3->setStyleSheet(QLatin1String("background-color: rgb(70, 70, 70);\n"
"color: rgb(231, 231, 231);"));

        gridLayout->addWidget(Clear_3, 9, 2, 1, 1);

        AddFile_3 = new QPushButton(centralWidget);
        AddFile_3->setObjectName(QStringLiteral("AddFile_3"));
        sizePolicy.setHeightForWidth(AddFile_3->sizePolicy().hasHeightForWidth());
        AddFile_3->setSizePolicy(sizePolicy);
        AddFile_3->setStyleSheet(QLatin1String("background-color: rgb(70, 70, 70);\n"
"color: rgb(231, 231, 231);"));

        gridLayout->addWidget(AddFile_3, 6, 1, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 779, 20));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\274\320\260\320\263\320\270\321\201\321\202\321\200\320\260\321\202\321\203\321\200\321\213", Q_NULLPTR));
        Generation->setText(QApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        ShowAudiences->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\260\321\203\320\264\320\270\321\202\320\276\321\200\320\270\320\270", Q_NULLPTR));
        DeleteFile_2->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\261\320\260\320\272\320\260\320\273\320\260\320\262\321\200\320\270\320\260\321\202\320\260", Q_NULLPTR));
        Clear_2->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        AddFile_2->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\220\321\203\320\264\320\270\321\202\320\276\321\200\320\270\320\270", Q_NULLPTR));
        SelectAll->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\262\321\201\320\265", Q_NULLPTR));
        DeleteFile_3->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        Clear_3->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        AddFile_3->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
