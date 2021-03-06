// Uglynumber.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution1 {
public:
	bool isUglyNumber(int n) {
		while (n >= 2) {
			if (n % 2 == 0) {
				n /= 2;
			}
			else if (n % 3 == 0) {
				n /= 3;
			}
			else if (n % 5 == 0) {
				n /= 5;
			}
			else
				return false;
		}
		return n == 1;
	}
};

class Solution2 {
public:
	int nthUglyNumber(int n) {
		vector<int> res(1,1);
		int i2 = 0, i3 = 0, i5 = 0;
		while (res.size()<n) {
			int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
			int mn = min(m2, min(m3, m5));
			if (mn == m2) ++i2;
			if (mn == m3) ++i3;
			if (mn == m5) ++i5;
			res.push_back(mn);
		}
		return res.back();
	}
};

int main()
{
	int t1 = 7, t2=9;
	Solution1 are1;
	Solution2 are2;
	bool rig = are1.isUglyNumber(t1);
	int  chek = are2.nthUglyNumber(t2);
    return 0;
}

