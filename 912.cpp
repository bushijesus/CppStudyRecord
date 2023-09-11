#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution912 {
public:
	vector<int> sortArray(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums;
	}
};