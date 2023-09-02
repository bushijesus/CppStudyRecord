#include "stdafx.h"
#include <set>
#include <string>
using namespace std;

class Solution2716 {
public:
	int minimizedStringLength(string s) {
		set<char> st;
		for (char i : s)
		{
			st.insert(i);
		}
		return st.size();
	}
};