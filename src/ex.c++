//
// Created by User on 01.04.2024.
//

#include <iostream>
#include <vector>
#include <set>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Python.h>
#include <string>
#include <algorithm>

std::set<int>
setCover(std::vector<std::set<int>> universe, std::vector<std::set<int>> subsets)
{
    std::set<int> elementsCovered;
    std::set<int> solution;

    while (!elementsCovered.empty() || !universe.empty())
    {
        int bestSubsetIndex = -1;
        int maxUncovered = 0;

        for (int i = 0; i < subsets.size(); ++i)
        {
            int uncovered = 0;
            for (int element : subsets[i])
                if (elementsCovered.find(element) == elementsCovered.end())
                    ++uncovered;

            if (uncovered > maxUncovered)
            {
                maxUncovered = uncovered;
                bestSubsetIndex = i;
            }
        }

        if (bestSubsetIndex == -1)
            break; // No more subsets to cover elements

        for (int element : subsets[bestSubsetIndex])
            elementsCovered.insert(element);

        solution.insert(bestSubsetIndex);
        universe.erase(std::remove_if(universe.begin(), universe.end(), [elementsCovered](const std::set<int>& subset)
        {
            for (int element : subset)
                if (elementsCovered.find(element) == elementsCovered.end())
                    return false;

            return true;
        }), universe.end());
    }

    return solution;
}

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

int
main()
{
    std::srand(std::time(nullptr)); // Seed for random number generation

    int numVertices = 12;
    Graph g(numVertices);

    // Probability of adding an edge between vertices
    double edgeProbability = 0.3;

    // Generate random edges in the graph based on the probability
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = i + 1; j < numVertices; ++j)
        {
            if (std::rand() / (RAND_MAX + 1.0) < edgeProbability)
            {
                g.addEdge(i, j);
            }
        }
    }

    // Print the generated random graph (adjacency matrix representation)
    g.printGraph();
    // Initialize Python
    Py_Initialize();

    // Import the networkx module
    PyObject* py_networkx = PyImport_ImportModule("networkx");
//    PyObject* py_matplotlib = PyImport_ImportModule("matplotlib");
    PyObject* py_plot = PyImport_ImportModule("matplotlib.pyplot");

    // Create a graph in Python
    PyObject* py_graph = PyObject_CallMethod(py_networkx, "Graph", NULL);

    // Check if creation was successful
    if (py_graph == NULL) {
        PyErr_Print();
        Py_Finalize();
        return 1; // Return an error code
    }

    // Loop to add edges to the graph
    for (int i = 0; i < g.getNumVertices(); ++i) {
        for (int j = i; j < g.getNumVertices(); ++j) {
            if (g.getEdge(i, j) == true) {

                // Add an edge to the graph
                PyObject* py_args = PyTuple_Pack(2, PyLong_FromLong(i), PyLong_FromLong(j));
                PyObject_CallMethod(py_graph, "add_edge", "(ii)", i, j); // Corrected the format and passed arguments
                // directly
                std::cout << "vertice i=" << i << ", j=" << j << std::endl;
                // Check for errors
                if (PyErr_Occurred()) {
                    PyErr_Print();
                    Py_DECREF(py_args);
                    Py_DECREF(py_graph);
                    Py_DECREF(py_networkx);
                    Py_Finalize();
                    return 1; // Return an error code
                }
                // Get the nodes in the graph
//                PyObject* nodes = PyObject_CallMethod(py_graph, "nodes", NULL);
//                std::cout << "Number of nodes in the graph: " << PyList_Size(nodes) << std::endl;
                Py_DECREF(py_args);
//                Py_DECREF(nodes);
            }
        }
    }

    // Get the number of nodes in the graph
    PyObject* nodes = PyObject_CallMethod(py_graph, "number_of_nodes", NULL);
    if (nodes == NULL) {
        PyErr_Print();
        Py_DECREF(py_graph);
        Py_DECREF(py_networkx);
        Py_Finalize();
        return 1; // Return an error code
    }

    Py_ssize_t num_nodes = PyLong_AsLong(nodes);
    // Print the number of nodes
    std::cout << "Number of nodes in the graph: " << num_nodes << std::endl;

    PyObject* kwargs = PyDict_New();
    PyDict_SetItemString(kwargs, "with_labels", Py_True);  // Setting with_labels=True
    PyDict_SetItemString(kwargs, "font_weight", PyUnicode_FromString("bold"));  // Setting font_weight='bold'
