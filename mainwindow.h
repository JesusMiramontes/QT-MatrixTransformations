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
    QPixmap *pix;
    QPainter* paint;
    triangulo* t1;
    triangulo* t2;
    triangulo* t3;
    triangulo* t4;

    QTimer* timer_rotacion;
    QTimer* timer_apuntar_al_centro;
    QTimer* timer_mover_al_centro;

    QPointF* cuadrante_uno;
    QPointF* cuadrante_dos;
    QPointF* cuadrante_tres;
    QPointF* cuadrante_cuatro;
    QPointF* centro;
    void configurarPlano();
    int global_angle;

    QPointF* linea_horizontal_inicio;
    QPointF* linea_horizontal_fin;
    QPointF* linea_vertical_inicio;
    QPointF* linea_vertical_fin;

    static QPointF *rotar(QPointF* posicion_actual, int angle, int length=3);
    void dibujarLineaWithAngle(int angle, QPointF *posicion_actual, int length=3);
    void dibujarLinea(QPointF *p1, QPointF *p2, int width=3);
    void dibujarTriangulo(QPointF *p1, QPointF *p2, QPointF *p3);
    void dibujarTriangulo(triangulo* t);
    void update_canvas();
    void girarTriangulos(float theta);
    void dibujarTriangulos();
    void dibujarLineas();
    void redibujar();
    bool trasladarAlCentro(triangulo* t);
    ~MainWindow();

private slots:
    void on_btnGirarTriangulos_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_btnGirar_clicked();

    void on_btnDetener_clicked();

    void on_btnApuntar_clicked();

    void on_btnMover_clicked();

public slots:
    void timerRotar();
    void timerApuntarAlCentro();
    void timerMoverAlCentro();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
