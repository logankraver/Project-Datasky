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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/logan/C++ Graphics/Project Datasky"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/logan/C++ Graphics/Project Datasky/build"

# Include any dependencies generated for this target.
include CMakeFiles/Datasky.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Datasky.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Datasky.dir/flags.make

CMakeFiles/Datasky.dir/libraries/glad.c.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/libraries/glad.c.o: ../libraries/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Datasky.dir/libraries/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Datasky.dir/libraries/glad.c.o   -c "/home/logan/C++ Graphics/Project Datasky/libraries/glad.c"

CMakeFiles/Datasky.dir/libraries/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Datasky.dir/libraries/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/libraries/glad.c" > CMakeFiles/Datasky.dir/libraries/glad.c.i

CMakeFiles/Datasky.dir/libraries/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Datasky.dir/libraries/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/libraries/glad.c" -o CMakeFiles/Datasky.dir/libraries/glad.c.s

CMakeFiles/Datasky.dir/src/main.cpp.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Datasky.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Datasky.dir/src/main.cpp.o -c "/home/logan/C++ Graphics/Project Datasky/src/main.cpp"

CMakeFiles/Datasky.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Datasky.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/src/main.cpp" > CMakeFiles/Datasky.dir/src/main.cpp.i

CMakeFiles/Datasky.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Datasky.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/src/main.cpp" -o CMakeFiles/Datasky.dir/src/main.cpp.s

CMakeFiles/Datasky.dir/src/objects/object.cpp.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/src/objects/object.cpp.o: ../src/objects/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Datasky.dir/src/objects/object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Datasky.dir/src/objects/object.cpp.o -c "/home/logan/C++ Graphics/Project Datasky/src/objects/object.cpp"

CMakeFiles/Datasky.dir/src/objects/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Datasky.dir/src/objects/object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/src/objects/object.cpp" > CMakeFiles/Datasky.dir/src/objects/object.cpp.i

CMakeFiles/Datasky.dir/src/objects/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Datasky.dir/src/objects/object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/src/objects/object.cpp" -o CMakeFiles/Datasky.dir/src/objects/object.cpp.s

CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.o: ../src/objects/objectgenerator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.o -c "/home/logan/C++ Graphics/Project Datasky/src/objects/objectgenerator.cpp"

CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/src/objects/objectgenerator.cpp" > CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.i

CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/src/objects/objectgenerator.cpp" -o CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.s

CMakeFiles/Datasky.dir/src/objects/tree.cpp.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/src/objects/tree.cpp.o: ../src/objects/tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Datasky.dir/src/objects/tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Datasky.dir/src/objects/tree.cpp.o -c "/home/logan/C++ Graphics/Project Datasky/src/objects/tree.cpp"

CMakeFiles/Datasky.dir/src/objects/tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Datasky.dir/src/objects/tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/src/objects/tree.cpp" > CMakeFiles/Datasky.dir/src/objects/tree.cpp.i

CMakeFiles/Datasky.dir/src/objects/tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Datasky.dir/src/objects/tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/src/objects/tree.cpp" -o CMakeFiles/Datasky.dir/src/objects/tree.cpp.s

CMakeFiles/Datasky.dir/src/player/player.cpp.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/src/player/player.cpp.o: ../src/player/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Datasky.dir/src/player/player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Datasky.dir/src/player/player.cpp.o -c "/home/logan/C++ Graphics/Project Datasky/src/player/player.cpp"

CMakeFiles/Datasky.dir/src/player/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Datasky.dir/src/player/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/src/player/player.cpp" > CMakeFiles/Datasky.dir/src/player/player.cpp.i

CMakeFiles/Datasky.dir/src/player/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Datasky.dir/src/player/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/src/player/player.cpp" -o CMakeFiles/Datasky.dir/src/player/player.cpp.s

CMakeFiles/Datasky.dir/src/shaders/shader.cpp.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/src/shaders/shader.cpp.o: ../src/shaders/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Datasky.dir/src/shaders/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Datasky.dir/src/shaders/shader.cpp.o -c "/home/logan/C++ Graphics/Project Datasky/src/shaders/shader.cpp"

CMakeFiles/Datasky.dir/src/shaders/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Datasky.dir/src/shaders/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/src/shaders/shader.cpp" > CMakeFiles/Datasky.dir/src/shaders/shader.cpp.i

CMakeFiles/Datasky.dir/src/shaders/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Datasky.dir/src/shaders/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/src/shaders/shader.cpp" -o CMakeFiles/Datasky.dir/src/shaders/shader.cpp.s

