#include <fstream>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <iomanip>

#include "Model.h"
#include "Triangle.h"
#include "Edge.h"

Model::Model(string fileName)
{
    parse(fileName);
    preprocessNeighbours();
}

Model::Model(vector<Triangle> triangulation) : m_triangulation(triangulation), m_s(vector<Triangle>())
{
}

Model::~Model()
{
}

void Model::improve(double tolerance)
{
    m_s = findBadTriangles(tolerance);

    int iterations = 0;
    // Mientras hayan triángulos malos
    while (m_s.size() > 0)
    {
        // Agarramos uno de ellos y mejoramos
        Triangle &t0 = m_s.front();

        // Buscamos lista Lepp
        bool borderFlag = false;
        vector<Triangle> leppList = lepp(t0, borderFlag);

        // Insertamos centroide o centro según caso detectado
        if (borderFlag)
        {

            insertCenter(leppList);
        }
        else
        {
            insertCentroid(leppList);
        }

        // Actualizamos los malos triángulos
        updateBadTriangles(m_s, tolerance);
        cout << "Iteración " << left << setw(6) << iterations << ": Quedan " << m_s.size() << " triángulos malos." << endl;

        // Detener iteraciones excesivas
//         if (++iterations == 4000)
            break;
    }
}

void Model::preprocessNeighbours()
{
    for (Triangle &t : m_triangulation)
    {
        for (Triangle &n : m_triangulation)
        {
            if (t == n)
                continue;
            else
            {
                if (n.hasEdge(t.m_ab))
                {
                    t.m_tc = &n;
                }
                else if (n.hasEdge(t.m_bc))
                {
                    t.m_ta = &n;
                }
                else if (n.hasEdge(t.m_ca))
                {
                    t.m_tb = &n;
                }
            }
        }
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

    for (Triangle &t : m_triangulation)
    {
        if (t.minAngle() < tolerance)
        {
            badTriangles.push_back(t);
        }
    }

    return badTriangles;
}

// FIXME Optimizar esto, parece que es lo que más demora
vector<Triangle> Model::lepp(Triangle t0, bool &borderFlag)
{
    vector<Triangle> leppList;
    leppList.push_back(t0);

    Edge longest = t0.m_longestEdge;

    cout << "t0= " << t0 << endl;
    cout << "longest = " << longest << endl;
    cout << endl;

    // Asumo caso de borde a menos que se demuestre lo contrario
    borderFlag = true;

    for (Triangle &t : m_triangulation)
    {
        if (t == t0)                                        // Ya considerado
        {
            continue;
        }
        else
        {
            // Si el triángulo que estoy viendo contiene un Edge igual que el mayor ya visto, agrego triángulo a Lepp
            if (t.hasEdge(longest))
            {
                // Caso borde
                if (leppList.back() == t)
                {
                    borderFlag = true;
                    return leppList;
                }

                leppList.push_back(t);

                // Encontré los triángulos terminales, retorno
                if (longest == t.m_longestEdge)
                {
                    borderFlag = false;
                    return leppList;
                }

                // Actualizo Edge más largo
                longest = t.m_longestEdge;
            }
        }
    }

    return leppList;
}

void Model::insertCenter(vector<Triangle> &lepp)
{
    // Dividimos el último triángulo en 2
    Triangle &t = lepp.back();
    vector<Triangle> division = t.divideOnLongestEdge();

    // Borramos este triángulo
    m_triangulation.erase(remove(m_triangulation.begin(), m_triangulation.end(), t), m_triangulation.end());

    // Insertamos los dos nuevos
    m_triangulation.push_back(division.front());
    m_triangulation.push_back(division.back());
}

void Model::insertCentroid(vector<Triangle>& lepp)
{
    // Dividimos los últimos 2 triángulos en 4
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

void Model::updateBadTriangles(vector<Triangle>& badTriangles, const double tolerance)
{
    badTriangles = findBadTriangles(tolerance);
}
