#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QColor>
#include <QColorDialog>
#include "shape.h"

#include <QMainWindow>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow();
        int StartX;
        int StartY;

    private slots:
        void stopAnimation();
        void startAnimation();
        void drawShape();
        //void squareShape();
        //void perimeterShape();
        //void centreShape();
        void scaleShape();
        void rotateShape();
        void addStartXY();


    private:
        Shape *shape;
        int shapeIndex;
        QGridLayout *mainLayout;
        QPushButton *move;
        QPushButton *stop;
        QPushButton *scale;
        QPushButton *rotate;
        QComboBox *drawComboBox;
        QLabel *drawLabel;
        //QComboBox *squareComboBox;
        QLabel *squareField;
        QLabel *squareLabel;
        //QComboBox *perimeterComboBox;
        QLabel *perimeterField;
        QLabel *perimeterLabel;
        //QComboBox *centreComboBox;
        QLabel *centreField_x;
        QLabel *centreField_y;
        QLabel *centreLabel;
        QLabel *startXLabel;
        QLabel *startYLabel;
        QLineEdit *startXEdit;
        QLineEdit *startYEdit;
        QPushButton *startXY;

};

#endif // MAINWINDOW_H