CMakeFiles/Datasky.dir/src/textures/texture.cpp.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/src/textures/texture.cpp.o: ../src/textures/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Datasky.dir/src/textures/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Datasky.dir/src/textures/texture.cpp.o -c "/home/logan/C++ Graphics/Project Datasky/src/textures/texture.cpp"

CMakeFiles/Datasky.dir/src/textures/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Datasky.dir/src/textures/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/src/textures/texture.cpp" > CMakeFiles/Datasky.dir/src/textures/texture.cpp.i

CMakeFiles/Datasky.dir/src/textures/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Datasky.dir/src/textures/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/src/textures/texture.cpp" -o CMakeFiles/Datasky.dir/src/textures/texture.cpp.s

CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.o: ../src/worldgen/chunk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.o -c "/home/logan/C++ Graphics/Project Datasky/src/worldgen/chunk.cpp"

CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/src/worldgen/chunk.cpp" > CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.i

CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/src/worldgen/chunk.cpp" -o CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.s

CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.o: ../src/worldgen/globalmap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.o -c "/home/logan/C++ Graphics/Project Datasky/src/worldgen/globalmap.cpp"

CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/src/worldgen/globalmap.cpp" > CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.i

CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/src/worldgen/globalmap.cpp" -o CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.s

CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.o: CMakeFiles/Datasky.dir/flags.make
CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.o: ../src/worldgen/tile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.o -c "/home/logan/C++ Graphics/Project Datasky/src/worldgen/tile.cpp"

CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/logan/C++ Graphics/Project Datasky/src/worldgen/tile.cpp" > CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.i

CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/logan/C++ Graphics/Project Datasky/src/worldgen/tile.cpp" -o CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.s

# Object files for target Datasky
Datasky_OBJECTS = \
"CMakeFiles/Datasky.dir/libraries/glad.c.o" \
"CMakeFiles/Datasky.dir/src/main.cpp.o" \
"CMakeFiles/Datasky.dir/src/objects/object.cpp.o" \
"CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.o" \
"CMakeFiles/Datasky.dir/src/objects/tree.cpp.o" \
"CMakeFiles/Datasky.dir/src/player/player.cpp.o" \
"CMakeFiles/Datasky.dir/src/shaders/shader.cpp.o" \
"CMakeFiles/Datasky.dir/src/textures/texture.cpp.o" \
"CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.o" \
"CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.o" \
"CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.o"

# External object files for target Datasky
Datasky_EXTERNAL_OBJECTS =

Datasky: CMakeFiles/Datasky.dir/libraries/glad.c.o
Datasky: CMakeFiles/Datasky.dir/src/main.cpp.o
Datasky: CMakeFiles/Datasky.dir/src/objects/object.cpp.o
Datasky: CMakeFiles/Datasky.dir/src/objects/objectgenerator.cpp.o
Datasky: CMakeFiles/Datasky.dir/src/objects/tree.cpp.o
Datasky: CMakeFiles/Datasky.dir/src/player/player.cpp.o
Datasky: CMakeFiles/Datasky.dir/src/shaders/shader.cpp.o
Datasky: CMakeFiles/Datasky.dir/src/textures/texture.cpp.o
Datasky: CMakeFiles/Datasky.dir/src/worldgen/chunk.cpp.o
Datasky: CMakeFiles/Datasky.dir/src/worldgen/globalmap.cpp.o
Datasky: CMakeFiles/Datasky.dir/src/worldgen/tile.cpp.o
Datasky: CMakeFiles/Datasky.dir/build.make
Datasky: libraries/glfw-3.3.6/src/libglfw3.a
Datasky: /usr/lib/x86_64-linux-gnu/librt.so
Datasky: /usr/lib/x86_64-linux-gnu/libm.so
Datasky: /usr/lib/x86_64-linux-gnu/libX11.so
Datasky: CMakeFiles/Datasky.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable Datasky"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Datasky.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Datasky.dir/build: Datasky

.PHONY : CMakeFiles/Datasky.dir/build

CMakeFiles/Datasky.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Datasky.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Datasky.dir/clean

CMakeFiles/Datasky.dir/depend:
	cd "/home/logan/C++ Graphics/Project Datasky/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/logan/C++ Graphics/Project Datasky" "/home/logan/C++ Graphics/Project Datasky" "/home/logan/C++ Graphics/Project Datasky/build" "/home/logan/C++ Graphics/Project Datasky/build" "/home/logan/C++ Graphics/Project Datasky/build/CMakeFiles/Datasky.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Datasky.dir/depend

