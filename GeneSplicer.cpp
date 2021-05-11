#include "GeneSplicer.hpp"


using namespace pandemic;
namespace pandemic
{
    Player& GeneSplicer::discover_cure(Color color)
    {
        if(board.research_stations.find(current_city)==board.research_stations.end())
        {
            unordered_set<City>::iterator it;
            unordered_set<City> temp;
            bool is_five=false;
            for(auto& elm: cards)
            {
                temp.insert(elm);
                if(temp.size()==5)
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
        }
        return *this;
    }
}