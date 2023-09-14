#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

// 双指针
class Solution392 {
public:
	bool isSubsequence(string s, string t) {
		int ps = 0;
		int pt = 0;
		while (ps < s.size() && pt < t.size()) {
			if (s[ps] == t[pt]) {
				ps++;
			}
			pt++;
		}
		return ps == s.size();
	}
};
// 动态规划
class Solution392 {
public:
	bool isSubsequence(string s, string t) {
		vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
		for (int i = 1; i <= s.size(); ++i)
		{
			for (int j = 1; j <= t.size(); ++j)
			{
				if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = dp[i][j - 1];
			}
		}
		return dp[s.size()][t.size()] == s.size();
	}
};
