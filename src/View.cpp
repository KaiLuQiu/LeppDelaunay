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
    delete label;
    delete tolerance;
}

void View::setupUi(QWidget* View, Model &model)
{
    if (View->objectName().isEmpty())
        View->setObjectName(QStringLiteral("View"));
    View->setMinimumSize(Constants::WIDTH, Constants::HEIGHT + 80);

    canvas = new Canvas(model, View);
    canvas->setObjectName(QStringLiteral("canvas"));
    canvas->setGeometry(QRect(-1, -1, Constants::WIDTH, Constants::HEIGHT));

    label = new QLabel(View);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(QRect(50, 740, 500, 50));

    tolerance = new QLineEdit(View);
    tolerance->setObjectName(QStringLiteral("tolerance"));
    tolerance->setText(QString("30"));
    tolerance->setGeometry(QRect(550, 740, 150, 50));

    improveButton = new QPushButton(View);
    improveButton->setObjectName(QStringLiteral("improveButton"));
    improveButton->setGeometry(QRect(850, 740, 150, 50));

    resetButton = new QPushButton(View);
    resetButton->setObjectName(QStringLiteral("resetButton"));
    resetButton->setGeometry(QRect(1080, 740, 150, 50));

    retranslateUi(View);

    QObject::connect(tolerance, &QLineEdit::returnPressed, this, &View::prepareSendEnter);
    QObject::connect(this, &View::emitToleranceEnter, canvas, &Canvas::improve);
    QObject::connect(improveButton, &QAbstractButton::clicked, this, &View::prepareSend);
    QObject::connect(this, &View::emitTolerance, canvas, &Canvas::improve);
    QObject::connect(resetButton, &QAbstractButton::clicked, canvas, &Canvas::reset);

    QMetaObject::connectSlotsByName(View);
}

void View::retranslateUi(QWidget *View)
{
    View->setWindowTitle(QApplication::translate("View", "Lepp-Delaunay", Q_NULLPTR));

    label->setText(QApplication::translate("Form", "Insert tolerance angle (in degrees):", Q_NULLPTR));
    improveButton->setText(QApplication::translate("View", "Improve!", Q_NULLPTR));
    resetButton->setText(QApplication::translate("View", "Reset", Q_NULLPTR));
}

void View::prepareSend()
{
    const double tol = tolerance->text().toDouble();
    emit emitTolerance(tol);
}

void View::prepareSendEnter()
{
    const double tol = tolerance->text().toDouble();
    emit emitToleranceEnter(tol);
}
