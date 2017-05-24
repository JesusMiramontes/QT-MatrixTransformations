#include "triangulo.h"
#include "mainwindow.h"

triangulo::triangulo()
{

}

triangulo::triangulo(int x, int y)
{
    punto = (new QPointF(x,y));
    angle = 0;
    wingA = MainWindow::rotar(punto,angle+30,100);
    wingB = MainWindow::rotar(punto,angle-30,100);
}

void triangulo::setAngle(float theta)
{
    angle = theta;
    wingA = MainWindow::rotar(punto,angle+30,100);
    wingB = MainWindow::rotar(punto,angle-30,100);
}
