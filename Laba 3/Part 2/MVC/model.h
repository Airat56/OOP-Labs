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
    void setA(int value);
    void setB(int value);
    void setC(int value);


signals:
    void dataChanged();

private:
    int _a, _b, _c;
    static const int MIN = 0;
    static const int MAX = 100;
    static const QString DATA_FILE_PATH;

    void saveData();
    void loadData();
};

#endif // MODEL_H
