#ifndef _VERTEX_H_
#define _VERTEX_H_

class Vertex
{
    friend class Triangle;
    friend class View;

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
     * @brief Destructor de Vertex.
     *
     */
    ~Vertex();

    void operator=(const Vertex &t);

private:
    int m_x;
    int m_y;
};

#endif // _VERTEX_H_
