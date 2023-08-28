#include "stdafx.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution2807 {
	// 辗转相除法求最大公约数
	int getMaxCommon(int x, int y) {
		int z = y;
		while (x % y != 0)
		{
			z = x % y;
			x = y;
			y = z;
		}
		return z;
	}
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
		if (head->next == nullptr) return head;
		ListNode* left = head;
		ListNode* right = head->next;
		while (left && right) {
			int mid = getMaxCommon(left->val, right->val);
			ListNode* node = new ListNode(mid);
			left->next = node;
			node->next = right;
			node = nullptr;
			left = right;
			right = left->next;
		}
		return head;
    }
};