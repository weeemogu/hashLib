cmake_minimum_required(VERSION 3.20)
project(HashProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(hashFunctions)
add_subdirectory(hashTests)

include_directories(hashFunctions hashTests)

# Add the main executable
add_executable(hash_test main.cpp)

# Link the main executable with the libraries
target_link_libraries(hash_test hashFunctions hashTests)