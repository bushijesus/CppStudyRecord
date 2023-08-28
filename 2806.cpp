#include "stdafx.h"
#include <iostream>
using namespace std;

class Solution2806 {
public:
	int accountBalanceAfterPurchase(int purchaseAmount) {
		if (purchaseAmount % 10 == 0) {

		}
		else {
			if (purchaseAmount % 10 > 5)
			{
				purchaseAmount += (10 - (purchaseAmount % 10));
			}
			else if (purchaseAmount % 10 < 5)
			{
				purchaseAmount -= (purchaseAmount % 10);
			}
			else
			{
				purchaseAmount += 5;
			}
		}
		return 100 - purchaseAmount;
	}
};