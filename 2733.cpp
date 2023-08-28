#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution2733 {
public:
	int findNonMinOrMax(vector<int>& nums) {
		if (nums.size() <= 2) return -1;
		sort(nums.begin(), nums.end());
		return nums[1];
	}
};
