#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new Model(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// SLOTS

void MainWindow::on_lineEdA_editingFinished()
{
    bool isInt = false;
    int enteredValue = ui->lineEdA->text().toInt(&isInt);
    int currentValue = model->getA();
    if (!isInt) {
        ui->lineEdA->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }

    if (!model->setA(enteredValue)) {
        ui->lineEdA->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

void MainWindow::on_lineEdB_editingFinished()
{
    bool isInt = false;
    int enteredValue = ui->lineEdB->text().toInt(&isInt);
    int currentValue = model->getB();
    if (!isInt) {
        ui->lineEdB->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }

    if (!model->setB(enteredValue)) {
        ui->lineEdB->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

void MainWindow::on_lineEdC_editingFinished()
{
    bool isInt = false;
    int enteredValue = ui->lineEdC->text().toInt(&isInt);
    int currentValue = model->getC();
    if (!isInt) {
        ui->lineEdC->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }

    if (!model->setC(enteredValue)) {
        ui->lineEdC->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

