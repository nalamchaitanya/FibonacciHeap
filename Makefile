# Makefile

CFLAGS = -c -g
GCC = g++

all: FibHeap Dijkstras

Dijkstras: Dijkstras.o
	$(GCC) $^ -o $@

FibHeap: Main.o
	$(GCC) $^ -o $@

Dijkstras.o: Dijkstras.cpp
	$(GCC) $(CFLAGS) $^ -o $@

Main.o: Main.cpp
	$(GCC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o
	rm FibHeap
	rm Dijkstras
