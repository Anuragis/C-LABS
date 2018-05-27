#include "BookList.h"
#include "Book.h"
#include "BookNode.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
BookList::BookList( string name)
    : name(name), head(nullptr), tail(nullptr)
{
    create();
}

void BookList::print()
{
   int book_count=0;
   cout<<"Book list: "+name<<endl;
   cout<<endl;
   BookNode *itr;
   itr=head;
   while(itr!=nullptr){
      cout<<itr->book;
      itr=itr->next;
      book_count++;
   }
   cout<<" ("<<book_count<<" books)"<<endl;
    /***** Complete this function. *****/
}

void BookList::create(){
      ifstream catFile;
      catFile.open(this->name+".txt");
      Book book;
      while(!catFile.fail()){
         catFile>>book;
       
         BookNode *b=new BookNode(book);
      if(book.getIsbn()!=""){
         BookNode *previous=nullptr;
         BookNode *current=head;
         bool isDuplicate=false;
        while (current != nullptr && book.getIsbn() >= current->book.getIsbn()) {
            previous = current;
            current = current->next;
            if(book.getIsbn() == previous->book.getIsbn()){
               isDuplicate=true;
            }
        }
         if(previous==nullptr && !isDuplicate){
            b->next = head;
            head=b;
         }
         else{
            if(!isDuplicate){
               b->next = current;
               previous->next = b;}
            }
         }
      }
      print();
      catFile.close();
}
/***** Complete this file. *****/
