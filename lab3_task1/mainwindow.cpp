#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QFileDialog>
#include "collection.h"

MainWindow::MainWindow(){
    QString str = QFileDialog::getOpenFileName(this, "Выбрать текстовый файл",
                                                    "C:/Users/Александра/OneDrive/Документы/lab3_task1",
                                                    "TXT File (*.txt);" );
    if (str.isEmpty()) {
        exit(1);
    }
    collection = new Collection(str);
    collection ->LoadData();
    header = new QLabel("List of trips");
    listOfTrips = new QLabel(collection->PrintData());

    beforTime = new QLabel("Trips that can be used to\n arrive at the destination\n earlier than the specified time:");
    timeLabel =  new QLabel("Arrival time:");
    timeEdit = new QTimeEdit();
    timeEdit->setDisplayFormat("hh.mm");
    placeLabel = new QLabel("Destination:");
    placeEdit = new QLineEdit();
    searchByTimeButton = new QPushButton("SEARCH TRIPS");
    searchByTimeField = new QLabel();

    tripsByPlaceLabel = new QLabel("Buses that can take you\n to this destination:");
    destinationLabel = new QLabel("Destination:");
    destinationEdit = new QLineEdit();
    searchByPlaceButton = new QPushButton("SEARCH TRIPS");
    searchByPlaceField = new QLabel();

    busesOnRouteLabel = new QLabel("List of buses on the route");
    busesOnRouteButton = new QPushButton("SHOW LIST");
    busesOnRouteField = new QLabel();

    busesInParkLabel = new QLabel("List of buses in the park");
    busesInParkButton = new QPushButton("SHOW LIST");
    busesInParkField = new QLabel();

    number = new QLabel("Trip number:");
    numberEdit = new QLineEdit();
    numberEdit->setValidator(new QIntValidator(0, 100, this));
    type = new QLabel("Bus type:");
    typeEdit = new QLineEdit();
    place = new QLabel("Destination:");
    plEdit = new QLineEdit();
    fTime = new QLabel("Dispatch time:");
    fTimeEdit = new QTimeEdit();
    fTimeEdit->setDisplayFormat("hh.mm");
    sTime = new QLabel("Arrival time:");
    sTimeEdit = new QTimeEdit();
    sTimeEdit->setDisplayFormat("hh.mm");
    addButton = new QPushButton("ADD");
    ex= new QLabel();

    deleteLabel = new QLabel("Deleting a trip with a specific number:");
    deleteEdit = new QLineEdit();
    deleteButton = new QPushButton("DELETE");

    changeLabel = new QLabel("Change the trip selected by number:");
    changeEdit = new QLineEdit();
    changeEdit->setValidator(new QIntValidator(0, 100, this));

    changeComboBox=new QComboBox();
    changeComboBox->addItem(tr("Type"));
    changeComboBox->addItem(tr("Destination"));
    changeComboBox->addItem(tr("Number"));
    changeButton = new QPushButton("CHANGE");
    newValue = new QLineEdit();

    mainLayout = new QGridLayout;
    mainLayout->addWidget(header,0,1);
    mainLayout->addWidget(listOfTrips,1,1, 1,4);
    mainLayout->addWidget(ex,1,1, 1,4);
    mainLayout->addWidget(number, 2, 1);
    mainLayout->addWidget(numberEdit,2,2);
    mainLayout->addWidget(type,2,3);
    mainLayout->addWidget(typeEdit,2,4);
    mainLayout->addWidget(place,2,5);
    mainLayout->addWidget(plEdit,2,6);
    mainLayout->addWidget(fTime,3,1);
    mainLayout->addWidget(fTimeEdit,3,2);
    mainLayout->addWidget(sTime,3,3);
    mainLayout->addWidget(sTimeEdit,3,4);
    mainLayout->addWidget(addButton,3,5);
    mainLayout->addWidget(beforTime, 4, 1);
    mainLayout->addWidget(timeLabel,4,2);
    mainLayout->addWidget(timeEdit,4,3);
    mainLayout->addWidget(placeLabel,4,4);
    mainLayout->addWidget(placeEdit,4,5);
    mainLayout->addWidget(searchByTimeButton,5,1);
    mainLayout->addWidget(searchByTimeField,5,2);
    mainLayout->addWidget(tripsByPlaceLabel,6,1);
    mainLayout->addWidget(destinationLabel,6,2);
    mainLayout->addWidget(destinationEdit,6,3);
    mainLayout->addWidget(searchByPlaceButton,7,1);
    mainLayout->addWidget(searchByPlaceField,7,2);
    mainLayout->addWidget(busesOnRouteLabel,8,1);
    mainLayout->addWidget(busesOnRouteButton,8,2);
    mainLayout->addWidget(busesOnRouteField,9,2);
    mainLayout->addWidget(busesInParkLabel,10,1);
    mainLayout->addWidget(busesInParkButton,10,2);
    mainLayout->addWidget(busesInParkField,11,2);
    mainLayout->addWidget(deleteLabel,12,1);
    mainLayout->addWidget(deleteEdit,12,2);
    mainLayout->addWidget(deleteButton,12,3);
    mainLayout->addWidget(changeLabel,13,1);
    mainLayout->addWidget(changeEdit,13,2);
    mainLayout->addWidget(changeComboBox,13,3);
    mainLayout->addWidget(newValue,13,4);
    mainLayout->addWidget(changeButton,13,5);

    connect(addButton, &QPushButton::clicked,this, &MainWindow::addToFile);
    connect(searchByTimeButton, &QPushButton::clicked,this, &MainWindow::searchByTime);
    connect(searchByPlaceButton, &QPushButton::clicked,this, &MainWindow::searchByPlace);
    connect(busesOnRouteButton, &QPushButton::clicked,this, &MainWindow::onRoute);
    connect(busesInParkButton, &QPushButton::clicked,this, &MainWindow::inPark);
    connect(deleteButton, &QPushButton::clicked,this, &MainWindow::Delete);
    connect(changeButton, &QPushButton::clicked,this, &MainWindow::ChangeBox);


    setLayout(mainLayout);

}

