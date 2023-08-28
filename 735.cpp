#include "stdafx.h"
#include <vector>
#include <stack>
#include <iostream>
#include <cstdlib>
using namespace std;


class Solution735 {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> st;
		for (int i = 0; i < asteroids.size(); ++i) {
			// ����������ջ
			if (asteroids[i] > 0) {
				st.push(asteroids[i]);
			}
			// �������ǱȽ�
			else {
				while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
					st.pop();
				}
				if (st.empty() || st.top() < 0) {
					st.push(asteroids[i]);
				}
				else if (st.top() == abs(asteroids[i])) {
					st.pop();
				}
			}
		}

		vector<int> result(st.size());
		for (int i = st.size() - 1; i >= 0; --i) {
			result[i] = st.top();
			st.pop();
		}

		return result;
	}
};