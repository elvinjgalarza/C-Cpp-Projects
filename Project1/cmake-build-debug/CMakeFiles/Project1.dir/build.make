# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project1.dir/flags.make

CMakeFiles/Project1.dir/main.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project1.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project1.dir\main.cpp.obj -c "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\main.cpp"

CMakeFiles/Project1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\main.cpp" > CMakeFiles\Project1.dir\main.cpp.i

CMakeFiles/Project1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\main.cpp" -o CMakeFiles\Project1.dir\main.cpp.s

CMakeFiles/Project1.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Project1.dir/main.cpp.obj.requires

CMakeFiles/Project1.dir/main.cpp.obj.provides: CMakeFiles/Project1.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Project1.dir\build.make CMakeFiles/Project1.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Project1.dir/main.cpp.obj.provides

CMakeFiles/Project1.dir/main.cpp.obj.provides.build: CMakeFiles/Project1.dir/main.cpp.obj


CMakeFiles/Project1.dir/Project1.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/Project1.cpp.obj: ../Project1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project1.dir/Project1.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project1.dir\Project1.cpp.obj -c "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\Project1.cpp"

CMakeFiles/Project1.dir/Project1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/Project1.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\Project1.cpp" > CMakeFiles\Project1.dir\Project1.cpp.i

CMakeFiles/Project1.dir/Project1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/Project1.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\Project1.cpp" -o CMakeFiles\Project1.dir\Project1.cpp.s

CMakeFiles/Project1.dir/Project1.cpp.obj.requires:

.PHONY : CMakeFiles/Project1.dir/Project1.cpp.obj.requires

CMakeFiles/Project1.dir/Project1.cpp.obj.provides: CMakeFiles/Project1.dir/Project1.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Project1.dir\build.make CMakeFiles/Project1.dir/Project1.cpp.obj.provides.build
.PHONY : CMakeFiles/Project1.dir/Project1.cpp.obj.provides

CMakeFiles/Project1.dir/Project1.cpp.obj.provides.build: CMakeFiles/Project1.dir/Project1.cpp.obj


# Object files for target Project1
Project1_OBJECTS = \
"CMakeFiles/Project1.dir/main.cpp.obj" \
"CMakeFiles/Project1.dir/Project1.cpp.obj"

# External object files for target Project1
Project1_EXTERNAL_OBJECTS =

Project1.exe: CMakeFiles/Project1.dir/main.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/Project1.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/build.make
Project1.exe: CMakeFiles/Project1.dir/linklibs.rsp
Project1.exe: CMakeFiles/Project1.dir/objects1.rsp
Project1.exe: CMakeFiles/Project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Project1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project1.dir/build: Project1.exe

.PHONY : CMakeFiles/Project1.dir/build

CMakeFiles/Project1.dir/requires: CMakeFiles/Project1.dir/main.cpp.obj.requires
CMakeFiles/Project1.dir/requires: CMakeFiles/Project1.dir/Project1.cpp.obj.requires

.PHONY : CMakeFiles/Project1.dir/requires

CMakeFiles/Project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project1.dir/clean

CMakeFiles/Project1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1" "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1" "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\cmake-build-debug" "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\cmake-build-debug" "C:\Users\Elvin's Laptop\Desktop\EE 312 LABS\Project1\cmake-build-debug\CMakeFiles\Project1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project1.dir/depend

