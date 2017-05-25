#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "triangulo.h"
#include "QPointF"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);


    // Elementos usados para dibujar
    QPixmap *pix;
    QPainter* paint;

    // Declara los 4 triangulos
    triangulo* t1;
    triangulo* t2;
    triangulo* t3;
    triangulo* t4;

    // Declara los 4 timers
    QTimer* timer_rotacion;
    QTimer* timer_apuntar_al_centro;
    QTimer* timer_mover_al_centro;
    QTimer* timer_helice;

    // Declara los cuatro cuadrantes y el centro
    QPointF* cuadrante_uno;
    QPointF* cuadrante_dos;
    QPointF* cuadrante_tres;
    QPointF* cuadrante_cuatro;
    QPointF* centro;

    // Método que obiene las coordenadas de las lineas separadoras
    void configurarPlano();

    // Variable que se utiliza para girar todos los triangulos al mismo tiempo
    int global_angle;

    // Coordenadas de las lineas separadoras
    QPointF* linea_horizontal_inicio;
    QPointF* linea_horizontal_fin;
    QPointF* linea_vertical_inicio;
    QPointF* linea_vertical_fin;

    // Rota un punto con respecto a otro
    static QPointF *rotar(QPointF* posicion_actual, int angle, int length=3);

    // Dibuja una linea del punto A a el punto calculado con base al angulo
    void dibujarLineaWithAngle(int angle, QPointF *posicion_actual, int length=3);

    // Dibuja una linea de un punto A a un punto B
    void dibujarLinea(QPointF *p1, QPointF *p2, int width=3);

    // Recibe tres puntos y dibuja lineas entre ellos
    void dibujarTriangulo(QPointF *p1, QPointF *p2, QPointF *p3);

    // Recibe un triangulo y traza las lineas entre sus puntos
    void dibujarTriangulo(triangulo* t);

    // Actualiza el lienzo
    void update_canvas();

    // Gira todos los triangulos en base a theta
    void girarTriangulos(float theta);

    // Dibuja los 4 triangulos
    void dibujarTriangulos();

    // Dibuja las lineas separadoras
    void dibujarLineas();

    // Limpia el lienzo, dibuja las lineas, y los triangulos
    void redibujar();

    // Traslada un triangulo T al centro
    bool trasladarAlCentro(triangulo* t);
    ~MainWindow();

private slots:
    void on_btnGirarTriangulos_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_btnGirar_clicked();

    void on_btnDetener_clicked();

    void on_btnApuntar_clicked();

    void on_btnMover_clicked();

    void on_btnDetenerApuntar_clicked();

    void on_btnDetenerMover_clicked();

    void on_btnHelice_clicked();

    void on_btnDetenerHelice_clicked();

public slots:
    void timerRotar();
    void timerApuntarAlCentro();
    void timerMoverAlCentro();
    void timerHelice();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
