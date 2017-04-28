#include <math.h>
#include "Angle.h"

Angle::Angle(double val, const bool isDegree) : m_val(val), m_isDegree(isDegree)
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
    return (m_val * 180.0) / M_PI;
}

double Angle::toRadians()
{
    if (m_isDegree)
    {
        return (m_val * M_PI) / 180.0;
    }
    return m_val;
}

std::ostream &operator<<(std::ostream &out, Angle &angle)
{
    out << "Angle (deg, rad) = (" << angle.toDegrees() << ", " << angle.toRadians() << ")";

    return out;
}
