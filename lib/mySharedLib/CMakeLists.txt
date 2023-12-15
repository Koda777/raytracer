cmake_minimum_required(VERSION 3.0)

project(mySharedLib VERSION 1.0)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the SFML libraries
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Create the library target
add_library(mySharedLib STATIC
    src/SharedLibHandler.cpp
    src/SharedLibLoader.cpp
)

# Add the include directories for the library target
target_include_directories(mySharedLib PUBLIC
    ./include
    ../myUtils/include
    ${CMAKE_SOURCE_DIR}/Interface/
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link the SFML libraries to the library target
target_link_libraries(mySharedLib PUBLIC
    sfml-graphics
)

# Set the output directory for the library target
set_target_properties(mySharedLib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "../../lib"
)