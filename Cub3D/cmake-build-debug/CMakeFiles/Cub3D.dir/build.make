# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yeschall/Desktop/GitHub/Cub3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Cub3D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cub3D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cub3D.dir/flags.make

CMakeFiles/Cub3D.dir/errors/ft_error.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/errors/ft_error.c.o: ../errors/ft_error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Cub3D.dir/errors/ft_error.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/errors/ft_error.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/errors/ft_error.c

CMakeFiles/Cub3D.dir/errors/ft_error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/errors/ft_error.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/errors/ft_error.c > CMakeFiles/Cub3D.dir/errors/ft_error.c.i

CMakeFiles/Cub3D.dir/errors/ft_error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/errors/ft_error.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/errors/ft_error.c -o CMakeFiles/Cub3D.dir/errors/ft_error.c.s

CMakeFiles/Cub3D.dir/parser/ft_parser.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/parser/ft_parser.c.o: ../parser/ft_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Cub3D.dir/parser/ft_parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/parser/ft_parser.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_parser.c

CMakeFiles/Cub3D.dir/parser/ft_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/parser/ft_parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_parser.c > CMakeFiles/Cub3D.dir/parser/ft_parser.c.i

CMakeFiles/Cub3D.dir/parser/ft_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/parser/ft_parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_parser.c -o CMakeFiles/Cub3D.dir/parser/ft_parser.c.s

CMakeFiles/Cub3D.dir/parser/binary_utils.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/parser/binary_utils.c.o: ../parser/binary_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Cub3D.dir/parser/binary_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/parser/binary_utils.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/parser/binary_utils.c

CMakeFiles/Cub3D.dir/parser/binary_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/parser/binary_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/parser/binary_utils.c > CMakeFiles/Cub3D.dir/parser/binary_utils.c.i

CMakeFiles/Cub3D.dir/parser/binary_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/parser/binary_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/parser/binary_utils.c -o CMakeFiles/Cub3D.dir/parser/binary_utils.c.s

CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.o: ../parser/ft_parse_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_parse_file.c

CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_parse_file.c > CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.i

CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_parse_file.c -o CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.s

CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.o: ../parser/ft_parse_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_parse_map.c

CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_parse_map.c > CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.i

CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_parse_map.c -o CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.s

CMakeFiles/Cub3D.dir/parser/ft_validator.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/parser/ft_validator.c.o: ../parser/ft_validator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Cub3D.dir/parser/ft_validator.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/parser/ft_validator.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_validator.c

CMakeFiles/Cub3D.dir/parser/ft_validator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/parser/ft_validator.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_validator.c > CMakeFiles/Cub3D.dir/parser/ft_validator.c.i

CMakeFiles/Cub3D.dir/parser/ft_validator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/parser/ft_validator.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/parser/ft_validator.c -o CMakeFiles/Cub3D.dir/parser/ft_validator.c.s

CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.o: ../regexp/ft_regexp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/regexp/ft_regexp.c

CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/regexp/ft_regexp.c > CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.i

CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/regexp/ft_regexp.c -o CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.s

CMakeFiles/Cub3D.dir/window/window.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/window/window.c.o: ../window/window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Cub3D.dir/window/window.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/window/window.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/window/window.c

CMakeFiles/Cub3D.dir/window/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/window/window.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/window/window.c > CMakeFiles/Cub3D.dir/window/window.c.i

CMakeFiles/Cub3D.dir/window/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/window/window.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/window/window.c -o CMakeFiles/Cub3D.dir/window/window.c.s

CMakeFiles/Cub3D.dir/window/player.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/window/player.c.o: ../window/player.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Cub3D.dir/window/player.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/window/player.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/window/player.c

CMakeFiles/Cub3D.dir/window/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/window/player.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/window/player.c > CMakeFiles/Cub3D.dir/window/player.c.i

CMakeFiles/Cub3D.dir/window/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/window/player.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/window/player.c -o CMakeFiles/Cub3D.dir/window/player.c.s

CMakeFiles/Cub3D.dir/window/map.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/window/map.c.o: ../window/map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Cub3D.dir/window/map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/window/map.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/window/map.c

CMakeFiles/Cub3D.dir/window/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/window/map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/window/map.c > CMakeFiles/Cub3D.dir/window/map.c.i

CMakeFiles/Cub3D.dir/window/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/window/map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/window/map.c -o CMakeFiles/Cub3D.dir/window/map.c.s

