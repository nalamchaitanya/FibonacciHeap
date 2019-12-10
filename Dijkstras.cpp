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

void testDjisktra (vector<vector<std::pair<int,int> > > adj, int sourceNode)
{
	Djisktra* djisktra = new Djisktra();
	pair<vector<int>, unordered_map<int, int> > output = djisktra->runDjisktraWithBin(adj, sourceNode);
	vector<int> distances = output.first;
	unordered_map<int, int> nodeToParentMapping = output.second;

	for (int i = 0; i < adj.size(); i++)
	{
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