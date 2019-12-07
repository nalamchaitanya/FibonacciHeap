#include <iostream>
#include <math.h>
#include <vector>
#include "BinNode.h"

#include<algorithm> 
using namespace std; 

#ifndef BINHEAP_H
#define BINHEAP_H

template <class K, class D>
class BinHeap
{
public:
	int count;
	vector<BinNode<K,D>*> heap;

	BinHeap()
	{
		this->count = 0;
		this->heap;
	}

	BinHeap<K,D>* MakeHeap()
	{
		// obsolete as constructor is there.
		return this;
	}

	void Insert(BinNode<K,D>* t)
	{
		// Inserting a node
		cout << "Added " << t << endl;
		this->count += 1;
		this->heap[this->count-1] = t;
		bubbleUp(this->count-1);
		return;
	}

	BinNode<K,D>* Minimum()
	{
		if (count > 0) 
		{
			return this->heap[0];
		}
		return NULL;
	}

	BinNode<K,D>* ExtractMin()
	{
		if (this->count == 0)
		{
			return NULL;
		}
		BinNode<K,D>* min = this->heap[0];
		this->heap[0] = this->heap[this->count-1];
		this->count = this->count - 1;
		siftDown(0);
		return min;
	}
	
	void DecreaseKey(int index, K k) 
	{ 
    	this->heap[index]->key = k;
    	bubbleUp(index);
    	return;
	}

	void Delete(BinNode<K,D>* t);

private:
	void siftDown(int index)
	{
		if (NULL == getLeftChild(index)) {
			return;
		}
		else if (NULL == getRightChild(index)) {
			BinNode<K,D>* current = this->heap[index];
			BinNode<K,D>* leftChild = getLeftChild(index);
			K currentKey = current->key;
			K leftKey = leftChild->key;
			K minKey = std::min(leftKey, currentKey);
			if (minKey == leftKey)
			{
				this->heap[index] = leftChild;
				this->heap[getLeftChildIndex(index)] = current;
				siftDown(getLeftChildIndex(index));
			}
		}
		else {
			BinNode<K,D>* current = this->heap[index];
			BinNode<K,D>* leftChild = getLeftChild(index);
			BinNode<K,D>* rightChild = getRightChild(index);
			K currentKey = current->key;
			K leftKey = leftChild->key;
			K rightKey = rightChild->key;
			K minKey = std::min(leftKey, rightKey, currentKey);
			if (minKey == leftKey)
			{
				this->heap[index] = leftChild;
				this->heap[getLeftChildIndex(index)] = current;
				siftDown(getLeftChildIndex(index));
			}
			else if (minKey == rightKey)
			{
				this->heap[index] = rightChild;
				this->heap[getRightChildIndex(index)] = current;
				siftDown(getRightChildIndex(index));
			}
		}
	}

	void bubbleUp(int index) 
	{
		if (index == 0)
		{
			return;
		}

		BinNode<K,D>* parent = getParent(index);
		K parentKey = parent->key;
		BinNode<K,D>* current = this->heap[index];
		K currentKey = current->key;
		
		if (currentKey == std::min(parentKey,currentKey)) 
		{
			this->heap[index] = parent;
			this->heap[getParentIndex(index)] = current;
			bubbleUp(getParentIndex(index));
		}
	}

	int getParentIndex(int index) {
		return (index+1)/2 - 1;
	}

	BinNode<K,D>* getParent(int index)
	{
		return this->heap[getParentIndex(index)];
	}

	int getLeftChildIndex(int index) {
		return 2*(index+1) - 1;
	}

	BinNode<K,D>* getLeftChild(int index)
	{
		if (this->count < getLeftChildIndex(index) + 1) {
			return NULL;
		};
		return this->heap[getLeftChildIndex(index)];
	}

	int getRightChildIndex(int index) {
		return 2*(index+1);
	}

	BinNode<K,D>* getRightChild(int index)
	{
		if (this->count < getRightChildIndex(index) + 1) {
			return NULL;
		}
		return this->heap[getRightChildIndex(index)];
	}
};

#endif
