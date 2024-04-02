cmake_minimum_required(VERSION 3.20)


project(Lab VERSION 1.0 LANGUAGES CXX)

get_directory_property(IS_SUBPROJ PARENT_DIRECTORY)

# options
option(MTEST "To enable module testing" ON)
option(MCON "To enable building console app" ON)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(lab INTERFACE)

target_link_directories(lab INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>    
)

target_compile_features(lab INTERFACE cxx_std_17)

add_library(Lab::lab ALIAS lab)

install(DIRECTORY include/lab DESTINATION lab)
install(TARGETS lab EXPORT LabConfig)
install(EXPORT LabConfig NAMESPACE Lab:: DESTINATION share/Lab/cmake)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/LabConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES "${PROJECT_BINARY_DIR}/LabConfigVersion.cmake" DESTINATION share/Lab/cmake)

if(NOT MTEST)
    message(STATUS "Module testing of Lab is disabled")
elseif(IS_SUBPROJECT)
    message(STATUS "Lab is not tested in module mode")
elseif(NOT MCON)
    message(STATUS "Console app of Lab is disabled")
else()
    add_subdirectory(test)
endif()