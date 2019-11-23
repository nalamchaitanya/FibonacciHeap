#include <iostream>

#ifndef HEAP_H
#define HEAP_H

template <class T, class K>
class Heap
{
	virtual Heap* MakeHeap() = 0;

	virtual void Insert(T t) = 0;

	virtual T Minimum() = 0;

	virtual T ExtractMin() = 0;

	virtual void DecreaseKey(T t, K k) = 0;

	virtual void Delete(T t) = 0;
};

#endif