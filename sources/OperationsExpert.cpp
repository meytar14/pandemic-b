#include "OperationsExpert.hpp"


using namespace pandemic;
namespace pandemic
{
Player& OperationsExpert::build()
{
    
    board->research_stations.insert(current_city);
    
    return *this;
}

}