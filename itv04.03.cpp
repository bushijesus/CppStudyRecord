#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionItv04_03 {
	vector<ListNode*> result;

	void connect(ListNode*& root, int val) {
		ListNode* tmp = new ListNode(val); // �����µĽڵ�
		if (!root) {
			root = tmp;  // ���rootΪ�գ����½ڵ�Ϊͷ�ڵ�
		}
		else {
			ListNode* curr = root;
			while (curr->next) {
				curr = curr->next;
			}
			curr->next = tmp; // ������ĩβ����½ڵ�
		}
	}

public:
	vector<ListNode*> listOfDepth(TreeNode* tree) {
		if (!tree) return result;

		queue<TreeNode*> que;
		que.push(tree);

		while (!que.empty())
		{
			ListNode* head = nullptr; // ͷ�ڵ���Ϊ��
			int size = que.size();

			for (int i = 0; i < size; ++i)
			{
				TreeNode* node = que.front();
				que.pop();

				connect(head, node->val);

				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}

			result.push_back(head);
		}

		return result;
	}
};