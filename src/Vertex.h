#ifndef _VERTEX_H_
#define _VERTEX_H_

class Vertex
{
    friend class Triangle;

public:
    Vertex();
    Vertex(int x, int y);
    ~Vertex();

private:
    int m_x;
    int m_y;
};

#endif // _VERTEX_H_
