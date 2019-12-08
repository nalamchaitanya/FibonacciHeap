#include <iostream>
#include <string>
#include "FibHeap.h"
#include "FibNode.h"
#include "BinNode.h"
#include "BinHeap.h"
using namespace std;

int main()
{
	BinHeap<int,string>* fib = new BinHeap<int,string>();
	string name;
	int key = 0;
	string label;
	int newKey;
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
				fib->Insert(new BinNode<int,string>(key, name));
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
				cout << "Type label: ";
				cin >> label;
				cout << "Type new key: ";
				cin >> newKey;
				fib->DecreaseKey(label, newKey);
				break;
			case 5:
				unordered_map<string, int> m = fib->mapping;
				for (auto it = m.cbegin(); it != m.cend(); ++it) {
			        std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
			    }
			    break;
		}
	}
	return 0;
}