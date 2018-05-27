#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "SortedVector.h"
#include "Node.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
    /***** Complete this function. *****/
   // vector<Node>::iterator it;
    data.insert(data.begin(),Node(value));
}

void SortedVector::append(const long value)
{
    /***** Complete this function. *****/
   Node val(value);
    data.push_back(val);
}

void SortedVector::remove(const int index)
{
    /***** Complete this function. *****/
    data.erase(data.begin() + index);
}

void SortedVector::insert(const long value)
{
  vector<Node>::iterator it = data.begin();
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

Node SortedVector::at(const int index) const
{
    /***** Complete this function. *****/
    return data[index];
}
