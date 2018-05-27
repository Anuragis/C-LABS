#include<string>
#include<iostream>
#include<fstream>
#include "BookList.h"
using namespace std;
const string CATEGORIES_FILE_NAME = "categories.txt";

/**
 * The main. Create and print the book lists.
 */
int main()
{
    /***** Complete this main. *****/
   ifstream in;
   in.open(CATEGORIES_FILE_NAME);
   string category;
   cout<<endl;
   string prev="";
   while(!in.fail()){
      in>>category;
      if(prev!=category){
      BookList List(category);
      }
      prev=category;
      cout <<endl;
   }
   
   
   
   return 0;
}

/***** Complete this file. *****/
