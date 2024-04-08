import networkx as nx
import matplotlib.pyplot as plt

n1, n2 = 0, 0
num = int(input())
print("vertices=", num)
G = nx.DiGraph()

for i in range(num):
    G.add_node(i)

# num_edges = int(input())
for i in range(num*num):
    n1 = int(input())
    if n1 == -1:
        break
    n2 = int(input())
    if n2 == -1:
        break
    w = int(input())
    print("iiiii= {0} j = {1} w = {2}".format(n1, n2, w))
    # G.add_weighted_edges_from(n1, n2, w)
    G.add_edge(n1, n2, weight=w)

# dfs_nodes = list(G.nodes)
# print('DFS Nodes:', dfs_nodes)
# dfs_nodes = list(nx.dfs_tree(G, source=0).nodes)
dfs_nodes = []
for i in range(num*num):
    n = int(input())
    print("ii = {0}".format(n))
    if n == -1:
        break
    dfs_nodes.append(n)

pos = nx.circular_layout(G)
# print('DFS Nodes:', dfs_nodes)
node_colors = ['b' if node in dfs_nodes else 'red' for node in G.nodes]
plt.show()

print(dfs_nodes)
# plt.pause(10.0)
for node in dfs_nodes:
    plt.cla()
    node_colors = ['r' if n == node else 'gray' for n in G.nodes]
    nx.draw_networkx_nodes(G, pos, node_color=node_colors)
    nx.draw_networkx_edges(G, pos)
    nx.draw_networkx_labels(G, pos)
    plt.pause(1.0)
plt.show()
