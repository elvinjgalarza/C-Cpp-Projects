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
CMAKE_COMMAND = "E:\CLion 2016.3.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2016.3.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/flags.make

CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj: CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/flags.make
CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj: ../cipher.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Project_4__Parameters__Strings__and_Ciphers_.dir\cipher.c.obj   -c "C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)\cipher.c"

CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)\cipher.c" > CMakeFiles\Project_4__Parameters__Strings__and_Ciphers_.dir\cipher.c.i

CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)\cipher.c" -o CMakeFiles\Project_4__Parameters__Strings__and_Ciphers_.dir\cipher.c.s

CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj.requires:

.PHONY : CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj.requires

CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj.provides: CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj.requires
	$(MAKE) -f CMakeFiles\Project_4__Parameters__Strings__and_Ciphers_.dir\build.make CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj.provides.build
.PHONY : CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj.provides

CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj.provides.build: CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj


# Object files for target Project_4__Parameters__Strings__and_Ciphers_
Project_4__Parameters__Strings__and_Ciphers__OBJECTS = \
"CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj"

# External object files for target Project_4__Parameters__Strings__and_Ciphers_
Project_4__Parameters__Strings__and_Ciphers__EXTERNAL_OBJECTS =

Project_4__Parameters__Strings__and_Ciphers_.exe: CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj
Project_4__Parameters__Strings__and_Ciphers_.exe: CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/build.make
Project_4__Parameters__Strings__and_Ciphers_.exe: CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/linklibs.rsp
Project_4__Parameters__Strings__and_Ciphers_.exe: CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/objects1.rsp
Project_4__Parameters__Strings__and_Ciphers_.exe: CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Project_4__Parameters__Strings__and_Ciphers_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project_4__Parameters__Strings__and_Ciphers_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/build: Project_4__Parameters__Strings__and_Ciphers_.exe

.PHONY : CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/build

CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/requires: CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/cipher.c.obj.requires

.PHONY : CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/requires

CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project_4__Parameters__Strings__and_Ciphers_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/clean

CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)" "C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)" "C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)\cmake-build-debug" "C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)\cmake-build-debug" "C:\Users\Elvin\Desktop\EE 312 (Fall 2017)\Project 4 (Parameters, Strings, and Ciphers)\cmake-build-debug\CMakeFiles\Project_4__Parameters__Strings__and_Ciphers_.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project_4__Parameters__Strings__and_Ciphers_.dir/depend
