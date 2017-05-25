#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "QPointF"

class triangulo
{
public:
    triangulo();
    triangulo(int x, int y);
    triangulo(QPointF* p);
    void setAngle(float theta);
    void setPosition(int x, int y);
    int getAngle();
    QPointF* punto;
    QPointF* wingA;
    QPointF* wingB;

private:
    int angle;

};

#endif // TRIANGULO_H
