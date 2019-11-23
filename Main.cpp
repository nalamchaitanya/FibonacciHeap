#include <iostream>
#include <string>
#include "FibHeap.h"
#include "FibNode.h"
using namespace std;

int main()
{
	FibHeap<int,string>* fib = new FibHeap<int,string>();
	string name("abc");
	int key = 4;
	FibNode<int,string>* node = new FibNode<int,string>(key, name);
	cout << *node << endl;
	fib->Insert(node);
	return 0;
}