#ifndef BINARYTREE_H
#define BINARYTREE_H


#include <iostream>
#include "binaryTreeNode.h"
 
using namespace std; 

class binaryTree 
{
   public:
      virtual ~binaryTree() {};
      virtual bool empty() const = 0;
      virtual int size() const = 0;
      virtual void preOrder(binaryTreeNode *) = 0;
      virtual void inOrder(binaryTreeNode *) = 0;
      virtual void postOrder(binaryTreeNode *) = 0;
};
#endif
