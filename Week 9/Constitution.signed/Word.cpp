#include <string>
#include "Word.h"
using namespace std;

/***** Modify this file as needed. *****/

Word::Word() : text(""), count(0) {}
Word::Word(string text) : text(text), count(1) {}

Word::~Word() {}

int Word::get_count(){
   return count;
}

bool operator !=(Word &first,Word &other){
   return first.text!=other.text;
}

string Word::get_text(){
   return this->text;
}

void Word::countPlusPlus(){
   this->count++;
}