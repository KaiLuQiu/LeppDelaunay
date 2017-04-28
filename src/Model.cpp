#include <fstream>
#include <vector>
#include <sstream>
#include <cassert>

#include "Model.h"
#include <iostream>

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
        vector<Triangle> leppList = lepp(s, t0);

        const int length = leppList.size();
        Vertex centroid = selectCentroid(leppList[length - 2], leppList[length - 1]);
        insertCentroid(centroid);

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

        vector<string> tokens;                              // Vector de coordenadas (tamaño 6)

        while (ss >> buf)                                   // Separamos por espacios
        {
            tokens.push_back(buf);
        }

        // Creamos vértices correspondientes
        Vertex a(stoi(tokens.at(0)), stoi(tokens.at(1)));
        Vertex b(stoi(tokens.at(2)), stoi(tokens.at(3)));
        Vertex c(stoi(tokens.at(4)), stoi(tokens.at(5)));

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
    std::cout << "Triangulación de " << m_triangulation.size() << " tiene " << badTriangles.size() << " triángulos malos." << std::endl;

    return badTriangles;
}

// TODO lepp
vector<Triangle> Model::lepp(vector<Triangle> s, Triangle &t0)
{
    return s;
}

Vertex Model::selectCentroid(Triangle& t1, Triangle& t2)
{
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

    return Vertex((a.m_x + b.m_x + c.m_x + d.m_x / 4.0), (a.m_y + b.m_y + c.m_y + d.m_y / 4.0));
}

// TODO insertCentroid
void Model::insertCentroid(Vertex centroid)
{
}

// TODO updateBadTriangles
vector<Triangle> Model::updateBadTriangles(vector<Triangle> badTriangles)
{
    return badTriangles;
}
