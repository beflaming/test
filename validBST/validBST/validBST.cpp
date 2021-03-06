// validBST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<stack>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution {
private:
	TreeNode * lastNode=NULL;
public:
	bool isValidBST(TreeNode *root) {
		if (root == NULL) return true;
		if (!isValidBST(root->left)) return false;
		if (lastNode != NULL && lastNode->val >= root->val) return false;
		lastNode = root;
		return isValidBST(root->right);
	}
};

//Recursion without inorder traversal
class Solution1 { 
public:
	bool isValidBST(TreeNode *root) {
		return validBST(root, LONG_MIN, LONG_MAX);
	}

	bool validBST(TreeNode *root, long lmin, long lmax) {
		if (!root) return true;
		if (root->val <= lmin || root->val >= lmax) return false;
		return validBST(root->left, lmin, root->val) && validBST(root->right, root->val, lmax);
	}
};

//left<=root<right (BST), inorder can't do for left<=root.
//Recursion
class Solution2 {
public:
	bool isValidBST(TreeNode *root) {
		if (!root) return true;
		vector<int> vals;
		inorder(root, vals);

	}
	void inorder(TreeNode *root, vector<int> &vals) {
		if (!root) return;
		inorder(root->left, vals);
		vals.push_back(root->val);
		inorder(root->right, vals);
	}
};

//still Recursion
class Solution3 {
public:
	TreeNode *pre;
	bool isValidBST(TreeNode *root) {
		int res = 1;
		pre = NULL;
		inorder(root, res);
		if (res == 1) 
			return true;
		else
			return false;
	}
	void inorder(TreeNode *root, int &res) {
		if (!root) return;
		inorder(root->left, res);
		if (!pre) 
			pre = root;
		else {
			if (root->val <= pre->val) res = 0;
			pre = root;
		}
		inorder(root->right, res);
	}
};

//Non-Recursion with stack
class Solution4 {
public:
	bool isValidBST(TreeNode *root) {
		stack<TreeNode *> s;
		TreeNode *p = root, *pre = NULL;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			TreeNode  *t = s.top(); s.pop();
			if (pre && t->val <= pre->val) return false;
			pre = t;
			p = t->right;
		}
		return true;
	}
};

//MOrris Traversal
class Solution5 {
public:
	bool isValidBST(TreeNode *root) {
		if (!root) return true;
		TreeNode *cur = root, *pre, *parent = NULL;
		bool res = true;
		while (cur) {
			if (!cur->left) {
				if (parent && parent->val >= cur->val) res = false;
				parent = cur;
				cur = cur->right;
			}
			else {
				pre = cur->left;
				while (pre->right && pre->right != cur) pre = pre->right;
				if (!pre->right) {
					pre->right = cur;
					cur = cur->left;
				}
				else {
					pre->right = NULL;
					if (parent->val >= cur->val) res = false;
					parent = cur;
					cur = cur->right;
				}
			}
		}
		return res;
	}
};

int main()
{
    return 0;
}

