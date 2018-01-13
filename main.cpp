
#include "my_vector.cpp"


int main() {
    my_vector<int> my_vector1;

    my_vector1.insert(2);
    my_vector1.insert(4);
    my_vector1.insertBefore(1);
    my_vector1.removeAtIndex(0);
    my_vector1.swap(0, 1);

    my_vector<int> vector2 = my_vector1;

    std::cout << "Equality should be true " << (my_vector1 == vector2) << std::endl;

    vector2.swap(0, 1);
    std::cout << "Equality should be true " << (my_vector1 == vector2) << std::endl;

    my_vector1.removeAtIndex(0);

    std::cout << "Equality should be false " << (my_vector1 == vector2) << std::endl;

    std::cout << " Should return true " << (my_vector1 < vector2) << std::endl;

    std::cout << my_vector1 << std::endl;

    return 0;
}