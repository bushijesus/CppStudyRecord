#include "stdafx.h"
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		// dp含义：以i-1结尾的字符串中含有以j-1结尾的子串个数
		vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
		for (int i = 0; i <= t.size(); ++i) dp[0][i] = 0;
		for (int j = 0; j <= s.size(); ++j) dp[j][0] = 1;
		for (int i = 1; i <= s.size(); ++i)
		{
			for (int j = 1; j <= t.size(); ++j)
			{
				if (s[i - 1] == t[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[s.size()][t.size()];
	}
};
