#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDateTime>
#include <QDate>
#include <QMessageBox>
#include <QTextStream>

#include <QDialog>
#include <QTableWidget>
#include <QDateEdit>
#include <QCalendarWidget>

#include "date.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int countOfDates;

private slots:

    void on_ChooseFile_clicked();
    void on_Enter_clicked();
    void on_CorrectData_clicked();
    bool validationByDate(QString str);

private:
    Ui::MainWindow *ui;
    QString FilePath;
    QString Bday;

    QPushButton *chooseFile;
    QDateEdit *nd;
    QDateTimeEdit *dateEdit;

    QDialog *wnd;
};
#endif // MAINWINDOW_H
