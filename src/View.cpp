#include <QApplication>
#include "View.h"
#include "Constants.h"

View::View(Model model, QWidget *parent) : QWidget(parent)
{
    setupUi(this, model);
}

View::~View()
{
    delete canvas;
    delete improveButton;
    delete resetButton;
}

void View::setupUi(QWidget* View, Model &model)
{
    if (View->objectName().isEmpty())
        View->setObjectName(QStringLiteral("View"));
    View->resize(Constants::WIDTH, Constants::HEIGHT + 80);

    canvas = new Canvas(model, View);
    canvas->setObjectName(QStringLiteral("canvas"));
    canvas->setGeometry(QRect(-1, -1, Constants::WIDTH, Constants::HEIGHT));

    improveButton = new QPushButton(View);
    improveButton->setObjectName(QStringLiteral("improveButton"));
    improveButton->setGeometry(QRect(440, 750, 160, 50));

    resetButton = new QPushButton(View);
    resetButton->setObjectName(QStringLiteral("resetButton"));
    resetButton->setGeometry(QRect(680, 750, 160, 50));

    retranslateUi(View);

    QObject::connect(improveButton, &QAbstractButton::clicked, canvas, &Canvas::improve);
    QObject::connect(resetButton, &QAbstractButton::clicked, canvas, &Canvas::reset);

    QMetaObject::connectSlotsByName(View);
}                                                           // setupUi

void View::retranslateUi(QWidget *View)
{
    View->setWindowTitle(QApplication::translate("View", "Lepp-Delaunay", Q_NULLPTR));
    improveButton->setText(QApplication::translate("View", "Improve!", Q_NULLPTR));
    resetButton->setText(QApplication::translate("View", "Reset", Q_NULLPTR));
}                                                           // retranslateUi
