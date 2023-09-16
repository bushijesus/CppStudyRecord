#include "stdafx.h"
#include <string>
#include <unordered_map>
using namespace std;

class MapSum {
public:
	MapSum() {}

	void insert(string key, int val) {
		mp[key] = val;
	}

	int sum(string prefix) {
		int count = 0;
		for (const auto& entry : mp) {
			if (entry.first.substr(0, prefix.length()) == prefix) {
				count += entry.second;
			}
		}
		return count;
	}

private:
	unordered_map<string, int> mp;
};
