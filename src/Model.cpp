#include "Model.h"

Model::Model() : m_x(0), m_y(0)
{
}

Model::~Model()
{
}

void Model::setPointAt(int x, int y)
{
    m_x = x;
    m_y = y;
}
