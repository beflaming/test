// graycode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<stack>
#include<iostream>
using namespace std;

/*
  The purpose of function is to convert an unsigned binary number to reflected binary Gray Code.
  in binary: 0,1,2,3; in Gray Code: 0,1,3,2
*/
unsigned int binaryToGray(unsigned int num) {
	return (num >> 1) ^ num;
}
/*
  To convert a reflected binary Gray code number to a binary number;
*/
unsigned int grayToBinary(unsigned int num) {
	unsigned int mask;
	for (mask = num >> 1; mask != 0; mask = mask >> 1) {
		num = num ^ mask;
	}
	return num;
}

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		for (int i = 0; i < pow(2,n);++i) {
			res.push_back((i<<1)^i);
		}
		return res;
	}

	//mirror arrangement
	vector<int> gray2(int n) {
		vector<int> res{0};
		for (int i = 0; i < n;++i) {
			int size = res.size();
			for (int j = size - 1; j >= 0;--j) {
				res.push_back(res[j]|(1<<i));
			}
		}
		return res;
	}

	vector<int> grayRec(int n) {
		vector<int> res{0};
		unordered_set<int> s;
		helper(n, s, 0, res);
		return res;
	}
	void helper(int n, unordered_set<int> &s, int out, vector<int> &res) {
		if (!s.count(out)) {
			s.insert(out);
			res.push_back(out);
		}
		for (int i = 0; i < n; ++i) {
			int t = out;
			if ((t&(1 << i)) == 0)
				t |= (1 << i);
			else
				t &= ~(1 << i);
			if (s.count(t)) continue;
			helper(n, s, t, res);
			break;
		}
	}

	vector<int> grayStack(int n) {
		vector<int> res{ 0 };
		unordered_set<int> s;
		stack<int> st;
		st.push(0);
		s.insert(0);
		while (!st.empty()) {
			int t = st.top(); st.pop();
			for (int i = 0; i < n; ++i) {
				int k = t;
				if ((k&(1 << i)) == 0)
					k |= (1 << i);
				else
					k &= ~(1 << i);
				if (s.count(k)) continue;
				s.insert(k);
				st.push(k);
				res.push_back(k);
				break;
			}
		}
		return res;
	}
};

int main()
{
    return 0;
}

