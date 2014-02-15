#ifndef DCQ_H
#define DCQ_H


#include <iostream>
#include "chain.h"
#include "queue.h"
 
using namespace std; 


class derivedChainQueue : private chain, public queue
{
   public:
		derivedChainQueue(int initialCapacity = 100) : chain(initialCapacity){}
		bool empty() const
		{
			return chain :: empty();
		}
		int size() const
		{
			return chain :: size();
		
		}
		
		void printQueue() const
		{
			cout<<endl;
			for(int i=0;i<chain :: size();i++)
				cout << *get(i) << " " ;
			cout<<endl;
		}
		
		int* front();
		int* back();
		void pop();
		void push(const int& theElement);
		
		
		
};
#endif
