#include "Scientist.hpp"

using namespace pandemic;
namespace pandemic
{
    Player& Scientist::discover_cure(Color color)
    {
        if(board.research_stations.find(current_city)==board.research_stations.end())
        {
            unordered_set<City>::iterator it;
            unordered_set<City> temp;
            bool is_five=false;
            if(board.cured_desease.find(color)!=board.cured_desease.end())
            {
            return *this;
            }
            for(auto& elm: cards)
            {
                if(board.city_colors[elm]==color)
                {
                    temp.insert(elm);
                }
                if(temp.size()==n)
                {
                    is_five=true;
                    break;
                }
            }
           if(is_five)
            {
                for(auto& elm: temp)
                {
                    cards.erase(elm);
                    board.not_in_deck.erase(elm);//return the card to the deck
                }
                board.cured_desease.insert(color);
            }
            else{
                throw logic_error("you dont have 5 cards");
            }
        }
        return *this;
    }
}