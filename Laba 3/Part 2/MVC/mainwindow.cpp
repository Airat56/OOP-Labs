#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _model(new Model(this))
    , _isUpdating(false)
{
    ui->setupUi(this);
    connect(_model, &Model::dataChanged, this, &MainWindow::on_model_changed);
    on_model_changed();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// SLOTS

void MainWindow::on_lineEdA_editingFinished()
{
    if (_isUpdating) {
        return;
    }

    bool isInt = false;
    int enteredValue = ui->lineEdA->text().toInt(&isInt);
    int currentValue = _model->getA();
    if (!isInt) {
        ui->lineEdA->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }

    if (!_model->setA(enteredValue)) {
        ui->lineEdA->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

void MainWindow::on_lineEdB_editingFinished()
{
    if (_isUpdating) {
        return;
    }

    bool isInt = false;
    int enteredValue = ui->lineEdB->text().toInt(&isInt);
    int currentValue = _model->getB();
    if (!isInt) {
        ui->lineEdB->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }

    if (!_model->setB(enteredValue)) {
        ui->lineEdB->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

void MainWindow::on_lineEdC_editingFinished()
{
    if (_isUpdating) {
        return;
    }

    bool isInt = false;
    int enteredValue = ui->lineEdC->text().toInt(&isInt);
    int currentValue = _model->getC();
    if (!isInt) {
        ui->lineEdC->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }

    if (!_model->setC(enteredValue)) {
        ui->lineEdC->setText(QString::number(currentValue));
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}


void MainWindow::on_spinBoxA_editingFinished()
{
    if (_isUpdating) {
        return;
    }

    int currentValue = _model->getA();
    if (!_model->setA(ui->spinBoxA->value())) {
        ui->spinBoxA->setValue(currentValue);
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

void MainWindow::on_spinBoxB_editingFinished()
{
    if (_isUpdating) {
        return;
    }

    int currentValue = _model->getB();
    if (!_model->setB(ui->spinBoxB->value())) {
        ui->spinBoxB->setValue(currentValue);
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

void MainWindow::on_spinBoxC_editingFinished()
{
    if (_isUpdating) {
        return;
    }

    int currentValue = _model->getC();
    if (!_model->setC(ui->spinBoxC->value())) {
        ui->spinBoxC->setValue(currentValue);
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

void MainWindow::on_HSliderA_valueChanged(int value)
{
    if (_isUpdating) {
        return;
    }

    int currentValue = _model->getA();
    if (!_model->setA(value)) {
        ui->HSliderA->setValue(currentValue);
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

void MainWindow::on_HSliderB_valueChanged(int value)
{
    if (_isUpdating) {
        return;
    }

    int currentValue = _model->getB();
    if (!_model->setB(value)) {
        ui->HSliderB->setValue(currentValue);
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

void MainWindow::on_HSliderC_valueChanged(int value)
{
    if (_isUpdating) {
        return;
    }

    int currentValue = _model->getC();
    if (!_model->setC(value)) {
        ui->HSliderC->setValue(currentValue);
        QMessageBox::warning(this, "Ошибка", "Введено некорректное значение");
        return;
    }
}

void MainWindow::on_model_changed() {
    _isUpdating = true;
    int currentValueA = _model->getA();
    int currentValueB = _model->getB();
    int currentValueC = _model->getC();

    ui->lineEdA->setText(QString::number(currentValueA));
    ui->lineEdB->setText(QString::number(currentValueB));
    ui->lineEdC->setText(QString::number(currentValueC));
    ui->spinBoxA->setValue(currentValueA);
    ui->spinBoxB->setValue(currentValueB);
    ui->spinBoxC->setValue(currentValueC);
    ui->HSliderA->setValue(currentValueA);
    ui->HSliderB->setValue(currentValueB);
    ui->HSliderC->setValue(currentValueC);

    _isUpdating = false;
}

