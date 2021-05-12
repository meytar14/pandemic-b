#include "Dispatcher.hpp"

using namespace pandemic;
namespace pandemic
{
    Player& Dispatcher::fly_direct(City city)
    {
        if(city==current_city)
        {
        throw logic_error("you are already in this city");
        }
        bool fly=false;
        if(board.research_stations.find(current_city)!=board.research_stations.end())
        {
            current_city=city;
            fly=true;
        }
        else if(cards.find(city)!=cards.end())
        {
            current_city=city;
            cards.erase(city);
            board.not_in_deck.erase(city);
        }
        else if(!fly)
        {
            throw logic_error("you doesnt have this city card");
        }
        return *this;
    }
}