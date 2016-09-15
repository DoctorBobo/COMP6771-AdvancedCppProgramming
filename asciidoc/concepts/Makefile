CPP=g++ -fconcepts -std=c++1z
CPP_FLAGS=-Wall -Wextra -pedantic -Werror -O2

motivation1: motivation1.cpp
	$(CPP) $(CPP_FLAGS) motivation1.cpp # won't compile, so no point giving -o

motivation2: motivation2.cpp
	$(CPP) $(CPP_FLAGS) motivation2.cpp

motivation3: motivation3.cpp
	$(CPP) $(CPP_FLAGS) motivation3.cpp

motivation4: motivation4.cpp
	$(CPP) $(CPP_FLAGS) motivation4.cpp

solution1: solution1.cpp
	$(CPP) $(CPP_FLAGS) -o solution1 solution1.cpp
	./solution1

solution2: solution2.cpp
	$(CPP) $(CPP_FLAGS) -o solution2 solution2.cpp
	./solution2

solution3: solution3.cpp
	$(CPP) $(CPP_FLAGS) -o solution3 solution3.cpp
	./solution3

solution4: solution4.cpp
	$(CPP) $(CPP_FLAGS) -o solution4 solution4.cpp
	./solution4

arithmetic1: arithmetic1.cpp
	$(CPP) $(CPP_FLAGS) arithmetic1.cpp

arithmetic2: arithmetic2.cpp
	$(CPP) $(CPP_FLAGS) arithmetic2.cpp

arithmetic: arithmetic.cpp
	$(CPP) $(CPP_FLAGS) -o arithmetic arithmetic3.cpp
	./arithmetic

clean:
	rm -f solution1 solution2 solution3 solution4 arithmetic