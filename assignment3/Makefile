main: main.o chain.o Myexception.o  derivedChainQueue.o derivedChainStack.o mainProgramInterface.o
	g++ main.o chain.o Myexception.o derivedChainQueue.o derivedChainStack.o mainProgramInterface.o -o main
main.o: main.cpp
	g++ -c main.cpp 
	
mainProgramInterface.o: mainProgramInterface.cpp mainProgramInterface.h
	g++ -c mainProgramInterface.cpp
	
derivedChainStack.o: stack.h derivedChainStack.h derivedChainStack.cpp chain.h
	g++ -c derivedChainStack.cpp
	
derivedChainQueue.o: queue.h derivedChainQueue.h derivedChainQueue.cpp chain.h
	g++ -c derivedChainQueue.cpp

	
chain.o: chain.cpp chain.h chainNode.h linearList.h
	g++ -c chain.cpp
	
Myexception.o: Myexception.cpp Myexception.h
	g++ -c Myexception.cpp
	
clean:
	rm -f *.o main


