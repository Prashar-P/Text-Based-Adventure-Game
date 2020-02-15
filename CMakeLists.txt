cmake_minimum_required(VERSION 2.8.9)
project(pokemon_cli_game)
 
#Bring the headers, 
include_directories(src/include)
 
#Can manually add the sources using the set command as follows:
set(SOURCES src/main.cpp
	    src/map-utils.cpp)
 
add_executable(pokemon ${SOURCES})