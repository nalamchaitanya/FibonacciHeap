#include <iostream>
#include "BinNode.h"
#include "BinHeap.h"
#include "FibNode.h"
#include "FibHeap.h"
#include <math.h>
#include <vector>
#include <utility> 
using namespace std;

#ifndef PRIMS_H
#define PRIMS_H

class Prims
{
public:
	Prims() {
	
	}

	unordered_map<int, int> runPrims(vector<vector<std::pair<int, int> > > adj, int sourceNode) {
		int size = adj.size();
		unordered_map<int, int> nodeToParentMapping(size);
		vector<int> distances(size);

		for (int i = 0; i < size; i++) {
			distances[i] = INT_MAX;
		}

		distances[sourceNode] = 0;

		BinNode<int, int>* node = new BinNode<int, int>(0, sourceNode);
		//FibNode<int, int>* node = new FibNode<int, int>(0, sourceNode);
		BinHeap<int, int>* heap = new BinHeap<int, int>();
		//FibHeap<int, int>* heap = new FibHeap<int, int>();
		heap->Insert(node);

		while (!heap->IsEmpty()) {
			node = heap->ExtractMin();
			int currentNodeIndex = node->data;
			delete node;
			vector<std::pair<int, int> > neighbors = adj[currentNodeIndex];
			for (int i = 0; i < neighbors.size(); i++) {
				if (distances[neighbors[i].first] == INT_MAX) {
					heap->Insert(new BinNode<int, int>(INT_MAX, neighbors[i].first));
					//heap->Insert(new FibNode<int, int>(INT_MAX, neighbors[i].first));
				}
				if (!heap->IsInHeap(neighbors[i].first)) {
					continue;
				}
				if (neighbors[i].second < distances[neighbors[i].first]) {
					distances[neighbors[i].first] = neighbors[i].second;
					nodeToParentMapping[neighbors[i].first] = currentNodeIndex;
					heap->DecreaseKey(neighbors[i].first, distances[neighbors[i].first]);
				}
			}
		}
		return nodeToParentMapping;
	}
};

#endif