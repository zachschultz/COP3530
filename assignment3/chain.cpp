#include <iostream>
#include <sstream>
#include "Myexception.h"
#include "chain.h"


using namespace std;


chain :: chain(int initialCapacity)
{
	//Constructor
	if(initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	
	firstNode = NULL;
	listSize = 0;

}


chain :: ~chain()
{
	//Destructor. Delete all nodes in chain
	
	while(firstNode != NULL)
	{
		//delete firstNode
		chainNode* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	
	}
	
}

int* chain :: get(int theIndex) const
{
	//Return element whose index is theIndex.
	//Throw illegalIndex exception if no such element.
	try{
		checkIndex(theIndex);
	}
	catch(illegalIndex &e){
		e.outputMessage();
		return NULL;
	}
	
	chainNode* currentNode = firstNode;
	for(int i=0;i<theIndex;i++)
		currentNode = currentNode->next;
	
	return &currentNode->element;


}


int chain :: indexOf(const int& theElement) const
{
	//Return index of first occurrence of theElement.
	//Return -1 of theElement not in list.
	
	
	chainNode* currentNode = firstNode;
	int index = 0;
	while(currentNode != NULL && currentNode->element != theElement)
	{
		//move to the next node
		currentNode = currentNode->next;
		index++;
	
	}
	
	
	//make sure we found matching element
	if(currentNode == NULL)
		return -1;

	else
		return index;

}


void chain :: erase(int theIndex)
{
	//Delete the element whose index is theIndex.
	//Throw illegalIndex exception if no such element.
	
	try{
		checkIndex(theIndex);
	}
	catch(illegalIndex &e){
		e.outputMessage();
		return;
	}
	
	chainNode* deleteNode;
	if(theIndex == 0)
	{
		//remove first node from chain
		deleteNode = firstNode;
		firstNode = firstNode->next;

	}
	else
	{
		//use p to get to predecessor of desired node
		chainNode* p = firstNode;
		for(int i=0;i<theIndex-1;i++)
			p = p->next;
			
		deleteNode = p->next;
		p->next = p->next->next; //remove deleteNode from chain
	
	}

	listSize--;
	delete deleteNode;


}

void chain :: insert(int theIndex, const int& theElement)
{
	//Insert theElement so that its index is theIndex.
	try{
   		if (theIndex < 0 || theIndex > listSize)
   		{// invalid index
    		
			ostringstream s;
    			s << "index = " << theIndex << " size = " << listSize;
    			throw illegalIndex(s.str());
		}
	}
	catch(illegalIndex &e){
		e.outputMessage();
		return;
	}
	
	if(theIndex == 0)
		//insert at front
		firstNode = new chainNode(theElement, firstNode);
	else
	{
		chainNode *p = firstNode;
		for(int i=0;i<theIndex-1;i++)
			p = p->next;
	
		//insert after p
		p->next = new chainNode(theElement, p->next);
	
	
	}

	listSize++;

}


void chain :: output() const
{
	//Put the list into the output.

	for(int i=0;i<listSize;i++)
		cout << *this->get(i) << " ";
	cout<<endl;

}




void chain::checkIndex(int theIndex) const
{
// Verify that theIndex is between 0 and 
 // listSize - 1.

   	if (theIndex < 0 || theIndex >= listSize){
		ostringstream s;
    		s << "index = " << theIndex << " size = " 
                    << listSize<<", the input index is invalid";
    		throw illegalIndex(s.str());
	}
 
}
