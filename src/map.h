#pragma once

enum Direction{
    LEFT = 'a', //<- Used to move left 
    RIGHT = 'd', //<- Used to move right
    UP = 'w', //<- Used to move up
    DOWN = 's'//<-Used to move down
};

class IMap{
    public:
        virtual void generateMap(std::string mapName) =0;
        virtual void printMap() = 0;
        virtual bool movePlayer(Direction newMovement) =0;
};
