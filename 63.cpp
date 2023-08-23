#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution63 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		{
			return 0;
		}
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < n && obstacleGrid[0][i] == 0; ++i)
		{
			dp[0][i] = 1;
		}
		for (int j = 0; j < m && obstacleGrid[j][0] == 0; ++j)
		{
			dp[j][0] = 1;
		}
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (obstacleGrid[i][j] == 1)
				{
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};