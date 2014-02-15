#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>

 
using namespace std; 


class queue
{
   public:
		virtual bool empty() const = 0;
		//return true if queue is empty
		virtual int size() const = 0;
		//return number of elements in queue
		virtual int* front() = 0;
		//return reference to the front element
		virtual int* back() = 0;
		//return reference to the back element		
		virtual void pop() = 0;
		//remove the front element
		virtual void push(const int& theElement) = 0;
		//insert theElement at the back of the queue
		virtual void printQueue() const = 0;
		
};
#endif
