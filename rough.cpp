#include <iostream>

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

	return adj;
}

void testPrims (vector<vector<std::pair<int,int> > > adj, int sourceNode){
	Prims* prims = new Prims();
	unordered_map<int, int> nodeToParentMapping = prims->runPrims(adj, sourceNode);
	for (auto i : nodeToParentMapping) {
		cout << i.first << ", " << i.second << endl;
	}
}