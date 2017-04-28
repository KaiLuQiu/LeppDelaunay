#ifndef _EDGE_H_
#define _EDGE_H_

#include <iostream>
#include "Vertex.h"
#include "Angle.h"

class Edge
{
    friend class Triangle;
    friend std::ostream &operator<<(std::ostream &out, const Edge & edge);

public:
    /**
    * @brief Constructor de Edge.
    *
    * @param a p_a: Vertex a.
    * @param b p_b: Vertex b.
    */
    Edge(Vertex& a, Vertex& b);

    /**
    * @brief Destructor de Edge.
    *
    */
    ~Edge();

    /**
    * @brief Detecta ángulo respecto a otro edge, usando uno auxiliar. Se usa
    *        Ley de Cosenos.
    *
    * @param other p_other: Edge a comparar.
    * @param aux p_aux: Edge auxiliar.
    * @return Angle Ángulo calculado.
    */
    Angle angleAgainst(const Edge &other, const Edge &aux) const;

private:
    /**
    * @brief Calcula el largo del Edge y lo asigna internamente.
    *
    */
    void detectLength();

    Vertex m_va;
    Vertex m_vb;
    double m_length;
};

#endif // _EDGE_H_
