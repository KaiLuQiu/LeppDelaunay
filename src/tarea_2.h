#ifndef TAREA_2_H
#define TAREA_2_H

#include <QMainWindow>

namespace Ui {
class Tarea_2;
}

class Tarea_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tarea_2(QWidget *parent = 0);
    ~Tarea_2();

private:
    Ui::Tarea_2 *ui;
};

#endif // TAREA_2_H
