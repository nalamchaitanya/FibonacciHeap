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
#include <chrono>
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
	Prims* prims = new Prims();
	unordered_map<int, int> output;
	auto start = chrono::high_resolution_clock::now();
	if(heapType == 0)
		output = prims->runPrimsWithBin(adj, 0);
	else
		output = prims->runPrimsWithFib(adj, 0);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
	cout << duration.count() << endl;
	// printResult({{},output});
	return 0;
}