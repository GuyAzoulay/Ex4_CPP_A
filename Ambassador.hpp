#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"
using namespace std;

namespace coup{

class Ambassador : public Player{
    public:
    Ambassador(Game& game, const string &name) : Player(game, name){
        this->name = name;
        game.add_player(this);
    }
    void transfer(Player& first, Player& second);
    void block(Player& target);
};







}