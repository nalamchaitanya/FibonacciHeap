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

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		cout << "Give two arguments" << endl;
		return 0;
	}
	vector<vector<std::pair<int,int> > > adj = getGraph(argv[0]);
	int heapType = stoi(argv[1]);
	Djisktra* djisktra = new Djisktra();
	pair<vector<int>, unordered_map<int, int> > output;
	if(heapType == 0)
		output = djisktra->runDjisktraWithBin(adj, sourceNode);
	else
		output = djisktra->runDjisktraWithFib(adj, sourceNode);
	return 0;
}