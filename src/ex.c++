#include <ctime>
#include <algorithm>
#include <random>
#include "../include/graph.h++"
#include "../include/Truba.h++"

//int
//main()
//{
//    // Define the number of vertices and edges
//    int numVertices = 12;
//    int numEdges = 17;
//    Graph g(numVertices);
//    // Initialize a random number generator
//    std::mt19937 gen(time(NULL));
//
//    // Create edges randomly
//    for (int i = 0; i < numEdges; ++i)
//    {
//        int from = gen() % numVertices;
//        int to = gen() % numVertices;
//        printf("from %d to %d\n", from, to);
//        g.addEdge(from, to);
//        g.addEdge(to, from);
//    }
//
//    // Initialize Python
////	Truba tube{};
//    constexpr char c[] = "cmd ../venv/Scripts/activate.bat\n";
//
//    // Check if creation was successful
////	try
////	{
////		tube.pipe(c);
//////		tube.printf("pip install -r ../requirements.txt\n");
////		tube.printf("python ../scripts/plot.py\n");
////	}
////	catch (std::exception &ex)
////	{
////		ex.what();
////		exit(EXIT_FAILURE);
////	}
//
////    tube.pipe(c);
////    tube.printf("python ../scripts/plot.py\n");
////    tube.printf("%d\n%d\n", g.getEdge(i), j);
////	tube.printf("%d\n", numVertices);
////    g.printGraph();
//g.printGraph();
////    g.DFS(1);
//    // Loop to add edges to the graph
////	for (int i = 0; i < g.getNumVertices(); ++i)
////		for (int j = 1; j < g.getNumVertices(); ++j)
//////			if (g.getEdge(i, j))
//////			if (g.getEdge(i, j))
////				tube.printf("%d\n%d\n", g.getEdge(i)., j);
//
////	tube.printf("-1");
////    g.dfs(1);
//    return 0;
//}


int
main()
{
    setlocale(LC_ALL, "rus");


    Graph2 graph = ch();

    int choice = -1;
    while (choice != 0)
    {
        cout << "0. Выход\n";
        cout << "1. Алгоритм обхода в ширину\n";
        cout << "2. Алгоритм обхода в глубину\n";
        cout << "3. Алгоритм Косораджу\n";
        cout << "4. Алгоритмы построения остова наименьшего веса\n";
        cout << "5. Алгоритм Беллмана-Мура\n";

//        tube.pipe("");


//        printf("adffs%d\n", 1);
//        printf ("Hi %с %d %s", 'c', 10, "there!");
        cout << "Выбор: ";
//        tube.printf("%d", 1);
//        printf("\n%d\n", 1);
        cin >> choice;
//        choice = 2;

        switch (choice)
        {
            case 1:
            {
                graph.BFS(0);
                break;
            }
            case 2:
            {
                graph.DFS(0);
                break;
            }
            case 3:
            {
                graph.Kosaraji();
                break;
            }
            case 4:
            {
                graph.Kruskal();
                graph.Prima();
                break;
            }
            case 5:
            {
                int v;
                cout << "Введите начальную вершину: ";
                cin >> v;
                graph.BellmanFord(v);
                break;
            }
            default:break;
        }

    }
}
