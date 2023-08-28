#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class SolutionLCR003 {
public:
	vector<int> countBits(int n) {
		vector<int> count(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			count[i] = count[i >> 1] + (i & 1);
		}
		return count;
	}
};