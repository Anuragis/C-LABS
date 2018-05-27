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
    BookList(const string name, vector<BookNode*>vec);
    BookList(const string name, BookNode* listHead,char firstLimitingChar, char lastLimitingChar);
    void create();
    void create(BookNode*);
    void create(BookNode*listHead, char firstLimitingChar, char lastLimitingChar);
    /**
     * Print the list.
     */
    void print();
    
   
    
    BookNode* getHead();
    /***** Complete this class. *****/

private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes
};

#endif /* BOOKLIST_H_ */
