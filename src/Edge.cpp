#include <cmath>

#include "Edge.h"
#include "Angle.h"

Edge::Edge(Vertex& a, Vertex& b) : m_va(a), m_vb(b)
{
    detectLength();
}

Edge::~Edge()
{
}

Angle Edge::angleAgainst(const Edge& other)
{
    double ax = m_va.m_x;
    double ay = m_va.m_y;
    double bx = m_vb.m_x;
    double by = m_vb.m_y;

    return Angle((acos((ax * bx + ay * by) / (m_length * other.m_length))), false);
}

void Edge::detectLength()
{
    m_length = sqrt(pow(m_va.m_x - m_vb.m_x, 2) + pow(m_va.m_y - m_vb.m_y, 2));
}
