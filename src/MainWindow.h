#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QWidget>
#include <QPushButton>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();
    void setupUi(QWidget *MainWindow);
    void retranslateUi(QWidget *MainWindow);

    QWidget *view;
    QPushButton *improveButton;
    QPushButton *resetButton;

};

#endif // _MAINWINDOW_H_
