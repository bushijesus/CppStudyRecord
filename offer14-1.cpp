#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class SolutionOffer14_1 {
public:
	int cuttingRope(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 0;
		dp[2] = 1;
		for (int i = 3; i <= n; ++i)
		{
			for (int j = 1; j <= i / 2; ++j)
			{
				dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
			}
		}
		return dp[n];
	}
};