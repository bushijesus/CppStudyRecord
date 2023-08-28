#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class SolutionLCP50 {
public:
	int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
		for (int i = 0; i < operations.size(); ++i)
		{
			int tmp = 0;
			tmp = gem[operations[i][0]] / 2;
			gem[operations[i][0]] -= tmp;
			gem[operations[i][1]] += tmp;
		}
		return *max_element(gem.begin(), gem.end()) - *min_element(gem.begin(), gem.end());
	}
};

int main() {
	SolutionLCP50 lcp;
	vector<int> gem = { 3,1,2 };
	vector<vector<int>> operations = { {0,2} ,{2,1},{2,0} };
	int result = lcp.giveGem(gem, operations);
	cout << result << endl;
	return 0;
}