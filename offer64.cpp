#include "stdafx.h"
#include <iostream>
using namespace std;

class SolutionOffer64 {
public:
	int sumNums(int n) {
		if (n == 1)
		{
			return 1;
		}
		return n + sumNums(n - 1);
	}
};