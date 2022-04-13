#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include "list.h"
#include <QFileDialog>

MainWindow::MainWindow()
{
    QString str = QFileDialog::getOpenFileName(this, "Выбрать текстовый файл",
                                                    "C:/Users/Александра/OneDrive/Документы/lab1_task4",
                                                    "TXT File (*.txt);" );

    list = new List(str);
    list->LoadData();
    header = new QLabel("List of patients");
    listOfPatients = new QLabel(list->PrintData());
    firstTaskLabel = new QLabel("The number of rooms \nin the hospital with patients with \nmore than three different diagnoses");
    firstAnswerField = new QLabel();


    calculateRoomNumber = new QPushButton("ROOM NUMBERS");
    secondTaskLabel = new QLabel("Sort patients according to\nthe receipt date");
    sortPatientsButton = new QPushButton("SORT PATIENTS");
    secondTaskField = new QLabel();

    minLabel = new QLabel("min:");
    maxLabel = new QLabel("max:");
    minField = new QLineEdit();
    minField->setValidator(new QIntValidator(0, 100, this));
    maxField = new QLineEdit();
    maxField->setValidator(new QIntValidator(0, 100, this));
    calculateAge = new QPushButton("PATIENTS BY AGE");
    patientsByAgeField = new QLabel();
    patientsByRoomNumberField = new QLabel();
    lookForNumbers = new QPushButton("PATIENTS BY ROOM NUMBER");
    patientsByRoomLabel = new QLabel("Number of room:");
    numberOfRoom = new QLineEdit();
    numberOfRoom->setValidator(new QIntValidator(0, 100, this));
    genderLabel = new QLabel("Patient gender:");
    genderComboBox=new QComboBox();
    genderComboBox->addItem(tr("m"));
    genderComboBox->addItem(tr("f"));
    genderField = new QLabel();
    diagnosisLabel = new QLabel("Patient's diagnosis:");
    diagnosisEdit = new QLineEdit();
    lookForDiagnosis = new QPushButton("PATIENTS BY DIAGNOSIS");
    diagnosisField = new QLabel();
    firstNameLabel = new QLabel("First name:");
    lastNameLabel = new QLabel("Last name:");
    firstNameEdit = new QLineEdit();
    lastNameEdit = new QLineEdit();
    lookForNameButton = new QPushButton("PATIENTS BY FIRST NAME AND LAST NAME");
    patientsByNameField = new QLabel();
    LNLabel = new QLabel("Last name:");
    LNEdit = new QLineEdit();
    FNLabel = new QLabel("First name:");
    FNEdit = new QLineEdit();
    AgeLabel = new QLabel("Age:");
    AgeEdit = new QLineEdit();
    AgeEdit->setValidator(new QIntValidator(0, 100, this));
    GenderLabel = new QLabel("Gender:");
    GenderComboBox = new QComboBox();
    GenderComboBox->addItem(tr("m"));
    GenderComboBox->addItem(tr("f"));
    DiagnosisLabel = new QLabel("Diagnosis:");
    DiagnosisEdit = new QLineEdit();
    RoomLabel = new QLabel("Number of room:");
    RoomEdit = new QLineEdit();
    RoomEdit->setValidator(new QIntValidator(0, 100, this));
    FDayLabel = new QLabel("First day:");
    FDay = new QCalendarWidget();
    FDay->setGridVisible(true);
    FDay->setDateRange(QDate(00,00,0000), QDate(01,01,2024));

    LDayLabel = new QLabel("Last day:");
    LDay = new QCalendarWidget();
    AddToFile = new QPushButton("ADD TO FILE");
    //chooseFile =  new QPushButton("CHOOSE FILE");



    mainLayout = new QGridLayout;
    mainLayout->addWidget(header,0,1);
    mainLayout->addWidget(listOfPatients,1,1, 1,4);
    mainLayout->addWidget(LNLabel, 2, 1);
    mainLayout->addWidget(LNEdit, 2, 2);
    mainLayout->addWidget(FNLabel, 2, 3);
    mainLayout->addWidget(FNEdit,2, 4);
    mainLayout->addWidget(GenderLabel, 2, 5);
    mainLayout->addWidget(GenderComboBox,2,6);
    mainLayout->addWidget(AgeLabel, 3, 1);
    mainLayout->addWidget(AgeEdit, 3, 2);
    mainLayout->addWidget(DiagnosisLabel, 3, 3);
    mainLayout->addWidget(DiagnosisEdit, 3, 4);
    mainLayout->addWidget(RoomLabel, 3, 5);
    mainLayout->addWidget(RoomEdit, 3, 6);
    mainLayout->addWidget(FDayLabel, 4, 1);
    mainLayout->addWidget(FDay, 4, 2);
    mainLayout->addWidget(LDayLabel, 4, 3);
    mainLayout->addWidget(LDay, 4, 4);
    mainLayout->addWidget(AddToFile, 4, 5);
    mainLayout->addWidget(firstTaskLabel, 5, 1);
    mainLayout->addWidget(calculateRoomNumber,5,2);
    mainLayout->addWidget(firstAnswerField,5,3);
    mainLayout->addWidget(secondTaskLabel,6, 1);
    mainLayout->addWidget(sortPatientsButton,6,2);
    mainLayout->addWidget(secondTaskField,7,2);
    mainLayout->addWidget(minLabel,8,1);
    mainLayout->addWidget(minField,8,2);
    mainLayout->addWidget(maxLabel,8,3);
    mainLayout->addWidget(maxField,8,4);
    mainLayout->addWidget(calculateAge, 9,1);
    mainLayout->addWidget(patientsByAgeField,9,2);
    mainLayout->addWidget(patientsByRoomLabel,10,1);
    mainLayout->addWidget(numberOfRoom,10,2);
    mainLayout->addWidget(lookForNumbers,11,1);
    mainLayout->addWidget(patientsByRoomNumberField,11,2);
    mainLayout->addWidget(genderLabel,12,1);
    mainLayout->addWidget(genderComboBox,12,2);
    mainLayout->addWidget(genderField,13,2);
    mainLayout->addWidget(diagnosisLabel,14,1);
    mainLayout->addWidget(diagnosisEdit,14,2);
    mainLayout->addWidget(lookForDiagnosis,15,1);
    mainLayout->addWidget(diagnosisField,15,2);
    mainLayout->addWidget(lastNameLabel,16,1);
    mainLayout->addWidget(lastNameEdit, 16, 2);
    mainLayout->addWidget(firstNameLabel,16,3);
    mainLayout->addWidget(firstNameEdit, 16, 4);
    mainLayout->addWidget(lookForNameButton, 17, 1);
    mainLayout->addWidget(patientsByNameField, 17, 2);
    //mainLayout->addWidget(chooseFile, 18, 3);


    connect(calculateRoomNumber, &QPushButton::clicked,this, &MainWindow::NumbersOfRooms);
    connect(sortPatientsButton, &QPushButton::clicked,this, &MainWindow::SortPatients);
    connect(calculateAge, &QPushButton::clicked,this, &MainWindow::lookForAge);
    connect(lookForNumbers, &QPushButton::clicked,this, &MainWindow::lookForRoomNumber);
    connect(genderComboBox, QOverload<int>::of(&QComboBox::activated),
                this, &MainWindow::defineGender);
    connect(lookForDiagnosis, &QPushButton::clicked,this, &MainWindow::defineDiagnosis);
    connect(lookForNameButton, &QPushButton::clicked,this, &MainWindow::lookForName);
    connect(AddToFile, &QPushButton::clicked,this, &MainWindow::addToFile);
    //connect(chooseFile, &QPushButton::clicked,this, &MainWindow::choose);

    setLayout(mainLayout);
}

