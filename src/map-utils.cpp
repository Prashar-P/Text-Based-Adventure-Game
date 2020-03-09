#include <iostream>
#include <fstream>
#include "map-utils.h"
#include <cstdlib>

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
            case('~'):
                newMap[xLineCounter].emplace_back(GRID_ITEM::PLAYER);
                break;
            case('P'):
                newMap[xLineCounter].emplace_back(GRID_ITEM::PLAYER);
                break;
        }
    }
    fin.close();
}

void Map::printMap(){
    int playerY=0;
    int playerX=0;
    //std::vector<std::map<int,GRID_ITEM>>; 
    for(auto yItem : newMap){
        playerY++;
        playerX=0;
        for(auto xMap : yItem){
            playerX++;
            auto item = xMap;
            switch(item){
                case GRID_ITEM::GRASS:{
                    std::cout << "\033[1;32m*\033[0m";
                    break;
                }
                case GRID_ITEM::PLAYER:{
                    std::cout << "\033[1;31mP\033[0m";
                    playerLocation = std::make_tuple(playerX-1,playerY-1);
                    break;
                }
                case GRID_ITEM::WATER:{
                    std::cout << "\033[1;34m~\033[0m";
                    playerLocation = std::make_tuple(playerX-1,playerY-1);
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
    int x = std::get<0>(playerLocation);
    int y = std::get<1>(playerLocation);
    //Set the player grid item back to what it was
    newMap[y][x] = playerGridItem;
    
    switch(newMovement){
        case(Direction::UP):{
            //Move player up
            y--;
            //TODO: Check somewhere here you don't go less than 0, or more than the max map size

            //Store what is where the player wants to go
            playerGridItem = newMap[y][x];
            //Move the player to the new co-ordinates
            newMap[y][x] = GRID_ITEM::PLAYER;
            break;
        }
        case(Direction::DOWN):{
            y++;
            playerGridItem = newMap[y][x];
            newMap[y][x] = GRID_ITEM::PLAYER;
            break;
        }
        case(Direction::LEFT):{
            x--;
            playerGridItem = newMap[y][x];
            newMap[y][x] = GRID_ITEM::PLAYER;
            break;
        }
        case(Direction::RIGHT):{
            x++;
            playerGridItem = newMap[y][x];
            newMap[y][x] = GRID_ITEM::PLAYER;
            break;
        }
        default:
            break;
    }
    playerLocation = {y,x};//https://en.cppreference.com/w/cpp/utility/tuple

}

std::tuple<int,int> Map::getPlayerLocation(){
    return playerLocation;
}
