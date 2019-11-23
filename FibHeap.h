#include <iostream>
#include "FibNode.h"

#ifndef FIBHEAP_H
#define FIBHEAP_H

template <class K, class D>
class FibHeap
{
public:
	int count;

	FibNode<K,D>* min;

	FibHeap()
	{
		this->count = 0;
		this->min = NULL;
	}

	FibHeap<K,D>* MakeHeap();

	void Insert(FibNode<K,D>* t);

	FibNode<K,D>* Minimum();

	FibNode<K,D>* ExtractMin();

	void DecreaseKey(FibNode<K,D>* t, K k);

	void Delete(FibNode<K,D>* t);
};

template void FibHeap<int,string>::Insert(FibNode<int,string>*);

#endif