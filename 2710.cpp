#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution2710 {
public:
	string removeTrailingZeros(string num) {
		int flag = 0;
		string result = "";
		for (int i = num.size() - 1; i >= 0; --i)
		{
			if (num[i] != '0')
			{
				flag = i;
				break;
			}
		}
		for (int j = 0; j <= flag; ++j)
		{
			result += num[j];
		}
		return result;
	}
};