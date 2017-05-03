#include <vector>
#include <algorithm>

#include "Triangle.h"

Triangle::Triangle(Vertex a, Vertex b, Vertex c) : m_va(a), m_vb(b), m_vc(c), m_longestEdge(Edge(m_va, m_vb)), m_notInLongestEdge(m_vc)
{
    setLongestEdge();
}

Triangle::~Triangle()
{
}

void Triangle::setLongestEdge()
{
    Edge ab(m_va, m_vb);
    Edge bc(m_vb, m_vc);
    Edge ca(m_vc, m_va);

    // Longest AB
    if (ab.m_length > bc.m_length and ab.m_length > ca.m_length)
    {
        m_longestEdge = ab;
        m_notInLongestEdge = m_vc;
    }
    // Longest BC
    else if (bc.m_length > ca.m_length and bc.m_length > ab.m_length)
    {
        m_longestEdge = bc;
        m_notInLongestEdge = m_va;
    }
    // Longest CA
    else
    {
        m_longestEdge = ca;
        m_notInLongestEdge = m_vb;
    }
}

void Triangle::operator=(const Triangle& t)
{
    m_va = t.m_va;
    m_vb = t.m_vb;
    m_vc = t.m_vc;
    m_longestEdge = t.m_longestEdge;
    m_notInLongestEdge = t.m_notInLongestEdge;
}

double Triangle::minAngle()
{
    Edge ab(m_va, m_vb);
    Edge bc(m_vb, m_vc);
    Edge ca(m_vc, m_va);

    std::vector<double> angles;
    angles.push_back(ab.angleAgainst(bc, ca).toDegrees());
    angles.push_back(bc.angleAgainst(ca, ab).toDegrees());
    angles.push_back(ca.angleAgainst(ab, bc).toDegrees());

    std::vector<double>::iterator minimal = std::min_element(std::begin(angles), std::end(angles));

    return *minimal;
}

std::vector<Triangle> Triangle::divideOnLongestEdge()
{
    std::vector<Triangle> div;

    Vertex mid((m_longestEdge.m_va.m_x + m_longestEdge.m_vb.m_x) / 2, (m_longestEdge.m_va.m_y + m_longestEdge.m_vb.m_y) / 2);

    div.push_back(Triangle(m_longestEdge.m_va, mid, m_notInLongestEdge));
    div.push_back(Triangle(m_notInLongestEdge, mid, m_longestEdge.m_vb));

    return div;
}

bool Triangle::hasEdge(Edge &edge)
{
    Edge ab(m_va, m_vb);
    Edge bc(m_vb, m_vc);
    Edge ca(m_vc, m_va);

    return (edge == ab or edge == bc or edge == ca);
}

std::ostream &operator<<(std::ostream &out, const Triangle &t)
{
    out << "Triangle (" << t.m_va << ", " << t.m_vb << ", " << t.m_vc << ")";

    return out;
}

bool Triangle::operator==(const Triangle& t) const
{
    return (m_va == t.m_va and m_vb == t.m_vb and m_vc == t.m_vc);
}

bool Triangle::operator!=(const Triangle& t) const
{
    return not (*this == t);
}
