#ifndef _ANGLE_H_
#define _ANGLE_H_

class Angle
{
public:
    /**
    * @brief Constructor de ángulo
    *
    * @param val p_val: Valor numérico del ángulo
    * @param isDegree p_isDegree: Confirma si es grado o radián.
    */
    Angle(double val, bool isDegree = true);
    ~Angle();

    /**
    * @brief Conversor a grados, si valor está en radianes.
    *
    * @return double Grados.
    */
    double toDegrees(void);

    /**
    * @brief Conversor a radianes, si valor está en grados.
    *
    * @return double Radianes.
    */
    double toRadians(void);

private:
    int m_val;
    bool m_isDegree;
};

#endif // _ANGLE_H_
