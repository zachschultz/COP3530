#ifndef LINEARLIST_H
#define LINEARLIST_H


#include <iostream>

 
using namespace std; 


class linearList 
{
   public:
      virtual ~linearList() {};
      virtual bool empty() const = 0;
      virtual int size() const = 0;
      virtual int* get(int theIndex) const = 0;
      virtual int indexOf(const int& theElement)const = 0;
      virtual void erase(int theIndex) = 0;
      virtual void insert(int theIndex, const int& theElement) = 0;
	
      virtual void output() const = 0;
};
#endif
