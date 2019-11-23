#include <iostream>
#include <FibNode.h>
#include <Heap.h>

#ifndef FIBHEAP_H
#define FIBHEAP_H

class FibHeap : public Heap
{
public:
	int count;
	FibNode* min;

	FibHeap()
	{
		this->count = 0;
		this->min = NULL;
	}

	virtual Heap* MakeHeap() override;

	virtual void Insert(T t) override;

	virtual T Minimum() override;

	virtual T ExtractMin() override;

	virtual void DecreaseKey(T t, K k) override;

	virtual void Delete(T t) override;
};


#endif