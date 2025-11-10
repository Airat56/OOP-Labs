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

