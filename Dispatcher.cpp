#include "Dispatcher.hpp"

using namespace pandemic;
namespace pandemic
{
    Player& Dispatcher::fly_direct(City city)
    {
        if(board.research_stations.find(current_city)!=board.research_stations.end())
        {
            current_city=city;
        }
        else if(cards.find(city)!=cards.end())
        {
            current_city=city;
            cards.erase(city);
        }
        else
        {
            throw logic_error("you doesnt have this city card");
        }
        return *this;
    }
}