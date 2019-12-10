#include <iostream>
#include <string>
#include <utility>
#include "FibHeap.h"
#include "FibNode.h"
#include "BinNode.h"
#include "BinHeap.h"
#include "Djisktra.h"
#include "Prims.h"
#include "Graph.cpp"
using namespace std;

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		cout << "Give two arguments" << endl;
		return 0;
	}
	vector<vector<std::pair<int,int> > > adj = getGraph(argv[1]);
	int heapType = stoi(argv[2]);
	Djisktra* djisktra = new Djisktra();
	pair<vector<int>, unordered_map<int, int> > output;
	if(heapType == 0)
		output = djisktra->runDjisktraWithBin(adj, 0);
	else
		output = djisktra->runDjisktraWithFib(adj, 0);
	printResult(output);
	return 0;
}