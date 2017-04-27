#include <QApplication>
#include "View.h"
#include "MainWindow.h"
#include "Constants.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Model model;
    MainWindow mainwindow;
//     View window(model, &mainwindow);

    mainwindow.show();

    return app.exec();
}
