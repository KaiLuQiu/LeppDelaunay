#include <QApplication>
#include <QMouseEvent>
#include <QPainter>
#include "Model.h"
#include "View.h"
#include "Constants.h"

View::View(Model& model, QWidget* parent) : QWidget(parent), m_model(model)
{
}

void View::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    doPainting();
}

void View::doPainting()
{
    QPainter painter(this);
    QPen pen(Qt::black, 2);

    pen.setStyle(Qt::SolidLine);
    pen.setBrush(Qt::red);

    painter.setPen(pen);

    QLinearGradient grad1(0, 20, 0, 110);

    grad1.setColorAt(0.1, Qt::black);
    grad1.setColorAt(0.5, Qt::yellow);
    grad1.setColorAt(0.9, Qt::black);

    painter.fillRect(20, 20, 300, 90, grad1);

    QLinearGradient grad2(0, 55, 250, 0);

    grad2.setColorAt(0.2, Qt::black);
    grad2.setColorAt(0.5, Qt::red);
    grad2.setColorAt(0.8, Qt::black);

    painter.fillRect(20, 140, 300, 100, grad2);

    painter.drawEllipse(QPoint(m_model.m_x, m_model.m_y), 10, 10);
}

void View::mousePressEvent(QMouseEvent* event)
{
    m_model.setPointAt(event->x(), event->y());
    update();
}
