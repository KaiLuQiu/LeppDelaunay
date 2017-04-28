#ifndef _VIEW_H_
#define _VIEW_H_

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "Canvas.h"
#include "Model.h"

class View : public QWidget
{
    Q_OBJECT

public:
    /**
    * @brief Constructor de View. Recibe un modelo y el padre de este QWidget.
    *
    * @param model p_model: Modelo recibido.
    * @param parent p_parent: QWidget padre.
    */
    View(Model model, QWidget* parent = 0);

    /**
    * @brief Destructor de View.
    *
    */
    ~View();

    /**
    * @brief Configurador de GUI inicial.
    *
    * @param View p_View: QWidget a configurar (this).
    * @param model p_model: Modelo a usar (para pasarlo al Canvas).
    */
    void setupUi(QWidget *View, Model &model);

    /**
    * @brief "Traductor" que escribe los nombres de los botones y labels.
    *
    * @param View p_View: QWidget a configurar (this).
    */
    void retranslateUi(QWidget *View);

public slots:
    void prepareSend();
    void prepareSendEnter();

signals:
    void emitTolerance(const int tolerance);
    void emitToleranceEnter(const int tolerance);

private:
    Canvas *canvas;
    QLabel *label;
    QLineEdit *tolerance;
    QPushButton *improveButton;
    QPushButton *resetButton;
};

#endif // _VIEW_H_
