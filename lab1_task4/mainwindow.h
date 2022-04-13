#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QCalendarWidget>


#include "list.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void NumbersOfRooms();
    void SortPatients();
    void lookForAge();
    void lookForRoomNumber();
    void defineGender();
    void defineDiagnosis();
    void lookForName();
    void addToFile();
    //void choose();



private:
    List *list;
    QGridLayout *mainLayout;
    QLabel *header;
    QLabel *listOfPatients;
    QLabel *firstTaskLabel;
    QPushButton *calculateRoomNumber;
    QLabel *firstAnswerField;
    QLabel *secondTaskLabel;
    QPushButton *sortPatientsButton;
    QLabel *secondTaskField;
    QLabel *minLabel;
    QLabel *maxLabel;
    QLineEdit *minField;
    QLineEdit *maxField;
    QPushButton *calculateAge;
    QLabel *patientsByAgeField;
    QLabel *patientsByRoomLabel;
    QLineEdit *numberOfRoom;
    QLabel *patientsByRoomNumberField;
    QPushButton *lookForNumbers;
    QLabel *genderLabel;
    QComboBox *genderComboBox;
    QLabel *genderField;
    QLabel *diagnosisLabel;
    QLineEdit *diagnosisEdit;
    QPushButton *lookForDiagnosis;
    QLabel *diagnosisField;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QPushButton *lookForNameButton;
    QLabel *patientsByNameField;
    QLabel *LNLabel;
    QLineEdit *LNEdit;
    QLabel *FNLabel;
    QLineEdit *FNEdit;
    QLabel *AgeLabel;
    QLineEdit *AgeEdit;
    QLabel *GenderLabel;
    QComboBox *GenderComboBox;
    QLabel *DiagnosisLabel;
    QLineEdit *DiagnosisEdit;
    QLabel *RoomLabel;
    QLineEdit *RoomEdit;
    QLabel *FDayLabel;
    QCalendarWidget *FDay;
    QLabel *LDayLabel;
    QCalendarWidget *LDay;
    QPushButton *AddToFile;
    //QPushButton *chooseFile;







};
#endif // MAINWINDOW_H
