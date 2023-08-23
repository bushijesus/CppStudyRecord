#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution338 {
public:
	vector<int> countBits(int n) {
		vector<int> v(n + 1, 0); // 初始化结果向量为长度为 n+1 的全零向量
		for (int i = 1; i <= n; ++i) {
			// 对于一个整数 i，其二进制表示中的 1 的个数等于 i/2 的二进制表示中 1 的个数加上 i%2 的值
			v[i] = v[i >> 1] + (i & 1);
		}
		return v;
	}
};