#include <QApplication>
#include "MainWindow.h"
#include "Constants.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUi(QWidget* MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QStringLiteral("MainWindow"));
    MainWindow->resize(Constants::WIDTH, Constants::HEIGHT + 80);

    view = new QWidget(MainWindow);
    view->setObjectName(QStringLiteral("view"));
    view->setGeometry(QRect(-1, -1, Constants::WIDTH, Constants::HEIGHT));

    improveButton = new QPushButton(MainWindow);
    improveButton->setObjectName(QStringLiteral("improveButton"));
    improveButton->setGeometry(QRect(440, 750, 160, 50));

    resetButton = new QPushButton(MainWindow);
    resetButton->setObjectName(QStringLiteral("resetButton"));
    resetButton->setGeometry(QRect(680, 750, 160, 50));

    retranslateUi(MainWindow);

    QObject::connect(improveButton, SIGNAL(clicked()), view, SLOT(update()));
    QObject::connect(resetButton, SIGNAL(clicked()), view, SLOT(update()));

    QMetaObject::connectSlotsByName(MainWindow);
}                                                           // setupUi

void MainWindow::retranslateUi(QWidget *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lepp-Delaunay", Q_NULLPTR));
    improveButton->setText(QApplication::translate("MainWindow", "Improve!", Q_NULLPTR));
    resetButton->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
}                                                           // retranslateUi
