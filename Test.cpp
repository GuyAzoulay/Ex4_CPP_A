#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "doctest.h"
using namespace std;
using namespace coup;

TEST_CASE("Test Game1 - good cases of Game") {
    Game game_1{};

    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    vector<string> players = game_1.players();
    CHECK(players.size() == 5);
    
    CHECK(game_1.turn() == "Moshe");
    duke.tax();
    CHECK(duke.coins() == 3);
    CHECK(game_1.turn() == "Yossi");
    assassin.income();
    CHECK(assassin.coins() == 1);
    ambassador.foreign_aid();
    CHECK(ambassador.coins() == 2);
    CHECK(game_1.turn() == "Meirav");
    ambassador.transfer(assassin,contessa);
    CHECK(assassin.coins() == 0);
    CHECK(contessa.coins() == 1);
    CHECK(game_1.turn() == "Reut");
    captain.income();
    CHECK(captain.coins() == 1);
    CHECK(game_1.turn() == "Gilad");
    contessa.foreign_aid();
    CHECK(contessa.coins() == 3);
    CHECK(game_1.turn() == "Moshe");
    duke.tax();
    CHECK(duke.coins() == 6);
    CHECK(game_1.turn() == "Yossi");    
    assassin.income();
    CHECK(assassin.coins() == 1);
    CHECK(game_1.turn() == "Meirav");
    ambassador.foreign_aid();
    CHECK(ambassador.coins() == 2);
    CHECK(game_1.turn() == "Reut");
    captain.steal(duke);
    CHECK(captain.coins() == 3);
    CHECK(duke.coins() == 4);
    CHECK(game_1.turn() == "Gilad");
    contessa.foreign_aid();
    CHECK(contessa.coins() == 4);
    CHECK(game_1.turn() == "Moshe");
    duke.tax();
    CHECK(duke.coins() == 7);
    CHECK(game_1.turn() == "Yossi");
    assassin.income();
    CHECK(assassin.coins() == 2);
    CHECK(game_1.turn() == "Meirav");
    ambassador.transfer(duke,assassin);
    CHECK(duke.coins() == 6);
    CHECK(assassin.coins() == 3);
    CHECK(game_1.turn() == "Reut");
    captain.foreign_aid();
    CHECK(captain.coins() == 5);
    CHECK(game_1.turn() == "Gilad");
    contessa.foreign_aid();
    CHECK(contessa.coins() == 6);
    CHECK(game_1.turn() == "Moshe");
    duke.tax();
    CHECK(duke.coins() == 9);
    CHECK(game_1.turn() == "Yossi");
    assassin.coup(contessa);
    CHECK(assassin.coins() == 0);
    CHECK(players.size() == 4);
    CHECK(game_1.turn() == "Meirav");
    ambassador.transfer(duke,assassin);
    CHECK(duke.coins() == 8);
    CHECK(assassin.coins() == 1);
    CHECK(game_1.turn() == "Reut");
    captain.foreign_aid();
    CHECK(captain.coins() == 7);
    CHECK(game_1.turn() == "Gilad");
    contessa.block(assassin);
    CHECK(contessa.coins() == 6);
    CHECK(game_1.turn() == "Moshe");
    duke.foreign_aid();
    CHECK(duke.coins() == 10);
}
////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("Test game 2 - good and bad cases of a Game") {

    Game game_2{};

    Duke duke{game_2, "Goku"};
    Assassin assassin{game_2, "Vegeta"};
    Ambassador ambassador{game_2, "Gohan"};
    Captain captain{game_2, "Trunks"};
    Contessa contessa{game_2, "Piccolo"};
    vector<string> players = game_2.players();
    
    //only if it your turn you can do something
    CHECK(players.size() == 5);
    CHECK_FALSE(game_2.turn()== "Vegeta");
    CHECK_FALSE(game_2.turn()== "Gohan");
    CHECK_FALSE(game_2.turn()== "Trunks");
    CHECK_FALSE(game_2.turn()== "Piccolo");
    
    CHECK(game_2.turn()== "Goku");
    duke.tax();
    CHECK(duke.coins() == 3);
    CHECK(game_2.turn()== "Vegeta");
    CHECK_FALSE(game_2.winner()== "Vegeta"); // if there is more than 1 player the game is not over
    assassin.foreign_aid();
    CHECK(assassin.coins() == 2);
    CHECK(game_2.turn()== "Gohan");
    CHECK_FALSE(game_2.winner()== "Gohan"); // if there is more than 1 player the game is not over
    ambassador.transfer(duke,contessa);
    CHECK(contessa.coins() == 1);
    CHECK(duke.coins() == 2);
    CHECK(game_2.turn()== "Trunks");
    CHECK_FALSE(game_2.winner()== "Trunks"); 
    captain.steal(duke);
    CHECK(captain.coins() == 2);
    CHECK(duke.coins() == 0);
    CHECK(game_2.turn()== "Piccolo");
    CHECK_FALSE(game_2.winner()== "Piccolo");
    contessa.foreign_aid();
    CHECK(contessa.coins() == 3);
    CHECK(game_2.turn()== "Goku");
    CHECK_FALSE(game_2.winner()== "Goku");
    duke.block(assassin);
    CHECK(assassin.coins() == 0);
    CHECK(duke.coins() == 0);
    CHECK(game_2.turn()== "Vegeta");
    assassin.income();
    CHECK(assassin.coins() == 1);
    CHECK(game_2.turn()== "Gohan");
    ambassador.block(captain);
    CHECK(captain.coins() == 0);
    CHECK(ambassador.coins() == 0);
    CHECK(duke.coins() == 2);
    CHECK(game_2.turn()== "Trunks");
    captain.foreign_aid();
    CHECK(captain.coins() == 2);
    CHECK(game_2.turn()== "Piccolo");
    contessa.foreign_aid();
    CHECK(contessa.coins() == 5);
    CHECK(game_2.turn()== "Goku");
    duke.block(captain);
    CHECK(captain.coins() == 0);
    CHECK(duke.coins() == 0);
    CHECK(game_2.turn()== "Vegeta");
    assassin.foreign_aid();
    CHECK(assassin.coins() == 3);
    CHECK(game_2.turn()== "Gohan");
    ambassador.transfer(contessa, ambassador);
    CHECK(contessa.coins() == 4);
    CHECK(ambassador.coins() == 1);
    CHECK(game_2.turn()== "Trunks");
    captain.steal(contessa);
    CHECK(captain.coins() == 2);
    CHECK(contessa.coins() == 2);
    CHECK(game_2.turn()== "Piccolo");
    contessa.foreign_aid();
    CHECK(contessa.coins() == 4);
    CHECK(game_2.turn()== "Goku");
    duke.tax();
    CHECK(duke.coins() == 3);
    CHECK(game_2.turn()== "Vegeta");
    assassin.coup(captain);
    CHECK_FALSE(game_2.turn()== "Piccolo");    
    CHECK(assassin.coins() == 0);
    CHECK(players.size() == 4);
    CHECK(game_2.turn()== "Gohan");
    CHECK_FALSE(game_2.winner()== "Gohan");
    ambassador.foreign_aid();
    CHECK(ambassador.coins() == 3);
    CHECK_FALSE(game_2.turn()== "Trunks"); // Trunks was killed by the assassin ( Vegeta)
    CHECK(game_2.turn()== "Piccolo");
    CHECK_THROWS(contessa.block(duke)); // contessa cannot block the tax commend
    CHECK_THROWS(contessa.block(captain)); // contessa cannot block a player that is out of the game
    CHECK_THROWS(contessa.block(ambassador)); // contessa cannot block the forgein aid commend
    contessa.block(assassin); // contessa can block the assassin
    CHECK(players.size() == 5); // after contessa blocks the assassin the captain return to the game
    CHECK(game_2.turn()== "Goku");
    CHECK_THROWS(duke.block(contessa)); // duke cannot block the contessa action
    CHECK_THROWS(duke.block(captain)); // duke cannot block a player that is out of the game
    
}

