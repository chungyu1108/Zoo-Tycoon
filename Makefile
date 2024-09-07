CC = g++ -std=c++11
EXE_FILE = assign3

all: $(EXE_FILE)

$(EXE_FILE): zoo_tycoon.cpp animal.o animal.h sealion.o sealion.h tiger.o tiger.h bear.o bear.h game.o game.h
	$(CC) zoo_tycoon.cpp animal.o game.o sealion.o tiger.o bear.o -o $(EXE_FILE)

animal.o: animal.cpp animal.h
	$(CC) -c animal.cpp

sealion.o: sealion.cpp sealion.h
	$(CC) -c sealion.cpp

tiger.o: tiger.cpp tiger.h
	$(CC) -c tiger.cpp

bear.o: bear.cpp bear.h
	$(CC) -c bear.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

clean:
	rm -f *.out *.o $(EXE_FILE)
