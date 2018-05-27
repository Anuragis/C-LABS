#include "Book.h"
#include <string>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;
/***** Complete this file. *****/
Book::Book():isbn(""),last(""), first(""), title(""), category(Category::NONE){}

Book::Book(string isbn, string last, string first, string title, Category category){
   this->isbn=isbn;
   this->last=last;
   this->first=first;
   this->title=title;
   this->category=category;
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
   
   string cat;
   getline(in,cat,',');
   book.setCategory(cat);
   inp>>ws;
return inp;
}

ostream& operator <<(ostream&  out, Book &book){
   out<< "Book{ISBN="<<book.isbn<<", last="<<book.last<<", first="<<book.first<<", title="<<book.title<<", category="<<book.getCategory()<<"}"<<endl;

   return out;
}
Book:: ~Book(){
}

void Book::setCategory(string &input){

   if(input == "technical")
   {
      category= Category::TECHNICAL;
   }
   if(input == "fiction"){
      category= Category::FICTION;
   }
   if(input == "history"){
      category= Category::HISTORY;
   }
   if(input == "none")
   {
      category= Category::NONE;
   }
}

string Book::getCategory(){
   if(category == Category::TECHNICAL){return "technical";}
   if(category == Category::FICTION){return "fiction";}
   if(category == Category::HISTORY){return "history";}
   if(category == Category::NONE){
      return "none";
   }
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