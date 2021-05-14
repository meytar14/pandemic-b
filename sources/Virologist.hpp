#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace pandemic;
namespace pandemic
{
    class Virologist : public Player
    {
        public:
        Virologist(Board& b,City city):Player(b,city,"Virologist")
        {
           
        }
        ~ Virologist()
        {
            
        }
    Player& treat(City city);
    };
} 