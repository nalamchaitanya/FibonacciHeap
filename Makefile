# Makefile

CFLAG = -c
GCC = g++

all: FibHeap

FibHeap: Main.o FibHeap.o
	$(GCC) $^ -o $@

Main.o: Main.cpp
	$(GCC) -c $^ -o $@

FibHeap.o: FibHeap.cpp
	$(GCC) -c $^ -o $@

clean:
	rm -rf *.o
