# Build directory
BUILD_DIR := build

# Default target
all: build

# Create build directory and run CMake
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..

# Build the project
build: $(BUILD_DIR)
	cd $(BUILD_DIR) && make

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Run tests
test: build
	cd $(BUILD_DIR) && ctest --output-on-failure

# Run specific test
test-lca: build
	cd $(BUILD_DIR) && ./common_test --gtest_filter=LCA*

test-modulo: build
	cd $(BUILD_DIR) && ./common_test --gtest_filter=ModuloArithmetic*

test-union: build
	cd $(BUILD_DIR) && ./common_test --gtest_filter=UnionFind*
test-segment: build
	cd $(BUILD_DIR) && ./common_test --gtest_filter=*SegmentTree*
test-kmp: build
	cd $(BUILD_DIR) && ./common_test --gtest_filter=KMP*

# Rebuild from scratch
rebuild: clean build

# Show help
help:
	@echo "Available targets:"
	@echo "  all        - Build the project (default)"
	@echo "  build      - Build the project"
	@echo "  clean      - Remove build directory"
	@echo "  test       - Run all tests"
	@echo "  test-lca   - Run LCA tests only"
	@echo "  test-modulo - Run modulo arithmetic tests only"
	@echo "  test-union - Run union-find tests only"
	@echo "  test-segment - Run segment tree tests only"
	@echo "  test-kmp   - Run KMP tests only"
	@echo "  rebuild    - Clean and rebuild the project"
	@echo "  help       - Show this help message"

.PHONY: all build clean test test-lca test-modulo test-union test-segment test-kmp rebuild help 