CPP=g++-6
CPPFLAGS=-Wall -Wextra -pedantic -Werror

all: book.hpp book.cpp bookstore.cpp
	$(CPP) $(CPPFLAGS) -o bookstore book.cpp bookstore.cpp

clean: bookstore
	rm bookstore
