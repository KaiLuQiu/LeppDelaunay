#include "Model.h"

Model::Model() : Model("Triangles.txt")
{
}

Model::Model(string fileName)
{
    parse(fileName);
}

Model::Model(Triangle* triangulation) : m_triangulation(triangulation)
{
}

Model::~Model()
{
}

// FIXME Re-parsear la tarea para saber si esta es la idea base
void Model::improve()
{
    Triangle *s = findBadTriangles();

    for (Triangle *t0 = s; t0 != nullptr; t0++)
    {
        Triangle *leppList = lepp(s, *t0);

        const int length = listLength(leppList);
        Vertex centroid = selectCentroid(leppList[length - 2], leppList[length - 1]);
        insertCentroid(centroid);

        updateBadTriangles(s);
    }
}

// TODO parse
void Model::parse(string fileName)
{
    m_triangulation = nullptr;
}

// TODO findBadTriangles
Triangle * Model::findBadTriangles()
{
    return m_triangulation;
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
void Model::insertCentroid(Vertex centroid)
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
