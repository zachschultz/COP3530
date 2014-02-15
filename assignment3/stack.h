#ifndef STACK_H
#define STACK_H


#include <iostream>

 
using namespace std; 


class stack
{
   public:
		virtual bool empty() const = 0;
		//return true if stack is empty
		virtual int size() const = 0;
		//return number of elements in stack
		virtual int* top() = 0;
		//return reference to the top element
		virtual void pop() = 0;
		//remove the top element
		virtual void push(const int& theElement) = 0;
		//insert theElement at the top of the stack
		virtual void printStack() const = 0;
		
};
#endif
