#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution645 {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> result(2);
		map<int, int> mp;
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			mp[nums[i]]++;
		}
		for (int i = 1; i <= len; ++i)
		{
			if (mp[i] == 2)
			{
				result[0] = i;
			}
			if (mp[i] == 0)
			{
				result[1] = i;
			}
		}
		return result;
	}
};