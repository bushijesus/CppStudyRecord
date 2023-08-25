#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution179 {
public:
	string largestNumber(vector<int>& nums) {
		string result = "";
		vector<string> tmp;
		for (const auto& i : nums)
		{
			tmp.push_back(to_string(i));
		}
		sort(tmp.begin(), tmp.end(), [](string& s1, string& s2) {return s1 + s2 > s2 + s1; });
		// 判断元素是否全为0
		bool allZero = true;
		for (const auto& i : tmp)
		{
			if (i != "0")
			{
				allZero = false;
			}
		}
		if (allZero)
		{
			return "0";
		}
		for (const auto& i : tmp)
		{
			result += i;
		}
		return result;
	}
};