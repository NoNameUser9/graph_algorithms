//
// Created by User on 18.03.2024.
//

#pragma once

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{
	unsigned int numVertices;
	list<int> *adjLists;

public:
	explicit Graph(unsigned int vertices);

	void
	addEdge(int src, int dest);

	void
	printGraph();
};

// Initialize graph
Graph::Graph(unsigned int vertices)
{
	numVertices = vertices;
	adjLists = new list<int>[vertices];
}

// Add edges
void
Graph::addEdge(int src, int dest)
{
	adjLists[src].push_back(dest);
}

// Print the graph
void
Graph::printGraph()
{
	for (int i = 0; i < numVertices; i++)
	{
		cout << "\n Adjacency list of vertex " << i << "\n head ";
		for (auto x : adjLists[i])
			cout << "-> " << x;
		cout << endl;
	}
}
