

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#ifndef ALGORITHMS_CV_PRACTICE_H
#define ALGORITHMS_CV_PRACTICE_H

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

class cv_practice {
private:
    std::condition_variable cv;
    std::mutex mtx;
    bool ready = false;

    void print_kame(bool flag);

    void print_hame(bool flag);

    void print_ha(bool flag);

public:
    cv_practice() = default;

    void threadded_print();

    void syncrhonized_print();
} __unused;


#endif //ALGORITHMS_CV_PRACTICE_H

#pragma clang diagnostic pop