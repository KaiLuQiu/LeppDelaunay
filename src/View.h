#ifndef _VIEW_H_
#define _VIEW_H_

#include <QWidget>
#include "Model.h"

class View : public QWidget
{
public:
    /**
    * @brief Constructor de clase View.
    *
    * @param model p_model: Modelo Lepp-Delaunay.
    * @param parent p_parent: Ventana padre para Qt.
    */
    View(Model &model, QWidget* parent = 0);

protected:
    /**
    * @brief Método usado por Qt para pintar el QWidget.
    *
    * @param e p_e: Evento no usado.
    */
    void paintEvent(QPaintEvent *e) override;

    /**
    * @brief Método usado por Qt para actuar frente a un click de mouse.
    *
    * @param event p_event: Evento detectado.
    */
    void mousePressEvent(QMouseEvent * event) override;

private:
    Model m_model;

    /**
    * @brief Genera el "pintado" del widget. Llamado por paintEvent.
    *
    */
    void doPainting();
};

#endif // _VIEW_H_
