#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution345 {
	bool isVowels(char c) {
		char elem = tolower(c);
		if (elem == 'a' || elem == 'e' || elem == 'i' || elem == 'o' || elem == 'u')
		{
			return true;
		}
		return false;
	}
public:
	string reverseVowels(string s) {
		string str = s;
		int left = 0;
		int right = str.size() - 1;
		while (left <= right)
		{
			if (!isVowels(str[left]))
			{
				left++;
				continue;
			}
			if (!isVowels(str[right]))
			{
				right--;
				continue;
			}
			swap(str[left], str[right]);
			left++;
			right--;
		}
		return str;
	}
};