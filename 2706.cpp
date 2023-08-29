#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution2706 {
public:
	int buyChoco(vector<int>& prices, int money) {
		sort(prices.begin(), prices.end());
		int totalPay = prices[0] + prices[1];
		if (totalPay > money) return money;
		else return money - totalPay;
	}
};