#include <iostream>
#include <stdlib.h>
#include "derivedChainStack.h"
 
using namespace std; 


int* derivedChainStack :: top()
{
	if(chain :: size() == 0)
	{
		cout << "Stack is Empty " <<endl;
		exit(0);
	}
	else
		return get(0);
   
}

void derivedChainStack :: pop()
{
	if(chain :: size() == 0)
	{
		cout << "Stack is Empty " <<endl;
		exit(0);
	}
	erase(0);

}

void derivedChainStack :: push(const int& theElement)
{
	insert(0, theElement);

}
