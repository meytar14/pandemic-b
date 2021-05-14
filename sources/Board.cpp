#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace pandemic;
using namespace std;
namespace pandemic
{
    void Board::read_cities()
    {
        ifstream cities_file{"cities_map.txt"};
        string city,neighbor,color;
        City c,n;
        Color col;
        
        for(int i=0;i<48;i++)
        {
            string l;
            getline(cities_file,l,'\n');
            stringstream line(l);
            unordered_set<City> neighbors;
            line>>city>>color;
            c=string_to_city(city);
            col=string_to_color(color);
            city_colors[c]=col;
            cities_cubes[c]=0;
            while(!line.eof())
            {
                line>>neighbor;
                n=string_to_city(neighbor);
                neighbors.insert(n);
            }
            cities_conection[c]=neighbors;
        }
    }
   
    int& Board::operator[](City city)
    {
        return cities_cubes[city];
    }
    ostream& operator<<(ostream& output,const Board& b)
    {
        output<<"the disease level in each city:"<<endl;
        for(auto& it: b.cities_cubes)
        {
             output<<b.city_to_string(it.first)<<" has "<<it.second<<"cubes"<<endl;
        }
        output<<"cured disease:"<<endl;
         for(auto& it: b.cured_desease)
        {
             output<<b.color_to_string(it)<<endl;
        }
        output<<"cities that has a research station:"<<endl;
        for(auto& it: b.research_stations)
        {
             output<<b.city_to_string(it)<<endl;
        }
        return output;
    }
    bool Board::is_clean()
    {
        bool is_clean=true;
        for(auto& it: cities_cubes)
        {
            if(it.second!=0)
            {
                is_clean=false;
            }
        }
        return is_clean;
    }
    void Board::remove_cures()
    {
        cured_desease.clear();
    }
    void Board::remove_stations()
    {
        research_stations.clear();
    }

    Color Board::string_to_color(string color)
    {
        if(color=="Black"){return Color::Black;}
        if(color=="Yellow"){return Color::Yellow;}
        if(color=="Red"){return Color::Red;}
        if(color=="Blue"){return Color::Blue;}
        return Color::Blue;
    }
    string Board::color_to_string(Color color)const
    {
        if(color==Color::Black){return "Black" ;}
        if(color==Color::Yellow){return "Yellow";}
        if(color== Color::Red){return "Red";}
        if(color==Color::Blue){return "Blue";}
        return "Red";
    }

     City Board::string_to_city(string city)
    {
    if(city== "Algiers" ){return City:: Algiers ;}
    if(city== "Atlanta" ){return City:: Atlanta ;}
    if(city== "Baghdad" ){return City:: Baghdad ;}
    if(city== "Bangkok" ){return City:: Bangkok ;}
    if(city== "Beijing" ){return City:: Beijing ;}
    if(city== "Bogota" ){return City:: Bogota ;}
    if(city== "BuenosAires" ){return City:: BuenosAires ;}
    if(city== "Cairo" ){return City:: Cairo ;}
    if(city== "Chennai" ){return City:: Chennai ;}
    if(city== "Chicago" ){return City:: Chicago ;}
    if(city== "Delhi" ){return City:: Delhi ;}
    if(city== "Essen" ){return City:: Essen ;}
    if(city== "HoChiMinhCity" ){return City:: HoChiMinhCity ;}
    if(city== "HongKong" ){return City:: HongKong ;}
    if(city== "Istanbul" ){return City:: Istanbul ;}
    if(city== "Jakarta" ){return City:: Jakarta ;}
    if(city== "Johannesburg" ){return City:: Johannesburg ;}
    if(city== "Karachi" ){return City:: Karachi ;}
    if(city== "Khartoum" ){return City:: Khartoum ;}
    if(city== "Kinshasa" ){return City:: Kinshasa ;}
    if(city== "Kolkata" ){return City:: Kolkata ;}
    if(city== "Lagos" ){return City:: Lagos ;}
    if(city== "Lima" ){return City:: Lima ;}
    if(city== "London" ){return City:: London ;}
    if(city== "LosAngeles" ){return City:: LosAngeles ;}
    if(city== "Madrid" ){return City:: Madrid ;}
    if(city== "Manila" ){return City:: Manila ;}
    if(city== "MexicoCity" ){return City:: MexicoCity ;}
    if(city== "Miami" ){return City:: Miami ;}
    if(city== "Milan" ){return City:: Milan ;}
    if(city== "Montreal" ){return City:: Montreal ;}
    if(city== "Moscow" ){return City:: Moscow ;}
    if(city== "Mumbai" ){return City:: Mumbai ;}
    if(city== "NewYork" ){return City:: NewYork ;}
    if(city== "Osaka" ){return City:: Osaka ;}
    if(city== "Paris" ){return City:: Paris ;}
    if(city== "Riyadh" ){return City:: Riyadh ;}
    if(city== "SanFrancisco" ){return City:: SanFrancisco ;}
    if(city== "Santiago" ){return City:: Santiago ;}
    if(city== "SaoPaulo" ){return City:: SaoPaulo ;}
    if(city== "Seoul" ){return City:: Seoul ;}
    if(city== "Shanghai" ){return City:: Shanghai ;}
    if(city== "StPetersburg" ){return City:: StPetersburg ;}
    if(city== "Sydney" ){return City:: Sydney ;}
    if(city== "Taipei" ){return City:: Taipei ;}
    if(city== "Tehran" ){return City:: Tehran ;}
    if(city== "Tokyo" ){return City:: Tokyo ;}
    if(city== "Washington" ){return City:: Washington ;}
    return City::Algiers;
    }

