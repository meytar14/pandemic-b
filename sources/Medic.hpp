#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace pandemic;
namespace pandemic
{
    class Medic : public Player
    {
        public:
        Medic(Board& b,City city):Player(b,city,"Medic")
        {
           
        }
        ~ Medic()
        {
            
        }
    Player& drive(City city);
    Player& fly_direct(City city);
    Player& fly_charter(City city);
    Player& fly_shuttle(City city);
    Player& treat(City city);
    };
}