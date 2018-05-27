#include "Node.h"
#include "Element.h"

/***** Complete this class. *****/
Node::Node(){
   element.value=0;
   this->next=nullptr;
}
Node::Node(Element ele){
   this->element.value=ele.value;
   this->next=nullptr;
}

Node::Node(Element &ele){
   this->element.value=ele.value;
   this->next=nullptr;
}