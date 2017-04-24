/********************************************************************************
** Form generated from reading UI file 'tarea_2.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAREA_2_H
#define UI_TAREA_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tarea_2
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tarea_2)
    {
        if (Tarea_2->objectName().isEmpty())
            Tarea_2->setObjectName(QStringLiteral("Tarea_2"));
        Tarea_2->resize(400, 300);
        menuBar = new QMenuBar(Tarea_2);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Tarea_2->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tarea_2);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Tarea_2->addToolBar(mainToolBar);
        centralWidget = new QWidget(Tarea_2);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Tarea_2->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Tarea_2);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Tarea_2->setStatusBar(statusBar);

        retranslateUi(Tarea_2);

        QMetaObject::connectSlotsByName(Tarea_2);
    } // setupUi

    void retranslateUi(QMainWindow *Tarea_2)
    {
        Tarea_2->setWindowTitle(QApplication::translate("Tarea_2", "Tarea_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Tarea_2: public Ui_Tarea_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAREA_2_H
