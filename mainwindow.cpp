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
    configurarPlano();
    t1 = new triangulo(cuadrante_uno);
    t2 = new triangulo(cuadrante_dos);
    t3 = new triangulo(cuadrante_tres);
    t4 = new triangulo(cuadrante_cuatro);

    //girarTriangulos();
    dibujarTriangulos();

    global_angle = 90;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerFunction()));

}

void MainWindow::configurarPlano()
{
    float x = (ui->drawing_area->width()/2);
    float y =  ui->drawing_area->height()/2;
    centro = new QPointF(x,y);

    QPointF* linea_horizontal_inicio = new QPointF(0,y);
    QPointF* linea_horizontal_fin = new QPointF(ui->drawing_area->width(),y);
    dibujarLinea(linea_horizontal_inicio, linea_horizontal_fin);

    QPointF* linea_vertical_inicio = new QPointF(x,0);
    QPointF* linea_vertical_fin = new QPointF(x,ui->drawing_area->height());
    dibujarLinea(linea_vertical_inicio, linea_vertical_fin);

    cuadrante_uno = new QPointF();
    cuadrante_uno->setX(centro->x() + (ui->drawing_area->width()/4));
    cuadrante_uno->setY(centro->y() - (ui->drawing_area->height()/4));

    cuadrante_dos = new QPointF();
    cuadrante_dos->setX(centro->x() + (ui->drawing_area->width()/4));
    cuadrante_dos->setY(centro->y() + (ui->drawing_area->height()/4));

    cuadrante_tres = new QPointF();
    cuadrante_tres->setX(centro->x() - (ui->drawing_area->width()/4));
    cuadrante_tres->setY(centro->y() - (ui->drawing_area->height()/4));

    cuadrante_cuatro = new QPointF();
    cuadrante_cuatro->setX(centro->x() - (ui->drawing_area->width()/4));
    cuadrante_cuatro->setY(centro->y() + (ui->drawing_area->height()/4));

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
    pen.setCapStyle(Qt::RoundCap); //Forma de extremos de lina (cuadrado, redondeado, etc)
    pen.setJoinStyle(Qt::RoundJoin);

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

void MainWindow::girarTriangulos(float theta)
{
    t1->setAngle(theta);
    t2->setAngle(theta);
    t3->setAngle(theta);
    t4->setAngle(theta);
}

void MainWindow::dibujarTriangulos()
{
    dibujarTriangulo(t1);
    dibujarTriangulo(t2);
    dibujarTriangulo(t3);
    dibujarTriangulo(t4);
}

void MainWindow::dibujarLineas()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnGirarTriangulos_clicked()
{

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    girarTriangulos((float)value);
    update_canvas();
    configurarPlano();
    //dibujarLineas();
    dibujarTriangulos();
}

void MainWindow::timerFunction()
{
    if (global_angle >= 450)
        global_angle = 90;
    global_angle ++;
    girarTriangulos(global_angle);
    update_canvas();
    configurarPlano();
    //dibujarLineas();
    dibujarTriangulos();
}

void MainWindow::on_btnGirar_clicked()
{
    timer->start(50);
}

void MainWindow::on_btnDetener_clicked()
{
    timer->stop();
}
