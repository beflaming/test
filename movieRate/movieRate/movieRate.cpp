// movieRate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<unordered_set>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> topKMovie(vector<int> &rating, vector<vector<int>> &G, int S, int K) {
		int m = G.size();
		int n = m > 0 ? G[0].size() : 0;
		if (m < 0) return NULL;
		vector<int> res;

		unordered_set<vector<int>> st;



	}
};

int main()
{
	vector<vector<int>> contactR = { {1,3},{0,2},{1},{0} };
	vector<int> res, ratingArray = {10, 20, 30, 40};
	int s = 0, k = 2;

	//out=[2,3];
	Solution test1;
	res = test1.topKMovie(ratingArray, contactR, s, k);
    return 0;
}

