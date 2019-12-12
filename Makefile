# Makefile

CFLAGS = -c -g
GCC = g++

all: Dijkstras Prims

Prims: Prims.o
	$(GCC) $^ -o $@

Dijkstras: Dijkstras.o
	$(GCC) $^ -o $@

FibHeap: Main.o
	$(GCC) $^ -o $@

Prims.o: Prims.cpp
	$(GCC) $(CFLAGS) $^ -o $@

Dijkstras.o: Dijkstras.cpp
	$(GCC) $(CFLAGS) $^ -o $@

Main.o: Main.cpp
	$(GCC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o
# 	rm *.res
# 	rm FibHeap
	rm Dijkstras
	rm Prims
