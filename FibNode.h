#include <iostream>
#include "Node.h"
using namespace std;

#ifndef FIBNODE_H
#define FIBNODE_H

template <class K, class D>
class FibNode : public Node<K,D>
{
public:
	FibNode* parent;
	FibNode* left;
	FibNode* right;
	FibNode* children;
	int degree;
	bool mark;

	FibNode(K k, D d) : Node<K,D>(K k, D d)
	{
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
		this->children = NULL;
		this->degree = 0;
		this->mark = false;
	}
};

template <class K, class D>
bool operator==(const FibNode<K,D>& a, const FibNode<K,D>& b)
{
	return a->key == b->key;
}

template <class K, class D>
bool operator<(const FibNode<K,D>& a, const FibNode<K,D>& b)
{
	return a->key < b->key;
}

template <class K, class D>
ostream& operator<<(ostream& out, const FibNode<K,D>& a)
{
	return out << a.key << " " << a.data;
}

#endif