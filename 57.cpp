#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution57 {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
// 		for (int i = 1 ; i < intervals.size(); ++i)
// 		{
// 			// 左端点位于区间内部
// 			if (newInterval[0] >= intervals[i - 1][0] && newInterval[0] <= intervals[i - 1][1])
// 			{
// 				// 够不到下一个
// 				if (newInterval[1] < intervals[i][0])
// 				{
// 					intervals[i - 1] = vector<int>(intervals[i - 1][0], newInterval[1]);
// 				}
// 				// 够得到下一个
// 				else
// 				{
// 					if (newInterval[1] <= intervals[i][1])
// 					{
// 						intervals[i - 1] = vector<int>(intervals[i - 1][0], intervals[i][1]);
// 					}
// 					else
// 					{
// 						intervals[i - 1] = vector<int>(intervals[i - 1][0], newInterval[1]);
// 					}
// 					// 删除i + 1位置的元素
// 					advance(intervals.begin(), i);
// 					intervals.erase(intervals.begin());
// 				}
// 			}
// 			// 左端点位于前区间外部
// 			if (newInterval[0] < intervals[i - 1][0])
// 			{
// 
// 			}
// 		}
	}
};