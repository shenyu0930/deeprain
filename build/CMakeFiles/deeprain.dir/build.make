# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /apps/deeprain/bin/cmake

# The command to remove a file.
RM = /apps/deeprain/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/deeprain/workspace/deeprain

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deeprain/workspace/deeprain/build

# Include any dependencies generated for this target.
include CMakeFiles/deeprain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/deeprain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/deeprain.dir/flags.make

CMakeFiles/deeprain.dir/deeprain/log.cc.o: CMakeFiles/deeprain.dir/flags.make
CMakeFiles/deeprain.dir/deeprain/log.cc.o: ../deeprain/log.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deeprain/workspace/deeprain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/deeprain.dir/deeprain/log.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/deeprain.dir/deeprain/log.cc.o -c /home/deeprain/workspace/deeprain/deeprain/log.cc

CMakeFiles/deeprain.dir/deeprain/log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/deeprain.dir/deeprain/log.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deeprain/workspace/deeprain/deeprain/log.cc > CMakeFiles/deeprain.dir/deeprain/log.cc.i

CMakeFiles/deeprain.dir/deeprain/log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/deeprain.dir/deeprain/log.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deeprain/workspace/deeprain/deeprain/log.cc -o CMakeFiles/deeprain.dir/deeprain/log.cc.s

CMakeFiles/deeprain.dir/deeprain/util.cc.o: CMakeFiles/deeprain.dir/flags.make
CMakeFiles/deeprain.dir/deeprain/util.cc.o: ../deeprain/util.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deeprain/workspace/deeprain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/deeprain.dir/deeprain/util.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/deeprain.dir/deeprain/util.cc.o -c /home/deeprain/workspace/deeprain/deeprain/util.cc

CMakeFiles/deeprain.dir/deeprain/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/deeprain.dir/deeprain/util.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deeprain/workspace/deeprain/deeprain/util.cc > CMakeFiles/deeprain.dir/deeprain/util.cc.i

CMakeFiles/deeprain.dir/deeprain/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/deeprain.dir/deeprain/util.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deeprain/workspace/deeprain/deeprain/util.cc -o CMakeFiles/deeprain.dir/deeprain/util.cc.s

CMakeFiles/deeprain.dir/deeprain/config.cc.o: CMakeFiles/deeprain.dir/flags.make
CMakeFiles/deeprain.dir/deeprain/config.cc.o: ../deeprain/config.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deeprain/workspace/deeprain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/deeprain.dir/deeprain/config.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/deeprain.dir/deeprain/config.cc.o -c /home/deeprain/workspace/deeprain/deeprain/config.cc

CMakeFiles/deeprain.dir/deeprain/config.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/deeprain.dir/deeprain/config.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deeprain/workspace/deeprain/deeprain/config.cc > CMakeFiles/deeprain.dir/deeprain/config.cc.i

CMakeFiles/deeprain.dir/deeprain/config.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/deeprain.dir/deeprain/config.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deeprain/workspace/deeprain/deeprain/config.cc -o CMakeFiles/deeprain.dir/deeprain/config.cc.s

# Object files for target deeprain
deeprain_OBJECTS = \
"CMakeFiles/deeprain.dir/deeprain/log.cc.o" \
"CMakeFiles/deeprain.dir/deeprain/util.cc.o" \
"CMakeFiles/deeprain.dir/deeprain/config.cc.o"

# External object files for target deeprain
deeprain_EXTERNAL_OBJECTS =

../lib/libdeeprain.so: CMakeFiles/deeprain.dir/deeprain/log.cc.o
../lib/libdeeprain.so: CMakeFiles/deeprain.dir/deeprain/util.cc.o
../lib/libdeeprain.so: CMakeFiles/deeprain.dir/deeprain/config.cc.o
../lib/libdeeprain.so: CMakeFiles/deeprain.dir/build.make
../lib/libdeeprain.so: CMakeFiles/deeprain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/deeprain/workspace/deeprain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library ../lib/libdeeprain.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/deeprain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/deeprain.dir/build: ../lib/libdeeprain.so

.PHONY : CMakeFiles/deeprain.dir/build

CMakeFiles/deeprain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/deeprain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/deeprain.dir/clean

CMakeFiles/deeprain.dir/depend:
	cd /home/deeprain/workspace/deeprain/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deeprain/workspace/deeprain /home/deeprain/workspace/deeprain /home/deeprain/workspace/deeprain/build /home/deeprain/workspace/deeprain/build /home/deeprain/workspace/deeprain/build/CMakeFiles/deeprain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/deeprain.dir/depend

