#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class SolutionItv10_01 {
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		for (int i = 0; i < n; ++i)
		{
			A[m + i] = B[i];
		}
		sort(A.begin(), A.end());
	}
};