cmake_minimum_required(VERSION 3.10)
project(PokemonClone LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

file(GLOB SRC_FILES
    src/*.cpp
)

set(INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/include
)

# Add the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})


