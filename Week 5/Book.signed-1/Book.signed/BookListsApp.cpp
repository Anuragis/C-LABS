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
   vector<BookNode*> bookLists;// vector for storing heads of each list
   bookLists.reserve(10);
   in.open(CATEGORIES_FILE_NAME);
   string category;// category name
   cout<<endl;
   
   string prev="";// check duplicate category
   while(!in.fail()){
      in>>category;
      //Create list for each names in the file
      if(prev!=category){
         BookList List(category);
         bookLists.push_back(List.getHead());
      }
         prev=category;
   }
   
   BookList mList(MERGED,bookLists);// create merged list
   BookList a_m(AUTHORS_A_M,mList.getHead(),'A','M');//create list with last names between A and M
   BookList n_z(AUTHORS_N_Z,mList.getHead(),'N','Z');// create list with first names between N and Z
   return 0;
}

/***** Complete this file. *****/
