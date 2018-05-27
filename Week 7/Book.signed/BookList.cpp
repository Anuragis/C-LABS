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

BookList::BookList(const string name, vector<BookNode*>vec)
      : name(name), head(nullptr), tail(nullptr)
{
   for(int i=0;i<vec.size();i++){
      create(vec[i]);
   }
   print();
}

BookList::BookList(const string name, BookNode* listHead,char firstLimitingChar, char lastLimitingChar)
      : name(name), head(nullptr), tail(nullptr){
         create(listHead, firstLimitingChar, lastLimitingChar);
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
   cout<<endl;
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
      catFile.close();
      print();
      
}
void BookList::create(BookNode*listHeader){
   while(listHeader!=nullptr){
         BookNode *previous=nullptr;
         BookNode *current=head;
         bool isDuplicate=false;
         BookNode *b=new BookNode(listHeader->book);
        while (current != nullptr && listHeader->book.getIsbn() >= current->book.getIsbn()) {
            previous = current;
            current = current->next;
            if(listHeader->book.getIsbn() == previous->book.getIsbn()){
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
      listHeader=listHeader->next;
   }
}
void BookList::create(BookNode*listHeader, char firstLimitingChar, char lastLimitingChar){
    while(listHeader!=nullptr){
         if(listHeader->book.getLast()[0]>=firstLimitingChar && listHeader->book.getLast()[0]<=lastLimitingChar)
         {
         BookNode *b=new BookNode(listHeader->book);
         if(head==nullptr){
           head=b;
           tail=b;
         }
         else{
              tail->next=b;
               tail=b;
            }
         }
      listHeader=listHeader->next;
   }
   print();
}
BookNode* BookList::getHead(){
   return this->head;
}
/***** Complete this file. *****/
