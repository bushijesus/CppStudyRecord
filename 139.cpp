#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>

class Solution139 {
public:
	bool wordBreak(const string& s, vector<string>& wordDict) {
		sort(wordDict.begin(), wordDict.end(), [](const string& a, const string& b) {
			return a.size() < b.size();
			});

		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;

		for (int i = 1; i <= s.size(); ++i) {
			for (const auto& word : wordDict) {
				if (i >= word.size() && s.substr(i - word.size(), word.size()) == word) {
					dp[i] = dp[i] || dp[i - word.size()];
				}
			}
		}

		return dp[s.size()];
	}
};
