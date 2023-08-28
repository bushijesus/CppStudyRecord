#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution2815 {
	int maxDigit(int num) {
		int maxNum = -1;
		while (num)
		{
			int tmp = num % 10;
			maxNum = maxNum > tmp ? maxNum : tmp;
			num /= 10;
		}
		return maxNum;
	}
public:
	int maxSum(vector<int>& nums) {
		vector<int> addNum;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (maxDigit(nums[i]) == maxDigit(nums[j]))
				{
					addNum.push_back(nums[i] + nums[j]);
				}
			}
		}
		if (!addNum.empty())
		{
			return *max_element(addNum.begin(), addNum.end());
		}
		else
			return -1;
	}
};