#include <QPainter>
#include <QTimer>
#include <QGridLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "triangle.h"
#include "circle.h"
#include "rhombus.h"
#include "square.h"
#include "hexagon.h"
#include "semicircle.h"
#include "rectangle.h"
#include "star_5.h"
#include "star_6.h"
#include "star_8.h"


MainWindow::MainWindow()
{
    shape = new Shape();
    shapeIndex = 0;
    move = new QPushButton("MOVE");
    stop = new QPushButton("STOP");
    scale = new QPushButton("SCALE");
    rotate = new QPushButton("ROTATE");
    StartX = 50;
    StartY = 50;


    startXLabel = new QLabel("Enter starting x:");
    startYLabel = new QLabel("Enter starting y:");
    startXEdit = new QLineEdit();
    startXEdit->setValidator(new QIntValidator(0, 100, this));
    startYEdit = new QLineEdit();
    startYEdit->setValidator(new QIntValidator(0, 100, this));
    startXY = new QPushButton("ADD START COORDINATES");


    //colorButton = new QPushButton("COLOR");



    drawComboBox=new QComboBox();
    drawComboBox->addItem(tr("Rectangle"));
    drawComboBox->addItem(tr("Triangle"));
    drawComboBox->addItem(tr("Circle"));
    drawComboBox->addItem(tr("Rhombus"));
    drawComboBox->addItem(tr("Square"));
    drawComboBox->addItem(tr("Hexagon"));
    drawComboBox->addItem(tr("Semicircle"));
    drawComboBox->addItem(tr("Star5"));
    drawComboBox->addItem(tr("Star6"));
    drawComboBox->addItem(tr("Star8"));

    drawLabel=new QLabel("Move shape");

//    squareComboBox=new QComboBox();
//    squareComboBox->addItem(tr("Rectangle"));
//    squareComboBox->addItem(tr("Triangle"));
//    squareComboBox->addItem(tr("Circle"));
//    squareComboBox->addItem(tr("Rhombus"));
//    squareComboBox->addItem(tr("Square"));
//    squareComboBox->addItem(tr("Hexagon"));
//    squareComboBox->addItem(tr("Semicircle"));
//    squareComboBox->addItem(tr("Star5"));
//    squareComboBox->addItem(tr("Star6"));
//    squareComboBox->addItem(tr("Star8"));

    squareField=new QLabel();
    squareLabel=new QLabel("SQUARE:");
    squareLabel->adjustSize();

//    perimeterComboBox=new QComboBox();
//    perimeterComboBox->addItem(tr("Rectangle"));
//    perimeterComboBox->addItem(tr("Triangle"));
//    perimeterComboBox->addItem(tr("Circle"));
//    perimeterComboBox->addItem(tr("Rhombus"));
//    perimeterComboBox->addItem(tr("Square"));
//    perimeterComboBox->addItem(tr("Hexagon"));
//    perimeterComboBox->addItem(tr("Semicircle"));
//    perimeterComboBox->addItem(tr("Star5"));
//    perimeterComboBox->addItem(tr("Star6"));
//    perimeterComboBox->addItem(tr("Star8"));


    perimeterField=new QLabel();
    perimeterLabel=new QLabel("PERIMETER:");
    perimeterLabel->adjustSize();

//    centreComboBox=new QComboBox();
//    centreComboBox->addItem(tr("Rectangle"));
//    centreComboBox->addItem(tr("Triangle"));
//    centreComboBox->addItem(tr("Circle"));
//    centreComboBox->addItem(tr("Rhombus"));
//    centreComboBox->addItem(tr("Square"));
//    centreComboBox->addItem(tr("Hexagon"));
//    centreComboBox->addItem(tr("Semicircle"));
//    centreComboBox->addItem(tr("Star5"));
//    centreComboBox->addItem(tr("Star6"));
//    centreComboBox->addItem(tr("Star8"));

    centreField_x=new QLabel();
    centreField_y=new QLabel();
    centreLabel=new QLabel("CENTRE(X,Y):");
    centreLabel->adjustSize();
    centreField_x->adjustSize();
    centreField_y->adjustSize();

//    mainLayout = new QGridLayout;
//    mainLayout->addWidget(shape, 0,0,2,4);
//    mainLayout->addWidget(startXLabel,3,0);
//    mainLayout->addWidget(startXEdit, 3, 1);
//    mainLayout->addWidget(startYLabel,3,2);
//    mainLayout->addWidget(startYEdit,3,3);
//    mainLayout->addWidget(startXY,3,4);
//    mainLayout->addWidget(drawLabel,4,0);
//    mainLayout->addWidget(drawComboBox, 4, 1);
//    mainLayout->addWidget(move,4,2);
//    mainLayout->addWidget(stop,4,3);
//    mainLayout->addWidget(squareLabel,5,0);
//    //mainLayout->addWidget(squareComboBox,4,1);
//    mainLayout->addWidget(squareField, 5,1);
//    mainLayout->addWidget(perimeterLabel,6,0);
//    //mainLayout->addWidget(perimeterComboBox,5,1);
//    mainLayout->addWidget(perimeterField, 6,1);
//    mainLayout->addWidget(centreLabel,7,0);
//    //mainLayout->addWidget(centreComboBox,6,1);
//    mainLayout->addWidget(centreField_x, 7,1);
//    mainLayout->addWidget(centreField_y, 7,2);
//    mainLayout->addWidget(scale, 8,1);
//    mainLayout->addWidget(rotate, 9,1);

      mainLayout = new QGridLayout;
      mainLayout->addWidget(shape, 0,0,2,4);
      mainLayout->addWidget(startXLabel,3,0);
      mainLayout->addWidget(startXEdit, 3, 1);
      mainLayout->addWidget(startYLabel,3,2);
      mainLayout->addWidget(startYEdit,3,3);
      mainLayout->addWidget(startXY,3,4);
      mainLayout->addWidget(drawLabel,4,0);
      mainLayout->addWidget(drawComboBox, 4, 1);
      mainLayout->addWidget(move,4,2);
      mainLayout->addWidget(stop,4,3);
      mainLayout->addWidget(squareLabel,5,0);

      //mainLayout->addWidget(squareComboBox,4,1);
      mainLayout->addWidget(squareField, 5,1);
      mainLayout->addWidget(perimeterLabel,5,2);
      //mainLayout->addWidget(perimeterComboBox,5,1);
      mainLayout->addWidget(perimeterField, 5,3);
      mainLayout->addWidget(centreLabel,5,4);
        //mainLayout->addWidget(centreComboBox,6,1);
        mainLayout->addWidget(centreField_x, 5,6);
        mainLayout->addWidget(centreField_y, 5,7);
        mainLayout->addWidget(scale, 6,1);
        mainLayout->addWidget(rotate, 7,1);
        //mainLayout->addWidget(colorButton, 10, 1);


    connect(move, &QPushButton::clicked,this, &MainWindow::startAnimation);
    connect(stop, &QPushButton::clicked,this, &MainWindow::stopAnimation);
    connect(drawComboBox, QOverload<int>::of(&QComboBox::activated),
                this, &MainWindow::drawShape);
//    connect(squareComboBox, QOverload<int>::of(&QComboBox::activated),
//                this, &MainWindow::squareShape);
//    connect(perimeterComboBox, QOverload<int>::of(&QComboBox::activated),
//                this, &MainWindow::perimeterShape);
//    connect(centreComboBox, QOverload<int>::of(&QComboBox::activated),
//                this, &MainWindow::centreShape);
    connect(scale, &QPushButton::clicked,this, &MainWindow::scaleShape);
    connect(rotate, &QPushButton::clicked,this, &MainWindow::rotateShape);
    connect(startXY, &QPushButton::clicked,this, &MainWindow::addStartXY);

    setLayout(mainLayout);
}

