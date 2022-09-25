#include<iostream>
#include<vector>

using namespace std;

int min_cost(vector<vector<int>>& mat, int si, int se, int ei, int ee) {
	if (si == ei && se == ee) {
		return mat[ei][ee];
	}
	if (si > ei || se > ee) {
		return INT_MAX;
	}
	int poss1 = min_cost(mat, si + 1, se, ei, ee);
	int poss2 = min_cost(mat, si + 1, se + 1, ei, ee);
	int poss3 = min_cost(mat, si, se + 1, ei, ee);
	return mat[si][se] + min(poss1, min(poss2, poss3));
}

int min_cost(vector<vector<int>>& mat, int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n));
	dp[0][0] = mat[0][0];
	for (int i = 1; i < n; i++) {
		dp[0][i] = mat[0][i] + dp[0][i - 1];
	}
	for (int i = 1; i < m; i++) {
		dp[i][0] = mat[i][0] + dp[i - 1][0];
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			int first = dp[i - 1][j];
			int second = dp[i][j - 1];
			int third = dp[i - 1][j - 1];
			dp[i][j] = min(first, min(second, third));
		}
	}
	return dp[m - 1][n - 1];
}