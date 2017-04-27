#ifndef _EDGE_H_
#define _EDGE_H_
#include "Vertex.h"
#include "Angle.h"

class Edge
{
    friend class Triangle;

public:
    Edge(Vertex& a, Vertex& b);
    ~Edge();

    Angle angleAgainst(const Edge &other);

private:
    void detectLength();

    Vertex m_va;
    Vertex m_vb;
    double m_length;
};

#endif // _EDGE_H_
