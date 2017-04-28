#ifndef _MODEL_H_
#define _MODEL_H_

#include <string>
#include <vector>

#include "Triangle.h"

using namespace std;

class Model
{
    friend class Canvas;

public:
    /**
    * @brief Constructor con nombre de archivo a ser parseado.
    *
    * @param fileName p_fileName: Nombre del archivo.
    */
    Model(string fileName = "../Triangles.txt");

    /**
    * @brief Constructor con triangulación.
    *
    * @param triangulation p_triangulation: La triangulación recibida.
    */
    Model(vector<Triangle> triangulation);

    /**
    * @brief Destructor de Model.
    *
    */
    ~Model();

    /**
    * @brief Algoritmo base de Lepp-Delaunay.
    *
    * @param tolerance p_tolerance: Tolerancia en grados.
    */
    void improve(double tolerance = 30.0);

    /**
    * @brief Parser de triangulaciones.
    *
    * @param fileName p_fileName: Nombre del archivo a parsear.
    */
    void parse(string fileName = "../Triangles.txt");


private:
    vector<Triangle> findBadTriangles(double tolerance);
    vector<Triangle> lepp(vector<Triangle> s, Triangle &t0);
    Vertex selectCentroid(Triangle &t1, Triangle &t2);
    void insertCentroid(Vertex centroid);
    vector<Triangle> updateBadTriangles(vector<Triangle> badTriangles);

    vector<Triangle> m_triangulation;
};

#endif // _MODEL_H_
