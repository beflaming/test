// ValidAnagram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
	bool validAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		int m[26] = { 0 };
		for (int i = 0; i < s.size(); ++i) ++m[s[i] - 'a'];
		for (int j = 0; j < t.size(); ++j) {
			if (--m[t[j] - 'a'] < 0) return false;
		}
		return true;
	}

	vector<vector<string>> groupAnagram(vector<string> &strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> m;

		for (int i = 0; i < strs.size();++i) {
			vector<int> cnt(26,0);
			string t = "";
			int 
		}
	}
};


int main()
{
    return 0;
}

