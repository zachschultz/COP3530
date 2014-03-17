#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H


#include <iostream>
#include "binaryTree.h"

 
using namespace std; 

class linkedBinaryTree : public binaryTree
{
   public:
	 linkedBinaryTree() {root = NULL; treeSize = 0;}
	 linkedBinaryTree(binaryTreeNode *t, int size)
	 {
		root = new binaryTreeNode(t->element, t->leftChild, t->rightChild);
		treeSize = size;

	 }
		 
	 bool empty() const {return treeSize == 0;}
	 int size() const {return treeSize;}

	 void preOrder(binaryTreeNode *t);
	 void inOrder(binaryTreeNode *t);
	 void postOrder(binaryTreeNode *t);

	 void preOrderOutput() {preOrder(root); cout << endl;}
	 void inOrderOutput() {inOrder(root); cout << endl;}
	 void postOrderOutput() {postOrder(root); cout << endl;}
	 void visit(binaryTreeNode *t);
	 int height(binaryTreeNode *t);

	 void consturctTree(int *in, int *post);
	 binaryTreeNode* buildTree(int *in, int inStart, int inEnd, int *post, int postStart, int postEnd);
	 int maxHeightDifference(); 
     
	 	
	
	 
	private:
		binaryTreeNode *root;
		int treeSize;
	
};
#endif
