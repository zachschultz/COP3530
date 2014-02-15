#ifndef MPI_H
#define MPI_H

#include<string.h>
#include <iostream>
#include "derivedChainStack.h"
#include "derivedChainQueue.h"
 
using namespace std; 


class mainProgramInterface
{
   public:
		mainProgramInterface(char *filename1, char *filename2, char *filename3)
		{
			strcpy(file1, filename1);
			strcpy(file2, filename2);
			strcpy(file3, filename3);
			
		}
		
		void call_Palindrome();
		//read from file1
		void call_validSequence();
		//read from file2
		void call_dupStack();
		//read from file 3
		void call_lastCustomer();
		
		
		
		bool checkPalindrome(long theNumber); 
		bool validSequence(int *theSequence, int n);
		void duplicateStack(derivedChainStack* source, derivedChainStack* dest);
		int lastCutomer(int m, int n);
		
		
	private:
		char 	file1[100], 
				file2[100], 
				file3[100];
		
		
};
#endif
