#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class Solution14 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result = "";
		int minSize = INT_MAX;
		for (auto& s : strs) {
			minSize = min(minSize, static_cast<int>(s.size()));
		}
		int flag = 0;
		while (flag < minSize) {
			for (int i = 0; i < strs.size(); ++i) {
				if (strs[i][flag] != strs[0][flag]) {
					return result;
				}
			}
			result += strs[0][flag];
			flag++;
		}
		return result;
	}
};
