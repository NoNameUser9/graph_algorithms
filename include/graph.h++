//
// Created by User on 18.03.2024.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
//#include <matplotlibcpp.h++>
//using namespace std;
//namespace plt = matplotlibcpp;

// A simple undirected graph represented as an adjacency matrix
class Graph
{
private:
	int numVertices;
	std::vector<std::vector<bool>> adjMatrix;

public:
	Graph(int n) : numVertices(n)
	{
		adjMatrix.resize(n, std::vector<bool>(n, false));
	}

	void
	addEdge(int u, int v)
	{
		adjMatrix[u][v] = true;
		adjMatrix[v][u] = true;
	}

	void
	printGraph()
	{
		for (int i = 0; i < numVertices; ++i)
		{
			for (int j = 0; j < numVertices; ++j)
			{
				std::cout << adjMatrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	bool
	getEdge(int i, int j)
	{
		return adjMatrix[i][j];
	}

	auto
	getNumVertices()
	{
		return numVertices;
	}
};

// Initialize graph

// Add edges

// Print the graph
