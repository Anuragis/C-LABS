#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();

    long get_value() const;
    static long get_copy_count();
    static long get_destructor_count();
    static void reset();
    /***** Complete this class. *****/
   bool operator <(const Element &ele)const;
   bool operator >(const Element &ele)const;
   friend ostream& operator<< (ostream& out, Element const & e);
//private:
    long value;
    static  long copy_count;
    static  long dest_count;
};

#endif /* DATA_H_ */
