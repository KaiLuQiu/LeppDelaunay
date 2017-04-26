#include "Model.h"

Model::Model()
{
}

Model::~Model()
{
}

void Model::improve(Triangle* triangulation)
{
    Triangle *s = findBadTriangles(triangulation);

    for (Triangle *t0 = s; t0 != nullptr; t0++)
    {
        Triangle *leppList = lepp(s, *t0);

        const int length = listLength(leppList);
        Vertex centroid = selectCentroid(leppList[length - 2], leppList[length - 1]);
        insertCentroid(triangulation, centroid);

        updateBadTriangles(s);
    }
}

// TODO findBadTriangles
Triangle * Model::findBadTriangles(Triangle* triangulation)
{
    return triangulation;
}

// TODO lepp
Triangle * Model::lepp(Triangle* s, Triangle &t0)
{
    return s;
}

// TODO selectCentroid
Vertex Model::selectCentroid(Triangle& t1, Triangle& t2)
{
    return Vertex();
}

// TODO insertCentroid
void Model::insertCentroid(Triangle* triangulation, Vertex centroid)
{
}

// TODO updateBadTriangles
Triangle * Model::updateBadTriangles(Triangle* badTriangles)
{
    return nullptr;
}

int Model::listLength(Triangle* list)
{
    if (list == nullptr)
        return 0;
    return 1 + listLength(&list[1]);
}
