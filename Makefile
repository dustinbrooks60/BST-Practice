all: NHLApp

NHLApp: NHLStats.o BST.h BSTNode.h Player.o ElementAlreadyExistsInBSTException.o ElementDoesNotExistInBSTException.o
	g++ -Wall -std=c++11 -o NHLApp NHLStats.o Player.o BST.h BSTNode.h ElementAlreadyExistsInBSTException.o ElementDoesNotExistInBSTException.o

NHLStats.o: NHLStats.cpp
	g++ -c NHLStats.cpp


Player.o: Player.cpp Player.h
	g++ -c Player.cpp

ElementAlreadyExistsInBSTException.o: ElementAlreadyExistsInBSTException.cpp ElementAlreadyExistsInBSTException.h
	g++ -c ElementAlreadyExistsInBSTException.cpp

ElementDoesNotExistInBSTException.o:	ElementDoesNotExistInBSTException.cpp ElementDoesNotExistInBSTException.h
	g++ -c ElementDoesNotExistInBSTException.cpp


clean:
	rm -f NHLApp *.o

