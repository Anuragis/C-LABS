#ifndef BOOKLIST_H_
#define BOOKLIST_H_
#include <string>
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
    
    void create();
    /**
     * Print the list.
     */
    void print();
    
    /***** Complete this class. *****/

private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes
};

#endif /* BOOKLIST_H_ */
