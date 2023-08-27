#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.size() == 0) return - 1;
		if (nums.size() == 1) return 0;
		for (int sub = 0; sub < nums.size(); ++sub)
		{
			int leftSum = 0;
			for (int i = 0; i < sub; ++i)
			{
				leftSum += nums[i];
			}
			int rightSum = 0;
			for (int j = sub + 1; j < nums.size(); ++j)
			{
				rightSum += nums[j];
			}
			if (leftSum == rightSum)
			{
				return sub;
			}
		}
		return -1;
	}
};