void MainWindow::stopAnimation()
{
    shape->stop();

}

void MainWindow::startAnimation()
{
    shape->start();
}

void MainWindow::addStartXY()
{
    StartX=startXEdit->text().toInt();
    StartY=startYEdit->text().toInt();

}

void MainWindow::drawShape(){
    int comboBoxIndex = drawComboBox->currentIndex();
    double square = 0.0;
    double perimeter = 0.0;
    double x = 0.0;
    double y = 0.0;
    switch (comboBoxIndex) {
    case 0:
        shape= new Rectangle(StartX, StartY);
        break;
     case 1:
        shape = new Triangle(StartX, StartY);
        break;
     case 2:
        shape = new Circle(StartX, StartY);
        break;
     case 3:
        shape = new Rhombus(StartX, StartY);
        break;
     case 4:
        shape = new Square2(StartX, StartY);
        break;
     case 5:
        shape = new Hexagon(StartX, StartY);
        break;
     case 6:
        shape = new Semicircle(StartX, StartY);
        break;
     case 7:
        shape = new Star5(StartX, StartY);
        break;
     case 8:
        shape = new Star6(StartX, StartY);
        break;
     case 9:
        shape = new Star8(StartX, StartY);
        break;
    }
    QLayoutItem *child;
    if((child = mainLayout->takeAt(shapeIndex)) != nullptr){
        delete child->widget();
        delete child;
    }
    mainLayout->addWidget(shape, 0,0,1,4);
    shapeIndex = mainLayout->indexOf(shape);//поиск индекса фигуры (будем использовать для удаления)
    square = shape->Square();
    squareField->setText(QString::number(square));
    perimeter = shape->Perimeter();
    perimeterField->setText(QString::number(perimeter));
    shape->Centre(x, y);
    centreField_x->setText(QString::number(x));
    centreField_y->setText(QString::number(y));
}

