#include <iostream>
#include <string>
#include "FibHeap.h"
#include "FibNode.h"
using namespace std;

void testBinHeap() {
	BinHeap<int,string>* bin = new BinHeap<int,string>();
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
				return;
			case 1:
				cout << "Type Key: ";
				cin >> key;
				cout << "Type Data: ";
				cin >> name;
				bin->Insert(new BinNode<int,string>(key, name));
				break;
			case 2:
				if(bin->count)
					cout << *(bin->Minimum()) << endl;
				else
					cout << "Invalid" << endl;
				break;
			case 3:
				if(bin->count)
					cout << *(bin->ExtractMin()) << endl;
				else
					cout << "Invalid" << endl;
				break;
			case 4:
				cout << "Type label: ";
				cin >> label;
				cout << "Type new key: ";
				cin >> newKey;
				bin->DecreaseKey(label, newKey);
				break;
			case 5:
				unordered_map<string, int> m = bin->mapping;
				for (auto it = m.cbegin(); it != m.cend(); ++it) {
			        std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
			    }
			    break;
		}
	}
}