#include <iostream>
#include <string.h>
#include "mainProgramInterface.h"

using namespace std;

int main (int argc, char *argv[]){

	
	char *argument[3];
	for(int i=0;i<3;i++)
		argument[i]=new char[100];
	strcpy(argument[0],"File1.txt");
	strcpy(argument[1],"File2.txt");
	strcpy(argument[2],"File3.txt");
	
	mainProgramInterface *mP = new mainProgramInterface(argument[0], argument[1], argument[2]);
	
	mP->call_Palindrome();
	mP->call_validSequence();
	mP->call_dupStack();
	mP->call_lastCustomer();
	
	return 0;
}
