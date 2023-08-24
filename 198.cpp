#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution198 {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		int len = nums.size();
		vector<int> dp(len);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < len; ++i)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		if (nums[0] != 0)
		{
			return dp[len - 2];
		}
		else
		{
			return dp[len - 1];
		}
	}
};