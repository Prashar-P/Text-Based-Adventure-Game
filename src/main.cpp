#include <iostream>
#include "map-utils.h"
#include "pokemon.h"
#include <stdlib.h>
#include <string>
#include <ncurses.h>
#include <unistd.h>


int main(){ 
    char key;

    std::system("clear");
    std::cout << "\033[1;33mPokemon\033[0m" << std::endl << std::endl;
    std:: cout << " 1. Start Game" << std::endl;
    std:: cout << " 2. Quit Game " << std::endl;
    initscr();
    char option = getchar();
    endwin();
    switch (option)
    {
        case '1':{
            std::system("clear");
            std:: cout << "\033[1;34mSelect Map:\033[0m"  << std::endl << std::endl;
            std:: cout << "1. Grass Fields:" << std::endl;
            std:: cout << "2. Lake Front:" << std::endl;
            char option = getchar();
            std::system("clear");
            switch(option)
            {
                case '1':{
                    Map newMap{};
                    newMap.generateMap("../maps/map_01.txt");    
                    break;
                }
                case '2':{
                    Map newMap{};
                    newMap.generateMap("../maps/map_02.txt");
                    break;
                }
                default:{
                    std::cout << "invalid option" << std::endl;
                    exit(0);
                }    
            
            }
            break;
        }
        case '2':{
            system("exit");
            break;
            //exit game    
        }
        default:{
            std::cout << "invalid option" << std::endl;
            break;
        }
    }
    Map newMap{};
    newMap.generateMap("../maps/map_01.txt");
    newMap.printMap();
    auto x = newMap.getPlayerLocation();
    while(key != 'x'){
        while (true){
            initscr(); 
            key = getchar();
            switch(key)
            {
                case 'w':{
                newMap.movePlayer(Direction::UP);
                std::system("clear");
                newMap.printMap();
                break;
                }
                case 's':{
                newMap.movePlayer(Direction::DOWN);
                std::system("clear");
                newMap.printMap();
                break;
                }
                case 'a':{
                newMap.movePlayer(Direction::LEFT);
                std::system("clear");
                newMap.printMap();
                break;  
                }
                case 'd':{
                newMap.movePlayer(Direction::RIGHT);
                std::system("clear");
                newMap.printMap();
                break;
                }
            }
        int chance = rand() % 101;
        if (chance <= 20)
            std::cout << "call pokemon" << std::endl;
           // readPokemon();
        }
    }
}
    
    //newMap.movePlayer(Direction::DOWN);
    //newMap.movePlayer(Direction::UP);
    //newMap.printMap();
