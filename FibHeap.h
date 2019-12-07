#include <iostream>
#include <math.h>
#include <vector>
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
				childNode->parent = NULL;
				childNode = addNodeToList(this->min, childNode);
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
		return result;
	}

	void Cut(FibNode<K,D>* t, FibNode<K,D>* temp) 
	{  
	    if (t == temp->child) 
	        temp->child = t->right; 
	    temp->degree = temp->degree - 1; 
	    t = addNodeToList(this->min, t);
	    
	    t->parent = NULL; 
	    t->mark = false; 
	} 

	void Cascase_cut(FibNode<K,D>* t) 
	{ 
    	FibNode<K,D>* z = t->parent; 
    	if (z != NULL) { 
    	    if (t->mark == false) { 
    	        t->mark = true; 
    	    } 
    	    else { 
    	        Cut(t, z); 
    	        Cascase_cut(z); 
    	    } 
    	} 
	} 
	
	void DecreaseKey(FibNode<K,D>* t, K k) 
	{ 
    	if (this->min == NULL) 
    	    cout << "The Heap is Empty" << endl; 
  
    	if (t == NULL) 
    	    cout << "Node not t in the Heap" << endl; 
  
    	t->key = k; 
  
    	FibNode<K,D>* temp = t->parent; 
    	if (temp != NULL && t->key < temp->key)
    	{ 
    	    Cut(t, temp); 
    	    Cascase_cut(temp); 
    	} 
    	if (t->key < this->min->key) 
        	this->min = t; 
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

	FibNode<K, D>* addNodeToList(FibNode<K, D>* head, FibNode<K, D>* node)
	{
		auto result = node->right;
		node->right = head->right;
		head->right->left = node;
		node->left = head;
		head->right = node;
		return result;
	}

	void removeNodeFromList(FibNode<K, D>* node)
	{
		auto leftNode = node->left;
		auto rightNode = node->right;
		leftNode->right = rightNode;
		rightNode->left = leftNode;
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
