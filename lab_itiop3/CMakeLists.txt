cmake_minimum_required(VERSION 3.12)

project(trees VERSION 1.0 LANGUAGE CXX)

get_directory_property(IS_SUBPROJ PARENT_DIRECTORY)

# options
option(MTEST "To enable module testing in project" ON)
option(MCOV "To enable measuring code coverage by tests" OFF)

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo
)
