#include "stdafx.h"
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class SolutionLCR060 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> mp;
		for (int i : nums) {
			mp[i]++;
		}

		vector<pair<int, int>> data(mp.begin(), mp.end());
		sort(data.begin(), data.end(),
			[](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second > p2.second; });

		vector<int> result;
		for (int i = 0; i < k && i < data.size(); i++) {
			result.push_back(data[i].first);
		}

		return result;
	}

};