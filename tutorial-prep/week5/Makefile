# Makefile
CPP=g++ -std=c++14
CPPFLAGS=-Wall -Wextra -pedantic -Werror

all: school.o tutorial.o
	$(CPP) $(CPPFLAGS) -o school school.o tutorial.o

tutorial.o: school.hpp tutorial.cpp
	$(CPP) $(CPPFLAGS) -c -o tutorial.o tutorial.cpp

school.o: school.hpp school.cpp
	$(CPP) $(CPPFLAGS) -c -o school.o school.cpp

clean:
	rm -f school school.o tutorial.o
