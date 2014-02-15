#include <iostream>
#include <stdlib.h>
#include "derivedChainQueue.h"
 
using namespace std; 


int* derivedChainQueue :: front()
{
	if(chain :: size() == 0)
	{
		cout << "Queue is Empty " <<endl;
		exit(0);
	}
	else
		return get(0);
   
}

int* derivedChainQueue :: back()
{
	if(chain :: size() == 0)
	{
		cout << "Queue is Empty " <<endl;
		exit(0);
	}
	else
		return get(chain :: size() - 1);
   
}



void derivedChainQueue :: pop()
{
	if(chain :: size() == 0)
	{
		cout << "Queue is Empty " <<endl;
		exit(0);
	}
	erase(0);

}

void derivedChainQueue :: push(const int& theElement)
{


	insert(chain :: size() , theElement);

}
