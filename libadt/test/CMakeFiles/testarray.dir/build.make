# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake.exe

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/simon/coding/libadt/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/simon/coding/libadt/test

# Include any dependencies generated for this target.
include CMakeFiles/testarray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testarray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testarray.dir/flags.make

CMakeFiles/testarray.dir/src/array_test.cpp.o: CMakeFiles/testarray.dir/flags.make
CMakeFiles/testarray.dir/src/array_test.cpp.o: src/array_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/simon/coding/libadt/test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testarray.dir/src/array_test.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testarray.dir/src/array_test.cpp.o -c /home/simon/coding/libadt/test/src/array_test.cpp

CMakeFiles/testarray.dir/src/array_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testarray.dir/src/array_test.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/simon/coding/libadt/test/src/array_test.cpp > CMakeFiles/testarray.dir/src/array_test.cpp.i

CMakeFiles/testarray.dir/src/array_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testarray.dir/src/array_test.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/simon/coding/libadt/test/src/array_test.cpp -o CMakeFiles/testarray.dir/src/array_test.cpp.s

CMakeFiles/testarray.dir/src/array_test.cpp.o.requires:
.PHONY : CMakeFiles/testarray.dir/src/array_test.cpp.o.requires

CMakeFiles/testarray.dir/src/array_test.cpp.o.provides: CMakeFiles/testarray.dir/src/array_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/testarray.dir/build.make CMakeFiles/testarray.dir/src/array_test.cpp.o.provides.build
.PHONY : CMakeFiles/testarray.dir/src/array_test.cpp.o.provides

CMakeFiles/testarray.dir/src/array_test.cpp.o.provides.build: CMakeFiles/testarray.dir/src/array_test.cpp.o

# Object files for target testarray
testarray_OBJECTS = \
"CMakeFiles/testarray.dir/src/array_test.cpp.o"

# External object files for target testarray
testarray_EXTERNAL_OBJECTS =

testarray.exe: CMakeFiles/testarray.dir/src/array_test.cpp.o
testarray.exe: CMakeFiles/testarray.dir/build.make
testarray.exe: CMakeFiles/testarray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testarray.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testarray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testarray.dir/build: testarray.exe
.PHONY : CMakeFiles/testarray.dir/build

CMakeFiles/testarray.dir/requires: CMakeFiles/testarray.dir/src/array_test.cpp.o.requires
.PHONY : CMakeFiles/testarray.dir/requires

CMakeFiles/testarray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testarray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testarray.dir/clean

CMakeFiles/testarray.dir/depend:
	cd /home/simon/coding/libadt/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simon/coding/libadt/test /home/simon/coding/libadt/test /home/simon/coding/libadt/test /home/simon/coding/libadt/test /home/simon/coding/libadt/test/CMakeFiles/testarray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testarray.dir/depend

