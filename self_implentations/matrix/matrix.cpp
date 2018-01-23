

/**
 * Inspection cancellation for unused
 * @author Chaosruler972
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"



#include "matrix.h"



/**
 * Constructor for matrix with dimension being defaulted to 3
 * @param n defaulted to 3, matrix dimension
 * @author Chaosruler972
 */
matrix::matrix(int n)
{
    this->_n_threads =(unsigned int) omp_get_num_procs();
    this->distribution = std::uniform_int_distribution<int>(0,SOFT_RAND_MAX);
    reinit(n);
}

/**
 * Copy constructor to copy other matrix data
 * @param other the matrix to copy
 * @author Chaosruler972
 */
matrix::matrix(const matrix &other) // copy ctor
{
    this->_n_threads =(unsigned int) omp_get_num_procs();
    this->distribution = std::uniform_int_distribution<int>(0,SOFT_RAND_MAX);
    reinit(other.N);
    int i, j;
    for (i = 0; i<this->N; i++)
    {
        for (j = 0; j<this->N; j++)
        {
            this->arr[i][j] = other.arr[i][j];
        }
    }
}

/**
 * equality operator to fill me with different matrix
 * @param other the matrix to fill me with
 * @return this matrix after being "updated"
 */
matrix &matrix::operator=(const matrix &other)
{
    if (&other == this)
        return *this;
    if (this->N != other.N)
    {
        this->delete_arr();
        this->reinit(other.N);
    }
    for (auto i = 0; i<this->N; i++)
    {
        for (auto j = 0; j<this->N; j++)
        {
            this->arr[i][j] = other.arr[i][j];
        }
    }

    return *this;
}

/**
 * delete operator, part of the freeing process
 * @author Chaosruler972
 */
void matrix::delete_arr()
{
    for (auto i = 0; i<this->N; i++)
        delete[] this->arr[i];
    delete[] this->arr;
}

/**
 * Rebuilds the matrix
 * @param n the dimension
 * @author Chaosruler972
 */
void matrix::reinit(int n)
{
    this->N = n;
    this->arr = new int*[n];// allocate master array
    for (auto i = 0; i<this->N; i++) // allocate inner array
        this->arr[i] = new int[n];

    for (auto i = 0; i<this->N; i++)
    {
        for (auto j = 0; j<this->N; j++)
        {
            this->arr[i][j] = 0;
        }
    }
}

/**
 * compare operator, compares both matrixes data
 * @param right the matrix to compare me with
 * @return if both matrixes are equal, true, otherwise false
 * @author Chaosruler972
 */
bool matrix::operator==(const matrix &right)
{
    if (this->N != right.N)
        return false;
    for (auto i = 0; i<this->N; i++)
    {
        for (auto j = 0; j<this->N; j++)
            if (this->arr[i][j] != right.arr[i][j])
                return false;
    }
    return true;
}

/**
 * compare operator, compares both matrixes data
 * @param right the matrix to compare me with
 * @return if both matrixes are equal, true, otherwise false
 * @author Chaosruler972
 */
bool matrix::operator!=(const matrix &right)
{
    return !(this->operator==(right));
}


/**
 * ostream operator, to print matrix
 * @param right the matrix to print
 * @param os the os that we print with (could be file)
 * @author Chaosruler972
 */
std::ostream& operator<<(std::ostream &os, const matrix& right)
{
    for (auto i = 0; i<right.N; i++)
    {
        for (auto j = 0; j<right.N; j++)
        {
            if (j != 0)
                os << " ";
            os << right.arr[i][j];
        }
        os << std::endl;
    }
    return os;
}


/**
 * + operator to create a new matrix equal to me with other
 * @param right the matrix to add myself with
 * @return a new matrix equal to me + right, a default of 3 on 3 matrix will be constructed if dimension mismatch
 * @author Chaosruler972
 */
matrix matrix::operator+(const matrix &right)
{
    if (this->N != right.N)
        return matrix();
    matrix matrix1(this->N);
    for (auto i = 0; i<this->N; i++)
    {
        for (auto j = 0; j<this->N; j++)
            matrix1.arr[i][j] = this->arr[i][j] + right.arr[i][j];
    }
    return matrix1;
}

/**
 * - operator to create a new matrix equal to me minus other
 * @param right the matrix to substract myself with
 * @return a new matrix equal to me - right, a default of 3 on 3 matrix will be constructed if dimension mismatch
 * @author Chaosruler972
 */
matrix matrix::operator-(const matrix &right)
{
    if (this->N != right.N)
        return matrix();
    matrix matrix1(this->N);
    for (auto i = 0; i<this->N; i++)
    {
        for (auto j = 0; j<this->N; j++)
            matrix1.arr[i][j] = this->arr[i][j] - right.arr[i][j];
    }
    return matrix1;
}

/**
 * * operator to create a new matrix equal to me product with other
 * @param right the matrix to product myself with
 * @return a new matrix equal to me * right, a default of 3 on 3 matrix will be constructed if dimension mismatch
 * @author Chaosruler972
 */
matrix matrix::operator*(const matrix& other)
{
    if (this->N != other.N)
        return matrix();
    matrix mult1(this->N);


    int trds = this->_n_threads;
#pragma omp parallel for num_threads(trds)
    for (auto i = 0; i<this->N; i++)
    {
        for (auto  j = 0; j<this->N; j++)
        {
            for (auto k = 0; k<this->N; k++)
            {
                mult1.arr[i][j] += this->arr[i][k] * other.arr[k][j];
            }
        }
    }
    return mult1;
}

/**
 * a [] operator to get a subarray of the matrix
 * @param x the index of the subarray of the matrix to grab
 * @return the subarray that we want to get, nullptr if out of range
 * @author Chaosruler972
 */
int* matrix::operator[](int x)
{
    if(x < 0)
        return nullptr;
    return (x<this->N) ? this->arr[x] : nullptr;
}

/**
 * a function to set amount of working threads
 * @param trds the amount of threads we want to set, 0 to be set to default (amount of threads on processor)
 * @author Chaosruler972
 */
void matrix::set_threads(unsigned int trds)
{
    if(trds == 0)
        this->_n_threads = (unsigned int) omp_get_num_procs();
    else
        this->_n_threads = trds;
}


/**
 * Destructor, destroys matrix
 * @author Chaosruler972
 */
matrix::~matrix()
{
    delete_arr();
}

/**
 * Generates random number, internal for randomizing matrix
 * @author Chaosruler972
 * @return a random number between 0 and SOFT_RAND_MAX
 */
int matrix::random_number()
{
    return this->distribution(this->generator);
}

/**
 * Randomizes entire matrix
 * @see random_number()
 * @author Chaosruler972
 */
void matrix::randomize()
{
    for(auto i=0; i<this->N; i++)
    {
        for(auto j=0; j<this->N; j++)
        {
            this->arr[i][j] = random_number();
        }
    }
}

/**
 * End of inspection cancelattion, therefore affect won't reach out of library
 * @author Chaosruler972
 */
#pragma clang diagnostic pop