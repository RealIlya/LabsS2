cmake_minimum_required(VERSION 3.12)

project(trees VERSION 1.0 LANGUAGES CXX)

get_directory_property(IS_SUBPROJ PARENT_DIRECTORY)

# options
option(MTEST "To enable module testing in project" ON)
option(MCOV "To enable measuring code coverage by tests" OFF)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(trees commander/Line.cpp myhandler.cpp Stack.cpp Tree.cpp Terminal.cpp main.cpp)
add_custom_target(launch ALL COMMAND trees)
# target_include_directories(trees PUBLIC commands)
