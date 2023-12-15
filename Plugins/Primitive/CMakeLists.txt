################################
# raytracer Primitive
################################

add_library(raytracer_primitive SHARED)

# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(raytracer_primitive
    PRIVATE
        ${SRC_FILES}
)

# Add the include directories for the library
target_include_directories(raytracer_primitive
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/Interface/
)

target_compile_options(raytracer_primitive PRIVATE -Wall -Wextra -fno-gnu-unique -ggdb3)

target_link_libraries(raytracer_primitive
    PRIVATE
        ${SFML_LIBRARIES}
        sfml-graphics
        myUtils
)

# Set the output directory for the library
set_target_properties(raytracer_primitive
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME raytracer_primitive
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
)
