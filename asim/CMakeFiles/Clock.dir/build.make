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
include asim/CMakeFiles/Clock.dir/depend.make

# Include the progress variables for this target.
include asim/CMakeFiles/Clock.dir/progress.make

# Include the compile flags for this target's objects.
include asim/CMakeFiles/Clock.dir/flags.make

asim/CMakeFiles/Clock.dir/Clock.cpp.o: asim/CMakeFiles/Clock.dir/flags.make
asim/CMakeFiles/Clock.dir/Clock.cpp.o: asim/Clock.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/simon/coding/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object asim/CMakeFiles/Clock.dir/Clock.cpp.o"
	cd /home/simon/coding/asim && /usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Clock.dir/Clock.cpp.o -c /home/simon/coding/asim/Clock.cpp

asim/CMakeFiles/Clock.dir/Clock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Clock.dir/Clock.cpp.i"
	cd /home/simon/coding/asim && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/simon/coding/asim/Clock.cpp > CMakeFiles/Clock.dir/Clock.cpp.i

asim/CMakeFiles/Clock.dir/Clock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Clock.dir/Clock.cpp.s"
	cd /home/simon/coding/asim && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/simon/coding/asim/Clock.cpp -o CMakeFiles/Clock.dir/Clock.cpp.s

asim/CMakeFiles/Clock.dir/Clock.cpp.o.requires:
.PHONY : asim/CMakeFiles/Clock.dir/Clock.cpp.o.requires

asim/CMakeFiles/Clock.dir/Clock.cpp.o.provides: asim/CMakeFiles/Clock.dir/Clock.cpp.o.requires
	$(MAKE) -f asim/CMakeFiles/Clock.dir/build.make asim/CMakeFiles/Clock.dir/Clock.cpp.o.provides.build
.PHONY : asim/CMakeFiles/Clock.dir/Clock.cpp.o.provides

asim/CMakeFiles/Clock.dir/Clock.cpp.o.provides.build: asim/CMakeFiles/Clock.dir/Clock.cpp.o

# Object files for target Clock
Clock_OBJECTS = \
"CMakeFiles/Clock.dir/Clock.cpp.o"

# External object files for target Clock
Clock_EXTERNAL_OBJECTS =

asim/Clock.exe: asim/CMakeFiles/Clock.dir/Clock.cpp.o
asim/Clock.exe: asim/CMakeFiles/Clock.dir/build.make
asim/Clock.exe: asim/CMakeFiles/Clock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Clock.exe"
	cd /home/simon/coding/asim && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Clock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
asim/CMakeFiles/Clock.dir/build: asim/Clock.exe
.PHONY : asim/CMakeFiles/Clock.dir/build

asim/CMakeFiles/Clock.dir/requires: asim/CMakeFiles/Clock.dir/Clock.cpp.o.requires
.PHONY : asim/CMakeFiles/Clock.dir/requires

asim/CMakeFiles/Clock.dir/clean:
	cd /home/simon/coding/asim && $(CMAKE_COMMAND) -P CMakeFiles/Clock.dir/cmake_clean.cmake
.PHONY : asim/CMakeFiles/Clock.dir/clean

asim/CMakeFiles/Clock.dir/depend:
	cd /home/simon/coding && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simon/coding /home/simon/coding/asim /home/simon/coding /home/simon/coding/asim /home/simon/coding/asim/CMakeFiles/Clock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : asim/CMakeFiles/Clock.dir/depend

