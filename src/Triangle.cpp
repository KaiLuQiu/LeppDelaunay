#include <vector>
#include <algorithm>

#include "Triangle.h"

Triangle::Triangle(Vertex a, Vertex b, Vertex c)
  : m_va(a),
    m_vb(b),
    m_vc(c),
    m_ab(Edge(m_va, m_vb)),
    m_bc(Edge(m_vb, m_vc)),
    m_ca(Edge(m_vc, m_va)),
    m_longestEdge(m_ab),
    m_notInLongestEdge(m_vc)
{
    setLongestEdge();
}

Triangle::~Triangle()
{
}

void Triangle::setLongestEdge()
{
    // Longest AB
    if (m_ab.m_length > m_bc.m_length and m_ab.m_length > m_ca.m_length)
    {
        m_longestEdge = m_ab;
        m_notInLongestEdge = m_vc;
        m_neighbourLongestEdge = m_tc;
    }
    // Longest BC
    else if (m_bc.m_length > m_ca.m_length and m_bc.m_length > m_ab.m_length)
    {
        m_longestEdge = m_bc;
        m_notInLongestEdge = m_va;
        m_neighbourLongestEdge = m_ta;
    }
    // Longest CA
    else
    {
        m_longestEdge = m_ca;
        m_notInLongestEdge = m_vb;
        m_neighbourLongestEdge = m_tb;
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
    vector<double> angles;
    angles.push_back(m_ab.angleAgainst(m_bc, m_ca).toDegrees());
    angles.push_back(m_bc.angleAgainst(m_ca, m_ab).toDegrees());
    angles.push_back(m_ca.angleAgainst(m_ab, m_bc).toDegrees());

    vector<double>::iterator minimal = min_element(begin(angles), end(angles));

    return *minimal;
}

double Triangle::maxAngle()
{
    vector<double> angles;
    angles.push_back(m_ab.angleAgainst(m_bc, m_ca).toDegrees());
    angles.push_back(m_bc.angleAgainst(m_ca, m_ab).toDegrees());
    angles.push_back(m_ca.angleAgainst(m_ab, m_bc).toDegrees());

    vector<double>::iterator maximal = max_element(begin(angles), end(angles));

    return *maximal;
}

vector<Triangle> Triangle::divideOnLongestEdge()
{
    vector<Triangle> div;

    Vertex mid((m_longestEdge.m_va.m_x + m_longestEdge.m_vb.m_x) / 2, (m_longestEdge.m_va.m_y + m_longestEdge.m_vb.m_y) / 2);

    div.push_back(Triangle(m_longestEdge.m_va, mid, m_notInLongestEdge));
    div.push_back(Triangle(m_notInLongestEdge, mid, m_longestEdge.m_vb));

    return div;
}

bool Triangle::hasEdge(Edge &edge)
{
    return (edge == m_ab or edge == m_bc or edge == m_ca);
}

ostream &operator<<(ostream &out, const Triangle &t)
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
