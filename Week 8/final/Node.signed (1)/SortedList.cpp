#include <iostream>
#include <iterator>
#include "SortedList.h"
#include "Node.h"
#include <vector>
#include <algorithm>
using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
    /***** Complete this function. *****/
    list<Node>::iterator it;
    it=data.begin();
    
    data.insert(it,Node(value));
}

void SortedList::append(const long value)
{
    /***** Complete this function. *****/
    Node val(value);
    data.push_back(val);
}

void SortedList::remove(const int index)
{
    /***** Complete this function. *****/
   list<Node>::iterator it=data.begin();
   if (data.size() > index)
   {
    std::advance(it, index);
   }
   it=data.erase(it);
}

void SortedList::insert(const long value)
{
   
	list<Node>::iterator it = data.begin();
    Node val(value);
    int index = 0;
    while (index < data.size()) {
       if((*it).get_value()>value) {
            data.insert(it, val);
            return;
       }
       index++;it++;
    }
    if(it == data.end()) {
      data.push_back(val);
    }

}

Node SortedList::at(const int index)
{
    /***** Complete this function. *****/
   list<Node>::iterator it=data.begin();
   if (data.size() > index)
   {
    std::advance(it, index);
    // 'it' points to the element at index 'N'
   }
    return *it;
}
