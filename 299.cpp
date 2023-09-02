#include "stdafx.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution299 {
public:
	string getHint(string secret, string guess) {
		unordered_map<char, int> store;
		int bulls = 0;
		int cows = 0;

		for (int i = 0; i < secret.size(); ++i) {
			if (secret[i] == guess[i]) {
				bulls++; // λ�ú�ֵ����ȷ��bulls��1
			}
			else {
				store[secret[i]]++; // �洢secret�г��ֵ��ַ�������ִ���
			}
		}

		for (int i = 0; i < guess.size(); ++i) {
			if (secret[i] != guess[i] && store[guess[i]] > 0) {
				cows++; // ֵ��ȷ��λ�ò���ȷ��cows��1
				store[guess[i]]--; // �뵱ǰguess�ַ�ƥ���secret�ַ��Ѿ�ʹ�ã���������ִ���
			}
		}

		string ret = to_string(bulls) + "A" + to_string(cows) + "B";
		return ret;
	}
};