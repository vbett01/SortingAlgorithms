CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3

sorter: sorter.o sortAlgs.o
	${CXX} ${LDFLAGS} -o sorter sorter.o sortAlgs.o
sorter.o: sorter.cpp sortAlgs.h
sortAlgs.o: sortAlgs.cpp sortAlgs.h

clean:
	rm -rf sorter *.o *.dSYM
