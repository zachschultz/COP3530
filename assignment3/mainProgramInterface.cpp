#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "mainProgramInterface.h"
#include "derivedChainStack.h"
#include "derivedChainQueue.h"
 
using namespace std; 

bool mainProgramInterface :: checkPalindrome(long theNumber)
{
	//Write your code here. This method returns true if theNumber is a Palindrome number 
	//else returns false.
	stringstream s;
	s << theNumber;
	string numStr;
	s >> numStr;
	int numLength = numStr.length();
	
	//create integer arrays that will eventually populate stack
	int *numArrayBefore = new int[numLength];
	int *numArrayAfter = new int[numLength];
	//insert into integer array each digit
	for (int i = 0; i < numLength; i++) 
	{
		numArrayBefore[i] = numStr[i] - '0';
	}
	//create stack
	derivedChainStack *myStack = new derivedChainStack(numLength);
	for (int i = 0; i < numLength; i++)
	{
		myStack->push(numArrayBefore[i]);
	}
	
	//populate second array while testing palindrome
	for (int i = 0; i < numLength; i++) 
	{
		numArrayAfter[i] = *myStack->top();
		if (numArrayBefore[i] != numArrayAfter[i])
			return false;
		myStack->pop();
	}
	
	return true;

} 

bool mainProgramInterface :: validSequence(int *theSequence, int n)
{
	//Write your code here. This method returns true if the Input Sequence is valid 
	//else returns false.
	int size = n;
	int fiveCount = 0;
	int tenCount = 0;
	derivedChainQueue *myQueue = new derivedChainQueue(size);
	for (int i = 0; i < size; i++)
	{
		if (theSequence[i] == 5)
		{
			fiveCount++;
		}
		else{
			fiveCount--;
			if (fiveCount < 0)
				return false;
		}
		myQueue->push(theSequence[i]);
	}

	return true;
		 
}

void mainProgramInterface :: duplicateStack(derivedChainStack* source, derivedChainStack* dest)
{
	//Write your code here. This method copies content of source stack to
	//the destination stack. The content should be exactly same.
	int size = source->size();

	int *tempStackHolder = new int[size];
	derivedChainStack *temp1 = new derivedChainStack(size);

	//copy elements into temp1 stack
	for (int i = 0; i < size; i++)
	{
		int test = *source->top();
		tempStackHolder[i] = test;
		temp1->push(test);
		source->pop();
	}

	//repopulate source, as it was deleted through pop
	for (int i = size-1; i >= 0; i--)
	{
		source->push(tempStackHolder[i]);
	}
	
	//copy from temp1 stack into the dest stack
	for (int i = 0; i < size; i++)
	{
		dest->push(*temp1->top());
		temp1->pop();
	}
	
	
	
}

int mainProgramInterface :: lastCutomer(int m, int n)
{
	//Write your code here. Returns the index of the last customer within m customers. 
	derivedChainQueue *customerQueue = new derivedChainQueue(m);
	int *tempQueueHolder = new int[m];
	for (int i = 1 ; i <= m; i ++)
	{
		customerQueue->push(i);
	}
	while (customerQueue->size() > 1)
	{
		for (int i = 0; i < n; i++)
		{
			tempQueueHolder[i] = *customerQueue->front();
			customerQueue->pop();
			customerQueue->push(tempQueueHolder[i]);
		}
		customerQueue->pop();
	}
	return *customerQueue->front();



		
}

void mainProgramInterface :: call_Palindrome()
{

	cout << endl<<endl<<"Check for Palindrome "<<endl<<endl;
	ifstream myfile;
	long num;
	myfile.open(file1);
	for(int i=0;i<4;i++)
	{
		myfile >> num;
		if(checkPalindrome(num))
			cout<< "The number " << num << " is a Palindrome number" << endl;
		else
			cout<< "The number " << num << " is not a Palindrome number" << endl;
	
	
	}
	
	myfile.close();

}
void mainProgramInterface :: call_validSequence()
{

	cout << endl<<endl<<"Check for Valid Sequence "<<endl<<endl;
	ifstream myfile;
	int *sequence;
	int length;
	myfile.open(file2);
	for(int i=0;i<4;i++)
	{
		myfile >> length;
		sequence = new int[length];
		for(int i=0;i<length;i++)
			myfile >> sequence[i];
		cout << endl << "The Sequence is : " << endl;
		for(int i = 0; i < length; i++)
			cout << sequence[i] << " ";
		cout << endl;

		if(validSequence(sequence, length))
			cout<< "The Sequence is a valid sequence" << endl;
		else
			cout<< "The Sequence is not a valid sequence" << endl;
	
		delete sequence;
	
	}
	
	myfile.close();




}

void mainProgramInterface :: call_dupStack()
{

	cout << endl<<endl<<"Output for Stack Duplicate "<<endl<<endl;
	ifstream myfile;
	int length;
	int temp;
	myfile.open(file3);
	derivedChainStack *myStack, *myStack1;
	for(int i=0;i<3;i++)
	{
		myfile >> length;
		myStack = new derivedChainStack(length);
		myStack1 = new derivedChainStack(length);
		for(int i=0;i<length;i++)
		{
			myfile >> temp;
			myStack->push(temp);
		}
		
		
		duplicateStack(myStack, myStack1);
		cout<<"The source stack is : ";
		
		myStack->printStack();
		
		cout<<"The copied stack is : ";
		
		myStack1->printStack();
		

		myStack->~derivedChainStack();
		myStack1->~derivedChainStack();
	
	}
	
	myfile.close();

}
void mainProgramInterface :: call_lastCustomer()
{
	
	cout << endl<<endl<<"Output for Last Customer program "<<endl<<endl;
	cout << "The last customer with lastCutomer(12, 5) is " << lastCutomer(12, 5) << endl;
	cout << "The last customer with lastCutomer(10, 6) is " << lastCutomer(10, 6) << endl;
	cout << "The last customer with lastCutomer(10, 3) is " << lastCutomer(10, 3) << endl;
	cout<<endl<<endl;

}
