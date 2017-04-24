#ifndef _VIEW_H_
#define _VIEW_H_

#include <QWidget>

class View : public QWidget {

public:
    View(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *e);

private:
    void doPainting();
  };

#endif // _VIEW_H_
