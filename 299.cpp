#include "stdafx.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution299 {
public:
	string getHint(string secret, string guess) {
		unordered_map<char, int> store;
		int bulls = 0;
		int cows = 0;

		for (int i = 0; i < secret.size(); ++i) {
			if (secret[i] == guess[i]) {
				bulls++; // 位置和值都正确，bulls加1
			}
			else {
				store[secret[i]]++; // 存储secret中出现的字符及其出现次数
			}
		}

		for (int i = 0; i < guess.size(); ++i) {
			if (secret[i] != guess[i] && store[guess[i]] > 0) {
				cows++; // 值正确但位置不正确，cows加1
				store[guess[i]]--; // 与当前guess字符匹配的secret字符已经使用，减少其出现次数
			}
		}

		string ret = to_string(bulls) + "A" + to_string(cows) + "B";
		return ret;
	}
};