     string Board::city_to_string(City city) const
    {
        if(city==City:: Algiers ){return " Algiers " ;}
if(city==City:: Atlanta ){return " Atlanta " ;}
if(city==City:: Baghdad ){return " Baghdad " ;}
if(city==City:: Bangkok ){return " Bangkok " ;}
if(city==City:: Beijing ){return " Beijing " ;}
if(city==City:: Bogota ){return " Bogota " ;}
if(city==City:: BuenosAires ){return " BuenosAires " ;}
if(city==City:: Cairo ){return " Cairo " ;}
if(city==City:: Chennai ){return " Chennai " ;}
if(city==City:: Chicago ){return " Chicago " ;}
if(city==City:: Delhi ){return " Delhi " ;}
if(city==City:: Essen ){return " Essen " ;}
if(city==City:: HoChiMinhCity ){return " HoChiMinhCity " ;}
if(city==City:: HongKong ){return " HongKong " ;}
if(city==City:: Istanbul ){return " Istanbul " ;}
if(city==City:: Jakarta ){return " Jakarta " ;}
if(city==City:: Johannesburg ){return " Johannesburg " ;}
if(city==City:: Karachi ){return " Karachi " ;}
if(city==City:: Khartoum ){return " Khartoum " ;}
if(city==City:: Kinshasa ){return " Kinshasa " ;}
if(city==City:: Kolkata ){return " Kolkata " ;}
if(city==City:: Lagos ){return " Lagos " ;}
if(city==City:: Lima ){return " Lima " ;}
if(city==City:: London ){return " London " ;}
if(city==City:: LosAngeles ){return " LosAngeles " ;}
if(city==City:: Madrid ){return " Madrid " ;}
if(city==City:: Manila ){return " Manila " ;}
if(city==City:: MexicoCity ){return " MexicoCity " ;}
if(city==City:: Miami ){return " Miami " ;}
if(city==City:: Milan ){return " Milan " ;}
if(city==City:: Montreal ){return " Montreal " ;}
if(city==City:: Moscow ){return " Moscow " ;}
if(city==City:: Mumbai ){return " Mumbai " ;}
if(city==City:: NewYork ){return " NewYork " ;}
if(city==City:: Osaka ){return " Osaka " ;}
if(city==City:: Paris ){return " Paris " ;}
if(city==City:: Riyadh ){return " Riyadh " ;}
if(city==City:: SanFrancisco ){return " SanFrancisco " ;}
if(city==City:: Santiago ){return " Santiago " ;}
if(city==City:: SaoPaulo ){return " SaoPaulo " ;}
if(city==City:: Seoul ){return " Seoul " ;}
if(city==City:: Shanghai ){return " Shanghai " ;}
if(city==City:: StPetersburg ){return " StPetersburg " ;}
if(city==City:: Sydney ){return " Sydney " ;}
if(city==City:: Taipei ){return " Taipei " ;}
if(city==City:: Tehran ){return " Tehran " ;}
if(city==City:: Tokyo ){return " Tokyo " ;}
if(city==City:: Washington ){return " Washington " ;}
return "Shanghai";
    }

}
