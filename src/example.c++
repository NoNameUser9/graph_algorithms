//
// Created by User on 24.03.2024.
//
#include <Python.h>
#include <iostream>
#include "OrientedGraph.h++"
#include "UnorientedGraph.h++"

int main() {
    Py_Initialize(); // Initialize the Python interpreter

    // Execute Python code to import the necessary libraries
    PyRun_SimpleString(
        "import networkx as nx\n"
        "import matplotlib.pyplot as plt\n"
        "import random"
    );

    // Execute Python code to define a function for generating a graph with 12 random vertices
    PyRun_SimpleString(
        "def generate_random_graph():\n"
        "    G = nx.Graph()\n"
        "    num_vertices = 12\n"
        "    for i in range(num_vertices):\n"
        "        G.add_node(i)\n"
        "    for i in range(num_vertices):\n"
        "        for j in range(i+1, num_vertices):\n"
        "            if random.random() < 0.3:  # Adjust the probability of adding an edge as needed\n"
        "                G.add_edge(i, j)\n"
        "    return G\n"
    );

    // Execute Python code to generate and draw the random graph with aligned vertices
    PyRun_SimpleString(
        "random_graph = generate_random_graph()\n"
        "pos = nx.circular_layout(random_graph)\n"  // Use circular layout for better node color visualization
        "nx.draw(random_graph, pos, with_labels=True, font_weight='bold')\n"
        "plt.show()\n"
        "dfs_nodes = list(nx.dfs_tree(random_graph, source=0).nodes)\n"
        "print('DFS Nodes:', dfs_nodes)\n"
        "node_colors = ['b' if node in dfs_nodes else 'gray' for node in random_graph.nodes]\n"
        "for node in dfs_nodes:\n"
        "    plt.cla()\n"
        "    node_colors = ['r' if n == node else 'gray' for n in random_graph.nodes]\n"
        "    nx.draw_networkx_nodes(random_graph, pos, node_color=node_colors)\n"
        "    nx.draw_networkx_edges(random_graph, pos)\n"
        "    nx.draw_networkx_labels(random_graph, pos)\n"
        "    plt.pause(1.0)\n"
        "plt.show()"

    );

    Py_Finalize(); // Finalize the Python interpreter
//    OrientedGraph orientedGraph(5);
//    orientedGraph.addEdge(0, 1);
//    orientedGraph.addEdge(0, 2);
//    orientedGraph.addEdge(1, 3);
//    orientedGraph.addEdge(2, 4);
//    orientedGraph.addEdge(3, 4);
//
//    std::cout << "Oriented Graph:" << std::endl;
//    orientedGraph.printGraph();
//
//    UnorientedGraph unorientedGraph(5);
//    unorientedGraph.addEdge(0, 1);
//    unorientedGraph.addEdge(0, 2);
//    unorientedGraph.addEdge(1, 3);
//    unorientedGraph.addEdge(2, 4);
//    unorientedGraph.addEdge(3, 4);
//
//    std::cout << "\nUnoriented Graph:" << std::endl;
//    unorientedGraph.printGraph();
//
    return 0;
}