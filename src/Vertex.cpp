#include "Vertex.h"

Vertex::Vertex() : m_x(0), m_y(0)
{
}

Vertex::Vertex(int x, int y) : m_x(x), m_y(y)
{
}

Vertex::~Vertex()
{
}

void Vertex::operator=(const Vertex& t)
{
    m_x = t.m_x;
    m_y = t.m_y;
}