TEST_CASE("player doesnt plays in is own turn"){
Game game_3{};
Duke duke{game_3, "Eren"};
Assassin assassin{game_3, "Levi"};
Ambassador ambassador{game_3, "Armin"};
Captain captain{game_3, "Mikasa"};
Contessa contessa{game_3, "Riner"};
vector<string> players = game_3.players();

    CHECK(players.size() == 5);
    CHECK_FALSE(game_3.turn()== "Eren");
    CHECK_FALSE(game_3.turn()== "Levi");
    CHECK_FALSE(game_3.turn()== "Armin");
    CHECK_FALSE(game_3.turn()== "Mikasa");
    CHECK_FALSE(game_3.turn()== "Rayner");
    CHECK(game_3.turn()== "Eren");
    duke.tax();
    CHECK(duke.coins() == 3);
    CHECK_FALSE(game_3.turn()== "Eren");
    CHECK(game_3.turn()== "Levi");
    assassin.foreign_aid();
    CHECK(assassin.coins() == 2);
    CHECK_FALSE(game_3.turn()== "Rayner");
    CHECK(game_3.turn()== "Armin");
    ambassador.transfer(duke,contessa);
    CHECK(contessa.coins() == 1);
    CHECK(duke.coins() == 2);
    CHECK_FALSE(game_3.turn()== "Rayner");
    CHECK(game_3.turn()== "Mikasa");
    captain.steal(duke);
    CHECK(captain.coins() == 2);
    CHECK(duke.coins() == 0);
    CHECK_FALSE(game_3.turn()== "Levi");
    CHECK(game_3.turn()== "Riner");
    contessa.foreign_aid();
    CHECK(contessa.coins() == 3);
}
TEST_CASE("Winner show  before the end of the game"){
Game game_4{};
Duke duke{game_4, "Deku"};
Assassin assassin{game_4, "AllMight"};
Ambassador ambassador{game_4, "Kachan"};
Captain captain{game_4, "Shoto"};
Contessa contessa{game_4, "Endevar"};
CHECK_FALSE(game_4.winner()== "Deku");
CHECK_FALSE(game_4.winner()== "AllMight");
CHECK_FALSE(game_4.winner()== "Kachan");
CHECK_FALSE(game_4.winner()== "Shoto");
CHECK_FALSE(game_4.winner()== "Endevar");
duke.tax(); // 3 coins to duke
assassin.foreign_aid(); // 2 coins to assassin
ambassador.transfer(duke,contessa); // 1 coin to contessa 2 coins to duke
captain.steal(duke); // 2 coin to captain 0 coins to duke
contessa.foreign_aid(); // 3 coin to contessa
duke.tax(); // 3 coins to duke
assassin.income(); // 3 coins to assassin
ambassador.foreign_aid(); // 2 coins to ambassador
captain.steal(contessa); // 4 coins to captain 1 coin to contessa
contessa.foreign_aid(); // 4 coins to contessa
duke.tax(); // 6 coins to duke
assassin.coup(captain); // 0 coins to assassin
CHECK_FALSE(game_4.winner()== "Deku");
CHECK_FALSE(game_4.winner()== "AllMight");
CHECK_FALSE(game_4.winner()== "Kachan");
CHECK_FALSE(game_4.winner()== "Endevar");
captain.foreign_aid(); //6 coins to captain
contessa.foreign_aid(); // 6 coins to contessa
duke.tax(); // 9 coins to duke
assassin.foreign_aid(); // 2 coins to assassin
ambassador.foreign_aid(); // 4 coins to ambassador
captain.income(); // 7 coins to captain
contessa.income(); // 7 coins to contessa
duke.coup(assassin); // 2 coins to duke

CHECK_FALSE(game_4.winner()== "Deku");
ambassador.foreign_aid(); // 6 coins to ambassador
captain.coup(ambassador); // 0 coins to captain
CHECK_FALSE(game_4.winner()== "Deku");
contessa.coup(captain); // 0 coins to contessa
CHECK_FALSE(game_4.winner()== "Deku");
duke.tax(); // 5 coins to duke
contessa.foreign_aid(); // 2 coins to contessa
duke.tax(); // 8 coins to duke
contessa.foreign_aid(); // 4 coins to contessa
duke.coup(contessa); // 1 coins to duke
CHECK_EQ(game_4.winner()== "Deku", true);


}

