#include "stdafx.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int distributeCandies(vector<int>& candyType) {
		if (candyType.empty()) return 0;

		unordered_map<int, int> mp;
		for (int i : candyType) {
			mp[i]++;
		}

		int n = candyType.size();
		int maxCandies = n / 2; // ÿ�����ֵ����ǹ�������
		int uniqueCandies = mp.size(); // ��ͬ������ǹ���

		return min(maxCandies, uniqueCandies);
	}
};
