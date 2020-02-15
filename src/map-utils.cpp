#include <iostream>
#include "map-utils.h"

Map::Map(MapObject & newMap)
    :newMap(newMap){}

void Map::updateMap(){
    //std::vector<std::map<int,GRID_ITEM>>; 
    for(auto yItem : newMap){
        for(auto xMap : yItem){
            auto item = xMap;
            switch(item){
                case GRID_ITEM::GRASS:{
                    std::cout << "*";
                    break;
                }
                default:
                    std::cout << ".";
                    break;
            }
        }
        std::cout << std::endl;
    }
}

bool Map::movePlayer(Direction newMovement){
    
}