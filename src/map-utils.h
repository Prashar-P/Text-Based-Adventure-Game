#include "map.h"
#include <vector>
#include <string>
#include <map>

enum GRID_ITEM{
    GRASS,
    PATH,
    WATER,
    PLAYER
};

using MapObject = std::vector<std::vector<GRID_ITEM>>; 

class Map : public IMap{
    public:
        void updateMap() override;
        bool movePlayer(Direction newMovement) override;
        Map(MapObject & newMap);
        ~Map() = default;
    private:
        MapObject & newMap; // The map of the game
        GRID_ITEM playerGridItem; // The tile that was set before the player stepped on it
};