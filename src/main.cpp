#include <iostream>
#include "map-utils.h"

int main(){
    std::vector<std::vector<GRID_ITEM>> newf {{GRID_ITEM::GRASS,GRID_ITEM::PATH,GRID_ITEM::GRASS},
                                              {GRID_ITEM::GRASS,GRID_ITEM::PATH,GRID_ITEM::WATER},
                                              {GRID_ITEM::PATH,GRID_ITEM::PLAYER,GRID_ITEM::GRASS}};
    Map newMap{newf};
    newMap.updateMap();
};