# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/youyue/Study/C++/lang/memory_pool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/youyue/Study/C++/lang/memory_pool

# Include any dependencies generated for this target.
include CMakeFiles/perf_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/perf_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/perf_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/perf_test.dir/flags.make

CMakeFiles/perf_test.dir/codegen:
.PHONY : CMakeFiles/perf_test.dir/codegen

CMakeFiles/perf_test.dir/src/CentralCache.cpp.o: CMakeFiles/perf_test.dir/flags.make
CMakeFiles/perf_test.dir/src/CentralCache.cpp.o: src/CentralCache.cpp
CMakeFiles/perf_test.dir/src/CentralCache.cpp.o: CMakeFiles/perf_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/youyue/Study/C++/lang/memory_pool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/perf_test.dir/src/CentralCache.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/perf_test.dir/src/CentralCache.cpp.o -MF CMakeFiles/perf_test.dir/src/CentralCache.cpp.o.d -o CMakeFiles/perf_test.dir/src/CentralCache.cpp.o -c /Users/youyue/Study/C++/lang/memory_pool/src/CentralCache.cpp

CMakeFiles/perf_test.dir/src/CentralCache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/perf_test.dir/src/CentralCache.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/youyue/Study/C++/lang/memory_pool/src/CentralCache.cpp > CMakeFiles/perf_test.dir/src/CentralCache.cpp.i

CMakeFiles/perf_test.dir/src/CentralCache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/perf_test.dir/src/CentralCache.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/youyue/Study/C++/lang/memory_pool/src/CentralCache.cpp -o CMakeFiles/perf_test.dir/src/CentralCache.cpp.s

CMakeFiles/perf_test.dir/src/PageCache.cpp.o: CMakeFiles/perf_test.dir/flags.make
CMakeFiles/perf_test.dir/src/PageCache.cpp.o: src/PageCache.cpp
CMakeFiles/perf_test.dir/src/PageCache.cpp.o: CMakeFiles/perf_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/youyue/Study/C++/lang/memory_pool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/perf_test.dir/src/PageCache.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/perf_test.dir/src/PageCache.cpp.o -MF CMakeFiles/perf_test.dir/src/PageCache.cpp.o.d -o CMakeFiles/perf_test.dir/src/PageCache.cpp.o -c /Users/youyue/Study/C++/lang/memory_pool/src/PageCache.cpp

CMakeFiles/perf_test.dir/src/PageCache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/perf_test.dir/src/PageCache.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/youyue/Study/C++/lang/memory_pool/src/PageCache.cpp > CMakeFiles/perf_test.dir/src/PageCache.cpp.i

CMakeFiles/perf_test.dir/src/PageCache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/perf_test.dir/src/PageCache.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/youyue/Study/C++/lang/memory_pool/src/PageCache.cpp -o CMakeFiles/perf_test.dir/src/PageCache.cpp.s

CMakeFiles/perf_test.dir/src/ThreadCache.cpp.o: CMakeFiles/perf_test.dir/flags.make
CMakeFiles/perf_test.dir/src/ThreadCache.cpp.o: src/ThreadCache.cpp
CMakeFiles/perf_test.dir/src/ThreadCache.cpp.o: CMakeFiles/perf_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/youyue/Study/C++/lang/memory_pool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/perf_test.dir/src/ThreadCache.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/perf_test.dir/src/ThreadCache.cpp.o -MF CMakeFiles/perf_test.dir/src/ThreadCache.cpp.o.d -o CMakeFiles/perf_test.dir/src/ThreadCache.cpp.o -c /Users/youyue/Study/C++/lang/memory_pool/src/ThreadCache.cpp

CMakeFiles/perf_test.dir/src/ThreadCache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/perf_test.dir/src/ThreadCache.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/youyue/Study/C++/lang/memory_pool/src/ThreadCache.cpp > CMakeFiles/perf_test.dir/src/ThreadCache.cpp.i

CMakeFiles/perf_test.dir/src/ThreadCache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/perf_test.dir/src/ThreadCache.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/youyue/Study/C++/lang/memory_pool/src/ThreadCache.cpp -o CMakeFiles/perf_test.dir/src/ThreadCache.cpp.s

CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.o: CMakeFiles/perf_test.dir/flags.make
CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.o: tests/PerformanceTest.cpp
CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.o: CMakeFiles/perf_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/youyue/Study/C++/lang/memory_pool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.o -MF CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.o.d -o CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.o -c /Users/youyue/Study/C++/lang/memory_pool/tests/PerformanceTest.cpp

CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/youyue/Study/C++/lang/memory_pool/tests/PerformanceTest.cpp > CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.i

CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/youyue/Study/C++/lang/memory_pool/tests/PerformanceTest.cpp -o CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.s

# Object files for target perf_test
perf_test_OBJECTS = \
"CMakeFiles/perf_test.dir/src/CentralCache.cpp.o" \
"CMakeFiles/perf_test.dir/src/PageCache.cpp.o" \
"CMakeFiles/perf_test.dir/src/ThreadCache.cpp.o" \
"CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.o"

# External object files for target perf_test
perf_test_EXTERNAL_OBJECTS =

perf_test: CMakeFiles/perf_test.dir/src/CentralCache.cpp.o
perf_test: CMakeFiles/perf_test.dir/src/PageCache.cpp.o
perf_test: CMakeFiles/perf_test.dir/src/ThreadCache.cpp.o
perf_test: CMakeFiles/perf_test.dir/tests/PerformanceTest.cpp.o
perf_test: CMakeFiles/perf_test.dir/build.make
perf_test: CMakeFiles/perf_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/youyue/Study/C++/lang/memory_pool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable perf_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/perf_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/perf_test.dir/build: perf_test
.PHONY : CMakeFiles/perf_test.dir/build

CMakeFiles/perf_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/perf_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/perf_test.dir/clean

CMakeFiles/perf_test.dir/depend:
	cd /Users/youyue/Study/C++/lang/memory_pool && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/youyue/Study/C++/lang/memory_pool /Users/youyue/Study/C++/lang/memory_pool /Users/youyue/Study/C++/lang/memory_pool /Users/youyue/Study/C++/lang/memory_pool /Users/youyue/Study/C++/lang/memory_pool/CMakeFiles/perf_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/perf_test.dir/depend

