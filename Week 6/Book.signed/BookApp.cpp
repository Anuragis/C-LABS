#include "Book.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
/***** Complete this file. *****/

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
void findISBN(vector<Book>& catalog,string const &isbn);
 void insert(vector<Book>& catalog,Book book);
 void display(vector<Book>& catalog);
 void findAuthor(vector<Book>& catalog, string const&author);
 void findCategory(vector<Book>& catalog, string const&category);
 void remove(vector<Book>& catalog,string const&isbn);
const string INPUT_FILE_NAME = "commands.in";

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    vector<Book> catalog;  // book catalog

   char command;
    input >> command;  // read the first command

    /**
     * Loop to read commands until the end of file.
     */
    Book book;
    while (!input.fail())
    {
       cout<< endl << command <<" ";
       if(command=='+'){
            input>>ws>>book;
            insert(catalog,book);
       }else if(command=='?'){
          //display(catalog);
          string s;
          getline(input, s);
          if(s.length()==0){
             display(catalog);
          }else{
            istringstream in(s);
            getline(in, s,'=');
            if(s.substr(1)=="author"){
                getline(in, s,'=');
               findAuthor(catalog,s);
            }else if(s.substr(1)=="category"){
               getline(in, s,'=');
               findCategory(catalog, s);
            }else if(s.substr(1)=="isbn"){
               getline(in, s,'=');
               findISBN(catalog,s);
            }
          }
       }else if(command=='-'){
          string r;
          getline(input,r);
          remove(catalog,r.substr(1));
       }else{
          string invalid;
          cout<<"*** Invalid command ***"<<endl;
          getline(input,invalid);
       }
        /*** Complete this main. *****/
        input>>command;
    }

    return 0;
}
 void insert(vector<Book>& catalog,Book book){
                if(catalog.size()==0){
               catalog.push_back(book);
               cout<<"Inserted at index 0: "<<book;   
            }else{
               bool isInserted=false;
               int i;
               for(i=0;i<catalog.size();i++){
                  
                  if(catalog[i].getIsbn()==book.getIsbn()){
                     cout<<"Inserted at index "<<i<<": "<<book;
                     cout<<"*** Duplicate ISDN ***"<<endl;
                     isInserted=true;
                     break;
                  }
                  if(catalog[i].getIsbn()>book.getIsbn()){
                     catalog.insert(catalog.begin() + i, book);
                     cout<<"Inserted at index "<<i<<": "<<book;
                     isInserted=true;
                     break;
                  }
                  
               }
               if(!isInserted){
                     catalog.push_back(book);
                     cout<<"Inserted at index "<<i<<": "<<book;
                  }
            }
 }
 void remove(vector<Book>& catalog,string const&isbn)
 {
    int low=0;
    int mid;
    int high=catalog.size()-1;
    bool found=false;
    
    while(low<high){
       mid=(low+high)/2;
       if(catalog[mid].getIsbn()==isbn){
          found=true;
          break;
       }else if(catalog[mid].getIsbn()>isbn){
          high=mid-1;
       }else{
          low=mid+1;
       }
    }
    
    if(!found){
       cout<<"Removed Book{ISBN="<<isbn<<", last=, first=, title=, category=none}"<<endl;
       cout<<"*** Book not found ***"<<endl;
    }else{
       cout<<"Removed "<<catalog[mid];
       catalog.erase(catalog.begin()+mid);
    }
 }
 void display(vector<Book>& catalog){
    cout<<" All books in the catalog:"<<endl;
    for(int i=0;i<catalog.size();i++){
       cout<<catalog[i];
       }
   }
 
 void findAuthor(vector<Book>& catalog, string const&author){
    cout<<"Books by author "<<author<<":"<<endl;
        for(int i=0;i<catalog.size();i++){
           if(catalog[i].getLast()==author){
            cout<<catalog[i];
           }
       }
 }

 void findCategory(vector<Book>& catalog, string const&category){
    cout<<"Books in category "<<category<<":"<<endl;
        for(int i=0;i<catalog.size();i++){
           if(catalog[i].getCategory()==category){
            cout<<catalog[i];
           }
       }
 }
 
 void findISBN(vector<Book>& catalog,string const &isbn){
    
    int low=0;
    int mid;
    int high=catalog.size()-1;
    cout<<"Book with ISBN "<<isbn<<":"<<endl;
    while(low<high){
       mid=(low+high)/2;
       if(catalog[mid].getIsbn()==isbn){
          cout<<catalog[mid];
          break;
       }else if(catalog[mid].getIsbn()>isbn){
          high=mid-1;
       }else{
          low=mid+1;
       }
    }
 }
