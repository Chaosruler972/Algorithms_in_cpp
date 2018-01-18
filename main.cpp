#include <iostream>

#include "Design Patterns/Singleton/singleton.h"

int main() {
    Singleton &singleton = Singleton::getInstance();
    Singleton &singleton1 = Singleton::getInstance();

    std::cout << singleton << std::endl;
    std::cout << singleton1 << std::endl;
    return 0;
}