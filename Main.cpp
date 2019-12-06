#include <iostream>
#include <string>
#include "FibHeap.h"
#include "FibNode.h"
using namespace std;

int main()
{
	FibHeap<int,string>* fib = new FibHeap<int,string>();
	string name;
	int key = 0;
	while(true)
	{
		int t;
		cout << "Type command: ";
		cin >> t;
		switch(t)
		{
			case -1:
				cout << "Bye bye" << endl;
				return 0;
			case 1:
				cout << "Type Key: ";
				cin >> key;
				cout << "Type Data: ";
				cin >> name;
				fib->Insert(new FibNode<int,string>(key, name));
				break;
			case 2:
				cout << *(fib->Minimum()) << endl;
				break;
			case 3:
				cout << *(fib->ExtractMin()) << endl;
				break;
			case 4:
				// cout << *fib << endl;
				break;
		}
	}
	return 0;
}