//void MainWindow::squareShape(){
//    int comboBoxIndex = squareComboBox->currentIndex();
//    double square = 0.0;
//    Shape *sh;
//    switch (comboBoxIndex) {
//    case 0:
//        sh = new Rectangle();
//        break;
//    case 1:
//        sh = new Triangle();
//        break;
//    case 2:
//        sh = new Circle();
//        break;
//    case 3:
//        sh = new Rhombus();
//        break;
//    case 4:
//        sh = new Square2();
//        break;
//    case 5:
//        sh = new Hexagon();
//        break;
//    case 6:
//        sh = new Semicircle();
//        break;
//    case 7:
//        sh = new Star5();
//        break;
//    case 8:
//        sh = new Star6();
//        break;
//    case 9:
//        sh = new Star8();
//        break;
//    }
//    square = sh->Square();
//    squareField->setText(QString::number(square));
//}

//void MainWindow::perimeterShape(){
//    int comboBoxIndex = perimeterComboBox->currentIndex();
//    double perimeter = 0.0;
//    Shape *sh;
//    switch (comboBoxIndex) {
//    case 0:
//        sh = new Rectangle();
//        break;
//    case 1:
//        sh = new Triangle();
//        break;
//    case 2:
//        sh = new Circle();
//        break;
//    case 3:
//        sh = new Rhombus();
//        break;
//    case 4:
//        sh = new Square2();
//        break;
//    case 5:
//        sh = new Hexagon();
//        break;
//    case 6:
//        sh = new Semicircle();
//        break;
//    case 7:
//        sh = new Star5();
//        break;
//    case 8:
//        sh = new Star6();
//        break;
//    case 9:
//        sh = new Star8();
//        break;
//    }
//    perimeter = sh->Perimeter();
//    perimeterField->setText(QString::number(perimeter));
//}

//void MainWindow::centreShape(){
//    int comboBoxIndex = centreComboBox->currentIndex();
//    double x = 0.0;
//    double y = 0.0;
//    Shape *sh;
//    switch (comboBoxIndex) {
//    case 0:
//        sh = new Rectangle(StartX, StartY);
//        break;
//    case 1:
//        sh = new Triangle();
//        break;
//    case 2:
//        sh = new Circle();
//        break;
//    case 3:
//        sh = new Rhombus();
//        break;
//    case 4:
//        sh = new Square2();
//        break;
//    case 5:
//        sh = new Hexagon();
//        break;
//    case 6:
//        sh = new Semicircle();
//        break;
//    case 7:
//        sh = new Star5();
//        break;
//    case 8:
//        sh = new Star6();
//        break;
//    case 9:
//        sh = new Star8();
//        break;
//    }
//    sh->Centre(x, y);
//    centreField_x->setText(QString::number(x));
//    centreField_y->setText(QString::number(y));
//}

void MainWindow::scaleShape(){
    shape -> startScale();
}
void MainWindow::rotateShape(){
    shape -> startRotate();
}



