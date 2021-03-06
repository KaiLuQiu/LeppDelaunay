#include <cmath>
#include "Edge.h"

Edge::Edge(Vertex a, Vertex b) : m_va(a), m_vb(b)
{
    detectLength();
}

Edge::~Edge()
{
}

Angle Edge::angleAgainst(const Edge& other, const Edge &aux) const
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

bool Edge::operator==(const Edge& other)
{
    return (m_va == other.m_va and m_vb == other.m_vb) or (m_va == other.m_vb and m_vb == other.m_va);
}

bool Edge::operator!=(const Edge& other)
{
    return not (*this == other);
}

bool Edge::operator<(const Edge& other)
{
    return m_length < other.m_length;
}

bool Edge::operator<=(const Edge& other)
{
    return m_length <= other.m_length;
}

bool Edge::operator>(const Edge& other)
{
    return m_length > other.m_length;
}

bool Edge::operator>=(const Edge& other)
{
    return m_length >= other.m_length;
}
