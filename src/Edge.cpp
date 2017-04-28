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

Angle Edge::angleAgainst(const Edge& other, const Edge &aux)
{
    // Ley de cosenos:
    // gamma = arccos(a^2 + b^2 - c^2 / 2*a*b)

    double a = (*this).m_length;
    double b = other.m_length;
    double c = aux.m_length;

    Angle ans(acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)), false);

    return ans;
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
