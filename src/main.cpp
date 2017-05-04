#include <QApplication>
#include "View.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Model model;
    View window(model);

    window.show();

    return app.exec();
}
