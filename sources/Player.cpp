#include "Player.hpp"
using namespace pandemic;
namespace pandemic
{
Player& Player::drive(City city)
{
    if(city==current_city)
    {
        throw logic_error("you are already in this city");
    }
    if(board.cities_conection[current_city].find(city)!=board.cities_conection[current_city].end())
    {
        current_city=city;
    }
    else
    {
        throw logic_error("this cities arent connected");
    }
    return *this;
}
Player& Player::fly_direct(City city)
{
    if(city==current_city)
    {
        throw logic_error("you are already in this city");
    }
    if(cards.find(city)!=cards.end())
    {
        current_city=city;
        cards.erase(city);
        board.not_in_deck.erase(city);//return the card to the deck
    }
    else
    {
        throw logic_error("you doesnt have this city card");
    }
    return *this;
}
Player& Player::fly_charter(City city)
{
    if(city==current_city)
    {
        throw logic_error("you are already in this city");
    }
    if(cards.find(current_city)!=cards.end())
    {
        current_city=city;
        cards.erase(current_city);
        board.not_in_deck.erase(current_city);//return the card to the deck
    }
    else
    {
        throw logic_error("you doesnt have your current city card");
    }
    return *this;
}
Player& Player::fly_shuttle(City city)
{
    if(city==current_city)
    {
        throw logic_error("you are already in this city");
    }
    if(board.research_stations.find(current_city)!=board.research_stations.end() &&board.research_stations.find(city)!=board.research_stations.end())
    {
        current_city=city;
    }
    else
    {
        throw logic_error("one of those cities dont have a research station");
    }
    return *this;
}
Player& Player::build()
{
    if(board.research_stations.find(current_city)==board.research_stations.end() && cards.find(current_city)!=cards.end())
    {
        board.research_stations.insert(current_city);
        cards.erase(current_city);
        board.not_in_deck.erase(current_city);//return the card to the deck
    }else if(board.research_stations.find(current_city)==board.research_stations.end())
    {
        throw logic_error("you dont have this city card");
    }
    return *this;
}
Player& Player::discover_cure(Color color)
{
    if(board.research_stations.find(current_city)!=board.research_stations.end())
    {
        unordered_set<City>::iterator it;
        unordered_set<City> temp;
        bool is_five=false;
        if(board.cured_desease.find(color)!=board.cured_desease.end())
        {
            return *this;
        }
        for(auto& elm: cards)
        {
            if(board.city_colors[elm]==color)
            {
                temp.insert(elm);
            }
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
        else{
            throw logic_error("you dont have 5 cards");
        }
    }
    return *this;
}
Player& Player::remove_cards()
{
    cards.clear();
    return *this;
}
Player& Player::treat(City city)
{
    if(current_city!=city)
    {
        throw logic_error("the city is not your current city");
    }
    if(board.cured_cities.find(city)!=board.cured_cities.end()){//if num of cubes=0
        throw logic_error("this city is already cured");
    }
    if(board.cured_desease.find(board.city_colors[current_city])!=board.cured_desease.end())
    {
        board.cities_cubes[current_city]=0;
    }
    else if(board.cities_cubes[current_city]>0)
    {
        board.cities_cubes[current_city]=board.cities_cubes[current_city]-1;
    }
    if(board.cities_cubes[city]==0){//if num of cubes=0
        board.cured_cities.insert(current_city);
    }
    return *this;
}
string Player::role()
{
    return this->role_;
}
Player& Player::take_card(City city)
{
    if(board.not_in_deck.find(city)==board.not_in_deck.end())
    {
    cards.insert(city);
    board.not_in_deck.insert(city);
    }
    return *this;
}


}