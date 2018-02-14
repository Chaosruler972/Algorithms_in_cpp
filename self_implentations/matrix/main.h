

#ifndef ALGORITHMS_MAIN_H
#define ALGORITHMS_MAIN_H


#include "matrix.h"
/**
 * To timestamp results and execution time
 * @author Chaosruler972
 */
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

#define TIME_TO_WAIT 10
#define TO_MILLISECONDS 1000

void test(unsigned int N_THREADS, int MAX_MAT_SIZE );

/**
 * A struct defining what we need in a test
 * @author Chaosruler972
 * @see test(unsigned int N_THREADS, int MAX_MAT_SIZE );
 */
typedef struct test_configuration_unit
{
    int MAX_MAT_SIZE{1};
    unsigned int N_THREADS{0};
    explicit test_configuration_unit(int mat, unsigned int threads)
    {
        this->MAX_MAT_SIZE = (mat==0) ? 1 : abs(mat);
        this->N_THREADS = threads;
    }
    bool operator==(const struct test_configuration_unit& other)
    {
        return this->MAX_MAT_SIZE == other.MAX_MAT_SIZE && this->N_THREADS == other.N_THREADS;
    }
    bool operator!=(const struct test_configuration_unit& other)
    {
        return !this->operator==(other);
    }
}test_configuration_unit;

/**
 * To hold list of test configuration unit
 * @author Chaosruler972
 * @see test_configuration_unit
 */
#include <vector>



#endif //ALGORITHMS_MAIN_H
