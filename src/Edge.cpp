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

// FIXME Todo está bien, excepto que los ángulos se calculan mal...
Angle Edge::angleAgainst(const Edge& other)
{
    Vertex p1 = this->m_va;
    Vertex p2 = this->m_vb;
    Vertex p3 = other.m_vb;

    double ax = p1.m_x - p2.m_x;
    double ay = p1.m_y - p2.m_y;
    double bx = p1.m_x - p3.m_x;
    double by = p1.m_y - p3.m_y;

    std::cout << ax << std::endl;
    std::cout << ay << std::endl;
    std::cout << bx << std::endl;
    std::cout << by << std::endl;
    std::cout << std::endl;

    return Angle((acos((ax * bx + ay * by) / (m_length * other.m_length))), false);
}

void Edge::detectLength()
{
    m_length = sqrt(pow(m_va.m_x - m_vb.m_x, 2) + pow(m_va.m_y - m_vb.m_y, 2));
}

std::ostream &operator<<(std::ostream &out, const Edge & edge)
{
    out << "Edge (";
    out << edge.m_va << "), ";
    out << edge.m_vb << ")";

    return out;
}