TEST_CASE("More than 6 player or less than 2 playes tries to play"){
Game game_5{};
Duke duke{game_5, "Naruto"};
Assassin assassin{game_5, "Sasuke"};
Ambassador ambassador{game_5, "Sakura"};
Captain captain{game_5, "Kakashi"};
Contessa contessa{game_5, "Gara"};
Contessa contessa_2{game_5, "Boruto"};
Duke duke_2{game_5, "Pain"};
CHECK(game_5.players().size() == 6);
Assassin assassin_2{game_5, "Shikamaru"};
CHECK(game_5.players().size() == 6);
Ambassador ambassador_2{game_5, "Rock_Lee"};
CHECK(game_5.players().size() == 6);
Captain captain_2{game_5, "Jiraya"};
CHECK(game_5.players().size() == 6);
Contessa contessa_3{game_5, "Itachi"};
CHECK(game_5.players().size() == 6);
Contessa contessa_4{game_5, "Hinata"};
CHECK(game_5.players().size() == 6);
Ambassador ambassador_3{game_5, "Neji"};
CHECK(game_5.players().size() == 6);
duke.tax();
assassin.foreign_aid();
ambassador.foreign_aid();
captain.foreign_aid();
contessa.foreign_aid();
contessa_2.foreign_aid();
duke.tax(); // 6 coins
assassin.foreign_aid(); // 4 coins
ambassador.foreign_aid(); // 4 coins
captain.foreign_aid(); // 4 coins
contessa.foreign_aid(); // 4 coins
contessa_2.foreign_aid(); // 4 coins
duke.tax(); // 9 coins
assassin.coup(captain); // 0 coins
ambassador.foreign_aid(); // 6 coins
contessa.foreign_aid(); // 6 coins
contessa_2.foreign_aid(); // 6 coins
duke.coup(assassin); // 2 coins
ambassador.foreign_aid(); // 8 coins
contessa.foreign_aid(); // 8 coins
contessa_2.foreign_aid(); // 8 coins
duke.tax(); // 5 coins
ambassador.coup(contessa); // 1 coins
contessa_2.coup(ambassador); // 1 coins
duke.tax(); // 8 coins
contessa_2.foreign_aid(); // 3 coins
duke.coup(contessa_2); // 1 coins
CHECK_THROWS(duke.income());
CHECK_THROWS(duke.foreign_aid());
CHECK_THROWS(duke.tax());
CHECK(game_5.winner()== "Naruto");
}


