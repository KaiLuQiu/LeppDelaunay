#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Vertex.h"

class Triangle
{
    friend class Model;

public:
    Triangle();
    Triangle(Vertex &a, Vertex &b, Vertex &c);
    ~Triangle();

private:
    Vertex m_va;
    Vertex m_vb;
    Vertex m_vc;
};

#endif // _TRIANGLE_H_
