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
    Edge(Vertex& a, Vertex& b);
    ~Edge();

    Angle angleAgainst(const Edge &other, const Edge &aux);

private:
    void detectLength();

    Vertex m_va;
    Vertex m_vb;
    double m_length;
};

#endif // _EDGE_H_
