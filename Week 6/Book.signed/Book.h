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
     * Book categories.
     */
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, Category category);

    /**
     * Destructor.
     */
    ~Book();
    
    /***** Complete the public members. *****/
void setCategory(string& input);
string getIsbn();
string getCategory();
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
    Category category;
    /***** Complete the private members. *****/
};

#endif /* EMPLOYEE_H_ */
