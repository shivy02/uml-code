CC = g++
CFLAGS  = -Wall -Werror -pedantic --std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = TFractal.cpp Triangle.h


%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<

all: TFractal

TFractal: Triangle.o TFractal.o
	$(CC) $(CFLAGS) -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)

clean: 
	rm -f Tfractal
	rm -f *.o
