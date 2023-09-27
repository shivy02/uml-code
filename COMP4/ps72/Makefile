CC = g++
CFLAGS  = -Wall -pedantic --std=c++17
LIBS = -lboost_regex
DEPS = ps7.cpp

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/opt/homebrew/Cellar/boost/1.76.0/include -c $<

all: PS7

PS7: ps7.o
	$(CC) $(CFLAGS) -L/opt/homebrew/Cellar/boost/1.76.0/lib -o $@ $^ $(LIBS)
	
clean:
	rm -f *.o
	rm -f PS7