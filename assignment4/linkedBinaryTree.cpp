#include <iostream>
#include <sstream>
#include "linkedBinaryTree.h"
#include <stdlib.h>


using namespace std;

void linkedBinaryTree :: consturctTree(int *in, int *post)
{
//Write your code here	
	//call helper function
	this->root=buildTree(in, 0, 16, post, 0, 16);
}

binaryTreeNode* linkedBinaryTree :: buildTree(int *in, int inStart, int inEnd, int *post, int postStart, int postEnd)
{
	//make sure indexes are within the bounds
	if (inStart > inEnd || postStart > postEnd)
		return NULL;
	//set value of current root to the last element in the post array
	int rootVal = post[postEnd];
	binaryTreeNode *root = new binaryTreeNode(rootVal);

	//keep track of root in "in" array
	int index = 0;
	for (int i = 0; i < 17; i++)
	{
		if (in[i] == rootVal)
		{
			index = i;
			break;
		}
	}

	//recursive call on left child, set upper bound to one less than root
	root->leftChild =  buildTree(in, inStart, index-1, post, postStart, postStart+index-(inStart+1));
	//recursive call on right child, lower bound is one more than root
	root->rightChild = buildTree(in, index+1, inEnd, post, postStart+index-inStart, postEnd-1);
	return root;
}



int linkedBinaryTree :: maxHeightDifference()
{
//write your code here

	//set up variables to be used
	int maxLeftDiff=0;
	int maxRightDiff=0;
	int tempDiff = 0;

	//while there is still a left child
	while (this->root->leftChild != NULL)
	{
		int a = height(this->root->leftChild);
		int b = height(this->root->rightChild);
		tempDiff = abs(a-b);
		//find max difference of left subtree
		if (tempDiff > maxLeftDiff)
			maxLeftDiff = tempDiff;
		this->root->leftChild=this->root->leftChild->leftChild;
	}

	//while there is still a right child
	while (this->root->rightChild != NULL)
	{
		int a = height(this->root->rightChild);
		int b = height(this->root->leftChild);
		tempDiff = abs(a-b);
		//find max difference of right subtree
		if (tempDiff > maxRightDiff)
			maxRightDiff = tempDiff;
		this->root->rightChild=this->root->rightChild->rightChild;
	}

	//compare two differences against each other
	int maxDiff = abs(maxRightDiff-maxLeftDiff);
	return maxDiff;


}

void linkedBinaryTree :: preOrder(binaryTreeNode *t)
{
	if(t != NULL)
	{
		visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}


void linkedBinaryTree :: inOrder(binaryTreeNode *t)
{
	if(t != NULL)
	{
		inOrder(t->leftChild);
		visit(t);
		inOrder(t->rightChild);
	}
}


void linkedBinaryTree :: postOrder(binaryTreeNode *t)
{
	if(t != NULL)
	{
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		visit(t);
	}
}


void linkedBinaryTree :: visit(binaryTreeNode *t)
{

	cout << t->element << " ";

}

int linkedBinaryTree :: height(binaryTreeNode *t)
{

	if(t == NULL)
		return 0;
	int hl = height(t->leftChild);
	int hr = height(t->rightChild);
	if (hl > hr)
		return ++hl;
	else
		return ++hr;


}



