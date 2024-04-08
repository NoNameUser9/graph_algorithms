//
// Created by User on 18.03.2024.
//

#pragma once

#include <iostream>
//#include <fstream>
//#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <windows.h>
#include <set>
#include "Truba.h++"

using namespace std;


// ������������� �����


// A simple undirected graph represented as an adjacency matrix
class Graph
{
    int numVertices;
    list<int>* adjLists;
//    bool* visited;
    Truba tube{};
    map<int, bool> visited;
public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
//        visited = new bool[vertices];
        constexpr char c[] = "cmd ../venv/Scripts/activate.bat\n";
        tube.pipe(c);
        tube.printf("python ../scripts/plot.py\n");
    }

    ~Graph()
    {

        tube.flush();
    }

    // ���������� �����
    void
    addEdge(int src, int dest)
    {
        adjLists[src].push_front(dest);
    }

    void
    sort()
    {
        for (unsigned int i = 0; i < numVertices; ++i)
            adjLists[0].sort();
    }

    void
    printGraph(unsigned int vert, int mode)
    {
        std::vector<std::vector<bool>> verts;
        verts.resize(numVertices, std::vector<bool>(numVertices, false));

        tube.printf("%d\n", numVertices);
        for (int i = 0; i < numVertices; ++i)
        {
            auto adjList = adjLists[i];

            for (auto it : adjList)
            {
                for (auto it2 : adjLists[it])
                {
                    verts[it][it2] = true;
                    std::cout << "ita " << it << " ita2 " << it2 << "\n";
                }
            }
            std::cout << std::endl;

        }

        for (int i = 0; i < numVertices; ++i)
            for (int j = 1; j < numVertices; ++j)
                if (verts[i][j])
                {
                    std::cout << i << " " << j << "\n";
                    tube.printf("%d\n%d\n", i, j);
                }

        tube.printf("-1\n");
        sort();
        for (int i = 0; i < numVertices; ++i)
        {
            auto adjList = adjLists[i];
            for (auto it : adjList)
            {
                cout << "\n" << it << "\n";
                for (auto it2 : adjLists[it])
                    cout << "it " << it << " " << it2 << "\n";
            }
        }

        switch (mode)
        {
            case 1:
            {
                DFS(vert);
                break;
            }
            case 2:
            {
                BFS(vert);
                break;
            }
            default:break;
        }

        tube.printf("-1\n");
    }

