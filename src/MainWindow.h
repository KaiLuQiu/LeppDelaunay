#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QWidget>
#include <QPushButton>
#include "Canvas.h"
#include "Model.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(Model model, QWidget* parent = 0);
    ~MainWindow();
    void setupUi(QWidget *MainWindow, Model &model);
    void retranslateUi(QWidget *MainWindow);

private:
    Canvas *canvas;
    QPushButton *improveButton;
    QPushButton *resetButton;

};

#endif // _MAINWINDOW_H_
