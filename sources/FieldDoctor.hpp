#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace pandemic;
namespace pandemic
{
    class FieldDoctor : public Player
    {
        public:
        FieldDoctor(Board b,City city):Player(b,city,"FieldDoctor")
        {
           
        }
        ~ FieldDoctor()
        {
            
        }
        Player& treat(City city);
    };
} 