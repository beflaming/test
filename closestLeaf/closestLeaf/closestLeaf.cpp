// closestLeaf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
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

class Solution {
private:
	unordered_map<int, vector<int>> neighbors;
	unordered_set<int> leaves;
public:
	void dfs(TreeNode *root) {
		if (!root->left && !root->right) {
			leaves.insert(root->val);
		}
		int cv = root->val;
		if (root->left) {
			int leftv = root->left->val;
			neighbors[cv].push_back(leftv);
			neighbors[leftv].push_back(cv);
			dfs(root->left);
		}
		if (root->right) {
			int rightv = root->right->val;
			neighbors[cv].push_back(rightv);
			neighbors[rightv].push_back(cv);
			dfs(root->right);
		}
	}
	int findClosestLeaf(TreeNode *root, int k) {
		dfs(root);

		unordered_set<int> visited;
		queue<int>	q;
		q.push(k);

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (leaves.find(cur) != leaves.end()) {
				return cur;
			}
			visited.insert(cur);

			for (auto next:neighbors[cur]) {
				if (visited.find(next)==visited.end()) {
					q.push(next);
				}
			}
		}
		return 0;
	}
};

int main()
{
    return 0;
}

