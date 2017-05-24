#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "QPointF"

class triangulo
{
public:
    triangulo();
    triangulo(int x, int y);
    void setAngle(float theta);
    QPointF* punto;
    QPointF* wingA;
    QPointF* wingB;

private:
    int angle;

};

#endif // TRIANGULO_H