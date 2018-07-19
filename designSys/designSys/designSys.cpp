// designSys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<unordered_map>
#include<vector>
#include<set>
#include<map>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Tweet {
public:
	int id;
	int user_id;
	string text;
	static Tweet create(int user_id, string tweet_text) {
         // This will create a new tweet object,
         // and auto fill id
	}
};

class MiniTwitter {
private:
	int cnt;
	unordered_map<int, set<int>> friends;
	unordered_map<int, vector<Tweet>> tweets;

public:
	MiniTwitter() {
		// do intialization if necessary
		cnt = 0;  //time stamp;
	}

	Tweet postTweet(int user_id, string &tweet_text) {
		// write your code here
		Tweet *tw = new Tweet();
		tweets[user_id].emplace_back(cnt++,tweet_text);
		return tw->create(user_id, tweet_text);
	}

	/*
	* @param user_id: An integer
	* @return: a list of 10 new feeds recently and sort by timeline
	*/
	vector<Tweet> getNewsFeed(int user_id) {
		vector<Tweet> res;
		vector<pair<Tweet*, Tweet*>> h;
		for (auto& u : friends[user_id]) {
			auto& t = tweets[u];
			if (t.size()) h.emplace_back(t.data, t.data() + t.size() - 1);
		}
		auto& t = tweets[user_id];
		if (t.size()) h.emplace_back(t.data, t.data() + t.size() - 1);
		auto f = [](const pair<Tweet*, Tweet*>&x, pair<Tweet*, Tweet*>&y) {
			if (x.second->id < y.second->id) {
				return y.second;
			}
			else {
				return x.second;
			}
		};
		make_heap(h.begin(),h.end());
		int n = 10;
		
	}

	/*
	* @param user_id: An integer
	* @return: a list of 10 new posts recently and sort by timeline
	*/
	vector<Tweet> getTimeline(int user_id) {
		vector<Tweet> timeLine;

	}

	void follow(int from_user_id, int to_user_id) {
		if (from_user_id != to_user_id) {
			friends[from_user_id].insert(to_user_id);
		}
	}

	void unfollow(int from_user_id, int to_user_id) {
		if (from_user_id != to_user_id) {
			friends[from_user_id].erase(to_user_id);
		}
	}
};
int main()
{
    return 0;
}

