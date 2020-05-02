cmake_minimum_required(VERSION 3.16)
project(average_shortest_path)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB SOURCE_HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)

add_library(average_shortest_path
        ${SOURCE_FILES}
        ${SOURCE_HEADERS}
        )

target_include_directories(average_shortest_path INTERFACE
        ${PROJECT_SOURCE_DIR}/src
        )

# Tests
add_subdirectory(tests)
