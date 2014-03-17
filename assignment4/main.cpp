#include <iostream>
#include <fstream>
#include<string.h>
#include "linkedBinaryTree.h"

using namespace std;

int main (int argc, char *argv[]){

	
	
	linkedBinaryTree *l = new linkedBinaryTree();
	int *in_array = new int[17];
	int *post_array = new int[17];
	ifstream infile;
	int temp;

	infile.open("Inorder.txt");
	for(int i=0;i<17;i++)
	{
		infile >> temp;
		in_array[i] = temp;
	}

	infile.close();

	infile.open("Postorder.txt");
	
	for(int i=0;i<17;i++)
	{
		infile >> temp;
		post_array[i] = temp;
	}

	infile.close();

	l->consturctTree(in_array, post_array);


	cout<<endl<<"The preorder Traversal Output is : " <<endl;
	l->preOrderOutput();
	

	cout<<endl<<"The inorder Traversal Output is : " <<endl;
	l->inOrderOutput();
	
	cout<<endl<<"The postorder Traversal Output is : " <<endl;
	l->postOrderOutput();
	

	//call maxHeightDifference method
	cout << endl<<"The maximum Height Difference is : " << l->maxHeightDifference() << endl<<endl;
		
	return 0;
}
