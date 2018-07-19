// atoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//blank issue; sign issue; string to integer issue;
class myAtoi{
public:
	int Datoi(string &str) {
		if (str == "") return 0;
		int sign=1, i=0, n=str.length();
		while (i < n && str[i] == ' ') ++i;
		if (str[i] == '+' || str[i] == '-') {
			sign = (str[i++] == '+') ? 1 : -1;
		}
		long long base = 0;
		for (i; i < n; ++i) {
			if (str[i]<'0' || str[i]>'9') break;
			base = base * 10 + (str[i] - '0');
			if (base > INT_MAX) break;
		}
		base *= sign;
		if (base > INT_MAX) return INT_MAX;
		if (base < INT_MIN) return INT_MIN;
		return base;
	}
};
int main()
{
    return 0;
}

