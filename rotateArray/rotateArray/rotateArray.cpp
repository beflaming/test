// rotateArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> rotate(vector<int> &nums, int k){
		if (k == 0) return nums;

		int n = nums.size();
		if (n%k == 0) return nums;
		for (int i = 0; i <k; ++i) {
			int tmp = nums[n-1-i];
			nums[n-1-i] = nums[i];
			nums[i] = tmp;
		}
		vector<int> left(k,0), right(n-k,0);
		for (int i = 0; i < k; ++i) {
			left[i] = nums[i];
		}
		for (int i = k; i < n; ++i) {
			right[i-k] = nums[i];
		}
		for (int i = 0; i<n-k; ++i) {
			int tmp = right[right.size() - 1 - i];
			right[right.size() - 1 - i] = right[i];
			right[i] = tmp;
		}
		for (int i = 0; i < k; ++i) {
			nums[i]=left[i];
			nums[k+i]=right[i];
		}
		return nums;
	}
};

int main()
{
	vector<int> lis = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	Solution ty;
	vector<int> rs = ty.rotate(lis, k);
    return 0;
}

