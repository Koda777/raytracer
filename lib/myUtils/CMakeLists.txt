cmake_minimum_required(VERSION 3.0)

project(myUtils VERSION 1.0)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the SFML libraries
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Create the library target
add_library(myUtils STATIC
    src/dot.cpp
    src/normalize.cpp
    src/reflect.cpp
    src/multilpyColor.cpp
    src/radians.cpp
    src/generateFilename.cpp
    src/sfDisplay.cpp
)

# Add the include directories for the library target
target_include_directories(myUtils PUBLIC
    include
)

# Link the SFML libraries to the library target
target_link_libraries(myUtils PUBLIC
    sfml-graphics
)

# Set the output directory for the library target
set_target_properties(myUtils PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "../../lib"
)