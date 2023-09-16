#include "stdafx.h"
#include <unordered_map>
using namespace std;

class MyHashMap {
public:
	MyHashMap() {

	}

	void put(int key, int value) {
		um[key] = value;
	}

	int get(int key) {
		auto it = um.find(key);
		return it == um.end() ? -1 : it->second;
	}

	void remove(int key) {
		um.erase(key);
	}
private:
	unordered_map<int, int> um;
};