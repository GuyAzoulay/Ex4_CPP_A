#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Game.hpp"

#pragma once
using namespace std;

namespace coup{
    class Game;
    class Player{
        private:
        int coin;

        public:
        string name;
        void income();
        void foreign_aid();
        virtual void coup(Player& target);
        int coins() ;
        string role();
       
    
    Player(Game& game, const string &name) {
        this->name = name;
        game.add_player(this);
    }
    
};
}