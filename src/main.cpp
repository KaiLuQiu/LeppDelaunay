#include <QApplication>
#include "View.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    View view;
    view.show();

    return app.exec();
}
