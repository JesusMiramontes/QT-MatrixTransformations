#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPen"
#include "QPainter"
#include <QtMath>
#include <math.h>
#include "triangulo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Establece el tamaño del pixmap segun el label
    pix = new QPixmap(ui->drawing_area->width(), ui->drawing_area->height()); //Tamaño canvas
    pix->fill(Qt::black); //Fondo negro

    paint = new QPainter(pix);

    // Declaracion de triangulos
    t1 = new triangulo(300,300);
    dibujarTriangulo(t1);
    t1->setAngle(90);
    dibujarTriangulo(t1);
}

// Rota un punto con respecto a otro punto
QPointF *MainWindow::rotar(QPointF *posicion_actual, int angle, int length)
{
    qreal new_x, new_y;

    float fradians = qDegreesToRadians((float)angle);

    qreal radians = (qreal)fradians;
    new_x = (qreal)(posicion_actual->x() + length * qCos(radians));
    new_y = (qreal)(posicion_actual->y() + length * qSin(radians));

    QPointF* new_point = new QPointF(new_x, new_y);
    return new_point;
}

// Dibuja una linea en base a un punto posicion actual con un angulo angle a una distancia lenght
void MainWindow::dibujarLineaWithAngle(int angle, QPointF* posicion_actual, int length)
{
    qreal new_x, new_y;

    float fradians = qDegreesToRadians((float)angle);

    qreal radians = (qreal)fradians;
    new_x = (qreal)(posicion_actual->x() + length * qCos(radians));
    new_y = (qreal)(posicion_actual->y() + length * qSin(radians));

    QPointF* new_point = new QPointF(new_x, new_y);
    dibujarLinea(posicion_actual,new_point);
}

// Dibuja  una linea de punto A a un punto B
void MainWindow::dibujarLinea(QPointF *p1, QPointF *p2, int width)
{
    QPen pen;  // creates a default pen

    pen.setStyle(Qt::SolidLine); //Estilo de linea
    pen.setWidth(width); //Ancho de linea
    pen.setBrush(Qt::green); //Color de lina
    pen.setCapStyle(Qt::SquareCap); //Forma de extremos de lina (cuadrado, redondeado, etc)
    //pen.setJoinStyle(Qt::RoundJoin);

    paint->setPen(pen); //Color separador
    paint->drawLine(*p1, *p2);

    ui->drawing_area->setPixmap(*pix);
}

// Recibe tres puntos y dibuja tres lineas de punto a punto
void MainWindow::dibujarTriangulo(QPointF *p1, QPointF *p2, QPointF *p3)
{
    dibujarLinea(p1,p2);
    dibujarLinea(p2,p3);
    dibujarLinea(p3,p1);
}

// Dibuja un triangulo en base a las propiedades del objeto triangulo
void MainWindow::dibujarTriangulo(triangulo *t)
{
    dibujarTriangulo(t->punto,t->wingA, t->wingB);
}

// Borra lo que esté dibujado en el label
void MainWindow::update_canvas()
{
    pix = new QPixmap(ui->drawing_area->width(), ui->drawing_area->height()); //Tamaño canvas
    pix->fill(Qt::black); //Fondo
    paint = new QPainter(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
