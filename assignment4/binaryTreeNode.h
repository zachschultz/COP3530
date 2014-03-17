#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H


#include <iostream>

 
using namespace std; 


struct binaryTreeNode 
{

   int  element;
   binaryTreeNode	*leftChild,
			*rightChild;
   
   binaryTreeNode() {leftChild = rightChild = NULL;}
   
   binaryTreeNode(const int& theElement)
   {
		element = theElement;
		leftChild = rightChild = NULL;
   }
   
   binaryTreeNode(const int& theElement,
				  binaryTreeNode *theLeftChild,
				  binaryTreeNode *theRightChild)
	{
		element = theElement;
		leftChild = theLeftChild;
		rightChild = theRightChild;
	
	}

};
#endif
