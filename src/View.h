#ifndef _VIEW_H_
#define _VIEW_H_

#include <QWidget>
#include <QPushButton>
#include "Canvas.h"
#include "Model.h"

class View : public QWidget
{
    Q_OBJECT

public:
    View(Model model, QWidget* parent = 0);
    ~View();
    void setupUi(QWidget *View, Model &model);
    void retranslateUi(QWidget *View);

private:
    Canvas *canvas;
    QPushButton *improveButton;
    QPushButton *resetButton;

};

#endif // _VIEW_H_
