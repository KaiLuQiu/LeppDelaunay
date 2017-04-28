#include <iostream>
#include <vector>
#include <algorithm>

#include "Edge.h"
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

double Triangle::minAngle()
{
    Edge ab(m_va, m_vb);
    Edge bc(m_vb, m_vc);
    Edge ca(m_vc, m_va);

    std::vector<double> angles;
    angles.push_back(ab.angleAgainst(bc, ca).toDegrees());
    angles.push_back(bc.angleAgainst(ca, ab).toDegrees());
    angles.push_back(ca.angleAgainst(ab, bc).toDegrees());

    for (double d : angles)
    {
        std::cout << d << std::endl;
    }
    std::cout << std::endl;

    std::vector<double>::iterator minimal = std::min_element(std::begin(angles), std::end(angles));

    return *minimal;
}

std::ostream &operator<<(std::ostream &out, const Triangle & t)
{
    out << "Triangle (" << t.m_va << ", " << t.m_vb << ", " << t.m_vc << ")";

    return out;
}
