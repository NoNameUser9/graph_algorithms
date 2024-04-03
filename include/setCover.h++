//
// Created by User on 03.04.2024.
//

#pragma once

#include <vector>
#include <set>
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
		universe.erase(std::remove_if(universe.begin(), universe.end(), [elementsCovered](const std::set<int> &subset)
		{
			for (int element : subset)
				if (elementsCovered.find(element) == elementsCovered.end())
					return false;

			return true;
		}), universe.end());
	}

	return solution;
}