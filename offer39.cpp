#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class SolutionOffer39 {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> mp;
		for (auto i : nums)
		{
			mp[i]++;
			if (mp[i] >= (nums.size() / 2))
			{
				return i;
			}
		}
		return 0;
	}
};