#include <QApplication>
#include <QMouseEvent>
#include <QPainter>

#include "Model.h"
#include "View.h"
#include "Triangle.h"
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

    for (int i = 0; i < m_model.listLength(m_model.m_triangulation); ++i)
    {
        Triangle t = m_model.m_triangulation[i];
        painter.drawLine(t.m_va.m_x, t.m_va.m_y, t.m_vb.m_x, t.m_vb.m_y);
        painter.drawLine(t.m_vb.m_x, t.m_vb.m_y, t.m_vc.m_x, t.m_vc.m_y);
        painter.drawLine(t.m_vc.m_x, t.m_vc.m_y, t.m_va.m_x, t.m_va.m_y);
    }
}

void View::mousePressEvent(QMouseEvent* event)
{
    update();
}
