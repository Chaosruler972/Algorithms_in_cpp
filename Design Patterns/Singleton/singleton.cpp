
#include "singleton.h"


std::unique_ptr<Singleton> Singleton::_instance = nullptr;

Singleton &Singleton::getInstance() {
    if (_instance == nullptr) {
        _instance = std::unique_ptr<Singleton>(new Singleton());
    }
    return *_instance;
}

std::ostream &operator<<(std::ostream &os, const Singleton &singleton) {
    os << &singleton << std::endl;
    return os;
}
