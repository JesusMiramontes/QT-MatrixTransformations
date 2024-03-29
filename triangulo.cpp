#include "triangulo.h"
#include "mainwindow.h"

triangulo::triangulo()
{

}

triangulo::triangulo(int x, int y)
{
    punto = (new QPointF(x,y));
    angle = 90;
    wingA = MainWindow::rotar(punto,angle+30,100);
    wingB = MainWindow::rotar(punto,angle-30,100);
}

triangulo::triangulo(QPointF *p)
{
    punto = p;
    angle = 90;
    wingA = MainWindow::rotar(punto,angle+30,100);
    wingB = MainWindow::rotar(punto,angle-30,100);
}

void triangulo::setAngle(float theta)
{
    angle = theta;
    if (angle >= 450)
        angle=90;
    wingA = MainWindow::rotar(punto,angle+30,100);
    wingB = MainWindow::rotar(punto,angle-30,100);
}

void triangulo::addAngle(float theta)
{
    angle += theta;
    if (angle >= 450)
        angle=90;
    wingA = MainWindow::rotar(punto,angle+30,100);
    wingB = MainWindow::rotar(punto,angle-30,100);
}

void triangulo::setPosition(int x, int y)
{
    punto = (new QPointF(x,y));
    wingA = MainWindow::rotar(punto,angle+30,100);
    wingB = MainWindow::rotar(punto,angle-30,100);
}

int triangulo::getAngle()
{
    return this->angle;
}
