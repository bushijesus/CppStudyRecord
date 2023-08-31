#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
// Ã»¶®
class Solution779 {
public:
	int kthGrammar(int n, int k) {
		if (n == 1) {
			return 0;
		}

		int parent = kthGrammar(n - 1, (k + 1) / 2);  // Calculate parent position in previous row
		if (k % 2 == 0) {
			// If k is even, the character at position k is the same as its parent
			return parent;
		}
		else {
			// If k is odd, the character at position k is the complement of its parent
			return 1 - parent;
		}
	}
};