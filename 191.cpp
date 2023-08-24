#include "stdafx.h"
#include <iostream>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count_one = 0;
		while (n)
		{
			if (n & 1)
			{
				count_one++;
			}
			n >>= 1;
		}
		return count_one;
	}
};