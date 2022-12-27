#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void shift_max(vector<vector<int>>& mat) {
	if (mat.size() == 0) return;
	int top = 0, bottom = mat.size() - 1;
	int left = 0, right = mat[0].size() - 1;
	int prev = mat[0][0];
	while (true) {
		if (left > right) break;
		for (int i = left; i <= right; i++) {
			swap(mat[top][i], prev);
		}
		top++;

		if (top > bottom) break;
		for (int i = top; i <= bottom; i++) {
			swap(mat[i][right], prev);
		}
		right--;

		if (left > right) break;
		for (int i = right; i >= left; i--) {
			swap(mat[bottom][i],prev);
		}
		bottom--;

		if (top>bottom) break;
		for (int i = bottom; i >= top; i--) {
			swap(mat[i][left], prev);
		}
		left++;
	}
	mat[0][0] = prev;
}