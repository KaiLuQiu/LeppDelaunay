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
    explicit Model(string fileName = "../Triangles.txt");

    /**
    * @brief Constructor con triangulación.
    *
    * @param triangulation p_triangulation: La triangulación recibida.
    */
    explicit Model(const vector<Triangle> &triangulation);

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
    * @brief Encuentra una lista de triángulos unidos por la arista más larga.
    *
    * @param t0 p_t0: Triángulo por el cual comienza Lepp.
    * @param borderFlag p_borderFlag: Setea True si la arista terminal se encontró en un borde.
    * @return std::vector< Triangle >
    */
    vector<Triangle> lepp(Triangle t0, bool &borderFlag);

    /**
     * @brief Encuentra el centro de la arista más larga del último triángulo, lo divide e inserta los 2 nuevos triángulos en la triangulación.
     *
     * @param lepp p_lepp: Lepp.
     */
    void insertCenter(vector<Triangle> &lepp);

    /**
    * @brief Encuentra el centroide entre los 2 últimos triángulos, que deben compartir un Edge, divide los 2 triángulos en 4, y los inserta en la triangulación.
    *
    * @param lepp p_lepp: Lepp.
    */
    void insertCentroid(vector<Triangle> &lepp);

    /**
    * @brief Intercambia diagonales entre estos 2 triángulos
    *
    * @param lepp p_lepp: Lepp.
    */
    void swapDiagonals(vector<Triangle> &lepp);

    /**
    * @brief Revisa nuevamente los triángulos después de una inserción por Lepp.
    *
    * @param badTriangles p_badTriangles: Lista (S) de triángulos malos
    */
    void updateBadTriangles(vector<Triangle> &badTriangles, const double tolerance);

    /**
    * @brief Actualiza los vecinos de los triángulos de la triangulación.
    *
    */
    void updateNeighbours();

    /**
    * @brief Detecta si los 2 triángulos recibidos son localmente Delaunay.
    *
    * @param t1 p_t1: Triángulo 1.
    * @param t2 p_t2: Triángulo 2.
    * @return bool True si lo son, False si no.
    */
    bool areLocallyDelaunay(Triangle &t1, Triangle t2);

    vector<Triangle> m_triangulation;
};

#endif // _MODEL_H_
