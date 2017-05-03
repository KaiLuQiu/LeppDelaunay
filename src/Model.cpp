#include <fstream>
#include <vector>
#include <sstream>
#include <cassert>
#include <QDebug>

#include "Model.h"

Model::Model(string fileName)
{
    parse(fileName);
}

Model::Model(vector<Triangle> triangulation) : m_triangulation(triangulation)
{
}

Model::~Model()
{
}

// FIXME Re-parsear la tarea para saber si esta es la idea base
void Model::improve(double tolerance)
{
    vector<Triangle> s = findBadTriangles(tolerance);

    for (Triangle &t0 : s)
    {
        bool borderFlag = false;
        vector<Triangle> leppList = lepp(s, t0, borderFlag);

        if (borderFlag)
        {
            insertCenter(leppList);
        }
        else
        {
            insertCentroid(leppList);
        }

        updateBadTriangles(s);
        break;
    }
}

void Model::parse(string fileName)
{
    m_triangulation.clear();

    ifstream myFile(fileName);
    vector<string> lines;
    string line;

    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            lines.push_back(line);
        }
    }

    for (int i = 0; i < lines.size(); ++i)
    {
        string buf;                                         // Buffer
        stringstream ss(lines.at(i));                       // String dentro de un stream

        vector<int> tokens;                                 // Vector de coordenadas (tamaño 6)

        while (ss >> buf)                                   // Separamos por espacios
        {
            tokens.push_back(stoi(buf));
        }

        // Creamos vértices correspondientes
        Vertex a(tokens.at(0), tokens.at(1));
        Vertex b(tokens.at(2), tokens.at(3));
        Vertex c(tokens.at(4), tokens.at(5));

        // Asignamos a la triangulación
        m_triangulation.push_back(Triangle(a, b, c));
    }
}

vector<Triangle> Model::findBadTriangles(double tolerance)
{
    vector<Triangle> badTriangles;

    for (Triangle t : m_triangulation)
    {
        if (t.minAngle() < tolerance)
        {
            badTriangles.push_back(t);
        }
    }

    qDebug() << "Triangulación de" << m_triangulation.size() << "triángulos tiene" << badTriangles.size() << "triángulos malos.";

    return badTriangles;
}

// TODO lepp
//  Cuando se devuelve t3 -> t4 -> t3,  estos son los terminales
vector<Triangle> Model::lepp(vector<Triangle> s, Triangle &t0, bool &borderFlag)
{
    return s;
}

// TODO insertCenter
void Model::insertCenter(vector<Triangle> &lepp)
{
    Triangle &t = lepp.back();
}

void Model::insertCentroid(vector<Triangle>& lepp)
{
    Triangle &t1 = lepp.at(lepp.size() - 1);                // Último
    Triangle &t2 = lepp.at(lepp.size() - 2);                // Penúltimo

    // Detección centroide
    assert(t1 != t2);

    Vertex a(t1.m_va);
    Vertex b(t1.m_vb);
    Vertex c(t1.m_vc);
    Vertex d;

    if (t2.m_va != a)
        d = Vertex(t2.m_va);
    else if (t2.m_vb != a)
        d = Vertex(t2.m_vb);
    else
        d = Vertex(t2.m_vc);

    Vertex centroid((a.m_x + b.m_x + c.m_x + d.m_x / 4.0), (a.m_y + b.m_y + c.m_y + d.m_y / 4.0));

    // Creación 4 triángulos

    Triangle T1(a, b, centroid);
    Triangle T2(b, c, centroid);
    Triangle T3(c, d, centroid);
    Triangle T4(d, a, centroid);

    // Eliminación triángulos t1, t2
    m_triangulation.erase(remove(m_triangulation.begin(), m_triangulation.end(), t1), m_triangulation.end());
    m_triangulation.erase(remove(m_triangulation.begin(), m_triangulation.end(), t2), m_triangulation.end());

    // Agregación 4 triángulos
    m_triangulation.push_back(T1);
    m_triangulation.push_back(T2);
    m_triangulation.push_back(T3);
    m_triangulation.push_back(T4);

}

// TODO updateBadTriangles
vector<Triangle> Model::updateBadTriangles(vector<Triangle> badTriangles)
{
    return badTriangles;
}
