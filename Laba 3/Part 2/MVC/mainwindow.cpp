#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// SLOTS

void MainWindow::on_lineEdA_textChanged(const QString &arg1)
{
    //
}

void MainWindow::on_lineEdB_textChanged(const QString &arg1)
{
    //
}

void MainWindow::on_lineEdC_textChanged(const QString &arg1)
{
    //
}


