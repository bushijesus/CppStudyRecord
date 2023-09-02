#include "stdafx.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution205 {
public:
	bool isIsomorphic(string s, string t) {
		if (s.length() != t.length()) {
			return false;
		}

		unordered_map<char, char> sToT;
		unordered_map<char, char> tToS;

		for (int i = 0; i < s.length(); i++) {
			char cs = s[i];
			char ct = t[i];

			if (sToT.count(cs) > 0) {
				if (sToT[cs] != ct) {
					return false;
				}
			}
			else {
				sToT[cs] = ct;
			}

			if (tToS.count(ct) > 0) {
				if (tToS[ct] != cs) {
					return false;
				}
			}
			else {
				tToS[ct] = cs;
			}
		}

		return true;
	}
};