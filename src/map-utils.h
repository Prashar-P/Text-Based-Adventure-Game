#include "map.h"
#include <vector>
#include <string>
#include <map>
#include <tuple>

enum GRID_ITEM{
    GRASS,
    PATH,
    WATER,
    PLAYER
};

using MapObject = std::vector<std::vector<GRID_ITEM>>; 

class Map : public IMap{
    public:
        void printMap() override;
        void generateMap(std::string mapName) override;
        bool movePlayer(Direction newMovement) override;
        std::tuple<int,int> getPlayerLocation();
        void clear();
        Map();
        ~Map() = default;
    private:
        MapObject newMap; // The map of the game
        GRID_ITEM playerGridItem; // The tile that was set before the player stepped on it
        std::tuple<int,int> playerLocation;
};