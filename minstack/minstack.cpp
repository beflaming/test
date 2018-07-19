// minstack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stack>
#include<iostream>
using namespace std;

class MinStack {
private:
	stack<int> s1, s2;
public:
	MinStack() {}

	void push(int x) {
		s1.push(x);
		if (s2.empty() || x <= s2.top()) s2.push(x);
	}

	int pop() {
		int res = s1.top();
		if (s1.top() == s2.top()) s2.pop();
		res = s1.top();
		s1.pop();
		return res;
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}
};

class Solution2 {
private:
	int min_val;
	stack<int> st;
public:
	MinStack() {
		min_val=INT_MAX;
	}
//如果需要进栈的数字小于等于当前最小值min_val，那么将min_val压入栈，并且将min_val更新为当前数字。
	void push(int x) {
		if (x <= min_val) {
			st.push(min_val);
			min_val = x;
		}
		st.push(x);
	}

//在出栈操作时，
//先将栈顶元素移出栈，再判断该元素是否和min_val相等，
//相等的话我们将min_val更新为新栈顶元素，再将新栈顶元素移出栈即可
	void pop() {
		int t = st.top(); st.pop();
		if (t == min_val()) {
			min_val = st.top(); st.pop();
		}
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return min_val;
	}
};
int main()
{
    return 0;
}

