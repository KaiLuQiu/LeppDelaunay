#ifndef _MODEL_H_
#define _MODEL_H_

#include "Triangle.h"

class Model
{
    friend class View;

public:
    Model();
    ~Model();

    void improve(Triangle* triangulation);

private:
    Triangle* findBadTriangles(Triangle* triangulation);
    Triangle* lepp(Triangle *s, Triangle &t0);
    Vertex selectCentroid(Triangle &t1, Triangle &t2);
    void insertCentroid(Triangle *triangulation, Vertex centroid);
    Triangle *updateBadTriangles(Triangle *badTriangles);
    int listLength(Triangle * list);
};

#endif // _MODEL_H_
