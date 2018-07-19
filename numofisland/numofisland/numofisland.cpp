// numofisland.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

class SolutionNI {
public:
	int numDistIsland(vector<vector<int>> &grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = m > 0 ? grid[0].size() : 0;
		int res = 0;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				numIslandDFS(grid, visited, i, j);
				++res;
			}
		}
		return res;
	}
	void numIslandDFS(vector<vector<int>>&grid, vector<vector<bool>>& visited, int x, int y) {
		if (x < 0 || x>=grid.size()) return;
		if (y < 0 || y>=grid[0].size()) return;
		if (grid[x][y] != 1 &&visited[x][y]) return;
		visited[x][y] = true;
		numIslandDFS(grid, visited, x - 1, y);
		numIslandDFS(grid, visited, x + 1, y);
		numIslandDFS(grid, visited, x, y - 1);
		numIslandDFS(grid, visited, x, y + 1);
	}
};

class Solutio434 {
public:   //unionFind
	int numDistIsland(vector<vector<int>> &grid) {
	}
};

class Solution804 {
public:
	int numDisShape(vector<vector<int>> &grid) {
		if (grid.size() || grid[0].size()) return 0;
		int m = grid.size(), n = m > 0 ? grid[0].size() : 0;
		set<vector<pair<int, int>>> res;


	}
};

class Solution860 {
public:
	vector<vector<int>> dirs{ {0,-1},{-1,0},{0,1},{1,0} };
//save to the array
	int numDistIsland(vector<vector<int>> &grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size();
		int n = m > 0 ? grid[0].size() : 0;
		set<vector<pair<int, int>>> res;
		for (int i = 0; i < m;++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] != 1) continue;
				vector<pair<int, int>> v;
				helper(grid,v,i,j,i,j);
				res.insert(v);
			}
		}
		return res.size();
	}
	void helper(vector<vector<int>>&grid, vector<pair<int, int>>&v, int x0, int y0, int i, int j) {
		int m = grid.size(), n = m > 0 ? grid.size() : 0;
		if (i<0 || i>=m || j<0 || j>=n || grid[i][j] <= 0) return;
		grid[i][j] *= -1;
		v.push_back({i-x0,j-y0});
		for (auto dir : dirs) {
			helper(grid,v,x0,y0,i+dir[0],j+dir[1]);
		}
	}

//encode to a string
	int numDistIslandST(vector<vector<int>> &grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = m > 0 ? grid[0].size() : 0;
		unordered_set<string> res;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m;++i) {
			for (int j = 0; j < n;++j) {
				if (grid[i][j]==1 && !visited[i][j]) {
					set<string> s;
					helperST(grid,visited,i,j,i,j,s);
					string t = "";
					for (auto str : s) t += str + "_";
					res.insert(t);
				} 
			}
		}
		return res.size();
	}
	void helperST(vector<vector<int>>&grid, vector<vector<bool>>& visited, int x0, int y0, int i, int j, set<string>& s) {
		int m = grid.size();
		int n = m>0? grid[0].size():0;
		visited[i][j] = true;
		for (auto dir : dirs) {
			int x = i + dir[0], y = j + dir[1];
			if (x<0 || x>=m || y<0 || y>=n || grid[x][y] == 0 || visited[x][y]) continue;
			string str = to_string(x-x0)+"_"+to_string(y-y0);
			s.insert(str);
			helperST(grid,visited,x0,y0,x,y,s);
		}
	}
//BFS 
	int numDistIsBFS(vector<vector<int>>&grid) {
		int m = grid.size(), n = m > 0 ? grid[0].size() : 0;
		set<vector<pair<int, int>>> res;
		for (int i = 0; i < m;++i) {
			for (int j = 0; j<n;++j) {
				if (grid[i][j] != 0) continue;
				vector<pair<int, int>> v;
				queue<pair<int, int>> q{{{i, j}}};
				grid[i][j] *= -1;
				while (!q.empty()) {
					auto t = q.front(); q.pop();
					for (auto dir : dirs) {
						int x = t.first + dir[0], y = t.second + dir[1];
						if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] <= 0) continue;
						q.push({x,y});
						grid[x][y] *= -1;
						v.push_back({x-i,y-i});
					}
				}
				res.insert(v);
			}
		}
		return res.size();
	}
};


int main()
{
    return 0;
}

