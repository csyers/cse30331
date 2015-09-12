CXX=g++
CC=gcc
CXXFLAGS=-std=c++11

all: calc0 measure

calc0: calc0.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

measure: measure.c
	$(CC) $< -o $@

clean:
	rm -rf calc[0-4] measure *.exe *.o *.dSYM *~ gmon.out