void MainWindow::NumbersOfRooms()
{
 firstAnswerField->setText(list->numbersOfRooms());
}

void MainWindow::SortPatients(){
    qDebug() << list->countOfPatients;
    secondTaskField->setText(list->sortingPatients());
    patientsByAgeField->setText({});
    patientsByRoomNumberField->setText({});
    genderField->setText({});
    diagnosisField->setText({});
    patientsByNameField->setText({});
    listOfPatients->setText({});
}

void MainWindow::lookForAge(){
    int min=minField->text().toInt();
    int max=maxField->text().toInt();
    patientsByAgeField->setText(list->patientsByAge(min, max));
    secondTaskField->setText({});
    patientsByRoomNumberField->setText({});
    genderField->setText({});
    diagnosisField->setText({});
    patientsByNameField->setText({});
    listOfPatients->setText({});
}

void MainWindow::lookForRoomNumber()
{
    int number=numberOfRoom->text().toInt();
    patientsByRoomNumberField->setText(list->patientsByRoom(number));
    secondTaskField->setText({});
    patientsByAgeField->setText({});
    genderField->setText({});
    diagnosisField->setText({});
    patientsByNameField->setText({});
    listOfPatients->setText({});
}

void MainWindow::defineGender()
{
    int comboBoxIndex = genderComboBox->currentIndex();
    switch (comboBoxIndex) {
    case 0:
        genderField->setText(list->patientsByGender("m"));
        break;
    case 1:
        genderField->setText(list->patientsByGender("f"));
        break;
    }
    secondTaskField->setText({});
    patientsByAgeField->setText({});
    patientsByRoomNumberField->setText({});
    diagnosisField->setText({});
    patientsByNameField->setText({});
    listOfPatients->setText({});
}

