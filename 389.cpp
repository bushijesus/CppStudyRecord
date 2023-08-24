#include "stdafx.h"
#include <map>
#include <iostream>
using namespace std;

class Solution389 {
public:
	char findTheDifference(string s, string t) {
		map<char, int> mps;
		for (const auto& i : s)
		{
			mps[i]++;
		}
		map<char, int> mpt;
		for (const auto& i : t)
		{
			mpt[i]++;
		}
		for (int i = 0; i < mpt.size(); ++i)
		{
			if (mps[i] != mpt[i])
			{
				return i;
			}
		}
		return 'N';
	}
};