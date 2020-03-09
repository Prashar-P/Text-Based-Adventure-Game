cmake_minimum_required(VERSION 2.8.9)
project(pokemon_cli_game)
 
#Can manually add the sources using the set command as follows:
set(SOURCES src/main.cpp
	    src/map-utils.cpp)

add_executable(pokemon ${SOURCES})

#Bring the headers, 
target_include_directories(pokemon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/lib)

target_link_libraries(pokemon PUBLIC ncurses sqlite3)


