// circularArray.cpp : Defines the entry point for the console application.
// 
/*循环必须是一个方向的就是说不能跳到一个数，再反方向跳回来，这不算一个loop。比如[1, -1]就不是一个loop，而[1, 1]是一个正确的loop。看到论坛中一半的帖子都是各种需要clarify和不理解test case就感觉很好笑～博主也成功踩坑了。弄清楚了题意后来考虑如何做，由于从一个位置只能跳到一个别的位置，而不是像图那样一个点可以到多个位置，所以这里我们就可以根据坐标建立一对一的映射，一旦某个达到的坐标已经有映射了，说明环存在，当然我们还需要进行一系列条件判断。首先我们需要一个visited数组，来记录访问过的数字，然后我们遍历原数组，如果当前数字已经访问过了，直接跳过，否则就以当前位置坐标为起始点开始查找，进行while循环，将当前位置在visited数组中标记true，然后计算下一个位置，计算方法是当前位置坐标加上对应的数字，由于是循环数组，所以结果可能会超出数组的长度，所以我们要对数组长度取余。当然上面的数字也可能是负数，加完以后可能也是负数，所以光取余还不够，还得再补上一个n，使其变为正数。此时我们判断，如果next和cur相等，说明此时是一个数字的循环，不符合题意，再有就是检查二者的方向，数字是正数表示forward，若是负数表示backward，在一个loop中必须同正或同负，我们只要让二者相乘，如果结果是负数的话，说明方向不同，直接break掉。此时如果next已经有映射了，说明我们找到了合法的loop，返回true，否则建立一个这样的映射，继续循环
*/

#include "stdafx.h"
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
	bool circArray(vector<int> &nums) {
		unordered_map<int, int> m;
		int n = nums.size();
		vector<bool> visited(n,false);
		for (int i = 0; i<n; ++i) {
			if (visited[i]) continue;
			int cur = i;
			while (true) {
				visited[cur] = true;
				int next = (cur + nums[cur]) % n;
				if (next < 0) next += n;
				if (next == cur || nums[next] * nums[cur] < 0) break;
				if (m.count(next)) return true;
				m[cur] = next;
				cur = next;
			}
		}
		return false;
	}
};

int main()
{
    return 0;
}

