
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef ALGORITHMS_VECTOR_H
#define ALGORITHMS_VECTOR_H

#include <iostream>


template<class T>
class my_vector;

template<class T>
std::ostream &operator<<(std::ostream &os, const my_vector<T> &L);

template<class T>
class my_vector {
    int _size{};
    int _capacity{};
    T **_arr;

    void double_the_array_size();

public:
    my_vector();

    my_vector(const my_vector<T> &other);

    explicit my_vector(int capacity);

    size_t size() const;

    int getCapacity() const;

    T &operator[](size_t index);

    const T &operator[](size_t index) const;

    friend std::ostream &operator<<<>(std::ostream &os, const my_vector &L);

    void insert(T value);

    void insertBefore(T value);

    bool removeAtIndex(unsigned int index);

    bool removeElement1Time(T value);

    int indexOf(const T &value) const;

    bool removeAllElements(T value);

    bool swap(unsigned int index1, unsigned int index2);

    bool operator<(const my_vector<T> &rhs) const;

    bool operator>(const my_vector<T> &rhs) const;

    bool operator<=(const my_vector<T> &rhs) const;

    bool operator>=(const my_vector<T> &rhs) const;

    ~my_vector();


    class iterator {
    public:
        typedef iterator self_type;
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;

        explicit iterator(pointer ptr) : ptr_(ptr) {}

        self_type operator++() {
            self_type i = *this;
            ptr_++;
            return i;
        }

        self_type operator++(int junk) {
            ptr_++;
            return *this;
        }

        reference operator*() { return *ptr_; }

        pointer operator->() { return ptr_; }

        bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }

        bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

    private:
        pointer ptr_;
    };

    class const_iterator {
    public:
        typedef const_iterator self_type;
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef int difference_type;
        typedef std::forward_iterator_tag iterator_category;

        explicit const_iterator(pointer ptr) : ptr_(ptr) {}

        self_type operator++() {
            self_type i = *this;
            ptr_++;
            return i;
        }

        self_type operator++(int junk) {
            ptr_++;
            return *this;
        }

        const reference operator*() { return *ptr_; }

        const pointer operator->() { return ptr_; }

        bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }

        bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

    private:
        pointer ptr_;
    };

    iterator begin();

    iterator end();

    const_iterator begin() const;

    const_iterator end() const;
};


#endif //ALGORITHMS_VECTOR_H

#pragma clang diagnostic pop