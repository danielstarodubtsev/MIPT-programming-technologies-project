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
include monster/CMakeFiles/monster.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include monster/CMakeFiles/monster.dir/compiler_depend.make

# Include the progress variables for this target.
include monster/CMakeFiles/monster.dir/progress.make

# Include the compile flags for this target's objects.
include monster/CMakeFiles/monster.dir/flags.make

monster/CMakeFiles/monster.dir/monster.cpp.o: monster/CMakeFiles/monster.dir/flags.make
monster/CMakeFiles/monster.dir/monster.cpp.o: ../monster/monster.cpp
monster/CMakeFiles/monster.dir/monster.cpp.o: monster/CMakeFiles/monster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object monster/CMakeFiles/monster.dir/monster.cpp.o"
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/monster && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT monster/CMakeFiles/monster.dir/monster.cpp.o -MF CMakeFiles/monster.dir/monster.cpp.o.d -o CMakeFiles/monster.dir/monster.cpp.o -c /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/monster/monster.cpp

monster/CMakeFiles/monster.dir/monster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/monster.dir/monster.cpp.i"
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/monster && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/monster/monster.cpp > CMakeFiles/monster.dir/monster.cpp.i

monster/CMakeFiles/monster.dir/monster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/monster.dir/monster.cpp.s"
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/monster && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/monster/monster.cpp -o CMakeFiles/monster.dir/monster.cpp.s

# Object files for target monster
monster_OBJECTS = \
"CMakeFiles/monster.dir/monster.cpp.o"

# External object files for target monster
monster_EXTERNAL_OBJECTS =

monster/libmonster.a: monster/CMakeFiles/monster.dir/monster.cpp.o
monster/libmonster.a: monster/CMakeFiles/monster.dir/build.make
monster/libmonster.a: monster/CMakeFiles/monster.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmonster.a"
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/monster && $(CMAKE_COMMAND) -P CMakeFiles/monster.dir/cmake_clean_target.cmake
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/monster && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/monster.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
monster/CMakeFiles/monster.dir/build: monster/libmonster.a
.PHONY : monster/CMakeFiles/monster.dir/build

monster/CMakeFiles/monster.dir/clean:
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/monster && $(CMAKE_COMMAND) -P CMakeFiles/monster.dir/cmake_clean.cmake
.PHONY : monster/CMakeFiles/monster.dir/clean

monster/CMakeFiles/monster.dir/depend:
	cd /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/monster /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/monster /home/dantheman/Desktop/everything/codes/programming_technologies/tp-2024-starodubtsev-and-boger-project/build/monster/CMakeFiles/monster.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : monster/CMakeFiles/monster.dir/depend

