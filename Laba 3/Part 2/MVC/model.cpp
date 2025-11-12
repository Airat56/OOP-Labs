#include "model.h"
#include <QFile>
#include <QIODevice>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>

Model::Model(QObject *parent) : QObject(parent) {
    connect(this, &Model::dataChanged, this, &Model::onDataChanged);
    loadData();
}

Model::~Model() {
    saveData();
}

int Model::getA() const {
    return _a;
}

int Model::getB() const {
    return _b;
}

int Model::getC() const {
    return _c;
}

void Model::setA(int value) {
    if (value == _a) {
        return;
    }

    if (value < MIN || value > MAX) {
        return;
    }

    // разрешающее поведение
    _a = value;
    if (_a > _c) {
        _c = _a;
    }

    if (_b < _a) {
        _b = _a;
    }
}

void Model::setB(int value) {
    if (value == _b) {
        return;
    }

    if (value < MIN || value > MAX) {
        return;
    }

    // запрещающее поведение
    if (value < _a || value > _c) {
        return;
    }

    _b = value;
}

void Model::setC(int value) {
    if (value == _c) {
        return;
    }

    if (value < MIN || value > MAX) {
        return;
    }

    // разрешающее поведение
    _c = value;
    if (_a > _c) {
        _a = _c;
    }

    if (_b > _c) {
        _b = _c;
    }
}

QString Model::getDataFilePath() {
    QString dirPath = QCoreApplication::applicationDirPath() + "/data";
    QDir dir(dirPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    return dirPath + "/saved_data.json";
}

void Model::saveData() {
    QString dataFilePath = getDataFilePath();
    QFile file(dataFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Couldn't open the file for writing: " << dataFilePath << "\n" << file.errorString();
        return;
    }

    QJsonObject json;
    json["a"] = _a;
    json["b"] = _b;
    json["c"] = _c;
    QJsonDocument doc(json);
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
    qDebug() << "Model saved successfully";
}

void Model::loadData() {
    QString dataFilePath = getDataFilePath();
    QFile file(dataFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Couldn't open the file (" << dataFilePath << "). Load default values.\n" << file.errorString();
        _a = MIN;
        _b = (MIN + MAX) / 2;
        _c = MAX;
        emit dataChanged();
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) {
        qWarning() << "Couldn't open the file (" << dataFilePath << "). Load default values.\n" << file.errorString();
        _a = MIN;
        _b = (MIN + MAX) / 2;
        _c = MAX;
        emit dataChanged();
        return;
    }

    QJsonObject json = doc.object();
    // проверка
    bool isAValid = json.contains("a") && json["a"].isDouble();
    bool isBValid = json.contains("a") && json["a"].isDouble();
    bool isCValid = json.contains("a") && json["a"].isDouble();

    _a = isAValid ? json["a"].toInt() : MIN;
    _c = isCValid ? json["c"].toInt() : MAX;
    _b = isBValid ? json["b"].toInt() : (_a + _c) / 2;

    if (_a < MIN || _a > MAX) {
        _a = MIN;
    }
    if (_c < MIN || _c > MAX) {
        _c = MAX;
    }
    if (_b < MIN || _b > MAX) {
        _b = (_a + _c) / 2;
    }

    if (_a > _c) {
        _c = _a;
    }
    if (_b < _a) {
        _b = _a;
    }
    if (_b > _c) {
        _b = _c;
    }

    qDebug() << "Model loaded successfully";
    emit dataChanged();
}

// SLOTS

void Model::onDataChanged() {
    // отладочная информация
    qDebug() << "Data in Model changed: A =" << _a << ", B =" << _b << ", C =" << _c;
}
