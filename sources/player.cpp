#include <iostream>
#include <string>
#include "player.hpp"

namespace ariel{
    Player::Player() : name("") {}

    Player::Player(std::string name) : name(name) {}

    int Player::stacksize() const {
        return 0;
    }

    int Player::cardesTaken() const {
        return 0;
    }
}


