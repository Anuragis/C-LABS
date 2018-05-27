#include <iostream>
#include "Element.h"

using namespace std;

/***** Complete this class. *****/
long Element::copy_count=0;
long Element::dest_count=0; 
/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
 

Element::Element(const Element& other)
{
    /***** Complete this class. *****/
    this->value=other.value;
    copy_count++;
    
}

/**
 * Destructor.
 */
Element::~Element()
{
    /***** Complete this class. *****/
    dest_count++;
}

void Element::reset(){
   copy_count=0;
   dest_count=0;
}
/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

long Element::get_copy_count(){
   return copy_count;
}

long Element::get_destructor_count(){
   return dest_count;
}

bool Element::operator <(const Element &ele)const{
   return(this->value<ele.value);
}

bool Element::operator >(const Element &ele)const{
   return(this->value>ele.value);
}

ostream& operator<< (ostream& out, Element const & e){
       cout << e.value;
       return out;
    }