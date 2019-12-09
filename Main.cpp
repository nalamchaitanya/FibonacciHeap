#include <iostream>
#include <string>
#include "FibHeap.h"
#include "FibNode.h"
using namespace std;

int main()
{
	FibHeap<int,int>* fib = new FibHeap<int,int>();
	int labelCount = 0;
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
				int key;
				cin >> key;
				fib->Insert(new FibNode<int,int>(key, labelCount++));
				break;
			case 2:
				if(fib->count)
					cout << *(fib->Minimum()) << endl;
				else
					cout << "Invalid" << endl;
				break;
			case 3:
				if(fib->count)
					cout << *(fib->ExtractMin()) << endl;
				else
					cout << "Invalid" << endl;
				break;
			case 4:
				cout << *fib << endl;
				break;
			case 0:
				string str;
				getline(cin, str);
				// cout << str << endl;
			case 5:
				int label;
				cin >> label;
				int decreasedKey;
				cin >> decreasedKey;
				fib->DecreaseKey(label, decreasedKey);
				break;
		}
	}
	return 0;
}