#ifndef BOOK_H_
#define BOOK_H_
#include <string>
using namespace std;

/***** Complete this file. *****/

/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title);

    /**
     * Destructor.
     */
    ~Book();
    
    /***** Complete the public members. *****/
string getIsbn();
string getAuthor();
string getLast();
string getFirst();
string getTitle();
friend istream& operator>>(istream&  in, Book &book);
friend ostream& operator <<(ostream&  out, Book &book);

private:
    string isbn;
    string last;
    string first;
    string title;
    /***** Complete the private members. *****/
};

#endif /* EMPLOYEE_H_ */
