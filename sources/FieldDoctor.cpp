
#include "FieldDoctor.hpp"

using namespace pandemic;
namespace pandemic
{
    Player& FieldDoctor::treat(City city)
{
    if(board.cured_cities.find(city)!=board.cured_cities.end()){//if num of cubes=0
        throw logic_error("this city is already cured");
    }
    if(current_city!=city && board.cities_conection[current_city].find(city)==board.cities_conection[current_city].end())
    {
        throw logic_error("the city is not your current city");
    }
    if(board.cured_desease.find(board.city_colors[city])!=board.cured_desease.end())
    {
        board.cities_cubes[city]=0;
    }
    else if(board.cities_cubes[city]>0)
    {
        board.cities_cubes[city]=board.cities_cubes[city]-1;
    }
    else if(board.cities_cubes[city]==0){//if num of cubes=0
        board.cured_cities.insert(city);
    }
    return *this;
}
}