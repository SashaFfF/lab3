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
    void searchByDate();
    void addToFile();
    //void Delete();


private:
    Collection *collection;
    QGridLayout *mainLayout;
    QLabel *header;
    QLabel *listOfTrips;
    QLabel *newListOfTrips;
    QLabel *searchByDateLabel;
    QLabel *dateLabel;
    QCalendarWidget *date;
    QPushButton *searchByDateButton;
    QLabel *searchByDateField;
    QLabel *beforTime;
    QLabel *timeLabel;
    QTimeEdit *timeEdit;
    QLabel *placeLabel;
    QLineEdit *placeEdit;
    QPushButton *searchByTimeButton;
    QLabel *searchByTimeField;
    QLabel *dtLabel;
    QCalendarWidget *calendar;
    QLabel *place;
    QLineEdit *plEdit;
    QLabel *time;
    QTimeEdit *tEdit;
    QLabel *number;
    QLineEdit *numberEdit;
    QPushButton *addButton;
//    QLabel *deleteLabel;
//    QLineEdit *deleteEdit;
//    QPushButton *deleteButton;




};
#endif // MAINWINDOW_H
