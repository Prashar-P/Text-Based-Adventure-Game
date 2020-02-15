#pragma once

enum Direction{
    LEFT, //<- Used to move left 
    RIGHT, //<- Used to move right
    UP, //<- Used to move up
    DOWN //<-Used to move down
};

class IMap{
    public:
        virtual void updateMap() = 0;
        virtual bool movePlayer(Direction newMovement) =0;
};