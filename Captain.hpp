#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"

using namespace std;

namespace coup{

class Captain : public Player{
    public:
    Captain(Game& game, const string &name) : Player(game, name){
        this->name = name;
        game.add_player(this);
    }
    void steal(Player& target);
    void block(Player& target);
};




}