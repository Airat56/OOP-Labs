#include "container.h"

template <typename T>
Container<T>::Container(int size) : _container(size) {}

template <typename T>
int Container<T>::getSize() const {
    return _container.size();
}

template <typename T>
const T &Container<T>::getObject(int idx) const {
    return _container[idx];
}

template <typename T>
void Container<T>::setObject(int idx, const T &obj) {
    _container[idx] = obj;
}

template <typename T>
void Container<T>::pushBack(const T &obj) {
    _container.push_back(obj);
}

template <typename T>
void Container<T>::clear() {
    // Удаляет все элементы. Если элементы являются указателями, их память не освобождается.
    _container.clear();
}

template <typename T>
void Container<T>::erase(int idx) {
    // Удаляет элемент под индексом idx
    _container.erase(_container.begin() + idx);
}
