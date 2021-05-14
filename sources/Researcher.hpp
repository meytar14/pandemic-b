#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace pandemic;
namespace pandemic
{
    class Researcher : public Player
    {
        public:
        Researcher(Board& b,City city):Player(b,city,"Researcher")
        {
           
        }
        ~ Researcher()
        {
            
        }
        Player& discover_cure(Color color);

    };
}