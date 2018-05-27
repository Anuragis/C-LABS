#ifndef BOOKLIST_H_
#define BOOKLIST_H_
#include <string>
#include <vector>
#include "BookNode.h"
using namespace std;
/**
 * A list of book nodes.
 */
class BookList
{
public:
    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name);
    
     /**
     * Constructor.
     * @param name the name of this list.
     * @vec vector containing list of all head nodes of the previously created Linklist
     */
    BookList(const string name, vector<BookNode*>vec);
    /**
     * Constructor.
     * @param name the name of this list.
     * @listHead Head node of merged list
     * @firstLimitingChar initial limiting character for sorting
     * @lastLimitingChar end limiting character for sorting
     */
    BookList(const string name, BookNode* listHead,char firstLimitingChar, char lastLimitingChar);
    
    /** 
    creates individual list by name
    */
    void create();
    
    /**
      creates merged list
      @param bookNode head node of individual list
    */
    void create(BookNode*bookNode);
    
    /**
     creates list sorted by last name within specified chars 
     * @listHead Head node of merged list
     * @firstLimitingChar initial limiting character for sorting
     * @lastLimitingChar end limiting character for sorting
    */
    void create(BookNode*listHead, char firstLimitingChar, char lastLimitingChar);
    /**
     * Print the list.
     */
    void print();
    
   
    /**Get head of current list*/
    BookNode* getHead();
    /***** Complete this class. *****/

private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes
};

#endif /* BOOKLIST_H_ */
