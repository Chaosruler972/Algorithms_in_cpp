
#ifndef ALGORITHMS_SINGLETON_H
#define ALGORITHMS_SINGLETON_H

#include <iostream>
#include <memory>

class Singleton {
private:

    static std::unique_ptr<Singleton> _instance;

    Singleton() = default;

public:
    Singleton(const Singleton &other) = delete;

    static Singleton &getInstance();

    friend std::ostream &operator<<(std::ostream &os, const Singleton &singleton);
};


#endif //ALGORITHMS_SINGLETON_H
