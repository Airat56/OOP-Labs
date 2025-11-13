#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <model.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdA_editingFinished();
    void on_lineEdB_editingFinished();
    void on_lineEdC_editingFinished();
    void on_spinBoxA_valueChanged(int arg1);
    void on_spinBoxB_valueChanged(int arg1);
    void on_spinBoxC_valueChanged(int arg1);
    void on_HSliderA_valueChanged(int value);
    void on_HSliderB_valueChanged(int value);
    void on_HSliderC_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    Model *model;
};
#endif // MAINWINDOW_H
