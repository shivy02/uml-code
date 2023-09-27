CC = g++
CFLAGS  = -Wall -Werror -pedantic --std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = FibLFSR.h PhotoMagic.cpp

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -I//opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<

all: PhotoMagic

PhotoMagic: FibLFSR.o PhotoMagic.o
	$(CC) $(CFLAGS) -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)
	
clean:
	rm -f *.o
	rm -f PhotoMagic