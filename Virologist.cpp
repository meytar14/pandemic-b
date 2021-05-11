#include "Virologist.hpp"

using namespace pandemic;
namespace pandemic
{
   Player& Virologist::treat(City city)
{
    if(board.cured_desease.find(board.city_colors[city])!=board.cured_desease.end())
    {
        board.cities_cubes[city]=0;
    }
    else if(board.cities_cubes[city]>0)
    {
        board.cities_cubes[city]=board.cities_cubes[city]-1;
    }
    if(board.cities_cubes[city]==0){//if num of cubes=0
        board.cured_cities.insert(city);
    }
    return *this;
} 
}