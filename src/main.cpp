#include <iostream>
#include "map-utils.h"
#include <stdlib.h>
#include <string>



int main(){
    

    Map newMap{};
    newMap.generateMap("../maps/map_01.txt");
    newMap.printMap(); 
    newMap.movePlayer(Direction::UP); // wheres the one argument u noob idkkkkk >.<
    
    
    //TODO Figure out some way to update the map
    //std::cout << std::string(50, '\n');   
};
