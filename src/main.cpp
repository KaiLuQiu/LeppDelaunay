#include <QApplication>
#include "Canvas.h"
#include "MainWindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Model model;
    MainWindow mainwindow(model);

    mainwindow.show();

    return app.exec();
}
