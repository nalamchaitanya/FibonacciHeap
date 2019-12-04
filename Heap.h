#include <iostream>
#include "Node.h"
#ifndef HEAP_H
#define HEAP_H

template <class K, class D>
class Heap
{
	virtual Heap* MakeHeap() = 0;

	virtual void Insert(Node<K,D>* n) = 0;

	virtual Node<K,D>* Minimum() = 0;

	virtual Node<K,D>* ExtractMin() = 0;

	virtual void DecreaseKey(Node<K,D>* n, K k) = 0;

	virtual void Delete(Node<K,D>* n) = 0;
};

#endif