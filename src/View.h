#ifndef _VIEW_H_
#define _VIEW_H_

#include <QWidget>
#include "Model.h"

class View : public QWidget
{
public:
    View(Model &model, QWidget* parent = 0);

protected:
    void paintEvent(QPaintEvent *e) override;
    void mousePressEvent(QMouseEvent * event) override;

private:
    Model m_model;

    void doPainting();
};

#endif // _VIEW_H_
