#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace pandemic;
namespace pandemic
{
    class OperationsExpert : public Player
    {
        public:
        OperationsExpert(Board b,City city):Player(b,city,"OperationsExpert")
        {
           
        }
        ~ OperationsExpert() 
        {
            
        }
        Player& build();

    };
}