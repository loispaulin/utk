# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/davidcoeurjolly/Projects/utk/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/davidcoeurjolly/Projects/utk/src/build

# Include any dependencies generated for this target.
include bin/statistics/CMakeFiles/computeMinDist_2dd.dir/depend.make

# Include the progress variables for this target.
include bin/statistics/CMakeFiles/computeMinDist_2dd.dir/progress.make

# Include the compile flags for this target's objects.
include bin/statistics/CMakeFiles/computeMinDist_2dd.dir/flags.make

bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o: bin/statistics/CMakeFiles/computeMinDist_2dd.dir/flags.make
bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o: ../bin/statistics/computeMinDist_2dd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/davidcoeurjolly/Projects/utk/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o"
	cd /Users/davidcoeurjolly/Projects/utk/src/build/bin/statistics && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o -c /Users/davidcoeurjolly/Projects/utk/src/bin/statistics/computeMinDist_2dd.cpp

bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.i"
	cd /Users/davidcoeurjolly/Projects/utk/src/build/bin/statistics && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/davidcoeurjolly/Projects/utk/src/bin/statistics/computeMinDist_2dd.cpp > CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.i

bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.s"
	cd /Users/davidcoeurjolly/Projects/utk/src/build/bin/statistics && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/davidcoeurjolly/Projects/utk/src/bin/statistics/computeMinDist_2dd.cpp -o CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.s

bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o.requires:

.PHONY : bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o.requires

bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o.provides: bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o.requires
	$(MAKE) -f bin/statistics/CMakeFiles/computeMinDist_2dd.dir/build.make bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o.provides.build
.PHONY : bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o.provides

bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o.provides.build: bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o


# Object files for target computeMinDist_2dd
computeMinDist_2dd_OBJECTS = \
"CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o"

# External object files for target computeMinDist_2dd
computeMinDist_2dd_EXTERNAL_OBJECTS =

bin/statistics/computeMinDist_2dd: bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o
bin/statistics/computeMinDist_2dd: bin/statistics/CMakeFiles/computeMinDist_2dd.dir/build.make
bin/statistics/computeMinDist_2dd: bin/statistics/CMakeFiles/computeMinDist_2dd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/davidcoeurjolly/Projects/utk/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable computeMinDist_2dd"
	cd /Users/davidcoeurjolly/Projects/utk/src/build/bin/statistics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/computeMinDist_2dd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/statistics/CMakeFiles/computeMinDist_2dd.dir/build: bin/statistics/computeMinDist_2dd

.PHONY : bin/statistics/CMakeFiles/computeMinDist_2dd.dir/build

bin/statistics/CMakeFiles/computeMinDist_2dd.dir/requires: bin/statistics/CMakeFiles/computeMinDist_2dd.dir/computeMinDist_2dd.cpp.o.requires

.PHONY : bin/statistics/CMakeFiles/computeMinDist_2dd.dir/requires

bin/statistics/CMakeFiles/computeMinDist_2dd.dir/clean:
	cd /Users/davidcoeurjolly/Projects/utk/src/build/bin/statistics && $(CMAKE_COMMAND) -P CMakeFiles/computeMinDist_2dd.dir/cmake_clean.cmake
.PHONY : bin/statistics/CMakeFiles/computeMinDist_2dd.dir/clean

bin/statistics/CMakeFiles/computeMinDist_2dd.dir/depend:
	cd /Users/davidcoeurjolly/Projects/utk/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/davidcoeurjolly/Projects/utk/src /Users/davidcoeurjolly/Projects/utk/src/bin/statistics /Users/davidcoeurjolly/Projects/utk/src/build /Users/davidcoeurjolly/Projects/utk/src/build/bin/statistics /Users/davidcoeurjolly/Projects/utk/src/build/bin/statistics/CMakeFiles/computeMinDist_2dd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/statistics/CMakeFiles/computeMinDist_2dd.dir/depend

