#include "stdafx.h"
#include <map>
#include <iostream>
using namespace std;

class Solution387 {
public:
	int firstUniqChar(string s) {
		map<char, int> mp;
		for (int i = 0; i < s.size(); ++i)
		{
			mp[s[i]]++;
		}
		for (int i = 0; i < s.size(); ++i)
		{
			if (mp[s[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};