void MainWindow::searchByTime()
{
    QString time = timeEdit->text();
    QString place = placeEdit->text();
    searchByTimeField->setText(collection->tripsByTime(time, place));
    searchByPlaceField->setText({});
    busesOnRouteField->setText({});
    busesInParkField->setText({});
}

void MainWindow::searchByPlace()
{
    QString place = destinationEdit->text();
    searchByPlaceField->setText(collection->tripsByPlace(place));
    searchByTimeField->setText({});
    busesOnRouteField->setText({});
    busesInParkField->setText({});
}

void MainWindow::onRoute()
{
    busesOnRouteField->setText(collection->busesOnRoute());
    searchByPlaceField->setText({});
    searchByTimeField->setText({});
    busesInParkField->setText({});
}

void MainWindow::inPark()
{
    busesInParkField->setText(collection->busesInPark());
    searchByPlaceField->setText({});
    searchByTimeField->setText({});
    busesOnRouteField->setText({});
}

void MainWindow::addToFile()
{
    QString number = numberEdit->text();
    QString type = typeEdit->text();
    QString place = plEdit->text();
    QString t1 = fTimeEdit->text();
    QString t2 = sTimeEdit->text();
    if(collection->file.open(QIODevice::Append)){
        QTextStream writeStream(&collection->file);
        writeStream << Qt::endl<< number << Qt::endl;
        writeStream << type << Qt::endl;
        writeStream << place << Qt::endl;
        writeStream << t1 << Qt::endl;
        writeStream << t2;
        collection->file.close();
    }
    else {
    qDebug() << "Could not open file";
    }
    collection->countOfTrips++;
    collection->LoadData();
    listOfTrips->setText({});
    ex->setText(collection->PrintData());
    numberEdit->setText({});
    typeEdit->setText({});
    plEdit->setText({});
    fTimeEdit->setTime(QTime(0,0));
    sTimeEdit->setTime(QTime(0,0));

}

void MainWindow::Delete()
{
    int number = deleteEdit->text().toInt();
    collection->Delete(number);
    listOfTrips->setText({});
    ex->setText(collection->PrintData());
    busesInParkField->setText({});
    searchByPlaceField->setText({});
    searchByTimeField->setText({});
    busesOnRouteField->setText({});
}

void MainWindow::ChangeBox()
{
    int comboBoxIndex = changeComboBox->currentIndex();
        switch (comboBoxIndex) {
        case 0:
        {
            int number = changeEdit->text().toInt();
            QString type = newValue->text();
            collection->ChangeByType(number, type);
            listOfTrips->setText({});
            ex->setText(collection->PrintData());
            break;
        }
        case 1:
        {
            int number = changeEdit->text().toInt();
            QString place = newValue->text();
            collection->ChangeByPlace(number, place);
            listOfTrips->setText({});
            ex->setText(collection->PrintData());
            break;

        }
        case 2:
        {
            newValue->setValidator(new QIntValidator(0, 100, this));
            int number = changeEdit->text().toInt();
            QString str = newValue->text();
            collection->ChangeByNumber(number, str);
            listOfTrips->setText({});
            ex->setText(collection->PrintData());
            break;
        }
        }

}



