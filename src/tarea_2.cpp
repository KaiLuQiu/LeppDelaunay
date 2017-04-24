#include "tarea_2.h"
#include "ui_tarea_2.h"

Tarea_2::Tarea_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tarea_2)
{
    ui->setupUi(this);
}

Tarea_2::~Tarea_2()
{
    delete ui;
}