void MainWindow::defineDiagnosis()
{
    QString diagnosis = diagnosisEdit->text();
    diagnosisField->setText(list->patientsByDiagnosis(diagnosis));
    secondTaskField->setText({});
    patientsByAgeField->setText({});
    patientsByRoomNumberField->setText({});
    genderField->setText({});
    patientsByNameField->setText({});

}

void MainWindow::lookForName()
{
    QString LN=lastNameEdit->text();
    QString FN=firstNameEdit->text();
    patientsByNameField->setText(list->patientsByName(LN, FN));
    secondTaskField->setText({});
    patientsByAgeField->setText({});
    patientsByRoomNumberField->setText({});
    genderField->setText({});
    diagnosisField->setText({});
    listOfPatients->setText({});
}

void MainWindow::addToFile()
{
    QString LN = LNEdit->text();
    QString FN = FNEdit->text();
    QString gender;
    int comboBoxIndex = GenderComboBox->currentIndex();
    switch (comboBoxIndex) {
    case 0:
        gender="m";
        break;
    case 1:
        gender="f";
        break;
    }
    QString age=AgeEdit->text();
    QString diagnosis=DiagnosisEdit->text();
    QString room = RoomEdit->text();
    QString fDay = FDay->selectedDate().toString("dd.MM.yyyy");
    QString lDay = LDay->selectedDate().toString("dd.MM.yyyy");


        if(list->file.open(QIODevice::Append)){
            QTextStream writeStream(&list->file);
            writeStream << Qt::endl<< LN << Qt::endl;
            writeStream << FN << Qt::endl;
            writeStream << gender << Qt::endl;
            writeStream << age << Qt::endl;
            writeStream << diagnosis << Qt::endl;
            writeStream << room << Qt::endl;
            writeStream << fDay << Qt::endl;
            writeStream << lDay;
            list->file.close();
        }
        else {
        qDebug() << "Could not open file";
        }
        list->countOfPatients++;
        list->LoadData();
}

//void MainWindow::choose()
//{
//   QString str = QFileDialog::getOpenFileName(this, "Выбрать текстовый файл",
//                                                    "C:/Users/admin/Desktop",
//                                                    "TXT File (*.txt);" );

//    file.setFileName(str);
//}



