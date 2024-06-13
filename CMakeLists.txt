

cmake_minimum_required(VERSION 3.10)
project(cppDinosaur)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(cppDinosaur main.cpp)

target_link_libraries(cppDinosaur sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
