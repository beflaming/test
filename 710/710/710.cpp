// 710.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
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
//1112. Set mismatch
class Solution1112 {
public:
	vector<int> setMismatch(vector<int> &nums) {
		if (nums.empty()) return {};
		int n = nums.size();
		vector<int> res(2,0),cnt(n,0);
		for (int i = 0; i < n; ++i) ++cnt[nums[i] - 1];
		for (int i = 0; i < n;++i) {
			if (cnt[i] == 2) {
				res[0] = i+1;
			}
			else if(cnt[i]==0){
				res[1] = i + 1;
			}
		}
		return res;
	}
	vector<int> setMismatchx(vector<int> &nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while(nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
		}
		for (int i = 0; i < n;++i) {
			if (nums[i] != i + 1) return { nums[i], i + 1 };
		}
	}
};


//1101 maximum width of Tree
class Solution1101 {
public:
	int maxWidthTree(TreeNode *root) {
		if (root) return 0;
		vector<int> res;
		leftMap(root, );

	}
	void leftMap(TreeNode *node, vector<int>&nums) {
		if (!node && !node->left && !node->right) return;

	}

	void rightMap(TreeNode *node, vector<int>&nums) {

	}
	void leaf(TreeNode *node, vector<int> &nums) {
	}
};
int main()
{
    return 0;
}