CMakeFiles/Cub3D.dir/window/moving.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/window/moving.c.o: ../window/moving.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Cub3D.dir/window/moving.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/window/moving.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/window/moving.c

CMakeFiles/Cub3D.dir/window/moving.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/window/moving.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/window/moving.c > CMakeFiles/Cub3D.dir/window/moving.c.i

CMakeFiles/Cub3D.dir/window/moving.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/window/moving.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/window/moving.c -o CMakeFiles/Cub3D.dir/window/moving.c.s

CMakeFiles/Cub3D.dir/window/vector_utils.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/window/vector_utils.c.o: ../window/vector_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/Cub3D.dir/window/vector_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/window/vector_utils.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/window/vector_utils.c

CMakeFiles/Cub3D.dir/window/vector_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/window/vector_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/window/vector_utils.c > CMakeFiles/Cub3D.dir/window/vector_utils.c.i

CMakeFiles/Cub3D.dir/window/vector_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/window/vector_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/window/vector_utils.c -o CMakeFiles/Cub3D.dir/window/vector_utils.c.s

CMakeFiles/Cub3D.dir/main.c.o: CMakeFiles/Cub3D.dir/flags.make
CMakeFiles/Cub3D.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/Cub3D.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Cub3D.dir/main.c.o   -c /home/yeschall/Desktop/GitHub/Cub3D/main.c

CMakeFiles/Cub3D.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cub3D.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yeschall/Desktop/GitHub/Cub3D/main.c > CMakeFiles/Cub3D.dir/main.c.i

CMakeFiles/Cub3D.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cub3D.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yeschall/Desktop/GitHub/Cub3D/main.c -o CMakeFiles/Cub3D.dir/main.c.s

# Object files for target Cub3D
Cub3D_OBJECTS = \
"CMakeFiles/Cub3D.dir/errors/ft_error.c.o" \
"CMakeFiles/Cub3D.dir/parser/ft_parser.c.o" \
"CMakeFiles/Cub3D.dir/parser/binary_utils.c.o" \
"CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.o" \
"CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.o" \
"CMakeFiles/Cub3D.dir/parser/ft_validator.c.o" \
"CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.o" \
"CMakeFiles/Cub3D.dir/window/window.c.o" \
"CMakeFiles/Cub3D.dir/window/player.c.o" \
"CMakeFiles/Cub3D.dir/window/map.c.o" \
"CMakeFiles/Cub3D.dir/window/moving.c.o" \
"CMakeFiles/Cub3D.dir/window/vector_utils.c.o" \
"CMakeFiles/Cub3D.dir/main.c.o"

# External object files for target Cub3D
Cub3D_EXTERNAL_OBJECTS =

Cub3D: CMakeFiles/Cub3D.dir/errors/ft_error.c.o
Cub3D: CMakeFiles/Cub3D.dir/parser/ft_parser.c.o
Cub3D: CMakeFiles/Cub3D.dir/parser/binary_utils.c.o
Cub3D: CMakeFiles/Cub3D.dir/parser/ft_parse_file.c.o
Cub3D: CMakeFiles/Cub3D.dir/parser/ft_parse_map.c.o
Cub3D: CMakeFiles/Cub3D.dir/parser/ft_validator.c.o
Cub3D: CMakeFiles/Cub3D.dir/regexp/ft_regexp.c.o
Cub3D: CMakeFiles/Cub3D.dir/window/window.c.o
Cub3D: CMakeFiles/Cub3D.dir/window/player.c.o
Cub3D: CMakeFiles/Cub3D.dir/window/map.c.o
Cub3D: CMakeFiles/Cub3D.dir/window/moving.c.o
Cub3D: CMakeFiles/Cub3D.dir/window/vector_utils.c.o
Cub3D: CMakeFiles/Cub3D.dir/main.c.o
Cub3D: CMakeFiles/Cub3D.dir/build.make
Cub3D: libft/liblibft.a
Cub3D: ../libmlx/libmlx.a
Cub3D: CMakeFiles/Cub3D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable Cub3D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Cub3D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cub3D.dir/build: Cub3D

.PHONY : CMakeFiles/Cub3D.dir/build

CMakeFiles/Cub3D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Cub3D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Cub3D.dir/clean

CMakeFiles/Cub3D.dir/depend:
	cd /home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yeschall/Desktop/GitHub/Cub3D /home/yeschall/Desktop/GitHub/Cub3D /home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug /home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug /home/yeschall/Desktop/GitHub/Cub3D/cmake-build-debug/CMakeFiles/Cub3D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cub3D.dir/depend

