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
    View->resize(Constants::WIDTH, Constants::HEIGHT + 80);

    canvas = new Canvas(model, View);
    canvas->setObjectName(QStringLiteral("canvas"));
    canvas->setGeometry(QRect(-1, -1, Constants::WIDTH, Constants::HEIGHT));

    label = new QLabel(View);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(QRect(50, 750, 500, 50));

    tolerance = new QLineEdit(View);
    tolerance->setObjectName(QStringLiteral("tolerance"));
    tolerance->setText(QString("30"));
    tolerance->setGeometry(QRect(650, 750, 150, 50));

    improveButton = new QPushButton(View);
    improveButton->setObjectName(QStringLiteral("improveButton"));
    improveButton->setGeometry(QRect(880, 750, 150, 50));

    resetButton = new QPushButton(View);
    resetButton->setObjectName(QStringLiteral("resetButton"));
    resetButton->setGeometry(QRect(1080, 750, 150, 50));
//     FIXME Este texto (int) hay que enviarlo al modelo con SIGNAL/SLOT
//     tolerance->text().toInt();

    retranslateUi(View);

//     QObject::connect(tolerance, &QLineEdit::copy, canvas, &Canvas::improve);
//     QObject::connect(improveButton, &QAbstractButton::clicked, canvas, &Canvas::improve);
    QObject::connect(resetButton, &QAbstractButton::clicked, canvas, &Canvas::reset);

    QMetaObject::connectSlotsByName(View);
}

void View::retranslateUi(QWidget *View)
{
    View->setWindowTitle(QApplication::translate("View", "Lepp-Delaunay", Q_NULLPTR));

    label->setText(QApplication::translate("Form", "Ingrese ángulo de tolerancia (en grados):", Q_NULLPTR));
    improveButton->setText(QApplication::translate("View", "Improve!", Q_NULLPTR));
    resetButton->setText(QApplication::translate("View", "Reset", Q_NULLPTR));
}
