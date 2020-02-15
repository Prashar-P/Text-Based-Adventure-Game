#include <iostream>
#include <fstream>
#include "map-utils.h"
#include "lib/strutils.h"

Map::Map()
    :newMap(),
     playerGridItem(GRID_ITEM::PATH){}

void Map::generateMap(std::string mapName){
    char ch;
    int xLineCounter =0; // Start creating the map from x = 0
    std::vector<GRID_ITEM> newItem;
    //Clears the map and starts to generate a new map
    newMap.clear();
    //Start reading the characters one by one
    std::ifstream fin(mapName);
    while (fin.get(ch)) {
        if(newMap.size() == 0){
            newMap.emplace_back(newItem);
        }
        //This signifies the end of a line
        if(ch == '|'){
            //Create a new x here
            xLineCounter++;
            //Create next line
            newMap.emplace_back(newItem);
        }
        switch(ch){
            case('*'):
                newMap[xLineCounter].emplace_back(GRID_ITEM::GRASS);
                break;
            case('.'):
                newMap[xLineCounter].emplace_back(GRID_ITEM::PATH);
                break;
            case('P'):
                newMap[xLineCounter].emplace_back(GRID_ITEM::PLAYER);
                break;
        }
    }
    fin.close();
}


void Map::printMap(){
    //std::vector<std::map<int,GRID_ITEM>>; 
    for(auto yItem : newMap){
        for(auto xMap : yItem){
            auto item = xMap;
            switch(item){
                case GRID_ITEM::GRASS:{
                    std::cout << "*";
                    break;
                }
                case GRID_ITEM::PLAYER:{
                    std::cout << "P";
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

void Map::clear(){
    system("clear");
}

bool Map::movePlayer(Direction newMovement){

}