#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solutionitv17_10 {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.size() == 0) return -1;
		if (nums.size() == 1) return nums[0];
		map<int, int> map;
		for (auto i : nums)
		{
			map[i]++;
		}
		for (auto i : map)
		{
			if (i.second > nums.size() / 2)
			{
				return i.first;
			}
		}
		return -1;
	}
};