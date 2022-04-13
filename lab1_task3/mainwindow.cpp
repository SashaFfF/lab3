
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    chooseFile = new QPushButton("Выберите файл", this);
    countOfDates=4;



    connect(chooseFile, SIGNAL(clicked()), this, SLOT(on_ChooseFile_clicked()));




}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_ChooseFile_clicked()
{
    FilePath = QFileDialog::getOpenFileName(this, "Выбрать текстовый файл",
                                                    "C:/Users/admin/Desktop",
                                                    "TXT File (*.txt);" );
    if (!FilePath.isEmpty()) chooseFile->setText(FilePath);


}

bool MainWindow::validationByDate(QString str)
{

        if(str.size() > 10)
        {
            return false;
        }
        else
        {

            foreach(QChar s, str)
            {

                if (s.isDigit() == false && s != '.') {
                    return false;
                }
            }

            int day = str.left(2).toInt();

            if(day > 31 || day <= 0)
            {
                return false;
            }

            int month = str.mid(3,2).toInt();

            if(month > 12 || month <= 0 )
            {
                return false;
            }

            int year = str.right(4).toInt();

            if(year <= 0)
            {
                return false;
            }

            int monthLeap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
            int monthNoLeap[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

            if((year % 4 == 0 && !(year % 100 == 0)) || (year % 400 == 0))
            {
                if(month == 2)
                {
                    if(monthLeap[1] <  day){
                        return false;
                    }
                }
            }else{
                if(month == 2)
                {
                    if(monthNoLeap[1] < day){
                        return false;
                    }
                }

           }
        }
        return true;

}


void MainWindow::on_Enter_clicked()
{

    Bday = ui->lineEdit->text();
    QRegularExpression reg("[0-9]{2}\\.[0-9]{2}\\.[0-9]{4}$");
    if (!Bday.contains(reg))
        QMessageBox::critical(this, "Ошибка", "Формат ввода:\ndd.mm.yyyy");
    else if (FilePath.isEmpty())
        ui->statusbar->showMessage("Выберите файл!");

    else {
        wnd = new QDialog(this);
        wnd->resize(1000, 700);

        QPushButton *btn = new QPushButton("Корректировка данных файла", wnd);
        btn->adjustSize();
//        nd = new QDateEdit(wnd);
//        nd->setDisplayFormat("dd.mm.yyyy");
//        nd->setMinimumDate(QDate(00,00,0000));
//        nd->move(600,650);



        btn->move(400, 650);

        QTableWidget *table = new QTableWidget(wnd);

        table->resize(1000, 650);
//        QCalendarWidget *calendar = new QCalendarWidget(wnd);
//        calendar->setMinimumDate(QDate(00,00,0000));
//        calendar->move(100,450);




        dateEdit = new QDateTimeEdit(QDate::currentDate(),wnd);
        //dateEdit->setDisplayFormat("dd.mm.yyyy");
        dateEdit->setMinimumDate(QDate::currentDate().addYears(-2022));
        dateEdit->setMaximumDate(QDate::currentDate().addYears(1000));
        dateEdit->setCalendarPopup(true);
        dateEdit->resize(150,25);
        dateEdit->move(200,550);



        QFile file(FilePath);
        QTextStream in(&file);
        file.open(QIODevice::ReadOnly);
        countOfDates = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            countOfDates++;
          }
        qDebug()<<countOfDates;
        file.close();

        file.open(QIODevice::ReadOnly);

        int expectation = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            if(validationByDate(line)){
                expectation++;
            }
          }
        qDebug()<<expectation;
        file.close();

        if(expectation != countOfDates){
            QMessageBox ms;
            ms.setText("The file contains invalid data");
            ms.exec();
            exit(1);

        }

        Date *dates = new Date[countOfDates];

        //QFile file(FilePath);

        file.open(QFile::ReadOnly);

        table->setRowCount(countOfDates+1);
        table->setColumnCount(8);

        QTextStream stream(&file);
        QString buffer;

        for (short i = 1, j = 0; i < table->rowCount(); ++i, ++j) {
            buffer = stream.readLine();

            dates[j].setData(buffer, Bday);

            QTableWidgetItem *itm = new QTableWidgetItem(buffer);
            table->setItem(i, 0, itm);
            buffer = "";
        }

        QTableWidgetItem *itm1 = new QTableWidgetItem("Разница между текущим и след.");
        table->setItem(0, 1, itm1);


        QTableWidgetItem *itm2 = new QTableWidgetItem("NextDay");
        table->setItem(0, 2, itm2);


        QTableWidgetItem *itm3 = new QTableWidgetItem("PrevDay");
        table->setItem(0, 3, itm3);


        QTableWidgetItem *itm4 = new QTableWidgetItem("isLeap");
        table->setItem(0, 4, itm4);


        QTableWidgetItem *itm5 = new QTableWidgetItem("WeekNumber");
        table->setItem(0, 5, itm5);


        QTableWidgetItem *itm6 = new QTableWidgetItem("DaysTillBday");
        table->setItem(0, 6, itm6);

        QTableWidgetItem *itm7 = new QTableWidgetItem("Duration");
        table->setItem(0, 7, itm7);

        file.close();

        for (short i = 1, k = 0; i < table->rowCount(); ++i, ++k)
            for (short j = 1; j < table->columnCount(); ++j) {

                switch (j) {

                case 1:
                    if (k == countOfDates-1) buffer = QString::number(dates[k].Duration(dates[0]));
                    else buffer = QString::number(dates[k].Duration(dates[k + 1]));
                    break;
                case 2:
                    buffer = dates[k].NextDay();
                    break;
                case 3:
                    buffer = dates[k].PreviousDay();
                    break;
                case 4:
                    buffer = dates[k].isLeap() ? "Да" : "Нет";
                    break;
                case 5:
                    buffer = QString::number(dates[k].WeekNumber());
                    break;
                case 6:
                    buffer = QString::number(dates[k].DaysTillYourBirthday());
                    break;
                case 7:
                    buffer = QString::number(dates[k].Duration(Date("25.04.2000")));
                }

                QTableWidgetItem *itm = new QTableWidgetItem(buffer);
                table->setItem(i, j, itm);
                buffer = "";
            }

        connect(btn, SIGNAL(clicked()), this, SLOT(on_CorrectData_clicked()));

        wnd->show();
    }

}

