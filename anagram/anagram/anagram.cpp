// anagram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

//647 find all anagram in a string
class Solution1 {
public:
	vector<int> findAnagram(string &s, string &p) {
		if (s.empty()) return {};
		vector<int> res, cnt(128,0);
		int ns = s.size(), ps = p.size(), i=0;
		for (char c : p) ++cnt[c];
		while (i<ns) {
			bool success = true;
			vector<int> tmp = cnt;
			for (int j = i; j < i + ns;++j) {
				if (--tmp[s[j]]<0) {
					success = false;
					break;
				}
			}
			if (success) {
				res.push_back(i);
			}
		}
		return res;
	}
};

class Solution2 {
public:
	vector<int> findAnagram(string &s, string &p) {
		if (s.empty()) return {};
		vector<int> res, cnt(256,0);
		int left = 0, right = 0, m = p.size(), n = s.size();
		for (char c : p) ++cnt[c];
		while (right<n) {
			if (cnt[s[right++]]-- >= 1) --m;
			if (m == 0) res.push_back(left);
			if (right - left == p.size() && cnt[s[left++]]++ >= 0) ++m;
		}
		return res;
	}
};
int main()
{
    return 0;
}

