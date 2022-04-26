#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#pragma once

using namespace std;

namespace coup{
class Player;

class Game{

    public:
    
    void add_player(Player* player);

    vector<string> players();
    
    string turn();
    
    string winner();
    Game(){
    
    }
    private:
    vector<Player*> members;
    int now_turn;
};

}






