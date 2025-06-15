cmake_minimum_required(VERSION 3.14)
project(common_algorithms)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    binary_index_tree.cpp
    lca.cpp
    modulo_arithmetic.cpp
    mono_queue.cpp
    segment_tree.cpp
    splay_tree.cpp
    trie.cpp
    union_find.cpp
)

# Create library target
add_library(common_algorithms STATIC ${SOURCES})

# Set include directories
target_include_directories(common_algorithms
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set compiler warnings
if(MSVC)
    target_compile_options(common_algorithms PRIVATE /W4)
else()
    target_compile_options(common_algorithms PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Testing setup
find_package(GTest REQUIRED)

# Add test executable
add_executable(common_test
    test/test_main.cpp
    test/test_lca.cpp
    test/test_modulo_arthmetic.cpp
    test/test_union_find.cpp
)

# Link test executable with library and GTest
target_link_libraries(common_test
    PRIVATE
    common_algorithms
    GTest::GTest
    GTest::Main
)

# Enable testing
enable_testing()
add_test(NAME common_test COMMAND common_test)
