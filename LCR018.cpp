#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class SolutionLCR018 {
public:
	bool isPalindrome(string s) {
		string validAlpha = "";
		for (char i : s)
		{
			if (isupper(i))
			{
				i = tolower(i);
			}
			if (isalnum(i))
			{
				validAlpha += i;

			}
		}
		int left = 0;
		int right = validAlpha.size() - 1;
		while (left <= right)
		{
			if (validAlpha[left] != validAlpha[right])
			{
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};