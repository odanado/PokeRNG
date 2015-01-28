cmake_minimum_required(VERSION 2.8)

file(GLOB PokeRNG_SOURCES "PokeRNG/*.cpp")
file(GLOB PokeRNG_HEADERS "PokeRNG/*.hpp")

add_library(PokeRNG SHARED ${PokeRNG_SOURCES})
add_library(PokeRNG-static STATIC ${PokeRNG_SOURCES})

SET_TARGET_PROPERTIES(PokeRNG-static PROPERTIES OUTPUT_NAME "PokeRNG")

if(UNIX)
    set(CMAKE_CXX_COMPILER "g++")

    add_definitions("-std=c++11 -Wall -Wextra -Weffc++ -O3")
    SET_TARGET_PROPERTIES(PokeRNG-static PROPERTIES PREFIX "lib")
    INSTALL(TARGETS PokeRNG LIBRARY DESTINATION lib)
    INSTALL(FILES ${PokeRNG_HEADERS} DESTINATION include/PokeRNG)
endif(UNIX)


