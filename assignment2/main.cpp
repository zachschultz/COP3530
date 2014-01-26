#include <iostream>
#include "chain.h"
using namespace std;

int main (int argc, char *argv[]){

	if(argc < 2)
	{
		cout << "Enter the file name as input" <<endl;
		return 0;
	}
	
	//Creates new chain
	chain *mychain = new chain(100);
	
	int multOf = 5;
	
	// Read the file with filename stored in argv[1]. Store the numbers in mychain. 
	
	mychain->readAndStoreFromFile(argv[1]);
	
	//Print mychain
	cout<<"\n\n The list is : "<<endl;
	mychain->output();
	
	// Delete all entries from mychain which contain element that is multiple of variable multOf
	
	mychain->eraseModuloValue(multOf);
	
	//Print mychain
	cout<<"\n\n The list after removal of elements with multiple of 5 is : "<<endl;
	mychain->output();
	
	//Reorder mychain such that all odd numbers precede all even numbers.
	//Note that the original ordering between odd (even) numbers should remain intact. 
	//Example: 3 4 5 1 2 will become 3 5 1 4 2. But, 5 1 3 4 2 is not valid.
	mychain->oddAndEvenOrdering();
	
	
	//Print mychain
	cout<<"\n\n The list after odd and even ordering is : "<<endl;
	mychain->output();
	
	
	//Reverse the mychain
	mychain->reverse();
	
	//Print mychain
	cout<<"\n\n The reversed list is : "<<endl;
	mychain->output();
	


}
