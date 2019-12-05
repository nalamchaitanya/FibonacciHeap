# Makefile

CFLAG = -c
GCC = g++

all: FibHeap

FibHeap: Main.o
	$(GCC) $^ -o $@

Main.o: Main.cpp
	$(GCC) -c $^ -o $@

clean:
	rm -rf *.o
	rm FibHeap
