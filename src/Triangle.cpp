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
    m_notInLongestEdge(c),
    m_longestEdge(Edge(m_va, m_vb))
{
    getLongestEdge();
}

Triangle::~Triangle()
{
}

Edge Triangle::getLongestEdge()
{
    // Longest AB
    if (m_ab > m_bc and m_ab > m_ca)
    {
        m_neighbourLongestEdge = m_tc;
        m_notInLongestEdge = m_vc;
        return m_ab;
    }
    // Longest BC
    else if (m_bc > m_ca and m_bc > m_ab)
    {
        m_neighbourLongestEdge = m_ta;
        m_notInLongestEdge = m_va;
        return m_bc;
    }
    // Longest CA
    else
    {
        m_neighbourLongestEdge = m_tb;
        m_notInLongestEdge = m_vb;
        return m_ca;
    }
}

void Triangle::operator=(const Triangle& t)
{
    m_va = t.m_va;
    m_vb = t.m_vb;
    m_vc = t.m_vc;
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

    cout << " Longest? " << m_longestEdge << endl;

    Vertex mid((m_longestEdge.m_va.m_x + m_longestEdge.m_vb.m_x) / 2, (m_longestEdge.m_va.m_y + m_longestEdge.m_vb.m_y) / 2);

    div.push_back(Triangle(m_longestEdge.m_va, mid, m_notInLongestEdge));
    div.push_back(Triangle(m_notInLongestEdge, mid, m_longestEdge.m_vb));

    cout << " " << div.front() << endl;
    cout << " " << div.back() << endl;
    cout << " + + + " << endl;

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
