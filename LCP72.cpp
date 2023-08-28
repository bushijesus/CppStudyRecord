#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class SolutionLCP72 {
public:
	// 合并vector中的元素,保证元素个数减半
	void mergeElements(vector<int>& suppliesVec, int targetSize) {

		if (suppliesVec.size() <= targetSize) {
			return;
		}

		// 两两合并元素    
		vector<int> merged(suppliesVec.size() - 1);
		for (int i = 0; i < merged.size(); ++i) {
			merged[i] = suppliesVec[i] + suppliesVec[i + 1];
		}

		// 找出最小的合并值
		int minIndex = min_element(merged.begin(), merged.end()) - merged.begin();

		// 合并最小的两个元素
		suppliesVec[minIndex] += suppliesVec[minIndex + 1];
		suppliesVec.erase(suppliesVec.begin() + minIndex + 1);

		// 递归调用
		mergeElements(suppliesVec, targetSize);
	}

	vector<int> supplyWagon(vector<int>& supplies) {
		if (supplies.size() <= 1) return {};
		mergeElements(supplies, supplies.size() / 2);
		return supplies;
	}
};