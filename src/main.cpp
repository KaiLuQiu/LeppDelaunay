#include <QApplication>
#include "View.h"
#include "Constants.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    View window;

    window.resize(Constants::WIDTH, Constants::HEIGHT);
    window.setWindowTitle("Lepp Delaunay");
    window.show();

    return app.exec();
}
