#include "stdafx.h"
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution1207 {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> um;
		for (int i : arr)
		{
			um[i]++;
		}
		set<int> s;
		for (auto a : um)
		{
			s.insert(a.second);
		}
		return s.size() == um.size();
	}
};