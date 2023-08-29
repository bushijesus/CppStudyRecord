#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution2639 {
	int getMaxStrLength(const vector<int>& obj) {
		int max_length = 0;
		for (int i : obj)
		{
			string tmp = to_string(i);
			max_length = max(max_length, static_cast<int>(tmp.size()));
		}
		return max_length;
	}
public:
	vector<int> findColumnWidth(const vector<vector<int>>& grid) {
		vector<vector<int>> newGrid(grid[0].size());
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[i].size(); ++j)
			{
				newGrid[j].push_back(grid[i][j]);
			}
		}
		vector<int> result;
		for (int i = 0; i < newGrid.size(); ++i)
		{
			result.push_back(getMaxStrLength(newGrid[i]));
		}
		return result;
	}
};