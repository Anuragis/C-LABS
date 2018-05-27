#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

/** Complete this file. **/

using namespace std;

WordVector::WordVector()
{
    /** Complete this member function. **/
    //data.reserve(10000);
}

WordVector::~WordVector()
{
    /** Complete this member function. **/
    data.reserve(1200);
}

Word *WordVector::insert(const string text)
{
    /** Complete this member function. **/
    vector<Word>::iterator it = data.begin();
    int index = 0;
    while (index < data.size()) {
       if(it->get_text()>text) {
            data.insert(it, Word(text));
            return &(*it);
       } else if(it->get_text()==text) {
          it->countPlusPlus();
          break;
       }
       index++;it++;
    }
    if(it == data.end()) {
      data.push_back(Word(text));
    }
    return &(*it);
}

Word *WordVector::search(const string text)
{
    /** Complete this member function. **/
    int low=0, high=data.size()-1, mid;
    while(low<=high) {
       mid = (low+high)/2;
       if(data[mid].get_text()==text) {
          return &data[mid];
       } else if(data[mid].get_text()<text) {
          low = mid+1;
       } else {
          high = mid-1;
       }
    }
    return nullptr;
}

int WordVector::get_size() {
   return data.size();
}

vector<Word> WordVector::get_data() {
   return data;
}