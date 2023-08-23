#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution62 {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
		{
			dp[0][i] = 1;
		}
		for (int j = 0; j < m; ++j)
		{
			dp[j][0] = 1;
		}
		for (int k = 1; k < m; ++k)
		{
			for (int l = 1; l < n; ++l)
			{
				dp[k][l] = dp[k - 1][l] + dp[k][l - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};