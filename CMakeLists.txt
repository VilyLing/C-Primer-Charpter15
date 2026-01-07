cmake_minimum_required(VERSION 3.16)
project(Charpter15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
message("SOURCES = ${SOURCES}")

add_executable(app ${SOURCES})

target_include_directories(app PRIVATE include)