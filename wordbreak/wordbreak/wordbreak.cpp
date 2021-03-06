// wordbreak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	int getMaxLength(unordered_set<string> &dict) {
		int maxLength = 0;
		for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
			maxLength = maxLength > (*it).length()? maxLength : (*it).length();
		}
		return maxLength;
	}
	bool wordBreak(string &s, unordered_set<string> &dict) {
		int len = s.size();
		vector<bool> res(len+1,false);
		//dp res[i] = res[i-1]+checking i-j;
		res[0] = true;
		for (int i = 1; i < len; ++i) {
			for (int j = 1; j <= i; ++j) { // j the length
				if (res[i - j] && dict.find(s.substr(i - j, j)) != dict.end()) {
					res[i] = true;
					break;
				}
			}
		}
		return res[len];
	}
	//DFS
	unordered_map<string, vector<string>> m;
	vector<string> wordBreakII(string s, vector<string> &wordDict) {
		if (m.count(s)) return m[s];
		if (m.empty()) return {""};
		vector<string> res;
		for (string word : wordDict) {
			if (s.substr(0, word.size()) != word) continue;
			vector<string> rem = wordBreakII(s.substr(word.size()),wordDict);
			for (string str:rem) {
				res.push_back(word+(str.empty()?"":" ")+str);
			}
		}
		return m[s] = res;
	}
};

class Solution2 {
public:
	int ladderLength(string &beginWord, string &endWord, vector<string> &wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		unordered_map<string, int> m;
		queue<string> q;
		m[beginWord] = 1;
		q.push(beginWord);
		while (!q.empty()) {
			string word = q.front(); q.pop();
			for (int i = 0; i < word.size(); ++i) {
				string newWord = word;
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					newWord[i] = ch;
					// non-exist
					if (dict.find(newWord)!=dict.end() && newWord == endWord) return m[word] + 1;
					// exist in dict but not in the hash table
					if (dict.count(newWord) && !m.count(newWord)) {
						q.push(newWord);
						m[newWord] = m[word] + 1;
					}
				}
			}
		}
		return 0;
	}

	//*"hit"
	// "cog"
    // ["hot","dot","dog","lot","log"]*/
	/* Expected [["hit", "hot", "dot", "dog", "cog"], ["hit", "hot", "lot", "log", "cog"]] */
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
		vector<vector<string>> res;
		unordered_set<string> dict(wordList.begin(),wordList.end());
		vector<string> p{ beginWord };
		queue<vector<string>> paths;
		paths.push(p);
		int level = 1, minLevel = INT_MAX;  //level:current length; minlevel: the shortest length;
		unordered_set<string> words;
		while (!paths.empty()) {
			vector<string> t = paths.front(); paths.pop();
			if (t.size() > level) {
				for (string w : words)  dict.erase(w);
				words.clear();
				level = t.size();
				if (level > minLevel) break;
			}
			string last = t.back();
			for (int i = 0; i < last.size(); ++i) {
				string newLast = last;
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					newLast[i] = ch;
					if (!dict.count(newLast)) continue;
					words.insert(newLast);
					vector<string> nextPath = t;
					nextPath.push_back(newLast);
					if (newLast == endWord) {
						res.push_back(nextPath);
						minLevel = level;
					}
					else {
						paths.push(nextPath);
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	string start1 = "hit", end1 = "cog";
	vector<string> wordL = { "hit","hot","dot","dog","cog" };
	Solution2 sol2,sol2x;
	int nums = sol2.ladderLength(start1, end1, wordL);
	vector<vector<string>> ways=sol2x.findLadders(start1, end1, wordL);
    return 0;
}

