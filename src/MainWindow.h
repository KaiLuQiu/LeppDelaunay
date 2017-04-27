#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QWidget>
#include <QPushButton>
#include "View.h"
#include "Model.h"

class View;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(Model model, QWidget* parent = 0);
    ~MainWindow();
    void setupUi(QWidget *MainWindow, Model model);
    void retranslateUi(QWidget *MainWindow);

    View *view;
    QPushButton *improveButton;
    QPushButton *resetButton;

};

#endif // _MAINWINDOW_H_
