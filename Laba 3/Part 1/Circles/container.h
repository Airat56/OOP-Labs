#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>

template <typename T>
class Container
{
public:
    Container() = default;
    Container(int size);
    ~Container() = default;
    int getSize() const;
    const T &getObject(int idx) const;
    void setObject(int idx, const T &obj);
    void pushBack(const T &obj);
    void clear();
    void erase(int idx);

private:
    std::vector<T*> container;
};

#endif // CONTAINER_H