void MainWindow::on_CorrectData_clicked()
{
    QString FilePath = QFileDialog::getOpenFileName(this, "Выбрать текстовый файл",
                                                    "C:/Users/Александра/OneDrive/Документы/build-lab1_task3-Desktop_Qt_6_2_3_MinGW_64_bit-Debug",
                                                    "TXT File (*.txt);" );
//    if (FilePath.isEmpty()){
//        return;
//    }


        QFile file(FilePath);
        QTextStream in(&file);

//        QString new_buffer = "\n30.08.2004";

//        file.open(QFile::Append|QFile::Text);

//        QByteArray ba = new_buffer.toLocal8Bit();
//        const char *new_buf = ba.data();

//        file.write(new_buf);

//        file.close();

//        wnd->close();


        file.open(QIODevice::ReadOnly);

        int expectation = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            if(validationByDate(line)){
                expectation++;
            }
          }
        qDebug()<<expectation;
        file.close();

        if(expectation != countOfDates){
            QMessageBox ms;
            ms.setText("The file contains invalid data");
            ms.exec();
            exit(1);

        }





    QString newDate = dateEdit->text();

        if(file.open(QIODevice::Append)){
            QTextStream writeStream(&file);
            writeStream << newDate << Qt::endl;
            file.close();
            wnd->close();
        }
        else {
        qDebug() << "Could not open file";
        }
        countOfDates++;

}


