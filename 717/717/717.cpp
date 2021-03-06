// 717.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

class Solution983 {
public:
	int baseball(vector<string> &ops) {

	}
};

class Solutionp {
public: 
	int countPrime(int n) {  //sieve of eratoshenes
		vector<bool> num(n-1,true);
		num[0] = false;
		int res = 0;
		int limit = sqrt(n);
		for (int i=2; i<=limit; ++i) {
			if (num[i - 1]) {
				for (int j = i * i; j < n; j+=i) {
					num[j - 1] = false;
				}
			}
		}
		for (int i = 0; i < n-1;++i) {
			if (num[i]) ++res;
		}
		return res;
	}
	int count2(int n) {
		vector<bool> num(n,true);
		int res = 0;
		num[0] = false; //1 not prime
		for (int i = n-1; i >1; --i) {
			for (int j = sqrt(i); j > 1; --j) {
				if (i%j == 0) {
					num[i] = false; break;
				}
			}
			if (num[i]) {
				++res;
				cout << "prime is " << i << endl;
			}
		}
		return res;
	}
};

class Solution1046 {
public:
	int countPrimeSetBits(int L, int R) {
		int res = 0;
		for (int i = L; i <= R;++i) {
			int t = i;
			int cnt = 0;
			while (t>0) {
				if ((t&1)==1) cnt++;
				t >>= 1;
			}
			bool succ = true;
			for (int j = sqrt(cnt); j > 1;--j) {
				if (cnt%j == 0) {
					succ = false; break;
				}
			}
			if (succ && cnt != 1) ++res;
		}
		return res;
	}
	int primeNum1(int L, int R) {
		int res = 0;
		unordered_set<int> primes = { 2,3,5,7,11,13,17,19 };
		for (int i = L; i <= R; ++i) {
			int cnt = 0;
			for (int j = i; j > 0; j>>=1){
				cnt += j & 1;
			}
			res += primes.count(cnt);
		}
		return res;
	}
};

class Solution1054 {
public:
	int minCostClimbingStairs(vector<int> &cost) {
		int n=cost.size();
		vector<int> dp(n,0);
		dp[0] = cost[0];
		dp[1] = cost[1];
		for (int i = 2; i < n; ++i) {
			dp[i] = cost[i]+min(dp[i-1], dp[i-2]);
		}
		return min(dp[n-1],dp[n-2]);
	}
};

class Solution1113 {
public:
	string solveEquation(string &equation) {
	}
};

class Solution1176{
public:
	string optimalDivision(vector<int> &nums) {

	}
};

class Solutionx {
public:
	string complexNumberMultiply(string &a, string &b) {

	}
};

class Solutiony {
public:
	string reverseWords(string &s) {
		int n = s.size();
		int i = 0, j = 0, start = 0;
		while (i < n) {
			while (i < n && s[i] == ' ') ++i;
			if (i < n && j>0) s[j++] = ' ';
			start = j;
			while (i<n&&s[i]!=' ') {
				s[j++] = s[i++];
			}
			reverse(s.begin(), s.begin()+j);
		}
		s.resize(j);
		reverse(s.begin(), s.end());
		return s;
	};
};

int main()
{
	int k = 55, res=0, res2=0;
	Solutionp prime;
	res=prime.countPrime(k);
	res2 = prime.count2(k);
    return 0;
}

