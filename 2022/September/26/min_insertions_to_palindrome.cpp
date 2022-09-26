#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int min_insertions(string str, int l, int h) {
	if (l > h) return INT_MAX;
	if (l == h) return 0;
	if (l == h - 1) return (str[l] == str[h]) ? 0 : 1;
	if (str[l] == str[h]) {
		return min_insertions(str, l + 1, h - 1);
	}
	else {
		return min(min_insertions(str, l, h - 1), min_insertions(str, l + 1, h) + 1);
	}
}

// dp for above approach 

int min_insertions(string str) {
	int n = str.size();
	vector<vector<int>> dp(n + 1, vector<int>(n,0));
	for (int gap = 1; gap < n; gap++) {
		for (int l = 0, h = gap; h < n; l++, h++) {
			if (str[l] == str[h]) {
				dp[l][h] = dp[l + 1][h - 1];
			}
			else {
				dp[l][h] = min(dp[l + 1][h], dp[l][h - 1]) + 1;
			}
		}
	}
	return dp[0][n - 1];
}


// another approach is by using lcs 
// we find the reverse of curr string and then 
// find lcs and then the number of misses is our answer

int lcs(string x, string y, int m, int n) {
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (x[i - 1] == y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[m][n];
}

int min_insertions(string str, int n) {
	string rev = str;
	reverse(rev.begin(), rev.end());
	return n - lcs(str, rev, n, n);
}