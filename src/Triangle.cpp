#include "Triangle.h"

Triangle::Triangle()
{
}

Triangle::Triangle(Vertex a, Vertex b, Vertex c) : m_va(a), m_vb(b), m_vc(c)
{
}

Triangle::~Triangle()
{
}

void Triangle::operator=(const Triangle& t)
{
    m_va = t.m_va;
    m_vb = t.m_vb;
    m_vc = t.m_vc;
}
