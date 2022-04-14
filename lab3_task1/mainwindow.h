#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QCalendarWidget>
#include <QTimeEdit>


#include "collection.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void searchByTime();
    void searchByPlace();
    void onRoute();
    void inPark();
    void addToFile();
    void Delete();
    void ChangeBox();

private:
    Collection *collection;
    QGridLayout *mainLayout;
    QLabel *header;
    QLabel *listOfTrips;
    QLabel *beforTime;
    QLabel *timeLabel;
    QTimeEdit *timeEdit;
    QLabel *placeLabel;
    QLineEdit *placeEdit;
    QPushButton *searchByTimeButton;
    QLabel *searchByTimeField;
    QLabel *tripsByPlaceLabel;
    QLabel *destinationLabel;
    QLineEdit *destinationEdit;
    QPushButton *searchByPlaceButton;
    QLabel *searchByPlaceField;
    QLabel *busesOnRouteLabel;
    QPushButton *busesOnRouteButton;
    QLabel *busesOnRouteField;
    QLabel *busesInParkLabel;
    QPushButton *busesInParkButton;
    QLabel *busesInParkField;
    QLabel *number;
    QLineEdit *numberEdit;
    QLabel *type;
    QLineEdit *typeEdit;
    QLabel *place;
    QLineEdit *plEdit;
    QLabel *fTime;
    QTimeEdit *fTimeEdit;
    QLabel *sTime;
    QTimeEdit *sTimeEdit;
    QPushButton *addButton;
    QLabel *ex;
    QLabel *deleteLabel;
    QLineEdit *deleteEdit;
    QPushButton *deleteButton;
    QLabel *changeLabel;
    QLineEdit *changeEdit;
    QComboBox *changeComboBox;
    QPushButton *changeButton;
    QLineEdit *newValue;





};
#endif // MAINWINDOW_H
