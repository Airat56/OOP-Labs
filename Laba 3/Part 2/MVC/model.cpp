#include "model.h"

Model::Model(QObject *parent) : QObject(parent) {
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
    correctValues();
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
    correctValues();
}