TEST_CASE(" more than 10 coins must coup"){
Game game_6{};
Duke duke{game_6, "Tanjiro"};
Assassin assassin{game_6, "Zenitsu"};
Ambassador ambassador{game_6, "Inosuke"};
Captain captain{game_6, "Guy"};
Contessa contessa{game_6, "Rengoku"};
duke.tax();
assassin.foreign_aid();
ambassador.foreign_aid();
captain.foreign_aid();
contessa.foreign_aid();
duke.tax(); // 6 coins
assassin.foreign_aid(); // 4 coins
ambassador.foreign_aid(); // 4 coins
captain.foreign_aid(); // 4 coins
contessa.foreign_aid(); // 4 coins
duke.tax(); // 9 coins
assassin.foreign_aid(); // 6 coins
ambassador.foreign_aid(); // 6 coins
captain.foreign_aid(); // 6 coins
contessa.foreign_aid(); // 6 coins
duke.tax(); // 12 coins
assassin.foreign_aid(); // 8 coins
ambassador.foreign_aid(); // 8 coins
captain.foreign_aid(); // 8 coins
contessa.foreign_aid(); // 8 coins
CHECK_THROWS(duke.tax());
CHECK_THROWS(duke.foreign_aid());
CHECK_THROWS(duke.income());
CHECK_NOTHROW(duke.coup(assassin)); // 5 coins
ambassador.foreign_aid(); // 10 coins
captain.foreign_aid(); // 10 coins
contessa.foreign_aid(); // 10 coins
duke.tax(); // 8 coins
CHECK_THROWS(ambassador.foreign_aid());
CHECK_THROWS(ambassador.income());
CHECK_THROWS(ambassador.transfer(captain, contessa));
CHECK_NOTHROW(ambassador.coup(contessa)); // 3 coins
CHECK_THROWS(captain.foreign_aid());
CHECK_THROWS(captain.income());
CHECK_THROWS(captain.steal(ambassador));
CHECK_NOTHROW(captain.coup(ambassador)); // 3 coins
duke.tax(); // 11 coins
captain.foreign_aid(); // 5 coins
CHECK_THROWS(duke.tax());
CHECK_THROWS(duke.foreign_aid());
CHECK_THROWS(duke.income());
CHECK_NOTHROW(duke.coup(captain)); // 4 coins
CHECK(game_6.winner()== "Tanjiro");
}







