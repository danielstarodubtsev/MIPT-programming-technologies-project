# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build

# Include any dependencies generated for this target.
include map/CMakeFiles/map.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include map/CMakeFiles/map.dir/compiler_depend.make

# Include the progress variables for this target.
include map/CMakeFiles/map.dir/progress.make

# Include the compile flags for this target's objects.
include map/CMakeFiles/map.dir/flags.make

map/CMakeFiles/map.dir/map.cpp.o: map/CMakeFiles/map.dir/flags.make
map/CMakeFiles/map.dir/map.cpp.o: ../map/map.cpp
map/CMakeFiles/map.dir/map.cpp.o: map/CMakeFiles/map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object map/CMakeFiles/map.dir/map.cpp.o"
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/map && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT map/CMakeFiles/map.dir/map.cpp.o -MF CMakeFiles/map.dir/map.cpp.o.d -o CMakeFiles/map.dir/map.cpp.o -c /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/map/map.cpp

map/CMakeFiles/map.dir/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/map.dir/map.cpp.i"
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/map && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/map/map.cpp > CMakeFiles/map.dir/map.cpp.i

map/CMakeFiles/map.dir/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/map.dir/map.cpp.s"
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/map && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/map/map.cpp -o CMakeFiles/map.dir/map.cpp.s

# Object files for target map
map_OBJECTS = \
"CMakeFiles/map.dir/map.cpp.o"

# External object files for target map
map_EXTERNAL_OBJECTS =

map/libmap.a: map/CMakeFiles/map.dir/map.cpp.o
map/libmap.a: map/CMakeFiles/map.dir/build.make
map/libmap.a: map/CMakeFiles/map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmap.a"
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/map && $(CMAKE_COMMAND) -P CMakeFiles/map.dir/cmake_clean_target.cmake
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/map && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/map.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
map/CMakeFiles/map.dir/build: map/libmap.a
.PHONY : map/CMakeFiles/map.dir/build

map/CMakeFiles/map.dir/clean:
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/map && $(CMAKE_COMMAND) -P CMakeFiles/map.dir/cmake_clean.cmake
.PHONY : map/CMakeFiles/map.dir/clean

map/CMakeFiles/map.dir/depend:
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/map /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/map /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/map/CMakeFiles/map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : map/CMakeFiles/map.dir/depend

