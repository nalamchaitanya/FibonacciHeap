#include <iostream>
using namespace std;

#ifndef FIBNODE_H
#define FIBNODE_H

template <class K, class D>
class FibNode
{
public:
	K key;
	D data;
	FibNode* parent;
	FibNode* left;
	FibNode* right;
	FibNode* children;
	int degree;
	bool mark;

	FibNode(K k, D d)
	{
		this->key = k;
		this->data = d;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
		this->children = NULL;
		this->degree = 0;
		this->mark = false;
	}
};

bool operator==(const FibNode& a, const FibNode& b)
{
	return a->key == b->key;
}

bool operator<(const FibNode& a, const FibNode& b)
{
	return a->key < b->key;
}

ostream& operator<<(ostream& out, const FibNode& a)
{
	return out << a->key;
}

#endif