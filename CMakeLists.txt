# ######################################
# #
# raytracer Epitech                 #
# #
# only for cmake --version >= 3.5.1   #
# ######################################

cmake_minimum_required(VERSION 3.5.1)

project(raytracer-cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

# ###############################
# build myUtils static library and mySharedLib
# ###############################
add_subdirectory(lib/myUtils)
add_subdirectory(lib/mySharedLib)

# get assets
file(COPY ./assets DESTINATION ${CMAKE_BINARY_DIR})

# ###############################
# raytracer src (App)
# ###############################

# libconfig++
find_library(libconfig libconfig)

# Find SFML libraries
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SMFML not found. Please install SFML and try again.")
endif()

file(GLOB_RECURSE SRC_FILES_CORE ${PROJECT_SOURCE_DIR}/App/src/*.cpp)

set(EXEC raytracer)
add_executable(${EXEC} ${SRC_FILES_CORE})

target_include_directories(${EXEC}
    PUBLIC
    ./Interface
    ./App/include
    ./lib/myUtils/include
    ./lib/mySharedLib/include
    ${LIBCONFIG++_INCLUDE_DIR}
    ${SFML_INCLUDE_DIRS}
)

target_compile_options(${EXEC}
    PRIVATE
    -Wall
    -Wextra
    -fno-gnu-unique
    -ggdb3
)

target_link_libraries(${EXEC}
    PRIVATE
    config++
    ${SFML_LIBRARIES}
    sfml-graphics
    sfml-audio
    myUtils
    mySharedLib
)

add_custom_target(core
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target raytracer
    COMMENT "Build the App executable only"
    VERBATIM
)

# ###############################
# Plugins
# ###############################
add_subdirectory(Plugins/Primitive)

add_subdirectory(Plugins/Light)

add_subdirectory(Plugins/Camera)

# ###############################
# Google Tests
# ###############################
find_package(GTest QUIET)

if(GTEST_FOUND)
    list(FILTER SRC_FILES_CORE EXCLUDE REGEX ".*main.cpp$")

    file(GLOB_RECURSE SRC_FILES_CORE_TESTS ${PROJECT_SOURCE_DIR}/Tests/src/*.cpp)

    add_executable(raytracerTEST ${SRC_FILES_CORE_TESTS} ${SRC_FILES_CORE})

    target_link_libraries(raytracerTEST PRIVATE gtest)

    add_custom_target(run_tests
        COMMAND ${CMAKE_CTEST_COMMAND}
        DEPENDS raytracerTEST
        COMMAND ./raytracerTEST
    )

    set_target_properties(raytracerTEST PROPERTIES EXCLUDE_FROM_ALL TRUE)
endif()

# ###############################
# Post build rules
# ###############################
add_custom_command(TARGET ${EXEC} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${EXEC}> ${PROJECT_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/plugins ${PROJECT_SOURCE_DIR}/plugins
    COMMENT "Copying ${EXEC} and plugins/ directory to ${PROJECT_SOURCE_DIR}"
)