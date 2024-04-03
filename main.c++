#include "include/graph.h++"
#include "include/breadth-first_search.h++"
#include "include/alg.h++"

// Driver code
#include <iostream>

int main() {
    // Создаем граф
	int numv = 12;
    Graph g{numv};

//    // Добавляем вершины в граф
//    auto v1 = g.add_vertex();
//    auto v2 = g.add_vertex();
//    auto v3 = g.add_vertex();
//    auto v4 = g.add_vertex();

    // Добавляем рёбра
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Выполняем алгоритм Фрюхтермана—Рейнгольдса для размещения вершин
//    graph_tool::sfdp_layout(g);

//    double k = 0.1; // Коэффициент отталкивания
//    for (int i = 0; i < g.size(); i++) {
//        for (int j = 0; j < g.size(); j++) {
//            if (i != j) {
//                double dist = distance(g[i], g[j]);
//                double force = k / (dist * dist);
//                // Обновляем вектора смещения для вершин i и j
//                g[i].dx += force * (g[i].x - g[j].x) / dist;
//                g[i].dy += force * (g[i].y - g[j].y) / dist;
//            }
//        }
//    }
    // Получаем координаты вершин после размещения
//    auto pos = g.vertex_properties["pos"];
//
//    // Выводим координаты вершин
//    for (auto v : g.vertices()) {
//        std::cout << "Vertex " << g.vp[v] << ": " << pos[v][0] << ", " << pos[v][1] << std::endl;
//    }



    vector<Node> graph = {{0, 0.5, 0.1, 0.1}, {0.1, 0.4, 0.1, 0.1}, {2, 2, 0.1, 0.1}};

    graph.push_back(g.at(0));

    auto i = 0;
    while (!isConverged(graph) && i < 10) {
        updatePositions(graph);
        ++i;
    }

    // Вывод итоговых позиций вершин
    for (const auto& node : graph) {
        cout << "x: " << node.x << ", y: " << node.y << endl;
    }

    return 0;
}