#ifndef _MODEL_H_
#define _MODEL_H_

class Model
{
    friend class View;

public:
    Model();
    ~Model();

    void setPointAt(int x, int y);

private:
    int m_x;
    int m_y;
};

#endif // _MODEL_H_
