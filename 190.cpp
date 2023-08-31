#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution190 {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t result = 0;  // 初始化结果为0
		int bitCount = 32;    // 一共32位
		while (bitCount--) {
			result <<= 1;      // 左移一位，给新的位腾出空间
			result |= n & 1;   // 将 n 的最低位设置到 result 中
			n >>= 1;           // 右移 n，继续处理下一位
		}
		return result;
	}
};