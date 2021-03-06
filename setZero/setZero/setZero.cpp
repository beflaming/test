// setZero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

class Solution {
	void setZeroes(vector<vector<int>> &matrix) {
		if (matrix.empty()||matrix[0].empty()) return ;
		int row = matrix.size();
		int col = row> 0 ? matrix[0].size() : 0;

		bool rowZero = false, colZero = false;
		for (int i = 0; i < row;++i) {
			if (matrix[i][0] == 0) colZero = true;
		}
		for (int i = 0; i < col; ++i) {
			if (matrix[0][i] == 0) rowZero = true;
		}

		for (int i = 1; i < row; ++i) {
			for (int j = i; j < col;++j) {
				if (matrix[i][j]==0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		for (int i = 1; i < row;++i) {
			for (int j = 1; j < col; ++j) {
				if (matrix[0][j]==0||matrix[i][0]==0) {
					matrix[i][j] = 0;
				}
			}
		}

		if (rowZero) {
			for (int i = 0; i < row; ++i) matrix[0][i] = 0;
		}
		if (colZero) {
			for (int i = 0; i < col; ++i) matrix[i][0] = 0;
		}
	}
};

int main()
{
    return 0;
}

