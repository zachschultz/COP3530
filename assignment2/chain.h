#ifndef CHAIN_H
#define CHAIN_H


#include <iostream>
#include "linearList.h"
#include "chainNode.h"
 
using namespace std; 


class chain : public linearList
{
   public:
	  //constructor, copy constructor and destructor
	  chain(int initialCapacity = 100);
	  ~chain();
	  
      bool empty() const {return listSize == 0;}
      int size() const {return listSize;}
      int* get(int theIndex) const;
    
      chainNode* getNode(const int theIndex);
      int indexOf(const int& theElement)const;
      void erase(int theIndex);
      void insert(int theIndex, const int& theElement);
	
      void output() const;
	  
	  //You can implement any additional helper methods required for the following four methods.
	  
	
	  //you have to implement the following four methods 
	  void readAndStoreFromFile(char* fileName);
	  void eraseModuloValue(int theInt);
	  void oddAndEvenOrdering();
	  void reverse();
	  
	protected:
		void checkIndex(int theIndex) const;
				//throw illegalIndex if theIndex is invalid
		chainNode* firstNode; //pointer to the first node in chain
		int listSize;         // number of elements in list
		
};
#endif
