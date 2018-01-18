
#include "cv_practice.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

void cv_practice::print_hame(bool flag) {
    std::cout << "hame";
    if (flag) {
        this->ready = true;
        cv.notify_one();
    }
}

void cv_practice::print_kame(bool flag) {
    std::cout << "Kame";
    if (flag) {
        this->ready = true;
        cv.notify_one();
    }
}

void cv_practice::print_ha(bool flag) {
    std::cout << "haa!!!";
    if (flag) {
        this->ready = true;
        cv.notify_one();
    }
}

void cv_practice::threadded_print() {
    std::thread t1([this] { this->print_kame(false); });
    std::thread t2([this] { this->print_hame(false); });
    std::thread t3([this] { this->print_ha(false); });


    t1.join();
    t2.join();
    t3.join();
    std::cout << std::endl;
}

void cv_practice::syncrhonized_print() {
    std::unique_lock<std::mutex> lk(mtx);

    std::thread t1([this] { this->print_kame(true); });

    cv.wait(lk, [this] { return this->ready; });
    ready = false;

    std::thread t2([this] { this->print_hame(true); });
    cv.wait(lk, [this] { return this->ready; });
    ready = false;

    std::thread t3([this] { this->print_ha(true); });


    t1.join();
    t2.join();
    t3.join();
    std::cout << std::endl;
}


#pragma clang diagnostic pop