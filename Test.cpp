#include "sources/game.hpp"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include "doctest.h"
#include <iostream>
using namespace std;

using namespace ariel;

TEST_CASE("initialize Game")
{
    Player p1("Alice");
    Player p2("Bob");
    
    CHECK_NOTHROW(Game game(p1, p2));
}

