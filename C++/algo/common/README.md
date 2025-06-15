# Common Algorithms Library

A collection of commonly used algorithms and data structures implemented in C++.

## Algorithms and Data Structures

- **Binary Index Tree (Fenwick Tree)**
  - Efficient range sum queries and point updates
  - O(log n) for both operations

- **LCA (Lowest Common Ancestor)**
  - Binary lifting implementation
  - O(log n) per query
  - Includes distance calculation between nodes

- **Modulo Arithmetic**
  - Basic operations (addition, subtraction, multiplication)
  - Modular exponentiation
  - Modular inverse (Fermat's little theorem)
  - Combination calculations with Lucas theorem

- **Monotonic Queue**
  - Sliding window maximum/minimum
  - O(n) time complexity

- **Segment Tree**
  - Range queries and updates
  - O(log n) per operation

- **Splay Tree**
  - Self-balancing binary search tree
  - Amortized O(log n) operations

- **Trie**
  - Prefix tree implementation
  - String operations and pattern matching

- **Union-Find (Disjoint Set)**
  - Path compression optimization
  - O(α(n)) amortized time per operation

## Building and Testing

### Prerequisites
- CMake (version 3.14 or higher)
- C++17 compatible compiler
- Google Test (for running tests)

### Build Instructions
```bash
# Build the project
make build

# Run all tests
make test

# Run specific tests
make test-lca      # Run LCA tests
make test-modulo   # Run modulo arithmetic tests
make test-union    # Run union-find tests

# Clean build files
make clean

# Rebuild from scratch
make rebuild
```

### Available Make Targets
- `all` (default): Build the project
- `build`: Build the project
- `clean`: Remove build directory
- `test`: Run all tests
- `test-lca`: Run LCA tests only
- `test-modulo`: Run modulo arithmetic tests only
- `test-union`: Run union-find tests only
- `rebuild`: Clean and rebuild the project
- `help`: Show help message

## Project Structure
```
common/
├── CMakeLists.txt
├── Makefile
├── README.md
├── binary_index_tree.cpp
├── lca.cpp
├── modulo_arithmetic.cpp
├── mono_queue.cpp
├── segment_tree.cpp
├── splay_tree.cpp
├── trie.cpp
├── union_find.cpp
└── test/
    ├── test_main.cpp
    ├── test_lca.cpp
    ├── test_modulo_arthmetic.cpp
    └── test_union_find.cpp
```

## License
This project is open source and available under the MIT License. 