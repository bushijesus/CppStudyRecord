#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution57 {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
// 		for (int i = 1 ; i < intervals.size(); ++i)
// 		{
// 			// ��˵�λ�������ڲ�
// 			if (newInterval[0] >= intervals[i - 1][0] && newInterval[0] <= intervals[i - 1][1])
// 			{
// 				// ��������һ��
// 				if (newInterval[1] < intervals[i][0])
// 				{
// 					intervals[i - 1] = vector<int>(intervals[i - 1][0], newInterval[1]);
// 				}
// 				// ���õ���һ��
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
// 					// ɾ��i + 1λ�õ�Ԫ��
// 					advance(intervals.begin(), i);
// 					intervals.erase(intervals.begin());
// 				}
// 			}
// 			// ��˵�λ��ǰ�����ⲿ
// 			if (newInterval[0] < intervals[i - 1][0])
// 			{
// 
// 			}
// 		}
	}
};