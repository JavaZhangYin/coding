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
CMAKE_SOURCE_DIR = /home/simon/coding

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/simon/coding

# Include any dependencies generated for this target.
include asim/CMakeFiles/Date.dir/depend.make

# Include the progress variables for this target.
include asim/CMakeFiles/Date.dir/progress.make

# Include the compile flags for this target's objects.
include asim/CMakeFiles/Date.dir/flags.make

asim/CMakeFiles/Date.dir/Date.cpp.o: asim/CMakeFiles/Date.dir/flags.make
asim/CMakeFiles/Date.dir/Date.cpp.o: asim/Date.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/simon/coding/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object asim/CMakeFiles/Date.dir/Date.cpp.o"
	cd /home/simon/coding/asim && /usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Date.dir/Date.cpp.o -c /home/simon/coding/asim/Date.cpp

asim/CMakeFiles/Date.dir/Date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Date.dir/Date.cpp.i"
	cd /home/simon/coding/asim && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/simon/coding/asim/Date.cpp > CMakeFiles/Date.dir/Date.cpp.i

asim/CMakeFiles/Date.dir/Date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Date.dir/Date.cpp.s"
	cd /home/simon/coding/asim && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/simon/coding/asim/Date.cpp -o CMakeFiles/Date.dir/Date.cpp.s

asim/CMakeFiles/Date.dir/Date.cpp.o.requires:
.PHONY : asim/CMakeFiles/Date.dir/Date.cpp.o.requires

asim/CMakeFiles/Date.dir/Date.cpp.o.provides: asim/CMakeFiles/Date.dir/Date.cpp.o.requires
	$(MAKE) -f asim/CMakeFiles/Date.dir/build.make asim/CMakeFiles/Date.dir/Date.cpp.o.provides.build
.PHONY : asim/CMakeFiles/Date.dir/Date.cpp.o.provides

asim/CMakeFiles/Date.dir/Date.cpp.o.provides.build: asim/CMakeFiles/Date.dir/Date.cpp.o

# Object files for target Date
Date_OBJECTS = \
"CMakeFiles/Date.dir/Date.cpp.o"

# External object files for target Date
Date_EXTERNAL_OBJECTS =

asim/Date.exe: asim/CMakeFiles/Date.dir/Date.cpp.o
asim/Date.exe: asim/CMakeFiles/Date.dir/build.make
asim/Date.exe: asim/CMakeFiles/Date.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Date.exe"
	cd /home/simon/coding/asim && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Date.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
asim/CMakeFiles/Date.dir/build: asim/Date.exe
.PHONY : asim/CMakeFiles/Date.dir/build

asim/CMakeFiles/Date.dir/requires: asim/CMakeFiles/Date.dir/Date.cpp.o.requires
.PHONY : asim/CMakeFiles/Date.dir/requires

asim/CMakeFiles/Date.dir/clean:
	cd /home/simon/coding/asim && $(CMAKE_COMMAND) -P CMakeFiles/Date.dir/cmake_clean.cmake
.PHONY : asim/CMakeFiles/Date.dir/clean

asim/CMakeFiles/Date.dir/depend:
	cd /home/simon/coding && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simon/coding /home/simon/coding/asim /home/simon/coding /home/simon/coding/asim /home/simon/coding/asim/CMakeFiles/Date.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : asim/CMakeFiles/Date.dir/depend

