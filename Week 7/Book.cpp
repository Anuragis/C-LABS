#include "Book.h"
#include <string>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;
/***** Complete this file. *****/
Book::Book():isbn(""),last(""), first(""), title(""){}

Book::Book(string isbn, string last, string first, string title){
   this->isbn=isbn;
   this->last=last;
   this->first=first;
   this->title=title;
}

istream& operator >>(istream&  inp, Book &book){
   string ln;
   getline(inp,ln);
   istringstream in(ln);
   
   string isbn;
   getline(in,isbn,',');
   book.isbn=isbn;
   
   string last;
   getline(in,last,',');
   book.last=last;
   
   string first;
   getline(in,first,',');
   book.first=first;
   
   string title;
   getline(in,title,',');
   book.title=title;
return inp;
}

ostream& operator <<(ostream&  out, Book &book){
   out<< "Book{ISBN="<<book.isbn<<", last="<<book.last<<", first="<<book.first<<", title="<<book.title<<"}"<<endl;

   return out;
}
Book:: ~Book(){
}

string Book::getIsbn(){
      return isbn;
}
   
string Book::getLast(){
   return last;
}
string Book::getFirst(){
   return first;
}
string Book::getTitle(){
   return title;
}