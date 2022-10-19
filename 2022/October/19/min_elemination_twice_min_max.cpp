#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int min_removals(vector<int> arr, int l, int r) {
	if (l >= r) return 0;
	int mn = min(arr, l, h);
	int mx = max(arr, l, h);
	if (2 * mn > mx) return 0;
	return min(min_removals(arr, l + 1, h), min_removals(arr, l, h - 1)) + 1;
}


// min and max in the sub array between l and h

int min(vector<int> arr, int l, int h) {
	int minx = 1e9 + 8;
	for (int i = l; i <= h; i++) {
		minx = min(arr[i], minx);
	}
	return minx;
}

int min_removals(string str) {
	int n = str.size();
	vector<vector<int>> dp(n, vector<int>(n));
	for (int gap = 0; gap < n; gap++) {
		// i and j be the limits of the ends
		for (int i = 0, j = gap; j < n; i++, j++) {
			int minx = min(arr, i, j);
			int maxx = max(arr, i, j);
			dp[i][j] = (2 * min > max) ? 0 : min(dp[i][j - 1], dp[i + 1][j]) + 1;
		}
	}
	return dp[0][n - 1];
}