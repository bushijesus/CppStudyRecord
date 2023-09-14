#include "stdafx.h"
#include <vector>
using namespace std;

class Solution1317 {
	bool containZero(int n) {
		while (n) {
			if (n % 10 == 0) {
				return true;
			}
			n /= 10;
		}
		return false;
	}
public:
	vector<int> getNoZeroIntegers(int n) {
		int first = 1;
		while (first <= n / 2) {
			if (!containZero(first) && !containZero(n - first))
			{
				return vector<int>{first, n - first};
			}
			first++;
		}
		return {};
	}
};