//
    auto
    getEdge(int i, int j)
    {
        return adjLists[i];
//        return adjMatrix[i][j];
    }

    [[nodiscard]] auto
    getNumVertices() const
    {
        return numVertices;
    }

    void
    DFS(unsigned int v)
    {
        // Mark the current node as visited and
        // print it
        visited[v] = true;
        cout << v << " ";
        tube.printf("%d\n", v);
        // Recur for all the vertices adjacent
        // to this vertex
        list<int>::iterator i;
        for (i = adjLists[v].begin(); i != adjLists[v].end(); ++i)
            if (!visited[*i])
                DFS(*i);
    }

    void
    BFS(unsigned int start)
    {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int current = q.front();
            std::cout << current << " ";
            q.pop();

            for (int neighbor : adjLists[current])
            {
                if (!visited[neighbor])
                {
                    cout << neighbor << " ";
                    tube.printf("%d\n", neighbor);
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

};

class Graph2
{
public:
    struct Edge
    {
        int source;
        int target;
        int weight;

        Edge(int s, int t, int w) : source(s), target(t), weight(w) {}
    };
    struct Point
    {
        int x;
        int y;
    };
    int peaks; // ���������� ������ � �����
    vector<vector<Edge>> table;

    Graph2(int V) : peaks(V), table(V) {}
    void
    add_edge(int a, int b, int weight)
    {
        //Edge _a(b, weight);
        //Edge _b(a, weight);
        table[a].emplace_back(a, b, weight);

    }
    void
    BFS(int start)
    {
        Truba tube{};
        constexpr char c[] = "cmd ../venv/Scripts/activate.bat\n";
        tube.pipe(c);
        tube.printf("python ../scripts/plot.py\n");
        tube.printf("%d\n", peaks);

        Sleep(500);

        vector<bool> visited(peaks, false);
        visited[start] = true;

        queue<int> q;
        q.push(start);

        vector<Point> xy(peaks);

        for (auto it = 0; it < peaks; ++it)
            for (auto it2 : table[it])
                if (it2.target != -1)
                    tube.printf("%d\n%d\n%d\n", it2.source, it2.target, it2.weight);

        Sleep(500);

        cout << "\n";
        tube.printf("%d\n", -1);

        while (!q.empty())
        { // ���� ���� ������� (����������) � �������
            int curr = q.front();

            cout << curr << " ";
            tube.printf("%d\n", curr);

            q.pop();

            for (auto edge : table[curr])
            { // ������� ���� �������
                if (!visited[edge.target])
                { // ���� ����� �� �������
                    visited[edge.target] = true; // �������� ������
                    q.push(edge.target); // ��������� ������ � �������
                }
            }
        }
        cout << "\n";
        Sleep(500);
        tube.printf("%d\n", -1);
        tube.flush();
    }
    void
    DFS(int start)
    {
        Truba tube{};
        constexpr char c[] = "cmd ../venv/Scripts/activate.bat\n";
        tube.pipe(c);
        tube.printf("python ../scripts/plot.py\n");
        tube.printf("%d\n", peaks);

        Sleep(500);

        vector<bool> visited(peaks, false);
        stack<int> s;
        vector<Point> xy(peaks);

        s.push(start);

        for (auto it = 0; it < peaks; ++it)
            for (auto it2 : table[it])
                if (it2.target != -1)
                    tube.printf("%d\n%d\n%d\n", it2.source, it2.target, it2.weight);

        Sleep(500);

        cout << "\n";
        tube.printf("%d\n", -1);

        while (!s.empty())
        {
            int curr = s.top();
            s.pop();

            if (!visited[curr])
            {
                cout << curr << " ";
                tube.printf("%d\n", curr);

                visited[curr] = true;
            }

            for (auto edge : table[curr])
                if (!visited[edge.target])
                    s.push(edge.target);
        }

        cout << "\n";
        Sleep(500);
        tube.printf("%d\n", -1);
        tube.flush();
    }
    // dfs ��� ��������� ���������
    bool
    _dfs(int curr, int des, vector<vector<Edge> >& adj, vector<int>& vis)
    {
        if (curr == des)
            return true;
        vis[curr] = 1;
        for (auto x : adj[curr])
            if (!vis[x.target])
                if (_dfs(x.target, des, adj, vis))
                    return true;
        return false;
    }
    bool
    dfs(int scr, int des, vector<vector<Edge> >& adj)
    {
        vector<int> vis(adj.size() + 1, 0);
        return _dfs(scr, des, adj, vis);
    }
    void
    Kosaraji()
    {
        Truba tube{};
        constexpr char c[] = "cmd ../venv/Scripts/activate.bat\n";
        tube.pipe(c);
        Sleep(500);
        tube.printf("python ../scripts/plot.py\n");
        tube.printf("%d\n", peaks);

        Sleep(500);
        // �������� ���� scc
        vector<vector<int>> ans;
        // ������ ��� scc
        vector<int> is_scc(peaks + 1, 0);

        Sleep(500);

        cout << "\n";
        // ����� ���� ������
        for (int i = 0; i < peaks; i++)
        {
            if (!is_scc[i])
            {
                // ���� ������� i �� �������� ������ scc
                // ��������� ������� � ����� ������ scc �
                // ��������� ������� ������ ������
                // (����� �� ��� ���� ������ ��� ������)

                vector<int> scc;
                scc.push_back(i);
                for (int j = i + 1; j < peaks; j++)
                {
                    // ���� ���������� ���� �� ������� i ��
                    // ������� j (� ��������)
                    // �������� ������� j � ������� ������ scc
                    if (!is_scc[j] && dfs(i, j, table) && dfs(j, i, table))
                    {
                        is_scc[j] = 1;
                        scc.push_back(j);
                    }
                }
                // ��������� scc � �������� i � ������������� ������
                ans.push_back(scc);
            }
        }

        vector<vector<int>> t;
        vector<int> tt;
        vector<int> sz;
        int num_sz = 0;
        cout << "SCC:\n";

        for (auto x : ans)
        {
            int now = 0;
            for (auto y : x)
            {
                tt.push_back(y);
                cout << y << " ";
                now++;
            }

            if (tt.size() > 1)
            {
                t.resize(num_sz + 1);
                sz.push_back(0);
                for (int i : tt)
                {
                    t[num_sz].push_back(i);
                    sz[num_sz]++;
                }
                num_sz++;
            }

            tt.clear();

            cout << "\n";
        }
        cout << "sad\n";

        for (int i = 0; i < num_sz; ++i)
        {
            int prev = 0;
            for (auto it = 1; it < t[i].size(); ++it)
            {
                printf("%d %d %d\n", t[i][it - 1], t[i][it], table[prev].back().weight);
                tube.printf("%d\n%d\n%d\n", t[i][it - 1], t[i][it], table[prev].back().weight);
                prev = it;
            }
            printf("%d %d %d\n", t[i].back(), t[i].front(), table[prev].back().weight);

            tube.printf("%d\n%d\n%d\n", t[i].back(), t[i].front(), table[prev].back().weight);
        }

        tube.printf("%d\n", -1);

        for (int i = 0; i < sz[i]; ++i)
        {
            for (int it : t[i])
                tube.printf("%d\n", it);
            tube.printf("%d\n", t[i].front());
        }

        tube.printf("%d\n", -1);
        tube.flush();
    }
    // ���������� ��������� ��� �������� / �����
    static void
    insertion_sort(vector<Edge>& edges)
    {
        int n = edges.size();
        for (int i = 1; i < n; ++i)
        {
            Edge key = edges[i];
            int j = i - 1;

            while (j >= 0 && edges[j].weight > key.weight)
            {
                edges[j + 1] = edges[j];
                --j;
            }
            edges[j + 1] = key;
        }
    }
    // ����� ����� ������, � �������� ����������� �������� �������
    int
    find_set(vector<int>& parent, int vertex)
    {
        // ���� ������� �������� ������ ��������� - ���������� ��
        if (parent[vertex] == -1)
            return vertex;

        // ���� ����� �� ������, ���� �� ������ ������
        return find_set(parent, parent[vertex]);
    }
    // ������� ��� �������� �������� �� ���������� ����� ���� � �������� ������
    bool
    cycle(vector<int>& parent, int vertex)
    {
        return find_set(parent, vertex) == find_set(parent, 0);
    }
    // ������� ��� ����������� ��������
    void
    union_set(vector<int>& parent, int a, int b)
    {
        // ������� ����� ��� � � �
        int root_a = find_set(parent, a);
        int root_b = find_set(parent, b);

        // ������������ ���� ������ � ������� (������ ������ ������ ������ ��������� �������)
        parent[root_a] = root_b;
    }
    void
    Kruskal()
    {
        vector<Edge> all_edges, result;
        // �������� ��� ����� � ���� ������
        for (int i = 0; i < peaks; i++)
            for (auto& edge : table[i])
                all_edges.push_back(edge);

        // ��������� �����
        insertion_sort(all_edges);

        vector<int> parent(peaks, -1);

        // �������� �� ������ � ��������� �� � �������� ������
        for (auto& edge : all_edges)
            // ���� ����� �� �������� ����
            if (!cycle(parent, edge.target))
            {
                result.push_back(edge);
                union_set(parent, edge.source, edge.target);
            }
        cout << "�������� ��������:" << endl;
        for (auto& edge : result)
            cout << edge.source << " --" << edge.weight << "--> " << edge.target << endl;
    }
    int
    min_key(vector<int>& key, vector<bool>& in_mst)
    {
        int min = INT_MAX;
        int min_index;

        for (int v = 0; v < peaks; v++)
            if (!in_mst[v] && key[v] < min)
            {
                min = key[v];
                min_index = v;
            }
        return min_index;
    }
    void
    Prima()
    {
        vector<Edge> result;
        vector<int> key(peaks, INT_MAX); // �������� ����� ������
        vector<bool> in_mst(peaks, false); // �������� ��������� �� �������

        key[0] = 0; // �������� � 0 �������

        for (int count = 0; count < peaks - 1; count++)
        {
            // ������� ������� � ��� ����� (�� ����������� � ��������)
            int m_key = min_key(key, in_mst);

            in_mst[m_key] = true;

            // ��������� ����� � ��������
            if (key[m_key] != INT_MAX)
                result.emplace_back(m_key, m_key, key[m_key]);

            // ��������� ���� ������� ������
            for (auto edge : table[m_key])
                if (!in_mst[edge.target] && edge.weight < key[edge.target])
                    key[edge.target] = edge.weight;
        }

        cout << "�������� �����:" << endl;
        for (auto& edge : result)
            cout << edge.source << " --" << edge.weight << "--> " << edge.target << endl;
    }
    void
    print_path(const vector<int>& predecessor, int v)
    {
        if (v == -1)
            return;

        print_path(predecessor, predecessor[v]);
        cout << v << " ";
    }

    void
    BellmanFord(int start_vertex)
    {
        vector<int> distance(peaks, INT_MAX);
        vector<int> predecessor(peaks, -1);

        distance[start_vertex] = 0;

        // ���������� ����� ��� V-1 ���
        for (int i = 0; i < peaks - 1; ++i)
        {
            for (int u = 0; u < peaks; ++u)
            {
                for (const auto& edge : table[u])
                {
                    int v = edge.target;
                    int weight = edge.weight;

                    if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                    {
                        distance[v] = distance[u] + weight;
                        predecessor[v] = u;
                    }
                }
            }
        }

        // �������� ������� ������������� ������
        for (int u = 0; u < peaks; ++u)
        {
            for (const auto& edge : table[u])
            {
                int v = edge.target;
                int weight = edge.weight;

                if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                {
                    cout << "���� �������� ������������� ����." << endl;
                    return;
                }
            }
        }

        // ����� ���������� �����
        cout << "�������� ��������-�����:" << endl;
        for (int v = 0; v < peaks; ++v)
        {
            cout << "�� ������� " << start_vertex << " � " << v << ": ";
            print_path(predecessor, v);
            cout << " (����������: " << distance[v] << ")" << endl;
        }
    }
};

Graph2
ch()
{
    cout << "1. ������������ ����������� ����\n";
    cout << "2. ������ ���� ����\n";
    int ch;
    cout << "�����: ";
    cin >> ch;

    if (ch == 1)
    {
        Graph2 graph(9);
        graph.add_edge(0, 1, 8);
        graph.add_edge(1, 2, 5);
        graph.add_edge(2, 3, 3);
        graph.add_edge(3, 4, 1);
        graph.add_edge(4, 0, 10);
        graph.add_edge(1, 5, 2);
        graph.add_edge(5, 6, 6);
//        graph.add_edge(6, 5, 6);
        graph.add_edge(6, 8, 11);
        graph.add_edge(2, 8, 12);
        graph.add_edge(5, 7, 7);
//        graph.add_edge(7, 5, 4);
        graph.add_edge(7, 8, 4);
        graph.add_edge(8, 7, 4);
        graph.add_edge(8, 5, 7);

        return graph;
    }
    else
    {
        int num;
        cout << "������� ���������� ������: ";
        cin >> num;
        Graph2 graph(num + 1);
        for (int i = 0; i <= num; i++)
        {
            int b, c, key = 0;
            cout << "\n�������: " << i << endl;
            while (key != -1)
            {
                cout << "����� ��������� ������� ������� ������� �������� -1, ����� 0: ";
                cin >> key;
                if (key == -1)
                    break;
                cout << "������� ������� �������: ";
                cin >> b;
                cout << "������� ��� ������� �������: ";
                cin >> c;
                graph.add_edge(i, b, c);
                cout << "������� ���������!\n";
            }
        }
        return graph;
    }
}

