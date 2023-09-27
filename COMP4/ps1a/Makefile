CC = g++
CFLAGS  = -Wall -Werror -pedantic --std=c++17
LIBS = -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system
DEPS = FibLFSR.h test.cpp

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/opt/homebrew/Cellar/boost/1.76.0/include -I//opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<

all: PhotoMagic

PhotoMagic: FibLFSR.o test.o
	$(CC) $(CFLAGS) -L/opt/homebrew/Cellar/boost/1.76.0/lib -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)
	
clean:
	rm -f *.o
	rm -f PhotoMagic