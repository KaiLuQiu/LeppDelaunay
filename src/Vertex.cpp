#include <cmath>
#include "Vertex.h"

Vertex::Vertex() : m_x(0), m_y(0)
{
}

Vertex::Vertex(int x, int y) : m_x(x), m_y(y)
{
}

Vertex::Vertex(const Vertex& v) : m_x(v.m_x), m_y(v.m_y)
{
}

Vertex::~Vertex()
{
}

double Vertex::distanceTo(const Vertex &v) const
{
    return sqrt(pow(m_x - v.m_x, 2) + pow(m_y - v.m_y, 2));
}

Vertex& Vertex::operator=(const Vertex& v)
{
    m_x = v.m_x;
    m_y = v.m_y;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Vertex & vertex)
{
    out << "Vertex(" << vertex.m_x << ", " << vertex.m_y << ")";

    return out;
}

bool Vertex::operator==(const Vertex& v) const
{
    return (m_x == v.m_x and m_y == v.m_y);
}

bool Vertex::operator!=(const Vertex& v) const
{
    return not (*this == v);
}
