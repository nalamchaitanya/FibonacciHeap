#include "FibHeap.h"
#include "FibNode.h"
#include <string>
using namespace std;

template <class K, class D>
Heap<K,D>* FibHeap<K,D>::MakeHeap()
{
	// obsolete as constructor is there.
	return this;
}

template <class K, class D>
void FibHeap<K,D>::Insert(Node<K,D>* t)
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


template <class K, class D>
Node<K,D>* FibHeap<K,D>::Minimum()
{
	return NULL;
}

template <class K, class D>
Node<K,D>* FibHeap<K,D>::ExtractMin()
{
	return NULL;
}

template <class K, class D>
void FibHeap<K,D>::DecreaseKey(Node<K,D>* t, K k)
{
	return;
}

template <class K, class D>
void FibHeap<K,D>::Delete(Node<K,D>* t)
{
	return;
}
