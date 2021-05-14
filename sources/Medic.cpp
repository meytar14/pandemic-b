#include "Medic.hpp"


using namespace pandemic;
namespace pandemic
{
    Player& Medic::drive(City city)
{
    if(city==current_city)
    {
        throw logic_error("you are already in this city");
    }
    if(board->cities_conection[current_city].find(city)!=board->cities_conection[current_city].end())
    {
        current_city=city;
    }
    else
    {
        throw logic_error("this cities arent connected");
    }
    if(board->cured_desease.find(board->city_colors[current_city])!=board->cured_desease.end())
    {
        board->cities_cubes[current_city]=0;
    }
    
    return *this;
}
Player& Medic::fly_direct(City city)
{
    if(city==current_city)
    {
        throw logic_error("you are already in this city");
    }
    if(cards.find(city)!=cards.end())
    {
        cards.erase(city);
        board->not_in_deck.erase(city);//return the card to the deck
        current_city=city;
    }
    else
    {
        throw logic_error("you doesnt have this city card");
    }
    if(board->cured_desease.find(board->city_colors[current_city])!=board->cured_desease.end())
    {
        board->cities_cubes[current_city]=0;
    }
    return *this;
}
Player& Medic::fly_charter(City city)
{
    if(city==current_city)
    {
        throw logic_error("you are already in this city");
    }
    if(cards.find(current_city)!=cards.end())
    {
        cards.erase(current_city);
        board->not_in_deck.erase(current_city);//return the card to the deck
        current_city=city;        
    }
    else
    {
        throw logic_error("you doesnt have your current city card");
    }
    if(board->cured_desease.find(board->city_colors[current_city])!=board->cured_desease.end())
    {
        board->cities_cubes[current_city]=0;
    }
    return *this;
}
Player& Medic::fly_shuttle(City city)
{
    if(city==current_city)
    {
        throw logic_error("you are already in this city");
    }
    if(board->research_stations.find(current_city)!=board->research_stations.end() &&board->research_stations.find(city)!=board->research_stations.end())
    {
        current_city=city;
    }
    else
    {
        throw logic_error("one of those cities dont have a research station");
    }
    if(board->cured_desease.find(board->city_colors[current_city])!=board->cured_desease.end())
    {
        board->cities_cubes[current_city]=0;
    }
    return *this;
}

Player& Medic::treat(City city)
{
    if(board->cities_cubes[city]==0){//if num of cubes=0
        throw logic_error("this city is already cured");
    }
    if(current_city!=city)
    {
        throw logic_error("the city is not your current city");
    }
    board->cities_cubes[current_city]=0;
    return *this;
}
}