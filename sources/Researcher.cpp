#include "Researcher.hpp"


using namespace pandemic;
namespace pandemic
{
    Player& Researcher::discover_cure(Color color)
    {
            unordered_set<City>::iterator it;
            unordered_set<City> temp;
            if(board.cured_desease.find(color)!=board.cured_desease.end())
            {
            return *this;
            }
            bool has_five=false;
            for(auto& elm: cards)
            {
                if(board.city_colors[elm]==color)
                {
                    temp.insert(elm);
                }
                if(temp.size()==5)
                {
                    has_five=true;
                    break;
                }
            }
            if(has_five)
            {
                for(auto& elm: temp)
                {
                    cards.erase(elm);
                }
                board.cured_desease.insert(color);
            }
            else{
                throw logic_error("you dont have five cards");
            }
        return *this;
    }
}


