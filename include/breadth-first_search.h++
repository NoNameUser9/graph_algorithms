//
// Created by User on 18.03.2024.
//

#pragma once
#include <vector>
#include <queue>

std::vector<int> g[maxn];

void bfs(int s) {
	std::queue<int> q;
	q.push(s);

	std::vector<int> d(n, -1), p(n);
	d[s] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : g[v]) {
			if (d[u] == -1) {
				q.push(u);
				d[u] = d[v] + 1;
				p[u] = v;
			}
		}
	}
	while (v != s) {
	cout << v << endl;
	v = p[v];
	}
}

