//
// Created by User on 18.03.2024.
//

#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include "graph.h++"

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include "graph.h++"




// Function to perform Depth First Search
void
dfs(Graph& graph, unsigned int start)
{
    std::map<unsigned int, bool> m;
    m[0] = true;
//    std::vector<unsigned int> h;
//    stack<int> s;
//    std::vector<int> stack;
//    stack.push_back(start);
    std::vector<unsigned int> visited;
    visited.push_back(1);
//
    std::stack<int> st;
    st.push(start);

    visited.push_back(start);
    auto current = start;

    std::cout << current << " ";
//    visited[current] = true;

//    for (int i = 0; i < graph.getNumVertices(); ++i)
//    {
//        if (graph.at(current, i) && !visited[i])
//        {
//            dfs(adjMatrix, visited, i);
//        }
//    }

    while (!st.empty())
    {
        int current = st.top();
//        st.pop();

        std::cout << current << " ";

//        for (int i = 0; i < graph.getNumVertices(); ++i)
//            for (int j = 1; j < graph.getNumVertices(); ++j)
//                if (graph.getEdge(i, j))
//                    for (auto neighbor : j graph.at(i, j))
//                    {
//                        if (!visited[neighbor])
//                        {
//                            st.push(neighbor);
//                            visited[neighbor] = true;
//                        }
//                    }
//                    tube.printf("%d\n%d\n", i, j);




    }
}

//int peaks;
//void DFS(int start)
//{
//    srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел
//    vector<bool> visited(peaks, false);
//    stack<int> s;
//    int key = 0;
//    vector<Point> xy(peaks);
//
//    xy[start].x = 300;
//    xy[start].y = 200;
//
//    s.push(start);
//
//    while (!s.empty()) {
//        int curr = s.top();
//        s.pop();
//
//        if (!visited[curr]) {
//
//            cout << curr << " ";
//
//            visited[curr] = true;
//        }
//
//        for (auto edge : table[curr]) {
//            if (!visited[edge.target]) {
//
//                int rndx = rand() % (80 - 20 + 1) + 20;
//                int rndy = rand() % (90 - 20 + 1) + 20;
//                if (key == 0) {
//                    xy[edge.target].x = xy[curr].x + rndx;
//                    key = 1;
//                }
//                else {
//                    xy[edge.target].x = xy[curr].x - rndx;
//                    key = 0;
//                }
//                xy[edge.target].y = xy[curr].y + rndy;
//
//                s.push(edge.target);
//            }
//        }
//    }
//
//}
//}

//// Function to perform Depth First Search
//void dfs(Graph &graph, std::vector<bool> &visited, int start) {
//    std::stack<int> s;
//    s.push(start);
//    visited[start] = true;
//
//    while (!s.empty()) {
//        int current = s.top();
//        s.pop();
//
//        std::cout << current << " ";
//
//        for (int neighbor : graph[current]) {
//            if (!visited[neighbor]) {
//                s.push(neighbor);
//                visited[neighbor] = true;
//            }
//        }
//    }
//}

