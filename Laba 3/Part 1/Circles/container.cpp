#include "container.h"

template <typename T>
Container<T>::Container(int size) : container(size) {}

template <typename T>
int Container<T>::getSize() const {
    return container.size();
}

template <typename T>
const T &Container<T>::getObject(int idx) const {
    return container[idx];
}

template <typename T>
void Container<T>::setObject(int idx, const T &obj) {
    container[idx] = obj;
}

template <typename T>
void Container<T>::pushBack(const T &obj) {
    container.push_back(obj);
}
