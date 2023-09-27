CC = g++
CFLAGS  = -Wall -Werror -pedantic --std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = CelestialBody.cpp Universe.h

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<

all: NBody1

lint:
	cpplint *.cpp *.h

NBody1: CelestialBody.o main.o Universe.o
	$(CC) $(CFLAGS) -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)
	
clean:
	rm -f *.o
	rm -f NBody1