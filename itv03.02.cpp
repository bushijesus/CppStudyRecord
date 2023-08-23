#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack()
		: min_elem(INT_MAX)
	{
	}

	void push(int x) {
		vec.push_back(x);
		min_elem = *min_element(vec.begin(), vec.end());
	}

	void pop() {
		vec.pop_back();
		min_elem = *min_element(vec.begin(), vec.end());
	}

	int top() {
		return vec[vec.size() - 1];
	}

	int getMin() {
		return min_elem;
	}
private:
	vector<int> vec;
	int min_elem;
};