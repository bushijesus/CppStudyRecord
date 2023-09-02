#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution229 {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int len = nums.size();
		unordered_map<int, int> um;
		for (int i : nums)
		{
			um[i]++;
		}
		vector<int> result;
		for (auto a : um)
		{
			if (a.second > len / 3)
			{
				result.push_back(a.first);
			}
		}
		return result;
	}
};