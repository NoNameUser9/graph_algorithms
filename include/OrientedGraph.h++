//
// Created by User on 31.03.2024.
//

#pragma once

#include <iostream>
#include <vector>

class OrientedGraph {
private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adjList;

public:
    OrientedGraph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Directed edge from u to v
    }

    void printGraph() {
        for (int i = 0; i < V; ++i) {
            std::cout << "Vertex " << i << " is connected to:";
            for (int v : adjList[i]) {
                std::cout << " " << v;
            }
            std::cout << std::endl;
        }
    }
};


