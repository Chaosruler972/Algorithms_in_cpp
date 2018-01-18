
#include <boost/assert.hpp>
#include "my_vector.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

template<class T>
my_vector<T>::my_vector() {
    this->_size = 0;
    this->_capacity = 2;
    this->_arr = new T *[2];
}

template<class T>
my_vector<T>::my_vector(const my_vector<T> &other) {
    this->_capacity = other._capacity;
    this->_size = other._size;
    this->_arr = new T *[other._capacity];
    for (auto i = 0; i < other._size; i++)
        this->_arr[i] = new T(other[i]);
}

template<class T>
my_vector<T>::my_vector(int capacity) {
    this->_size = 0;
    this->_capacity = capacity;
    this->_arr = new T[capacity];
}

template<class T>
size_t my_vector<T>::size() const {
    return static_cast<size_t>(this->_size);
}

template<class T>
int my_vector<T>::getCapacity() const {
    return this->_capacity;
}


template<class T>
T &my_vector<T>::operator[](size_t index) {
    assert(index < this->_size);
    return *this->_arr[index];
}

template<class T>
const T &my_vector<T>::operator[](size_t index) const {
    assert(index < this->_size);
    return *this->_arr[index];
}

template<class T>
typename my_vector<T>::iterator my_vector<T>::end() {
    return iterator((*this->_arr) + this->_size);
}

template<class T>
typename my_vector<T>::iterator my_vector<T>::begin() {
    return iterator((*this->_arr));
}

template<class T>
typename my_vector<T>::const_iterator my_vector<T>::begin() const {
    return const_iterator((*this->_arr));
}

template<class T>
typename my_vector<T>::const_iterator my_vector<T>::end() const {
    return const_iterator((*this->_arr) + this->_size);
}

template<class T>
std::ostream &operator<<(std::ostream &os, const my_vector<T> &vector) {
    for (auto i = 0; i < vector._size; i++) {
        os << "#" << i << "=" << vector[i];
        if (i + 1 != vector._size)
            os << ",";
    }
    return os;
}

template<class T>
void my_vector<T>::insert(T value) {
    if (this->_size + 1 >= this->_capacity)
        double_the_array_size();
    this->_arr[this->_size] = new T(value);
    this->_size++;
}

template<class T>
my_vector<T>::~my_vector() {

    for (int i = 0; i < this->_size; i++) {
        delete this->_arr[i];
        this->_arr[i] = nullptr;
    }

    delete[] this->_arr;
    this->_arr = nullptr;
}

template<class T>
void my_vector<T>::insertBefore(T value) {
    if (this->_size + 1 >= this->_capacity)
        double_the_array_size();
    for (auto i = this->_size; i > 0; i--)
        this->_arr[i] = this->_arr[i - 1];
    this->_arr[0] = new T(value);
    this->_size++;
}

template<class T>
bool my_vector<T>::removeAtIndex(unsigned int index) {
    if (index >= this->_size)
        return false;
    delete this->_arr[index];
    this->_arr[index] = nullptr;
    for (auto i = index; i < this->_size - 1; i++) {
        this->_arr[i] = this->_arr[i + 1];
    }
    this->_size--;
    return true;
}


template<class T>
void my_vector<T>::double_the_array_size() {
    auto *new_arr = new T *[this->_capacity * 2];
    for (auto i = 0; i < this->_size; i++)
        new_arr[i] = this->_arr[i];
    delete[] this->_arr;
    this->_arr = new_arr;
    this->_capacity *= 2;
}

template<class T>
bool my_vector<T>::removeElement1Time(T value) {
    int index = this->indexOf(value);
    if (index == -1)
        return false;
    return removeAtIndex(static_cast<unsigned int>(index));
}

template<class T>
int my_vector<T>::indexOf(const T &value) const {
    for (auto i = 0; i < this->_size; i++) {
        if ((*this)[i] == value)
            return i;
    }
    return -1;
}

template<class T>
bool my_vector<T>::removeAllElements(T value) {
    int index;
    bool return_value = false;
    while ((index = this->indexOf(value)) != -1) {
        this->removeAtIndex(static_cast<unsigned int>(index));
        return_value = true;
    }
    return return_value;
}

template<class T>
bool my_vector<T>::swap(unsigned int index1, unsigned int index2) {
    if (index1 < this->_size && index2 < this->_size) {
        T *temp = this->_arr[index1];
        this->_arr[index1] = this->_arr[index2];
        this->_arr[index2] = temp;
    }
    return false;
}


template<class T>
bool my_vector<T>::operator<(const my_vector<T> &rhs) const {
    return _size < rhs._size;
}

template<class T>
bool my_vector<T>::operator>(const my_vector<T> &rhs) const {
    return rhs < *this;
}

template<class T>
bool my_vector<T>::operator<=(const my_vector<T> &rhs) const {
    return !(rhs < *this);
}

template<class T>
bool my_vector<T>::operator>=(const my_vector<T> &rhs) const {
    return !(*this < rhs);
}


#pragma clang diagnostic pop