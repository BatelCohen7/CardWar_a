#include <iostream>
#include <string>
#include "player.hpp"

using namespace std;

namespace ariel {
    class Game {
        Player p1;
        Player p2;

    public:
        Game(Player &p1, Player &p2) : p1(p1), p2(p2) {}

        void playTurn() {
            // TODO: implement the logic for playing a turn
        }

        void printLastTurn() {
            // TODO: implement the logic for printing the last turn
        }

        void playAll() {
            // TODO: implement the logic for playing all turns
        }

        void printWinner() {
            // TODO: implement the logic for printing the winner
        }

        void printLog() {
            // TODO: implement the logic for printing the log
        }

        void printStats() {
            // TODO: implement the logic for printing the stats
        }
    };
}
