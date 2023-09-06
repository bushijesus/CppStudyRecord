#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (!root) return nullptr;

		vector<int> inorder;
		inorderTraversal(root, inorder);

		for (int i = 0; i < inorder.size() - 1; ++i) {
			if (inorder[i] == p->val) {
				return new TreeNode(inorder[i + 1]);
			}
		}
		return nullptr;
	}

private:
	void inorderTraversal(TreeNode* root, vector<int>& inorder) {
		if (!root) return;

		inorderTraversal(root->left, inorder);
		inorder.push_back(root->val);
		inorderTraversal(root->right, inorder);
	}
};