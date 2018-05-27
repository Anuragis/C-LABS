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
/* Get ISBN */   
string getIsbn();

/** Get Author */
string getAuthor();

/** Get Last */
string getLast();

/** Get First */
string getFirst();

/** Get Title */
string getTitle();

/** Overloaded >> operator */
friend istream& operator>>(istream&  in, Book &book);

/** Overloaded << operator */
friend ostream& operator <<(ostream&  out, Book &book);

private:
    string isbn; //ISBN of book 
    string last; // Last name of Author of book
    string first;//First name of Author of book
    string title;// Title of book
    /***** Complete the private members. *****/
};

#endif /* EMPLOYEE_H_ */
