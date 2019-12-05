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

	FibHeap<K,D>* MakeHeap()
	{
		// obsolete as constructor is there.
		return this;
	}

	void Insert(FibNode<K,D>* t)
	{
		// Inserting a node
		cout << "Added " << t << endl;
		if(this->min == NULL)
		{
			this->min = t;
		}
		else
		{
			t->right = this->min->right;
			this->min->right->left = t;
			t->left = this->min;
			this->min->right = t;
			if(t->key < this->min->key)
				this->min = t;
		}
		this->count += 1;
		return;
	}

	FibNode<K,D>* Minimum()
	{
		return this->min;
	}

	FibNode<K,D>* ExtractMin()
	{
		auto result = this->min;
		if(result != NULL)
		{
			auto childNode = result->children;
			while(childNode != NULL)
			{
				childNode->parent = NULL;
				childNode = addNodeToList(this->min, childNode);
			}
		}
	}

	void DecreaseKey(FibNode<K,D>* t, K k);

	void Delete(FibNode<K,D>* t);

private:
	void Consolidate();
	FibNode<K, D>* addNodeToList(FibNode<K, D>* head, FibNode<K, D>* node)
	{
		auto result = node->right;
		node->right = head->right;
		head->right->left = node;
		node->left = head;
		head->right = node;
		return result;
	}
};

#endif