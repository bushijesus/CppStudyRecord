#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// ´í
class SolutionItv16_15 {
public:
	vector<int> masterMind(string solution, string guess) {
		vector<int> result(2);
		for (int i = 0; i < guess.size(); ++i)
		{
			if (guess[i] == solution[i])
			{
				result[0]++;
			}
			int pos;
			if ((pos = solution.find(guess[i])) != string::npos && guess[i] != solution[i])
			{
				result[1]++;
			}
		}
		return result;
	}
};