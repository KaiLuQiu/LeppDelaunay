#include <fstream>
#include <vector>
#include <sstream>

#include "Model.h"

Model::Model() : Model("../Triangles.txt")
{
}

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
void Model::improve()
{
    vector<Triangle> s = findBadTriangles();

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
    myFile.close();

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

// TODO findBadTriangles
vector<Triangle> Model::findBadTriangles()
{
    return m_triangulation;
}

// TODO lepp
vector<Triangle> Model::lepp(vector<Triangle> s, Triangle &t0)
{
    return s;
}

// TODO selectCentroid
Vertex Model::selectCentroid(Triangle& t1, Triangle& t2)
{
    return Vertex();
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