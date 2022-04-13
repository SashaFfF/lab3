#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow()
{  
    QString str = QFileDialog::getOpenFileName(this, "Выбрать текстовый файл",
                                                    "C:/Users/Александра/OneDrive/Документы/lab3_task1_v2",
                                                    "TXT File (*.txt);" );
    if (str.isEmpty()) {
        exit(1);
    }
    collection = new Collection(str);
    collection ->LoadData();
    header = new QLabel("List of trips");
    listOfTrips = new QLabel(collection->PrintData());

    searchByDateLabel = new QLabel("Train search by date:");
    dateLabel = new QLabel("Date of departure:");
    date = new QCalendarWidget();
    searchByDateButton = new QPushButton("SEARCH TRIPS");
    searchByDateField = new QLabel();

    beforTime = new QLabel("Train search by destination and time:");
    timeLabel =  new QLabel("Departure time:");
    timeEdit = new QTimeEdit();
    timeEdit->setDisplayFormat("hh.mm");
    placeLabel = new QLabel("Destination:");
    placeEdit = new QLineEdit();
    searchByTimeButton = new QPushButton("SEARCH TRIPS");
    searchByTimeField = new QLabel();

    dtLabel = new QLabel("Date of departure:");
    calendar = new QCalendarWidget();
    place = new QLabel("Destination:");
    plEdit = new QLineEdit();
    time = new QLabel("Departure time:");
    tEdit = new QTimeEdit();
    tEdit->setDisplayFormat("hh.mm");
    number = new QLabel("Number of free seats:");
    numberEdit = new QLineEdit();
    addButton = new QPushButton("ADD");
    newListOfTrips = new QLabel();

//    deleteLabel = new QLabel("Deleting a trip with a specific number:");
//    deleteEdit = new QLineEdit();
//    deleteButton = new QPushButton("DELETE");


    mainLayout = new QGridLayout;
    mainLayout->addWidget(header,0,1);
    mainLayout->addWidget(listOfTrips,1,1, 1,4);
    mainLayout->addWidget(newListOfTrips,1,1, 1,4);

    mainLayout->addWidget(dtLabel, 2, 1);
    mainLayout->addWidget(calendar,2,2);
    mainLayout->addWidget(place,2,3);
    mainLayout->addWidget(plEdit, 2, 4);
    mainLayout->addWidget(time,3,1);
    mainLayout->addWidget(tEdit,3,2);
    mainLayout->addWidget(number,3,3);
    mainLayout->addWidget(numberEdit,3,4);
    mainLayout->addWidget(addButton,3,5);


    mainLayout->addWidget(searchByDateLabel,4, 1);
    mainLayout->addWidget(dateLabel,4,2);
    mainLayout->addWidget(date,4,3);
    mainLayout->addWidget(searchByDateButton,5,1);
    mainLayout->addWidget(searchByDateField,5,2);
    mainLayout->addWidget(beforTime, 6, 1);
    mainLayout->addWidget(timeLabel,6,2);
    mainLayout->addWidget(timeEdit,6,3);
    mainLayout->addWidget(placeLabel,6,4);
    mainLayout->addWidget(placeEdit,6,5);
    mainLayout->addWidget(searchByTimeButton,7,1);
    mainLayout->addWidget(searchByTimeField,7,2);
//    mainLayout->addWidget(deleteLabel,8,1);
//    mainLayout->addWidget(deleteEdit,8,2);
//    mainLayout->addWidget(deleteButton,8,3);


    connect(addButton, &QPushButton::clicked,this, &MainWindow::addToFile);
    connect(searchByTimeButton, &QPushButton::clicked,this, &MainWindow::searchByTime);
    connect(searchByDateButton, &QPushButton::clicked,this, &MainWindow::searchByDate);
//    connect(deleteButton, &QPushButton::clicked,this, &MainWindow::Delete);

    setLayout(mainLayout);
}

void MainWindow::searchByTime()
{
    QString time = timeEdit->text();
    QString place = placeEdit->text();
    searchByTimeField->setText(collection->tripsByTime(time, place));
    searchByDateField->setText({});
}

void MainWindow::searchByDate()
{
    QString d = date->selectedDate().toString("dd.MM.yyyy");
    searchByDateField->setText(collection->tripsByDate(d));
    searchByTimeField->setText({});
}

void MainWindow::addToFile()
{
    QString date= calendar->selectedDate().toString("dd.MM.yyyy");
    QString place = plEdit->text();
    QString time = tEdit->text();
    QString number =  numberEdit->text();
    if(collection->file.open(QIODevice::Append)){
        QTextStream writeStream(&collection->file);
        writeStream << Qt::endl<< date << Qt::endl;
        writeStream << place << Qt::endl;
        writeStream << time << Qt::endl;
        writeStream << number;
        collection->file.close();
    }
    else {
    qDebug() << "Could not open file";
    }
    collection->countOfTrips++;
    collection->LoadData();
    listOfTrips->setText({});
    newListOfTrips->setText(collection->PrintData());
    plEdit->setText({});
    numberEdit->setText({});
    tEdit->setTime(QTime(0,0));
}

//void MainWindow::Delete()
//{
//    int number = deleteEdit->text().toInt();
//    collection->delete(number);

//}
