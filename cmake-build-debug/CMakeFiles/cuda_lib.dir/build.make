# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/chaosruler/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/173.3727.114/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/chaosruler/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/173.3727.114/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chaosruler/Desktop/Algorithms_in_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cuda_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cuda_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cuda_lib.dir/flags.make

CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/cuda_lib_generated_kernel.cu.o: CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/cuda_lib_generated_kernel.cu.o.depend
CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/cuda_lib_generated_kernel.cu.o: CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/cuda_lib_generated_kernel.cu.o.Debug.cmake
CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/cuda_lib_generated_kernel.cu.o: ../self_implentations/amount_of_threads_on_performance/kernel.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building NVCC (Device) object CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/cuda_lib_generated_kernel.cu.o"
	cd /home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug/CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance && /home/chaosruler/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/173.3727.114/bin/cmake/bin/cmake -E make_directory /home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug/CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/.
	cd /home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug/CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance && /home/chaosruler/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/173.3727.114/bin/cmake/bin/cmake -D verbose:BOOL=$(VERBOSE) -D build_configuration:STRING=Debug -D generated_file:STRING=/home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug/CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/./cuda_lib_generated_kernel.cu.o -D generated_cubin_file:STRING=/home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug/CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/./cuda_lib_generated_kernel.cu.o.cubin.txt -P /home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug/CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/cuda_lib_generated_kernel.cu.o.Debug.cmake

# Object files for target cuda_lib
cuda_lib_OBJECTS =

# External object files for target cuda_lib
cuda_lib_EXTERNAL_OBJECTS = \
"/home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug/CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/cuda_lib_generated_kernel.cu.o"

libcuda_lib.so: CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/cuda_lib_generated_kernel.cu.o
libcuda_lib.so: CMakeFiles/cuda_lib.dir/build.make
libcuda_lib.so: /opt/cuda/lib64/libcudart_static.a
libcuda_lib.so: /usr/lib/librt.so
libcuda_lib.so: CMakeFiles/cuda_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libcuda_lib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cuda_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cuda_lib.dir/build: libcuda_lib.so

.PHONY : CMakeFiles/cuda_lib.dir/build

CMakeFiles/cuda_lib.dir/requires:

.PHONY : CMakeFiles/cuda_lib.dir/requires

CMakeFiles/cuda_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cuda_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cuda_lib.dir/clean

CMakeFiles/cuda_lib.dir/depend: CMakeFiles/cuda_lib.dir/self_implentations/amount_of_threads_on_performance/cuda_lib_generated_kernel.cu.o
	cd /home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chaosruler/Desktop/Algorithms_in_cpp /home/chaosruler/Desktop/Algorithms_in_cpp /home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug /home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug /home/chaosruler/Desktop/Algorithms_in_cpp/cmake-build-debug/CMakeFiles/cuda_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cuda_lib.dir/depend

