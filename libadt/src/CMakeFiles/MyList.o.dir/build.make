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
CMAKE_SOURCE_DIR = /home/simon/coding/libadt/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/simon/coding/libadt/src

# Include any dependencies generated for this target.
include CMakeFiles/MyList.o.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyList.o.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyList.o.dir/flags.make

CMakeFiles/MyList.o.dir/MyList.cpp.o: CMakeFiles/MyList.o.dir/flags.make
CMakeFiles/MyList.o.dir/MyList.cpp.o: MyList.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/simon/coding/libadt/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyList.o.dir/MyList.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyList.o.dir/MyList.cpp.o -c /home/simon/coding/libadt/src/MyList.cpp

CMakeFiles/MyList.o.dir/MyList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyList.o.dir/MyList.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/simon/coding/libadt/src/MyList.cpp > CMakeFiles/MyList.o.dir/MyList.cpp.i

CMakeFiles/MyList.o.dir/MyList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyList.o.dir/MyList.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/simon/coding/libadt/src/MyList.cpp -o CMakeFiles/MyList.o.dir/MyList.cpp.s

CMakeFiles/MyList.o.dir/MyList.cpp.o.requires:
.PHONY : CMakeFiles/MyList.o.dir/MyList.cpp.o.requires

CMakeFiles/MyList.o.dir/MyList.cpp.o.provides: CMakeFiles/MyList.o.dir/MyList.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyList.o.dir/build.make CMakeFiles/MyList.o.dir/MyList.cpp.o.provides.build
.PHONY : CMakeFiles/MyList.o.dir/MyList.cpp.o.provides

CMakeFiles/MyList.o.dir/MyList.cpp.o.provides.build: CMakeFiles/MyList.o.dir/MyList.cpp.o

# Object files for target MyList.o
MyList_o_OBJECTS = \
"CMakeFiles/MyList.o.dir/MyList.cpp.o"

# External object files for target MyList.o
MyList_o_EXTERNAL_OBJECTS =

MyList.o.exe: CMakeFiles/MyList.o.dir/MyList.cpp.o
MyList.o.exe: CMakeFiles/MyList.o.dir/build.make
MyList.o.exe: CMakeFiles/MyList.o.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable MyList.o.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyList.o.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyList.o.dir/build: MyList.o.exe
.PHONY : CMakeFiles/MyList.o.dir/build

CMakeFiles/MyList.o.dir/requires: CMakeFiles/MyList.o.dir/MyList.cpp.o.requires
.PHONY : CMakeFiles/MyList.o.dir/requires

CMakeFiles/MyList.o.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyList.o.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyList.o.dir/clean

CMakeFiles/MyList.o.dir/depend:
	cd /home/simon/coding/libadt/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simon/coding/libadt/src /home/simon/coding/libadt/src /home/simon/coding/libadt/src /home/simon/coding/libadt/src /home/simon/coding/libadt/src/CMakeFiles/MyList.o.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyList.o.dir/depend

