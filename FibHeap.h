#include <iostream>
#include "Heap.h"
#include "FibNode.h"

#ifndef FIBHEAP_H
#define FIBHEAP_H

template <class K, class D>
class FibHeap : public Heap<K,D>
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

	void Insert(Node<K,D>* t);

	Node<K,D>* Minimum();

	Node<K,D>* ExtractMin();

	void DecreaseKey(Node<K,D>* t, K k);

	void Delete(Node<K,D>* t);
};

template void FibHeap<int,string>::Insert(Node<int,string>*);

#endif