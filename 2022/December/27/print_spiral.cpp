#include<iostream>
#include<vector>

using namespace std;

void print_spiral(vector<vector<int>> const& mat) {
	if (mat.size() == 0) return;
	int top = 0, bottom = mat.size() - 1;
	int left = 0, right = mat[0].size() - 1;
	while (1) {
		if (left > right)break;
		for (int i = left; i <= right; i++) {
			cout << mat[top][i] << " ";
		}
		top++;
		
		if (top > bottom) break;
		for (int i = top; i < bottom; i++) {
			cout << mat[i][right] << " ";
		}
		right--;

		if (left > right) break;
		for (int i = right; i >= left; i--) {
			cout << mat[bottom][i] << " ";
		}
		bottom--;

		if (top > bottom) break;
		for (int i = bottom; i >= top; i--) {
			cout << mat[i][left] << " ";
		}
		left++;
	}
}