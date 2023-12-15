# ###############################
# raytracer camera
# ###############################

add_library(raytracer_camera SHARED)

# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(raytracer_camera
    PRIVATE
    ${SRC_FILES}
)

# Add the include directories for the library
target_include_directories(raytracer_camera
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/Interface/
)

target_compile_options(raytracer_camera PRIVATE -Wall -Wextra -fno-gnu-unique -ggdb3)

target_link_libraries(raytracer_camera
    PRIVATE
    ${SFML_LIBRARIES}
    sfml-graphics
    myUtils
)

# Set the output directory for the library
set_target_properties(raytracer_camera
    PROPERTIES
    PREFIX ""
    OUTPUT_NAME raytracer_camera
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
)
