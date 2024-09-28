#pragma once
#include "array.h"


class Application
{
private:
    Array array;
public:
    Application();
    ~Application();
    void run();
    void fill();
    void resize(int newCapacity);
};