#include <iostream>
#include <math.h>
#include <vector>
#include <assert.h>
#include <unordered_map>
#include "FibNode.h"

#ifndef FIBHEAP_H
#define FIBHEAP_H

template <class K, class D>
class FibHeap
{
public:
	int count;
	FibNode<K,D>* min;
	unordered_map<D,FibNode<K,D>*> findNode;

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
		// cout << "Added " << t << endl;
		this->findNode[t->data] = t;
		if(this->min == NULL)
		{
			this->min = t;
			this->min->right = this->min;
			this->min->left = this->min;
		}
		else
		{
			addNodeToList(this->min, t);
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
				// cout << childNode->key << endl;
				removeNodeFromList(childNode);
				childNode->parent = NULL;
				addNodeToList(this->min, childNode);
				childNode = result->children;
			}
			if(result == result->right)
			{
				this->min = NULL;
			}
			else
			{
				removeNodeFromList(this->min);
				this->min = result->right;
				this->Consolidate();
			}
			this->count--;
		}
		this->findNode.erase(result->data);
		return result;
	}

	void Cut(FibNode<K,D>* x, FibNode<K,D>* y)
	{  
	    removeNodeFromList(x);
	    y->degree--;
	    addNodeToList(this->min, x);
	    x->parent = NULL;
	    x->mark = false;
	} 

	void CascadeCut(FibNode<K,D>* t)
	{
		auto z = t->parent;
		if(z != NULL)
		{
			if (t->mark == false)
			{
				t->mark = true;
			}
			else
			{
				Cut(t, z);
				CascadeCut(z);
			}
		}
	}
	
	void DecreaseKey(D d, K k)
	{
		if(this->findNode.find(d) != this->findNode.end())
		{
			auto t = this->findNode[d];
			if(k > t->key)
			{
				assert(false);
			}
			t->key = k;
			FibNode<K,D>* y = t->parent;
			if(y != NULL && t->key < y->key)
			{
				Cut(t, y);
				CascadeCut(y);
			}
			if(t->key < this->min->key)
				this->min = t;
		}
	}

	void Delete(FibNode<K,D>* t);

private:
	void Consolidate()
	{
		int size = 1.5*log2(this->count);
		vector<FibNode<K,D>*> consol(size, NULL);
		auto nextNode = this->min;
		auto finalNode = nextNode->left;
		do
		{
			auto curr = nextNode;
			auto processingNode = nextNode;
			nextNode = curr->right;
			auto degree = curr->degree;
			while(consol[degree] != NULL)
			{
				auto sameDegreeNode = consol[degree];
				if(curr->key > sameDegreeNode->key)
				{
					auto temp = curr;
					curr = sameDegreeNode;
					sameDegreeNode = temp;
				}
				FibLink(sameDegreeNode, curr);
				consol[degree] = NULL;
				degree++;
			}
			consol[degree] = curr;
			if(processingNode == finalNode)
				break;
		}while(true);
		this->min = NULL;
		for(auto tempNode : consol)
		{
			if(tempNode != NULL)
			{
				if(this->min == NULL)
				{
					this->min = tempNode;
					this->min->right = this->min;
					this->min->left = this->min;
				}
				else
				{
					addNodeToList(this->min, tempNode);
					if(tempNode->key < this->min->key)
					{
						this->min = tempNode;
					}
				}
			}
		}
	}

	void FibLink(FibNode<K, D>* y, FibNode<K, D>* x)
	{
		removeNodeFromList(y);
		y->parent = x;
		if(x->children == NULL)
		{
			x->children = y;
			y->left = y;
			y->right = y;
		}
		else
		{
			addNodeToList(x->children, y);
		}
		x->degree++;
		y->mark = false;
	}

	void addNodeToList(FibNode<K, D>* head, FibNode<K, D>* node)
	{
		// auto result = head->right;
		node->right = head->right;
		head->right->left = node;
		node->left = head;
		head->right = node;
		// return result;
	}

	void removeNodeFromList(FibNode<K, D>* node)
	{
		if(node->parent != NULL && node->parent->children == node)
		{
			node->parent->children = node->right;
		}
		auto leftNode = node->left;
		auto rightNode = node->right;
		if(leftNode == node)
		{
			if(node->parent != NULL)
			{
				node->parent->children = NULL;
			}
			else
			{
				this->min = NULL;
			}
		}
		else
		{
			leftNode->right = rightNode;
			rightNode->left = leftNode;
		}
	}

	string printHeap()
	{
		return this->min->printList();
	}
};

template <class K, class D>
ostream& operator<<(ostream& out, const FibHeap<K,D>& a)
{
	return out << "[count: " << a.count << "|nodes:\n" << a.min->printList("\t") << "]\n";
}

#endif
