// Jun7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		vector<int> res;
		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); ++i) {
			m[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); ++i) {
			int t = target - nums[i];
			if (m.count(t) && m[t] != i) {
				res.push_back(i);
				res.push_back(m[t]);
				break;
			}
		}
		return res;
	}

	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());

		for (int k = 0; k < nums.size(); ++k) {
			if (nums[k] > 0) break;
			if (k > 0 && nums[k] == nums[k - 1]) continue;
			int target = 0 - nums[k];
			int i = k + 1, j = nums.size() - 1;
			while (i<j) {
				if (nums[i] + nums[j] == target) {
					res.push_back({nums[k],nums[i],nums[j]});
					while (i < j && nums[i] == nums[i + 1]) ++i;
					while (i < j && nums[j] == nums[j + 1]) --j;
					++i;
					--j;
				}
				else if (nums[i] + nums[j] < target) ++i;
				else --j;
			}
		}
		return res;
	}
};


class Solution1 {
public:
	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());

		for (int k = 0; k < nums.size(); ++k) {
			if (nums[k] > 0) break;
			if (k > 0 && nums[k] == nums[k - 1]) continue;

			int i = k, j = nums.size()-1;
			int target = 0 - nums[k];
			while (i<j) {
				if (nums[i] + nums[j] == target) {
					res.push_back({ nums[k],nums[i],nums[j] });
					while (i < j && nums[i] == nums[i + 1]) ++i;
					while (i < j && nums[j] == nums[j + 1]) --j;
					++i;
					--j;
				}
				else if (nums[i] + nums[j] < target) {
					++i;
				}
				else
					--j;
			}
		}
		return res;
	}

	vector<int> twoSum(vector<int> &nums, int target) {
		vector<int> res;
		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); ++i) {
			m[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); ++i) {
			int t = target - nums[i];
			if (m.count(t) && m[t] != i) {
				res.push_back(i);
				res.push_back(m[t]);
				break;
			}
		}
		return res;
	}

	int threeSumCloset(vector<int> &nums, int target) {
		if (nums.size() < 3) return 0;
		int closet = nums[0] + nums[1] + nums[2];
		int diff = abs(target - closet);
		 
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i) {
			int left = i + 1, right = nums.size() - 1;
			while (left<right) {
				int sum = nums[i] + nums[left] + nums[right];
				int newDiff = abs(sum-target);
				if (newDiff < diff) {
					diff = newDiff;
					closet = sum;
				}
				if (sum < target) ++left;
				else
					--right;
			}
		}
		return closet;
	}

	int threeSumSmallest(vector<int> &nums, int target) {
		if (nums.size() < 3) return 0;
		int res = 0;

		sort(nums.begin(),nums.end());
		for (int k = 0; k < nums.size() - 2; ++k) {
			int left = k + 1, right = nums.size() - 1;
			while (left < right) {
				if (nums[k] + nums[left] + nums[right] < target) {
					res += right - left;
					++left;
				}
				else {
					--right;
				}
			}
		}
		return res;
	}

	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		if (nums.size() < 4) return NULL;
		set<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; ++i) {
			for (int j = i+1; j < nums.size() - 2; ++j) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int left = j + 1, right = nums.size() - 1;
				while (left<right) {
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						vector<int> out{ nums[i],nums[j],nums[left],nums[right] };
						res.insert(out);
						++left;
						--right;
					}
					else if (sum<target) {
						++left;
					}
					else {
						--right;
					}
				}
			}
			return vector<vector<int>>(res.begin(), res.end());
		}
	} 
};
/*
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
*/
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};
class Solution2 {
public:
	ListNode * mergeTwoSortedList(ListNode *a1, ListNode *a2) {
		ListNode *dummy=new ListNode(-1),
	}
};
int main()
{
    return 0;
}

