#include <iostream>
using namespace std;
#ifndef NODE_H

template <class K, class D>
class Node
{
public:
	K key;
	D data;

	Node(K k, D d)
	{
		this->key = k;
		this->data = d;
	}
};

template <class K, class D>
bool operator==(const Node<K,D>& a, const Node<K,D>& b)
{
	return a->key == b->key;
}

template <class K, class D>
bool operator<(const Node<K,D>& a, const Node<K,D>& b)
{
	return a->key < b->key;
}

template <class K, class D>
ostream& operator<<(ostream& out, const Node<K,D>& a)
{
	return out << a.key << " " << a.data;
}

#define NODE_H
#endif