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
    updateNeighbours();
}

Model::Model(vector<Triangle> triangulation) : m_triangulation(triangulation)
{
}

Model::~Model()
{
}

void Model::improve(double tolerance)
{
    // Encuentro triángulos malos
    vector<Triangle> s;
    s = findBadTriangles(tolerance);

    int iterations = 0;
    // Mientras hayan triángulos malos
    // FIXME no necesariamente tomaste el mismo t0 a la siguiente iteración!!! (haz un do - while *t0 != nullptr/ respalda t0 y compara si sigue existiendo )
    while (s.size() > 0)
    {
        cout << "Iteración " << left << setw(6) << iterations << endl;

        // Agarramos uno de ellos y mejoramos
        Triangle t0 = s.front();
//         cout << "Analizando malo: " << t0 << endl;

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
            if (leppList.at(leppList.size() - 1).maxAngle() > 120 or leppList.at(leppList.size() - 2).maxAngle() > 120)
            {
                swapDiagonals(leppList);
            }
            else
            {
                insertCentroid(leppList);
            }
        }

        // Actualizamos los malos triángulos
        updateBadTriangles(s, tolerance);

        cout << "Quedan " << s.size() << " triángulos malos." << endl;
//         cout << "- - - - - - - - " << endl;

        // Detener iteraciones excesivas
        // FIXME Con 20 grados, de la iteración 27 a la 28 algo falla
        if (++iterations == 28)
            break;
    }
}

void Model::swapDiagonals(vector<Triangle>& lepp)
{
    Triangle &t1 = lepp.at(lepp.size() - 1);                // Último
    Triangle &t2 = lepp.at(lepp.size() - 2);                // Penúltimo

    assert(t1 != t2);

    Vertex a(t1.m_va);
    Vertex b(t1.m_vb);
    Vertex c(t1.m_vc);
    Vertex d;

    // Buscamos cual es el distinto para no crear los mismos triángulos
    if (t2.m_va != a and t2.m_va != b and t2.m_va != c)
        d = Vertex(t2.m_va);
    else if (t2.m_vb != a and t2.m_vb != b and t2.m_vb != c)
        d = Vertex(t2.m_vb);
    else
        d = Vertex(t2.m_vc);

    // Buscamos el edge compartido para no usarlo
    Edge ab(a, b);
    Edge bc(b, c);
    Edge ca(c, a);

    Triangle T1(a, b, c);
    Triangle T2(a, d, c);

    if (t1.hasEdge(ab) and t2.hasEdge(ab))                  // CD sería nueva diagonal
    {
        T1 = Triangle(c, d, a);
        T2 = Triangle(c, d, b);
    }
    else if (t1.hasEdge(bc) and t2.hasEdge(bc))             // AD sería nueva diagonal
    {
        T1 = Triangle(a, d, b);
        T2 = Triangle(a, d, c);
    }
    else                                                    // BD sería nueva diagonal
    {
        T1 = Triangle(b, d, a);
        T2 = Triangle(b, d, c);
    }

    // Eliminación triángulos t1, t2
    m_triangulation.erase(remove(m_triangulation.begin(), m_triangulation.end(), t1), m_triangulation.end());
    m_triangulation.erase(remove(m_triangulation.begin(), m_triangulation.end(), t2), m_triangulation.end());

    // Agregación triángulos T1, T2
    m_triangulation.push_back(T1);
    m_triangulation.push_back(T2);
}

void Model::updateNeighbours()
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
                t.getLongestEdge();
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

vector<Triangle> Model::lepp(Triangle t0, bool &borderFlag)
{
    vector<Triangle> leppList;
    Edge longest = t0.m_longestEdge;

    leppList.push_back(t0);

    // Asumo caso de borde a menos que se demuestre lo contrario
    borderFlag = true;

    while (true)
    {
        // Caso borde
        if (t0.m_neighbourLongestEdge == nullptr)
        {
//             cout << "Caso borde para t0 = " << t0 << endl;
            borderFlag = true;
            leppList.push_back(t0);
            return leppList;
        }
        // Casos terminales
        // Caso raro, investigar
        else if ((*t0.m_neighbourLongestEdge).m_neighbourLongestEdge == nullptr)
        {
//             cout << "Caso borde avanzado para t0.neighbour = " << *(t0.m_neighbourLongestEdge) << endl;
            borderFlag = true;
            leppList.push_back(*(t0.m_neighbourLongestEdge));
            return leppList;
        }
        else if (t0 == *t0.m_neighbourLongestEdge->m_neighbourLongestEdge)
        {
//             cout << "Caso terminal para t0 = " << t0 << endl;
            borderFlag = false;
            leppList.push_back(t0);
            leppList.push_back(*(t0.m_neighbourLongestEdge));
            return leppList;
        }
        else
        {
//             cout << "Caso neighbour para t0 = " << t0 << endl;
            t0 = *(t0.m_neighbourLongestEdge);
        }
    }

    return leppList;
}

void Model::insertCenter(vector<Triangle> &lepp)
{
    // Dividimos el último triángulo en 2
    Triangle &t = lepp.back();
    vector<Triangle> division = t.divideOnLongestEdge();

//     cout << "Dividí (center) en: " << division.front() << " y " << division.back() << endl;

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

//     cout << "Salieron terminales: " << endl;
//     cout << t1 << endl;
//     cout << t2 << endl;
//     cout << endl;

    // Detección centroide
    assert(t1 != t2);

    Vertex a(t1.m_va);
    Vertex b(t1.m_vb);
    Vertex c(t1.m_vc);
    Vertex d;

    // Buscamos cual es el distinto para hacer un cuadrilatero
    if (t2.m_va != a and t2.m_va != b and t2.m_va != c)
        d = Vertex(t2.m_va);
    else if (t2.m_vb != a and t2.m_vb != b and t2.m_vb != c)
        d = Vertex(t2.m_vb);
    else
        d = Vertex(t2.m_vc);

//     cout << "Voy a buscar el centroide entre: " << endl;
//     cout << a << endl;
//     cout << b << endl;
//     cout << c << endl;
//     cout << d << endl;
//     cout << endl;

    Vertex centroid((a.m_x + b.m_x + c.m_x + d.m_x) / 4.0, (a.m_y + b.m_y + c.m_y + d.m_y) / 4.0);

//     cout << "Me dicen que el centroide es " << centroid << endl;

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

void Model::updateBadTriangles(vector<Triangle> &bad_s, const double tolerance)
{
    bad_s.clear();
    updateNeighbours();
    bad_s = findBadTriangles(tolerance);
}
