#include <math.h>
#include "Angle.h"

Angle::Angle(double val, bool isDegree) : m_val(val), m_isDegree(isDegree)
{
}

Angle::~Angle()
{
}

double Angle::toDegrees()
{
    if (m_isDegree)
    {
        return m_val;
    }
    return m_val * 180 / M_PI;
}

double Angle::toRadians()
{
    if (m_isDegree)
    {
        return m_val * M_PI / 180;
    }
    return m_val;
}
