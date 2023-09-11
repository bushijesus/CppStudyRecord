#include "stdafx.h"
#include <algorithm>
using namespace std;

class Solution754 {
public:
	int reachNumber(int target) {
		target = abs(target);
		int step = 0;
		int sum = 0;

		while (sum < target || (sum - target) % 2 != 0) {
			step++;
			sum += step;
		}

		return step;
	}
};
