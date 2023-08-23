#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class SolutionItv08_03 {
public:
	int findMagicIndex(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i == nums[i])
			{
				return i;
			}
		}
		return -1;
	}
};