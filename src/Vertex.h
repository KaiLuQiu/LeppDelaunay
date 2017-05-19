#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <iostream>

using namespace std;

class Vertex
{
    friend class Triangle;
    friend class Edge;
    friend class Canvas;
    friend class Model;
    friend ostream &operator<<(ostream &out, const Vertex & vertex);

public:
    /**
    * @brief Constructor vacío. Inicia a (0, 0).
    *
    */
    Vertex();

    /**
    * @brief Constructor de Vertex.
    *
    * @param x p_x: Coordenada x.
    * @param y p_y: Coordenada y.
    */
    Vertex(int x, int y);

    /**
    * @brief Constructor de copia.
    *
    * @param v p_v: Otro Vertex.
    */
    Vertex(const Vertex& v);

    /**
     * @brief Destructor de Vertex.
     *
     */
    ~Vertex();

    /**
    * @brief Overload de asignación.
    *
    * @param v p_v: Vertex a igualar.
    */
    Vertex& operator=(const Vertex &v);

    /**
    * @brief Overload de comparación de igualdad.
    *
    * @param v p_v: Vertex a comparar.
    * @return bool True si son iguales.
    */
    bool operator==(const Vertex &v) const;

    /**
    * @brief Overload de comparación de desigualdad.
    *
    * @param v p_v: Vertex a comparar.
    * @return bool True si son distintos.
    */
    bool operator!=(const Vertex &v) const;

private:
    int m_x;
    int m_y;
};

#endif // _VERTEX_H_
