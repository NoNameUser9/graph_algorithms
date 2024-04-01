//
// Created by User on 24.03.2024.
//

#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    double x, y;
    double dx, dy;
};

double distance(Node a, Node b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

void updatePositions(vector<Node>& graph) {
    double k = 0.1; // Коэффициент отталкивания

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            if (i != j) {
                double dist = distance(graph[i], graph[j]);
                double force = k / (dist * dist);
                graph[i].dx += force * (graph[i].x - graph[j].x) / dist;
                graph[i].dy += force * (graph[i].y - graph[j].y) / dist;
            }
        }
    }

    double c = 0.01; // Коэффициент притяжения

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            // Здесь нужно добавить обработку связей между вершинами и вычисление сил притяжения
        }
    }

    double maxDisplace = 0.5; // Максимальное смещение

    for (int i = 0; i < graph.size(); i++) {
        double len = sqrt(graph[i].dx * graph[i].dx + graph[i].dy * graph[i].dy);
        if (len > 0) {
            double d = min(maxDisplace, len);
            graph[i].x += (graph[i].dx / len) * d;
            graph[i].y += (graph[i].dy / len) * d;
        }
    }
}

bool isConverged(const vector<Node>& graph) {
    double threshold = 0.001; // Порог для равновесия

    for (const auto& node : graph) {
        if (abs(node.dx) > threshold || abs(node.dy) > threshold) {
            return false; // Не достигнуто равновесие
        }
    }

    return true; // Достигнуто равновесие
}
