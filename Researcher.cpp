#include "Researcher.hpp"


using namespace pandemic;
namespace pandemic
{
    Player& Researcher::discover_cure(Color color)
    {
            unordered_set<City>::iterator it;
            unordered_set<City> temp;
            for(auto& elm: cards)
            {
                if(board.city_colors[elm]==color)
                {
                    temp.insert(elm);
                }
                if(temp.size()==5)
                {
                    break;
                }
            }
            for(auto& elm: temp)
            {
                cards.erase(elm);
            }
            board.research_stations.insert(current_city);
        return *this;
    }
}


