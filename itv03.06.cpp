#include "stdafx.h"
#include <list>
#include <vector>
#include <iostream>
using namespace std;


class AnimalShelf {
public:
	AnimalShelf() {

	}

	void enqueue(vector<int> animal) {
		ls.push_back(animal);
	}

	vector<int> dequeueAny() {
		if (ls.empty()) {
			return { -1, -1 };
		}
		vector<int> result = ls.front();
		ls.pop_front();
		return result;
	}

	vector<int> dequeueDog() {
		if (ls.empty()) {
			return { -1, -1 };
		}
		vector<int> result = { -1, -1 };
		for (auto iter = ls.begin(); iter != ls.end(); ++iter) {
			if ((*iter)[1] == 1) {
				result = *iter;
				ls.erase(iter);
				break;  // 找到狗后即可跳出循环
			}
		}
		return result;
	}

	vector<int> dequeueCat() {
		if (ls.empty()) {
			return { -1, -1 };
		}
		vector<int> result = { -1, -1 };
		for (auto iter = ls.begin(); iter != ls.end(); ++iter) {
			if ((*iter)[1] == 0) {
				result = *iter;
				ls.erase(iter);
				break;  // 找到猫后即可跳出循环
			}
		}
		return result;
	}

private:
	list<vector<int>> ls;
};


/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */