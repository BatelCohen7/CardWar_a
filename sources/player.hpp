#pragma once 
#include <iostream>
#include <string.h>

namespace ariel{
    class Player
    {
        std::string name; 
          
    public:
        Player();
        Player(std::string name);
        int stacksize() const;
        int cardesTaken() const;
    };
}
