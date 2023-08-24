#include "stdafx.h"
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution414 {
public:
	int thirdMax(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}

		set<int> uniqueNums(nums.begin(), nums.end());
		if (uniqueNums.size() < 3) {
			return *max_element(uniqueNums.begin(), uniqueNums.end());
		}

		auto it = uniqueNums.rbegin();
		advance(it, 2);  // 获取第三大的元素
		return *it;
	}
};