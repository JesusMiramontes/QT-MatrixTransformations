#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "triangulo.h"

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
    static QPointF *rotar(QPointF* posicion_actual, int angle, int length=3);
    void dibujarLineaWithAngle(int angle, QPointF *posicion_actual, int length=3);
    void dibujarLinea(QPointF *p1, QPointF *p2, int width=3);
    void dibujarTriangulo(QPointF *p1, QPointF *p2, QPointF *p3);
    void dibujarTriangulo(triangulo* t);
    void update_canvas();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
