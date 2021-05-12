#include "Virologist.hpp"

using namespace pandemic;
namespace pandemic
{
   Player& Virologist::treat(City city)
{
    if(board.cities_cubes[city]==0){//if num of cubes=0
        throw logic_error("this city is already cured");
    }
    
    if(city==current_city)
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
    }
    else if(cards.find(city)!=cards.end())
        {
            if(board.cured_desease.find(board.city_colors[city])!=board.cured_desease.end())
            {
            board.cities_cubes[city]=0;
            }
            else if(board.cities_cubes[city]>0)
            {
            board.cities_cubes[city]=board.cities_cubes[city]-1;
            }
            if(board.cities_cubes[city]==0)
            {//if num of cubes=0
                board.cured_cities.insert(city);
            }
            cards.erase(city);
            board.not_in_deck.erase(city);
        }
        else{
            throw logic_error("you dont have this card");
        }
    return *this;
} 
}