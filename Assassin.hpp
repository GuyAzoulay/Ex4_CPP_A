#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"
using namespace std;

namespace coup{


class Assassin : public Player{
    public:
    Assassin(Game& game, const string &name) : Player(game, name){
        this->name = name;
        game.add_player(this);
    }
    void coup(Player& target) override;
    
};


}