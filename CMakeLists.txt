cmake_minimum_required(VERSION 3.9)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)


add_executable(algorithms main.cpp self_implentations/vector/my_vector.cpp self_implentations/vector/my_vector.h "Design Patterns/Singleton/singleton.cpp" "Design Patterns/Singleton/singleton.h" self_implentations/threadding_sync/cv_practice.cpp self_implentations/threadding_sync/cv_practice.h)

#   Threads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(algorithms Threads::Threads)