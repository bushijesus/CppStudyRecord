#include "stdafx.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int distributeCandies(vector<int>& candyType) {
		if (candyType.empty()) return 0;

		unordered_map<int, int> mp;
		for (int i : candyType) {
			mp[i]++;
		}

		int n = candyType.size();
		int maxCandies = n / 2; // 每人最多分到的糖果种类数
		int uniqueCandies = mp.size(); // 不同种类的糖果数

		return min(maxCandies, uniqueCandies);
	}
};
