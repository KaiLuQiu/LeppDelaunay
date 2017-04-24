#ifndef _VIEW_H_
#define _VIEW_H_

#include <QMainWindow>

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();

private:

};

#endif // _VIEW_H_
