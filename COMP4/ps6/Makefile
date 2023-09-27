CC = g++
CFLAGS  = -Wall -Werror -pedantic --std=c++17
LIBS = -lboost_unit_test_framework
DEPS = RandWriter.h TextWriter.cpp test.cpp

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/opt/homebrew/Cellar/boost/1.76.0/include -c $<

all: TextWriter

TextWriter: RandWriter.o TextWriter.o
	$(CC) $(CFLAGS) -L/opt/homebrew/Cellar/boost/1.76.0/lib -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f TextWriter