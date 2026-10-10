cmake_minimum_required(VERSION 3.20)
project(stl VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Check for osyncstream support
include(CheckCXXSourceCompiles)
check_cxx_source_compiles("
    #include <syncstream>
    int main() { std::osyncstream(std::cout) << \"test\"; return 0; }
" HAS_OSYNCSTREAM)

if(NOT HAS_OSYNCSTREAM)
    message(STATUS "Compiler doesn't support std::osyncstream, using mutex fallback")
    add_definitions(-DUSE_MUTEX_FOR_OUTPUT)
endif()

add_executable(
    semaphore semaphore.cpp
)
add_executable(
    union union.cpp
)