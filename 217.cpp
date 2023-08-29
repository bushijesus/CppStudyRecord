#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

using namespace std;
class Solution217 {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int> mp;
		for (int i : nums)
		{
			mp[i]++;
		}
		for (auto i : mp)
		{
			if (i.second > 1)
			{
				return true;
			}
		}
		return false;
	}
};