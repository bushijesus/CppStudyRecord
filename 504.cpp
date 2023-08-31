#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution504 {
public:
	string convertToBase7(int num) {
		if (num == 0) return "0";
		string s = "";
		string sign = num > 0 ? "" : "-";
		num = num > 0 ? num : -num;
		while (num)
		{
			if (num % 7 == 0)
			{
				s = '0' + s;
			}
			else if (num % 7 == 1)
			{
				s = '1' + s;
			}
			else if (num % 7 == 2)
			{
				s = '2' + s;
			}
			else if (num % 7 == 3)
			{
				s = '3' + s;
			}
			else if (num % 7 == 4)
			{
				s = '4' + s;
			}
			else if (num % 7 == 5)
			{
				s = '5' + s;
			}
			else
			{
				s = '6' + s;
			}
			num /= 7;
		}
		return sign + s;
	}
};