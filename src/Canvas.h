#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <QWidget>
#include "Model.h"

class Canvas : public QWidget
{
public:
    /**
    * @brief Constructor de clase Canvas.
    *
    * @param model p_model: Modelo Lepp-Delaunay.
    * @param parent p_parent: Ventana padre para Qt.
    */
    Canvas(Model &model, QWidget* parent = 0);

public slots:
    void improve();
    void reset();

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

#endif // _CANVAS_H_
