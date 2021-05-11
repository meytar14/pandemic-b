#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace pandemic;
namespace pandemic
{
    class Dispatcher : public Player
    {
        public:
        Dispatcher(Board b,City city):Player(b,city,"Dispatcher")
        {
           
        }
        ~ Dispatcher()
        {
            
        }
        Player& Dispatcher::fly_direct(City city);

    };
}