//    PyDict_SetItemString(kwargs, "ax", Py_None);  // Setting font_weight='bold'
//    PyDict_SetItemString(kwargs, "get_figure", Py_None);  // Setting font_weight='bold'


    PyObject* pos = PyObject_CallMethod(py_networkx, "circular_layout", "O", py_graph);
//    PyObject *with_labelsTrue = PyDict_New();
//    PyDict_SetItemString(with_labelsTrue, "with_labels", Py_True);
//    PyObject *font_weightBold = PyDict_New();
//    PyDict_SetItemString(font_weightBold, "font_weight", "bold");
    // Create a dictionary object to hold node labels
//    PyObject* node_labels = PyDict_New();

    // Set node labels to be the node indices
//    for (Py_ssize_t i = 0; i < num_nodes; i++) {
//        PyObject* label = PyLong_FromSsize_t(i);
//        PyDict_SetItem(node_labels, PyLong_FromSsize_t(i), label);
//    }


    PyObject* py_str_graph = PyObject_Repr(py_graph);
    const char* str_graph = PyUnicode_AsUTF8(py_str_graph);
// Convert the PyObject py_graph to a Python string object
    PyObject* py_graph_str = PyObject_Str(py_graph);
// Prepare the Python code string with py_graph as an argument
    const char* code_template = "graph = %s\nprint('Received graph object:', graph)\n";
    PyObject *args = PyTuple_Pack(1, py_graph_str);  // Pack the argument as a tuple

// Execute the Python code string with the provided argument py_graph
//    PyRun_SimpleString("graph = %s\nprint('Received graph object:', graph)\n", args);


    PyObject* result = PyObject_CallMethod(py_networkx, "draw", "OOO", py_graph, pos, Py_None, kwargs);
    PyRun_SimpleString(
    // Use circular layout for better node color visualization
        "import networkx as nx\n"
        "nx.draw(py_graph, pos, with_labels=True, font_weight='bold')\n"
        "plt.show()\n"

    );

    if (result == NULL) {
        PyErr_Print();
    } else {
        std::cout << "Draw method called successfully\n";
        Py_DECREF(result);
    }
//    PyObject *args = Py_BuildValue("(s)", "with_labels");
//    PyObject *keywords = PyDict_New();
//    PyDict_SetItemString(keywords, "with_labels", Py_True);
//    PyDict_SetItemString(keywords, "font_weight", std::string("bold"));

//    PyObject_Call(PyObject_GetAttrString(py_networkx, "draw"), args, keywords);
    //    std::cout << PyList_GetItem(PyObject_CallMethod(py_graph, "edges", NULL), 1);
    PyObject_CallMethod(py_plot, "show", NULL);
// Call the edges method to get the list of edges
    PyObject* edges = PyObject_CallMethod(py_graph, "edges", NULL);

    PyObject_Print(edges, stdout, Py_PRINT_RAW);
    Py_DECREF(edges);
//    "dfs_nodes = list(nx.dfs_tree(random_graph, source=0).nodes)\n"
//    "print('DFS Nodes:', dfs_nodes)\n"
//    "plt.show()\n"
//    "dfs_nodes = list(nx.dfs_tree(random_graph, source=0).nodes)\n"
//    "print('DFS Nodes:', dfs_nodes)\n"
//    "node_colors = ['b' if node in dfs_nodes else 'gray' for node in random_graph.nodes]\n"
//    "for node in dfs_nodes:\n"
//    "    plt.cla()\n"
//    "    node_colors = ['r' if n == node else 'gray' for n in random_graph.nodes]\n"
//    "    nx.draw_networkx_nodes(random_graph, pos, node_color=node_colors)\n"
//    "    nx.draw_networkx_edges(random_graph, pos)\n"
//    "    nx.draw_networkx_labels(random_graph, pos)\n"
//    "    plt.pause(1.0)\n"
//    "plt.show()"

    Py_DECREF(nodes);
    Py_DECREF(py_graph);
    Py_DECREF(py_plot);
    Py_DECREF(py_networkx);

    // Finalize Python
    Py_Finalize();
    return 0;
}
