#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution190 {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t result = 0;  // ��ʼ�����Ϊ0
		int bitCount = 32;    // һ��32λ
		while (bitCount--) {
			result <<= 1;      // ����һλ�����µ�λ�ڳ��ռ�
			result |= n & 1;   // �� n �����λ���õ� result ��
			n >>= 1;           // ���� n������������һλ
		}
		return result;
	}
};