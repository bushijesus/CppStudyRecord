#include "stdafx.h"
#include <iostream>
using namespace std;

class Solution693 {
public:
	bool hasAlternatingBits(int n) {
		while (n)
		{
			if (((n & 3) == 3) || ((n & 3) == 0))
			{
				return false;
			}
			n >>= 1;
		}
		return true;
	}
};