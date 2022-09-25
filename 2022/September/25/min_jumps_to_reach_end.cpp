#include<iostream>
#include<vector>


using namespace std;

int min_jumps(vector<int> vi) {
	int n = vi.size();
	if (n == 0 || vi[0] == 0)
		return INT_MAX;
	vector<int> dp(n);
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = INT_MAX;
		for (int j = 0; j < i; j++) {
			if (j + vi[j] >= i && dp[j] != INT_MAX) {
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}
	return dp[n - 1];
}