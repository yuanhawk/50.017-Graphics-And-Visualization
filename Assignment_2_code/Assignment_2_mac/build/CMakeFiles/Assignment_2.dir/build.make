# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac/build

# Include any dependencies generated for this target.
include CMakeFiles/Assignment_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment_2.dir/flags.make

CMakeFiles/Assignment_2.dir/src/main.cpp.o: CMakeFiles/Assignment_2.dir/flags.make
CMakeFiles/Assignment_2.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment_2.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_2.dir/src/main.cpp.o -c /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac/src/main.cpp

CMakeFiles/Assignment_2.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_2.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac/src/main.cpp > CMakeFiles/Assignment_2.dir/src/main.cpp.i

CMakeFiles/Assignment_2.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_2.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac/src/main.cpp -o CMakeFiles/Assignment_2.dir/src/main.cpp.s

# Object files for target Assignment_2
Assignment_2_OBJECTS = \
"CMakeFiles/Assignment_2.dir/src/main.cpp.o"

# External object files for target Assignment_2
Assignment_2_EXTERNAL_OBJECTS =

Assignment_2: CMakeFiles/Assignment_2.dir/src/main.cpp.o
Assignment_2: CMakeFiles/Assignment_2.dir/build.make
Assignment_2: libsource_lib.a
Assignment_2: /usr/local/lib/libglfw.dylib
Assignment_2: libGLAD.a
Assignment_2: /usr/local/lib/libglfw.dylib
Assignment_2: CMakeFiles/Assignment_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Assignment_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment_2.dir/build: Assignment_2

.PHONY : CMakeFiles/Assignment_2.dir/build

CMakeFiles/Assignment_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment_2.dir/clean

CMakeFiles/Assignment_2.dir/depend:
	cd /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac/build /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac/build /Users/pengsong/SongPeng/_Teaching/_50.017_Graphics_and_Visualisation_Git/Assignment/Assignment_2/Assignment_2_code/Assignment_2_mac/build/CMakeFiles/Assignment_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment_2.dir/depend

