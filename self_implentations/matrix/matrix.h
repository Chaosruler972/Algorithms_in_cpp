

#ifndef ALGORITHMS_MATRIX_H
#define ALGORITHMS_MATRIX_H


#include <iostream>
#include <omp.h>
#include <random>
#include <cstdlib>

#define SOFT_RAND_MAX 1000

class matrix
{
private:
    /**
     * The array itself that holds the data
     * @author Chaosruler972
     */
    int** arr;
    /**
     * the dimensions, matrixes on this software will be N on N for now
     * @author Chaosruler972
     */
    int N;
    /**
     * The amount of threads we work with for computation
     * @author Chaosruler972
     */
    unsigned int _n_threads;
    /**
     * the random number generator
     * @author Chaosruler972
     */
    std::default_random_engine generator;
    /**
     * The disturbtion, what range shall the RNG take a number from?
     * @author Chaosruler972
     */
    std::uniform_int_distribution<int> distribution;
    void delete_arr();
    void reinit(int n);
    int random_number();
public:
    explicit matrix(int n = 3);
    matrix(const matrix& other);
    void set_threads(unsigned int trds);
    friend std::ostream& operator<<(std::ostream &os, const matrix& right);
    matrix& operator=(const matrix& other); // copy constructor
    bool operator==(const matrix& right); // compare
    bool operator!=(const matrix& right); // unequal
    matrix operator+(const matrix& right); // add operator
    matrix operator-(const matrix& right); // substract operator
    matrix operator*(const matrix& other);// operator *
    int* operator[](int x);
    void randomize();
    ~matrix();

};

#endif //ALGORITHMS_MATRIX_H
