// serialization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<queue>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
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
public:
	string Serialization(TreeNode *root) {
		std::ostringstream out;
		std::queue<TreeNode*> q;
		if (root) q.push(root);
		while (!q.empty()) {
			TreeNode *t = q.front(); q.pop();
			if (t) {
				out << t->val<< ' ';
				q.push(t->left);
				q.push(t->right);
			}else {
				out<< "#";
			}
		}
		return out.str();
	}
	
	TreeNode* deserialization(string &data) {
		
		if (data.empty()) return nullptr;
		std::istringstream in(data);
		queue<TreeNode *> q;
		string val;
		in >> val;
		TreeNode *res = new TreeNode(stoi(val)), *cur = res;
		q.push(cur);
		while (!q.empty()) {
			TreeNode *t = q.front(); q.pop();
			if (!(in >> val)) break;
			if (val != "#") {
				cur = new TreeNode(stoi(val));
				q.push(cur);
				t->left = cur;
			}
			if (!(in >> val)) break;
			if (val != "#") {
				cur = new TreeNode(stoi(val));
				q.push(cur);
				t->right = cur;
			}
		}
		return res;
	}
	
};

class SolutionDFS {
public:
	//Recursion
	string serial(TreeNode *root) {
		ostringstream out;
		serialize(root, out);
		return out.str();
	}
	TreeNode *deserial(string data) {
		istringstream in(data);
		deserialize(in);
	}
private:
	void serialize(TreeNode *root, ostringstream &out) {
		if (root) {
			out << root->val << ' ';
			serialize(root->left, out);
			serialize(root->right, out);
		}
		else {
			out << "#";
		}
	}
	TreeNode *deserialize(istringstream &in) {
		string val;
		in >> val;
		if (val == "#") return nullptr;
		TreeNode *root = new TreeNode(stoi(val));
		root->left = deserialize(in);
		root->right = deserialize(in);
		return root;
	}
};

int main()
{
    return 0;
}


