# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/tameer/Desktop/clion-2019.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tameer/Desktop/clion-2019.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tameer/CLionProjects/cTranslator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tameer/CLionProjects/cTranslator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cTranslator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cTranslator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cTranslator.dir/flags.make

CMakeFiles/cTranslator.dir/main.c.o: CMakeFiles/cTranslator.dir/flags.make
CMakeFiles/cTranslator.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tameer/CLionProjects/cTranslator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cTranslator.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cTranslator.dir/main.c.o   -c /home/tameer/CLionProjects/cTranslator/main.c

CMakeFiles/cTranslator.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cTranslator.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tameer/CLionProjects/cTranslator/main.c > CMakeFiles/cTranslator.dir/main.c.i

CMakeFiles/cTranslator.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cTranslator.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tameer/CLionProjects/cTranslator/main.c -o CMakeFiles/cTranslator.dir/main.c.s

CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.o: CMakeFiles/cTranslator.dir/flags.make
CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.o: ../c_encapsulation_defs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tameer/CLionProjects/cTranslator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.o   -c /home/tameer/CLionProjects/cTranslator/c_encapsulation_defs.c

CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tameer/CLionProjects/cTranslator/c_encapsulation_defs.c > CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.i

CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tameer/CLionProjects/cTranslator/c_encapsulation_defs.c -o CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.s

CMakeFiles/cTranslator.dir/c_inheritance_defs.c.o: CMakeFiles/cTranslator.dir/flags.make
CMakeFiles/cTranslator.dir/c_inheritance_defs.c.o: ../c_inheritance_defs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tameer/CLionProjects/cTranslator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cTranslator.dir/c_inheritance_defs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cTranslator.dir/c_inheritance_defs.c.o   -c /home/tameer/CLionProjects/cTranslator/c_inheritance_defs.c

CMakeFiles/cTranslator.dir/c_inheritance_defs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cTranslator.dir/c_inheritance_defs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tameer/CLionProjects/cTranslator/c_inheritance_defs.c > CMakeFiles/cTranslator.dir/c_inheritance_defs.c.i

CMakeFiles/cTranslator.dir/c_inheritance_defs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cTranslator.dir/c_inheritance_defs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tameer/CLionProjects/cTranslator/c_inheritance_defs.c -o CMakeFiles/cTranslator.dir/c_inheritance_defs.c.s

CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.o: CMakeFiles/cTranslator.dir/flags.make
CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.o: ../c_polymorphism_defs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tameer/CLionProjects/cTranslator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.o   -c /home/tameer/CLionProjects/cTranslator/c_polymorphism_defs.c

CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tameer/CLionProjects/cTranslator/c_polymorphism_defs.c > CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.i

CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tameer/CLionProjects/cTranslator/c_polymorphism_defs.c -o CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.s

# Object files for target cTranslator
cTranslator_OBJECTS = \
"CMakeFiles/cTranslator.dir/main.c.o" \
"CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.o" \
"CMakeFiles/cTranslator.dir/c_inheritance_defs.c.o" \
"CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.o"

# External object files for target cTranslator
cTranslator_EXTERNAL_OBJECTS =

cTranslator: CMakeFiles/cTranslator.dir/main.c.o
cTranslator: CMakeFiles/cTranslator.dir/c_encapsulation_defs.c.o
cTranslator: CMakeFiles/cTranslator.dir/c_inheritance_defs.c.o
cTranslator: CMakeFiles/cTranslator.dir/c_polymorphism_defs.c.o
cTranslator: CMakeFiles/cTranslator.dir/build.make
cTranslator: CMakeFiles/cTranslator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tameer/CLionProjects/cTranslator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable cTranslator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cTranslator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cTranslator.dir/build: cTranslator

.PHONY : CMakeFiles/cTranslator.dir/build

CMakeFiles/cTranslator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cTranslator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cTranslator.dir/clean

CMakeFiles/cTranslator.dir/depend:
	cd /home/tameer/CLionProjects/cTranslator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tameer/CLionProjects/cTranslator /home/tameer/CLionProjects/cTranslator /home/tameer/CLionProjects/cTranslator/cmake-build-debug /home/tameer/CLionProjects/cTranslator/cmake-build-debug /home/tameer/CLionProjects/cTranslator/cmake-build-debug/CMakeFiles/cTranslator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cTranslator.dir/depend

