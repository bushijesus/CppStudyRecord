#include "stdafx.h"
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution532 {
public:
	int findPairs(vector<int>& nums, int k) {
		unordered_map<int, int> um;
		set<pair<int, int>> store; // 使用set来存储唯一的数对

		for (int i : nums) {
			um[i]++;
		}

		for (int i : nums) {
			if (k > 0 && um[i + k] > 0) {
				store.insert({ i, i + k });
			}
			else if (k == 0 && um[i] > 1) {
				store.insert({ i, i });
			}
		}

		return store.size();
	}
};