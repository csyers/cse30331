CC=gcc
XXFLAGS=-std=c++11

all: measure distance1 distance2 distance3 distance4a distance4b distance5

measure: measure.c
	$(CC) $< -o $@

distance1: distance1.cpp location.h
	g++ $(XXFLAGS) distance1.cpp -o $@

distance2: distance2.cpp location.h
	g++ $(XXFLAGS) distance2.cpp -o $@

distance3: distance3.cpp location.h
	g++ $(XXFLAGS) distance3.cpp -o $@

distance4a: distance4a.cpp location.h
	g++ $(XXFLAGS) distance4a.cpp -o $@

distance4b: distance4b.cpp location.h
	g++ $(XXFLAGS) distance4b.cpp -o $@

distance5: distance5.cpp location.h
	g++ $(XXFLAGS) distance5.cpp -o $@

clean:
	rm -f measure distance1 distance2 distance3 distance4a distance4b distance5
