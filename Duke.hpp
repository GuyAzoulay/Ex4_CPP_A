#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"

using namespace std;
namespace coup{


class Duke : public Player{
    public:
    Duke(Game& game, const string &name) : Player(game, name){
        this->name = name;
        game.add_player(this);
    }
    void tax();
    void block(Player &target); 
};



}