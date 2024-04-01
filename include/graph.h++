//
// Created by User on 18.03.2024.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
#include <matplotlibcpp.h++>
using namespace std;
namespace plt = matplotlibcpp;

class Graph
{
private:
    unordered_map<int, vector<int>> adjList;

public:
    void
    addEdge(int source, int destination)
    {
        adjList[source].push_back(destination);
        // Для неориентированного графа добавьте следующую строчку
        // adjList[destination].push_back(source);
    }

    void
    saveGraphToFile(const string& filename)
    {
        ofstream file(filename);
        if (!file.is_open())
        {
            cout << "Unable to open file" << endl;
            return;
        }

        for (auto const& [node, neighbors] : adjList)
        {
            file << node << " ";
            for (int neighbor : neighbors)
            {
                file << neighbor << " ";
            }
            file << endl;
        }

        file.close();
    }

    void
    visualizeGraph()
    {
        vector<double> x, y;

        for (auto const& [node, neighbors] : adjList)
        {
            for (int neighbor : neighbors)
            {
                x.push_back(node);
                y.push_back(neighbor);
            }
        }

        plt::plot(x, y, "ro-");
        plt::title("Graph Visualization");
        plt::grid(true);
        plt::show();
    }

    auto size(){
        return adjList.size();
    }

    auto at(size_t idx){
        return adjList[idx].at(0);
    }
};

// Initialize graph

// Add edges

// Print the graph
