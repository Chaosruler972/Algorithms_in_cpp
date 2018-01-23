cmake_minimum_required(VERSION 3.9)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)


add_executable(algorithms
        main.cpp self_implentations/matrix/matrix.cpp self_implentations/matrix/matrix.h self_implentations/matrix/main.h)



#   Pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(algorithms Threads::Threads)



# OpenMP
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()


