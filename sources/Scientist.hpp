#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace pandemic;
namespace pandemic
{
    class Scientist : public Player
    {
        private:
        int n;
        public:
        Scientist(Board& b,City city,int num):Player(b,city,"Scientist")
        {
           n=num;
        }
        ~ Scientist()
        {
            
        }
        Player& discover_cure(Color color);

    };
}