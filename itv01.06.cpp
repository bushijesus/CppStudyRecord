#include "stdafx.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

char* compressString(char* S) {
	string s = "";
	int left = 0;
	int right = 0;
	int len = strlen(S);

	while (left < len) {
		int tmp = 1;
		while (right + 1 < len && S[right + 1] == S[right]) {
			tmp++;
			right += 1;
		}

		s += S[left];
		s += to_string(tmp);

		left = right + 1;
		right = left;
	}

	char* ret = new char[len];
	strcpy_s(ret, len, s.c_str());
	return ret;
}

//int main() {
//	char * t = "aaabbffffffbccddcddd";
//	char * s = compressString(t);
//	cout << s << endl;
//	return 0;
//}