#ifndef DCS_H
#define DCS_H


#include <iostream>
#include "chain.h"
#include "stack.h"
 
using namespace std; 


class derivedChainStack : private chain, public stack
{
   public:
		~derivedChainStack(){};
		derivedChainStack(int initialCapacity = 100) : chain(initialCapacity){}
		bool empty() const
		{
			return chain :: empty();
		}
		int size() const
		{
			return chain :: size();
		
		}
		void printStack() const
		{
			cout<<endl;
			for(int i=chain :: size() - 1; i >= 0;i--)
				cout << *get(i) << " " ;
			cout<<endl;
		}
		int * top();
		void pop();
		void push(const int& theElement);
		
		
		
};
#endif
