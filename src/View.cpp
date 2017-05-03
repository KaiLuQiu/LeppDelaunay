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

void View::setupUi(QWidget* view, Model &model)
{
    if (view->objectName().isEmpty())
        view->setObjectName(QStringLiteral("View"));
    view->setMinimumSize(Constants::WIDTH, Constants::HEIGHT + 80);

    canvas = new Canvas(model, view);
    canvas->setObjectName(QStringLiteral("canvas"));
    canvas->setGeometry(QRect(-1, -1, Constants::WIDTH, Constants::HEIGHT));

    label = new QLabel(view);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(QRect(50, 740, 500, 50));

    tolerance = new QLineEdit(view);
    tolerance->setObjectName(QStringLiteral("tolerance"));
    tolerance->setText(QString("10"));
    tolerance->setGeometry(QRect(550, 740, 150, 50));

    improveButton = new QPushButton(view);
    improveButton->setObjectName(QStringLiteral("improveButton"));
    improveButton->setGeometry(QRect(850, 740, 150, 50));

    resetButton = new QPushButton(view);
    resetButton->setObjectName(QStringLiteral("resetButton"));
    resetButton->setGeometry(QRect(1080, 740, 150, 50));

    retranslateUi(view);

    QObject::connect(tolerance, &QLineEdit::returnPressed, this, &View::prepareSendEnter);
    QObject::connect(this, &View::emitToleranceEnter, canvas, &Canvas::improve);
    QObject::connect(improveButton, &QAbstractButton::clicked, this, &View::prepareSend);
    QObject::connect(this, &View::emitTolerance, canvas, &Canvas::improve);
    QObject::connect(resetButton, &QAbstractButton::clicked, canvas, &Canvas::reset);

    QMetaObject::connectSlotsByName(view);
}

void View::retranslateUi(QWidget *view)
{
    view->setWindowTitle(QApplication::translate("View", "Lepp-Delaunay", Q_NULLPTR));

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
