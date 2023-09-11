#include "stdafx.h"
#include <vector>
using namespace std;

class Solution566 {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		vector<vector<int>> result(r, vector<int>(c));
		int originalRow = mat.size();
		int originalCol = mat[0].size();
		if (originalRow * originalCol != r * c) return mat;
		int row = 0;
		int col = 0;
		for (int i = 0; i < originalRow; ++i)
		{
			for (int j = 0; j < originalCol; ++j)
			{
				result[row][col] = mat[i][j];
				col++;
				if (col == c)
				{
					col = 0;
					row++;
				}
			}
		}
		return result;
	}
};
