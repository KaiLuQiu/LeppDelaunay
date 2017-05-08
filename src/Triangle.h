#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Triangle
{
    friend class Model;
    friend class Canvas;
    friend ostream &operator<<(ostream &out, const Triangle & t);

public:
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

    /**
    * @brief Overload de asignación.
    *
    * @param t p_t: Triángulo a igualar.
    */
    void operator=(const Triangle &t);

    /**
    * @brief Overload de comparación de igualdad.
    *
    * @param t p_t: Triángulo a comparar.
    * @return bool True si son iguales.
    */
    bool operator==(const Triangle &t) const;

    /**
    * @brief Overload de comparación de desigualdad.
    *
    * @param t p_t: Triángulo a comparar.
    * @return bool True si son distintos.
    */
    bool operator!=(const Triangle &t) const;

    /**
    * @brief Detecta mínimo ángulo del triángulo.
    *
    * @return double El menor ángulo encontrado.
    */
    double minAngle(void);

    /**
    * @brief Detecta máximo ángulo del triángulo.
    *
    * @return double El mayor ángulo encontrado.
    */
    double maxAngle(void);

    /**
    * @brief Detecta el Edge más largo y retorna 2 triángulos divididos en el punto medio de este Edge.
    *
    * @return vector< Triangle > 2 Triángulos hijos de éste.
    */
    vector<Triangle> divideOnLongestEdge(void);

    /**
    * @brief Detecta si existe este 'edge' en el triángulo.
    *
    * @param edge p_edge: Edge a detectar.
    * @return bool True si existe.
    */
    bool hasEdge(Edge &edge);

private:
    void setLongestEdge(void);

    Vertex m_va;
    Vertex m_vb;
    Vertex m_vc;
    Edge m_ab;
    Edge m_bc;
    Edge m_ca;
    Edge m_longestEdge;
    Vertex m_notInLongestEdge;
    Triangle *m_ta = nullptr;
    Triangle *m_tb = nullptr;
    Triangle *m_tc = nullptr;
};

#endif // _TRIANGLE_H_
