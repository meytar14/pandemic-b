#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "City.hpp"
#include "Color.hpp"
using namespace std;
namespace pandemic
{
class Board
{


public:
    Color string_to_color(string color);
    string city_to_string(City city) const;
    string color_to_string(Color color)const;
    void read_cities();
    City string_to_city(string city);
    unordered_map<City,Color>city_colors;
    unordered_map<City,unordered_set<City>> cities_conection;
    
    unordered_map<City,int> cities_cubes;
    unordered_set<City> research_stations;
    unordered_set<City> cured_cities;
    unordered_set<City> not_in_deck;
    unordered_set<Color> cured_desease;
    
     Board()
     {
       read_cities();
     }
    ~ Board()
    {

    }

    int& operator[](City city);
    friend std::ostream& operator<<(ostream& output,const Board& b);
    bool is_clean();
    void remove_cures();
    void remove_stations();


    

};


}
