#include <iostream>
using namespace std;

#ifndef BINNODE_H
#define BINNODE_H

template <class K, class D>
class BinNode
{
public:
	K key;
	D data;
	BinNode* parent;
	BinNode* left;
	BinNode* right;

	BinNode(K k, D d)
	{
		this->key = k;
		this->data = d;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}
};

template <class K, class D>
bool operator==(const BinNode<K,D>& a, const BinNode<K,D>& b)
{
	return a->key == b->key;
}

template <class K, class D>
bool operator<(const BinNode<K,D>& a, const BinNode<K,D>& b)
{
	return a->key < b->key;
}

template <class K, class D>
ostream& operator<<(ostream& out, const BinNode<K,D>& a)
{
	return out << "[key:" << a.key << "|data:" << a.data << "|parent:"
				<< a.parent << "|left:" << a.left << "|right:" << a.right << "]";
}

#endif