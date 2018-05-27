#include <iostream>
#include <map>
#include "WordMap.h"

/***** Complete this file. *****/

using namespace std;

WordMap::WordMap()
{
    /***** Complete this member function. *****/
}

WordMap::~WordMap()
{
    /***** Complete this member function. *****/
}

Word *WordMap::insert(const string text)
{
    /***** Complete this member function. *****/
    map<string, Word>::iterator it = data.find(text);
    if (it != data.end()){
    data.at(text).countPlusPlus();
   }else{
      Word word(text);
      data.insert(it,std::make_pair(text, word));
   }
   
   return &it->second;
}

Word *WordMap::search(const string text)
{
    /***** Complete this member function. *****/
    map<string, Word>::iterator it = data.find(text);
    
    if(it ==data.end()){
       return nullptr;
    }
    return &it->second;
}

int WordMap::get_size(){
   return data.size();
}

map<string, Word>& WordMap::get_data(){
   return data;
}