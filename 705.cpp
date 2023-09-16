#include "stdafx.h"
#include <unordered_set>
using namespace std;

class MyHashSet {
public:
	MyHashSet() {

	}

	void add(int key) {
		us.insert(key);
	}

	void remove(int key) {
		us.erase(key);
	}

	bool contains(int key) {
		return us.find(key) != us.end();
	}
private:
	unordered_set<int> us;
};