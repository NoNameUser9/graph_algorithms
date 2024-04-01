//
// Created by User on 18.03.2024.
//

#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include "graph.h++"
#include <matplotlibcpp.h++>

//std::vector<int> g[maxn];
//
//void bfs(int s) {
//	std::queue<int> q;
//	q.push(s);
//
//	std::vector<int> d(n, -1), p(n);
//	d[s] = 0;
//
//	while (!q.empty()) {
//		int v = q.front();
//		q.pop();
//		for (int u : g[v]) {
//			if (d[u] == -1) {
//				q.push(u);
//				d[u] = d[v] + 1;
//				p[u] = v;
//			}
//		}
//	}
//	while (v != s) {
//	cout << v << endl;
//	v = p[v];
//	}
//}

namespace plt = matplotlibcpp;

using namespace std;

//void bfs(TreeNode* root) {
//    if (!root) return;
//
//    vector<vector<int>> levels;
//    queue<TreeNode*> q;
//    q.push(root);
//
//    while (!q.empty()) {
//        int level_size = q.size();
//        vector<int> current_level;
//
//        for (int i = 0; i < level_size; i++) {
//            TreeNode* current_node = q.front();
//            q.pop();
//            current_level.push_back(current_node->val_);
//
//            if (current_node->left_) q.push(current_node->left_);
//            if (current_node->right_) q.push(current_node->right_);
//        }
//
//        levels.push_back(current_level);
//    }
//
//    // Визуализация уровней дерева при помощи matplotlibcpp
//    plt::title("BFS tree traversal");
//
//    for (int i = 0; i < levels.size(); i++) {
//        vector<double> x(levels[i].size());
//        vector<double> y(levels[i].size());
//        for (int j = 0; j < levels[i].size(); j++) {
//            x[j] = j;
//            y[j] = -i; // Отрицательное значение уровня для отображения вверху
//        }
//        plt::named_plot("Level " + std::to_string(i), x, y, "o");
//    }
//
//    plt::legend();
//    plt::show();
//}
