main: main.o  linkedBinaryTree.o
	g++ main.o linkedBinaryTree.o -o main
main.o: main.cpp
	g++ -c main.cpp 
	
linkedBinaryTree.o: linkedBinaryTree.cpp linkedBinaryTree.h binaryTree.h binaryTreeNode.h
	g++ -c linkedBinaryTree.cpp
	
	
clean:
	rm -f *.o main


