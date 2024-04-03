#include <ctime>
#include <algorithm>
#include <random>
#include "../include/graph.h++"
#include "../include/Truba.h++"

int
main()
{
	// Define the number of vertices and edges
	int numVertices = 12;
	int numEdges = 17;
	Graph g(numVertices);
	// Initialize a random number generator
	std::mt19937 gen(time(NULL));

	// Create edges randomly
	for (int i = 0; i < numEdges; ++i)
	{
		int from = gen() % numVertices;
		int to = gen() % numVertices;

		g.addEdge(from, to);
	}

	// Initialize Python
	Truba tube{};
	constexpr char c[] = "cmd ../venv/Scripts/activate.bat\n";

	// Check if creation was successful
	try
	{
		tube.pipe(c);
//		tube.printf("pip install -r ../requirements.txt\n");
		tube.printf("python ../scripts/plot.py\n");
	}
	catch (std::exception &ex)
	{
		ex.what();
		exit(EXIT_FAILURE);
	}

	tube.printf("%d\n", numVertices);

	// Loop to add edges to the graph
	for (int i = 0; i < g.getNumVertices(); ++i)
		for (int j = 1; j < g.getNumVertices(); ++j)
			if (g.getEdge(i, j))
				tube.printf("%d\n%d\n", i, j);

	tube.printf("-1");

	return 0;
}