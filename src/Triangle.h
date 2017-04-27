#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Vertex.h"

class Triangle
{
    friend class Model;
    friend class Canvas;

public:
    /**
    * @brief Constructor Vacío. Inicia triángulos de área 0 en posición (0, 0).
    *
    */
    Triangle();

    /**
    * @brief Constructor de triángulos. Recibe los 3 vertex correspondientes.
    *
    * @param a p_a: Vertex a.
    * @param b p_b: Vertex b.
    * @param c p_c: Vertex c.
    */
    Triangle(Vertex a, Vertex b, Vertex c);

    /**
    * @brief Destructor de Triangle.
    *
    */
    ~Triangle();

    void operator=(const Triangle &t);

private:
    Vertex m_va;
    Vertex m_vb;
    Vertex m_vc;
};

#endif // _TRIANGLE_H_
