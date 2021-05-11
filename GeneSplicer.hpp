#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace pandemic;
namespace pandemic
{
    class GeneSplicer : public Player
    {
        public:
        GeneSplicer(Board b,City city):Player(b,city,"GeneSplicer")
        {
           
        }
        ~ GeneSplicer()
        {
            
        }
        Player& discover_cure(Color color);
    };
} 