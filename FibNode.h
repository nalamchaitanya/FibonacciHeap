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
	return out << "[key:" << a.key << "|data:" << a.data << "|parent:"
				<< a.parent << "|left:" << a.left << "|right:" << a.right << "|children:"
				<< a.children << "|degree:" << a.degree << "|mark:" << a.mark << "]";
}

#endif