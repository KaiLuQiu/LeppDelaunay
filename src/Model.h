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
    /**
    * @brief Encuentra triángulos cuyo ángulo más pequeño es menor que tolerance.
    *
    * @param tolerance p_tolerance: Ángulo de prueba. Si hay uno menor, es "mal triángulo".
    * @return std::vector< Triangle > Vector de "triángulos malos".
    */
    vector<Triangle> findBadTriangles(double tolerance);

    /**
    * @brief TODO
    *
    * @param s p_s:...
    * @param t0 p_t0:...
    * @return std::vector< Triangle >
    */
    vector<Triangle> lepp(vector<Triangle> s, Triangle &t0);

    /**
    * @brief Encuentra el centroide entre estos 2 triángulos, que deben compartir un Edge.
    *
    * @param t1 p_t1: Triángulo 1.
    * @param t2 p_t2: Triángulo 2.
    * @return Vertex
    */
    Vertex selectCentroid(Triangle &t1, Triangle &t2);

    /**
    * @brief Inserta el centroide en la triangulación, creando nuevos triángulos en el proceso.
    *
    * @param centroid p_centroid: Centroide.
    */
    void insertCentroid(Vertex centroid);

    /**
    * @brief TODO
    *
    * @param badTriangles p_badTriangles:...
    * @return std::vector< Triangle >
    */
    vector<Triangle> updateBadTriangles(vector<Triangle> badTriangles);

    vector<Triangle> m_triangulation;
};

#endif // _MODEL_H_
