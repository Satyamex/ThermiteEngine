cmake_minimum_required(VERSION 3.20)
project(ThermiteEngine C)
set(CMAKE_C_STANDARD 11)
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)
add_executable(ThermiteEngine
    src/core/main.c
    src/core/_windowing.c
    src/core/_renderer.c
    src/core/_time.c
    src/glad.c
)
target_include_directories(ThermiteEngine PRIVATE include)
target_link_libraries(ThermiteEngine PRIVATE glfw)