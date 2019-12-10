#include <iostream>
#include <string>
#include <utility> 
#include "FibHeap.h"
#include "FibNode.h"
#include "BinNode.h"
#include "BinHeap.h"
#include "Djisktra.h"
#include "Prims.h"
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

vector<vector<std::pair<int,int> > > getAdj() {
	pair<int,int> node;
	vector<pair<int,int> > oneList;
	vector<vector<std::pair<int,int> > > adj;

	node = make_pair(1, 4);
	oneList.push_back(node);
	node = make_pair(7, 8);
	oneList.push_back(node);
	adj.push_back(oneList);

	oneList.clear();
	node = make_pair(0, 4);
	oneList.push_back(node);
	node = make_pair(2, 8);
	oneList.push_back(node);
	node = make_pair(7, 11);
	oneList.push_back(node);
	adj.push_back(oneList);

	oneList.clear();
	node = make_pair(1, 8);
	oneList.push_back(node);
	node = make_pair(3, 7);
	oneList.push_back(node);
	node = make_pair(5, 4);
	oneList.push_back(node);
	node = make_pair(8, 2);
	oneList.push_back(node);
	adj.push_back(oneList);

	oneList.clear();
	node = make_pair(2, 7);
	oneList.push_back(node);
	node = make_pair(4, 9);
	oneList.push_back(node);
	node = make_pair(5, 14);
	oneList.push_back(node);
	adj.push_back(oneList);

	oneList.clear();
	node = make_pair(3, 9);
	oneList.push_back(node);
	node = make_pair(5, 10);
	oneList.push_back(node);
	adj.push_back(oneList);

	oneList.clear();
	node = make_pair(2, 4);
	oneList.push_back(node);
	node = make_pair(3, 14);
	oneList.push_back(node);
	node = make_pair(4, 10);
	oneList.push_back(node);
	node = make_pair(6, 2);
	oneList.push_back(node);
	adj.push_back(oneList);

	oneList.clear();
	node = make_pair(5, 2);
	oneList.push_back(node);
	node = make_pair(7, 1);
	oneList.push_back(node);
	node = make_pair(8, 6);
	oneList.push_back(node);
	adj.push_back(oneList);

	oneList.clear();
	node = make_pair(0, 8);
	oneList.push_back(node);
	node = make_pair(1, 11);
	oneList.push_back(node);
	node = make_pair(6, 1);
	oneList.push_back(node);
	node = make_pair(8, 7);
	oneList.push_back(node);
	adj.push_back(oneList);

	oneList.clear();
	node = make_pair(2, 2);
	oneList.push_back(node);
	node = make_pair(6, 6);
	oneList.push_back(node);
	node = make_pair(7, 7);
	oneList.push_back(node);
	adj.push_back(oneList);

	// for (int i = 0; i < adj.size(); i++) {
	// 	cout << "--------- " << i << endl;
	// 	vector<pair<int,int> > temp = adj[i];
	// 		for (int j = 0; j < temp.size(); j++) {
	// 			cout << temp[j].first << ", " << temp[j].second << endl;
	// 		}
	// }
	// cout << "--------- " << endl;
	return adj;
}

void testDjisktra (vector<vector<std::pair<int,int> > > adj, int sourceNode){
	Djisktra* djisktra = new Djisktra();
	pair<vector<int>, unordered_map<int, int> > output = djisktra->runDjisktra(adj, sourceNode);
	vector<int> distances = output.first;
	unordered_map<int, int> nodeToParentMapping = output.second;

	for (int i = 0; i < adj.size(); i++) {
		cout << i << ", " << distances[i] << endl;
	}

	cout << "--------- " << endl;

	for (auto i : nodeToParentMapping) {
		cout << i.first << ", " << i.second << endl;
	}
}

void testPrims (vector<vector<std::pair<int,int> > > adj, int sourceNode){
	Prims* prims = new Prims();
	unordered_map<int, int> nodeToParentMapping = prims->runPrims(adj, sourceNode);

	for (auto i : nodeToParentMapping) {
		cout << i.first << ", " << i.second << endl;
	}
}

int main()
{
	//testBinHeap();
	vector<vector<std::pair<int,int> > > adj = getAdj();
	testDjisktra(adj, 0);
	// testPrims(adj, 0);
	return 0;
}