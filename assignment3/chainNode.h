#ifndef CHAINNODE_H
#define CHAINNODE_H


#include <iostream>

 
using namespace std; 


struct chainNode 
{
   //data members
   int element;
   chainNode *next;
   
   //methods
   chainNode(){}
   chainNode(const int& element){
		this->element = element;
	}
	chainNode(const int& element, chainNode *next){
		this->element = element;
		this->next = next;
	}

};
#endif
