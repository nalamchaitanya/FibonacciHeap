# Makefile

CFLAGS = -c -g
GCC = g++

all: FibHeap

FibHeap: Main.o
	$(GCC) $^ -o $@

Main.o: Main.cpp
	$(GCC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o
	rm FibHeap
