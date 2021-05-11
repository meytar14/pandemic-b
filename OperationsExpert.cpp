#include "OperationsExpert.hpp"


using namespace pandemic;
namespace pandemic
{
Player& OperationsExpert::build()
{
    if(board.research_stations.find(current_city)==board.research_stations.end())
    {
        board.research_stations.insert(current_city);
    }
    return *this;
}

}