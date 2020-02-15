#include <iostream>
#include "map-utils.h"
#include <stdlib.h>

int main(){
    Map newMap{};
    newMap.generateMap("../maps/map_01.txt");
    newMap.printMap();


    //TODO Figure out some way to update the map
    //std::cout << std::string(50, '\n');


    newMap.generateMap("../maps/map_02.txt");
    newMap.printMap();
};