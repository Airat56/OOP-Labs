#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QString>

class Model : public QObject {
    Q_OBJECT

public:
    Model(QObject *parent = nullptr);
    ~Model();
    int getA() const;
    int getB() const;
    int getC() const;
    bool setA(int value);
    bool setB(int value);
    bool setC(int value);


signals:
    void dataChanged();

private slots:
    void on_data_changed();

private:
    int _a, _b, _c;
    static const int MIN = 0;
    static const int MAX = 100;

    void saveData();
    void loadData();
    QString getDataFilePath();
};

#endif // MODEL_H
