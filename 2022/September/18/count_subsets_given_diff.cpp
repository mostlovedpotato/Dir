#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;
// index , sum
int dp[1001][10000];

int count_subsets(vector<int>& v, int i, int s2, int curr) {
	if (curr == s2) {
		return 1;
	}
	if (i >= v.size()) {
		return 0;
	}
	if (dp[i][curr] != -1) {
		return dp[i][curr];
	}
	if (curr + v[i] > s2) {
		return dp[i][curr] = count_subsets(v, i + 1, s2, curr + v[i]) + count_subsets(v, i + 1, s2, curr);
	}
	else {
		return dp[i][curr] = count_subsets(v, i + 1, s2, curr + v[i]) + count_subsets(v, i + 1, s2, curr);
	}
}

int count(vector<int>& v, int s2) {
	dp[0][0] = 1;
	for (int i = 0; i < 1001; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i < 10000; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i < v.size(); i++) {
		for (int j = 1; j < s2; j++) {
			if (v[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else if (v[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i - 1]];
			}
		}
	} 
	return dp[v.size()][s2];

}


int findWays(vector<int>& num, int k) {
	int n = num.size();

	vector<vector<int>> dp(n, vector<int>(k + 1, 0));

	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}

	if (num[0] <= k)
		dp[0][num[0]] = 1;

	for (int ind = 1; ind < n; ind++) {
		for (int target = 1; target <= k; target++) {

			int notTaken = dp[ind - 1][target];

			int taken = 0;
			if (num[ind] <= target)
				taken = dp[ind - 1][target - num[ind]];

			dp[ind][target] = notTaken + taken;
		}
	}

	return dp[n - 1][k];

}


int count_sub(vector<int>& vp, int n, int diff) {
	int sum = 0;
	for (auto& x : vp) {
		sum += x;
	}
	if (sum - diff < 0 || (sum - diff) % 2 == 1) {
		return 0;
	}
	return count_subsets(vp, 0, (sum - diff) / 2, 0);
}