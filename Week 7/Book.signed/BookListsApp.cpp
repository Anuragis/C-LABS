#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include "BookList.h"
using namespace std;
const string CATEGORIES_FILE_NAME = "categories.txt";
const string MERGED="MERGED";
const string AUTHORS_A_M="AUTHORS A-M";
const string AUTHORS_N_Z="AUTHORS N_Z";
/**
 * The main. Create and print the book lists.
 */
int main()
{
    /***** Complete this main. *****/
   ifstream in;
   vector<BookNode*> bookLists;
   bookLists.reserve(10);
   in.open(CATEGORIES_FILE_NAME);
   string category;
   cout<<endl;
   string prev="";
   while(!in.fail()){
      in>>category;
      if(prev!=category){
      BookList List(category);
      bookLists.push_back(List.getHead());
      }
      prev=category;
     
   }
   BookList mList(MERGED,bookLists);
   BookList a_m(AUTHORS_A_M,mList.getHead(),'A','M');
   BookList n_z(AUTHORS_N_Z,mList.getHead(),'N','Z');
   return 0;
}

/***** Complete this file. *****/
