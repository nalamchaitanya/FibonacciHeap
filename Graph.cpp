#include <iostream>
#include <fstream>

vector<vector<std::pair<int,int> > > getGraph(string fileName, int* nodes = NULL, int* edges = NULL)
{
	ifstream fin(fileName, std::ifstream::in);
	int lines;
	fin >> lines;
	*nodes = lines;
	*edges = 0;
	vector<vector<std::pair<int,int> > > adj(lines);
	for(int i = 0;i<lines;i++)
	{
		int label, degree;
		fin >> label >> degree;
		int weight;
		*edges += degree;
		vector<pair<int,int> > list(degree);
		for(int j = 0;j<degree;j++)
		{
			fin >> label >> weight;
			list[j] = make_pair(label, weight);
		}
		adj[i] = list;
	}
	*edges /= 2;
	return adj;
}

void printGraph(vector<vector<std::pair<int,int> > > adj)
{
	for (int i = 0; i < adj.size(); i++) {
	cout << "--------- " << i << endl;
	vector<pair<int,int> > temp = adj[i];
		for (int j = 0; j < temp.size(); j++) {
			cout << temp[j].first << ", " << temp[j].second << endl;
		}
	}
	cout << "--------- " << endl;
}

void printResult(pair<vector<int>, unordered_map<int, int> > output)
{
	vector<int> distances = output.first;
	unordered_map<int, int> nodeToParentMapping = output.second;
	for (int i = 0; i < distances.size(); i++)
	{
		cout << i << ", " << distances[i] << endl;
	}

	cout << "--------- " << endl;

	for (auto i : nodeToParentMapping) {
		cout << i.first << ", " << i.second << endl;
	}
}