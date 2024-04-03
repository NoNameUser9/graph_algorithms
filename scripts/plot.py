import networkx as nx
import matplotlib.pyplot as plt

n1, n2 = 0, 0
num = int(input())

G = nx.Graph()

for i in range(num):
    G.add_node(i)

# num_edges = int(input())
for i in range(num*num):
    n1 = int(input())
    if n1 == -1:
        break
    n2 = int(input())
    print("i= {0}, j = {1}".format(n1, n2))
    G.add_edge(n1, n2)

dfs_nodes = list(nx.dfs_tree(G, source=0).nodes)
# print('DFS Nodes:', dfs_nodes)
pos = nx.circular_layout(G)
# dfs_nodes = list(nx.dfs_tree(G, source=0).nodes)
# print('DFS Nodes:', dfs_nodes)
node_colors = ['b' if node in dfs_nodes else 'red' for node in G.nodes]
plt.show()
# plt.pause(10.0)
for node in dfs_nodes:
    plt.cla()
    node_colors = ['r' if n == node else 'gray' for n in G.nodes]
    nx.draw_networkx_nodes(G, pos, node_color=node_colors)
    nx.draw_networkx_edges(G, pos)
    nx.draw_networkx_labels(G, pos)
    plt.pause(1.0)
plt.show()
