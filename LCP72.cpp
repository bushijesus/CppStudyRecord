#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class SolutionLCP72 {
public:
	// �ϲ�vector�е�Ԫ��,��֤Ԫ�ظ�������
	void mergeElements(vector<int>& suppliesVec, int targetSize) {

		if (suppliesVec.size() <= targetSize) {
			return;
		}

		// �����ϲ�Ԫ��    
		vector<int> merged(suppliesVec.size() - 1);
		for (int i = 0; i < merged.size(); ++i) {
			merged[i] = suppliesVec[i] + suppliesVec[i + 1];
		}

		// �ҳ���С�ĺϲ�ֵ
		int minIndex = min_element(merged.begin(), merged.end()) - merged.begin();

		// �ϲ���С������Ԫ��
		suppliesVec[minIndex] += suppliesVec[minIndex + 1];
		suppliesVec.erase(suppliesVec.begin() + minIndex + 1);

		// �ݹ����
		mergeElements(suppliesVec, targetSize);
	}

	vector<int> supplyWagon(vector<int>& supplies) {
		if (supplies.size() <= 1) return {};
		mergeElements(supplies, supplies.size() / 2);
		return supplies;
	}
};