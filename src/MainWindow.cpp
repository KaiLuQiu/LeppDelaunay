#include <QApplication>
#include "MainWindow.h"
#include "Constants.h"

MainWindow::MainWindow(Model model, QWidget *parent) : QWidget(parent)
{
    setupUi(this, model);
}

MainWindow::~MainWindow()
{
    delete view;
    delete improveButton;
    delete resetButton;
}

void MainWindow::setupUi(QWidget* MainWindow, Model &model)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QStringLiteral("MainWindow"));
    MainWindow->resize(Constants::WIDTH, Constants::HEIGHT + 80);

    view = new View(model, MainWindow);
    view->setObjectName(QStringLiteral("view"));
    view->setGeometry(QRect(-1, -1, Constants::WIDTH, Constants::HEIGHT));

    improveButton = new QPushButton(MainWindow);
    improveButton->setObjectName(QStringLiteral("improveButton"));
    improveButton->setGeometry(QRect(440, 750, 160, 50));

    resetButton = new QPushButton(MainWindow);
    resetButton->setObjectName(QStringLiteral("resetButton"));
    resetButton->setGeometry(QRect(680, 750, 160, 50));

    retranslateUi(MainWindow);

    QObject::connect(improveButton, &QAbstractButton::clicked, view, &View::improve);
    QObject::connect(resetButton, &QAbstractButton::clicked, view, &View::reset);

    QMetaObject::connectSlotsByName(MainWindow);
}                                                           // setupUi

void MainWindow::retranslateUi(QWidget *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lepp-Delaunay", Q_NULLPTR));
    improveButton->setText(QApplication::translate("MainWindow", "Improve!", Q_NULLPTR));
    resetButton->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
}                                                           // retranslateUi
