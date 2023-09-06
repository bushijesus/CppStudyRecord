#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution121 {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len == 0) return 0;
		vector<vector<int>> dp(len, vector<int>(2));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < len; ++i)
		{
			dp[i][0] = max(dp[i - 1][0], -prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}
		return dp[len - 1][1];
	}
};