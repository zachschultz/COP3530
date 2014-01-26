main: main.o chain.o Myexception.o
	g++ main.o chain.o Myexception.o -o main
main.o: main.cpp
	g++ -c main.cpp 
chain.o: chain.cpp chain.h chainNode.h linearList.h
	g++ -c chain.cpp
	
Myexception.o: Myexception.cpp Myexception.h
	g++ -c Myexception.cpp
	
clean:
	rm *.o


