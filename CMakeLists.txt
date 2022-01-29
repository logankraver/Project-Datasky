cmake_minimum_required(VERSION 3.0)

project(Datasky)

set(OBJECTS_DIR src/objects)
set(PLAYER_DIR src/player)
set(SHADERS_DIR src/shaders)
set(TEXTURES_DIR src/textures)
set(WORLDGEN_DIR src/worldgen)


add_executable(
    Datasky
    libraries/glad.c
    src/main.cpp
    ${OBJECTS_DIR}/object.cpp
    ${OBJECTS_DIR}/objectgenerator.cpp
    ${OBJECTS_DIR}/tree.cpp
    ${PLAYER_DIR}/player.cpp
    ${SHADERS_DIR}/shader.cpp
    ${TEXTURES_DIR}/texture.cpp
    ${WORLDGEN_DIR}/chunk.cpp
    ${WORLDGEN_DIR}/globalmap.cpp
    ${WORLDGEN_DIR}/tile.cpp
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libraries/glfw-3.3.6)
target_link_libraries(Datasky glfw)