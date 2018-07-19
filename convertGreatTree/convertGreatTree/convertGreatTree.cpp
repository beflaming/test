// convertGreatTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<stack>
#include<iostream>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution{
public:
	TreeNode * convertGreaterI(TreeNode *root) {
		if (!root) return NULL;
		int sum = 0;
		helper(root, sum);
		return root;
	}
	void helper(TreeNode * &node, int sum) {
		if (!node) return;
		helper(node->right, sum);
		node->val += sum;
		sum = node->val;
		helper(node->left, sum);
	}
	TreeNode *convertBST(TreeNode *root) {
		if (!root) return NULL;
		convertBST(root->right);
		root->val += xum;
		xum = root->val;
		convertBST(root->left);
		return root;
	}
	TreeNode *convertBSTII(TreeNode *root) {
		if (!root) return NULL;
		int vum = 0;
		stack<TreeNode*> st;
		TreeNode *p = root;
		while (p || !st.empty()) {
			while (p) {
				st.push(p);
				p = p->right;
			}
			p = st.top(); st.pop();
			p->val += vum;
			vum = p->val;
			p = p->left;
		}
		return root;
	}
private:
	int xum = 0;
};

int main()
{
    return 0;
}

