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

//test for the function Player.stacksize()
TEST_CASE("Test Player stacksize() function") {
    Player p("Alice");
    Player p1("Bob");
    Player p2("Roni");

    CHECK(p.stacksize() == 0); //Should return True
    CHECK(p1.stacksize() == 26); //Should return True
    CHECK(p2.stacksize() == 26); //Should return True
}

//test for the function Player.cardesTaken()
TEST_CASE("Test Player cardesTaken() function") {
    Player p("Bob");
    CHECK(p.cardesTaken() == 0);
    
    Player p1("Alice");
    CHECK(p1.cardesTaken() == 0);
    
    Player p2("Roni");
    CHECK(p2.cardesTaken() == 0);
    
    CHECK_NOTHROW(p.cardesTaken());
}

//test for the function Game.playTurn()
TEST_CASE("Test Game playTurn() function") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    for (size_t i = 0; i < 7; i++)
    {
        CHECK_NOTHROW(game.playTurn());
    }

}

//test for the function Game.printLastTurn()
TEST_CASE("Test Game printLastTurn() function") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_THROWS(game.printLastTurn());
}

//test for the function Game.playAll()
TEST_CASE("Test Game playAll() function") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_NOTHROW(game.playAll());
}

//test for the function Game.printWinner()
TEST_CASE("Test Game printWinner() function") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_THROWS(game.printWiner());
}

//test for the function Game.printLog()
TEST_CASE("Test Game printLog() function") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_THROWS(game.printLog());
}

//test for the function Game.printStats()
TEST_CASE("Test Game printStats() function") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_THROWS(game.printStats());
}

