cmake_minimum_required(VERSION 2.8.9)
project(cbuff)
include_directories(include)
file(GLOB SOURCES "src/*.cpp" )
file(GLOB TSOURCES "test/*.cpp")
add_compile_options("-std=c++11" "-Wall")

add_executable(cbuff ${SOURCES} ${TSOURCES})
