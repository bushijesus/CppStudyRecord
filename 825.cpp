#include "stdafx.h"
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution825 {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> ageCount(121, 0);
        int count = 0;

        for (int age : ages) {
            ageCount[age]++;
        }

        for (int i = 0; i <= 120; ++i) {
            for (int j = 0; j <= 120; ++j) {
                if (i * 0.5 + 7 >= j) continue;
                if (i < j) continue;

                count += ageCount[i] * (ageCount[j] - (i == j ? 1 : 0));
            }
        }
        return count;
    }
};
