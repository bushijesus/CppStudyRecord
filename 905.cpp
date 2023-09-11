#include "stdafx.h"
#include <vector>
using namespace std;

class Solution905 {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            while (left < right && nums[left] % 2 == 0)
            {
                left++;
            }
            while (left < right && nums[right] % 2 == 1)
            {
                right--;
            }
            if (left < right)
            {
                swap(nums[left++], nums[right--]);
            }
        }
        return nums;
    }
};