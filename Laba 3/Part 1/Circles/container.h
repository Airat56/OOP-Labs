#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>

template <typename T>
class Container
{
public:
    Container();
    ~Container();
    int getSize() const;
    const T &getObject(int idx) const;
    void setObject(int idx, const T &obj);
    void append(const T &obj);

private:
    std::vector<T*> container;
};

#endif // CONTAINER_H
