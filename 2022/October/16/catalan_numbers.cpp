#include<iostream>
#include<vector>

using namespace std;

unsigned long int catalan(unsigned int n) {
	if (n <= 1) {
		return 1;
	}
	unsigned int res = 0;
	for (int i = 0; i < n; i++) {
		res += catalan(i) * catalan(n - i - 1);
	}
	return res;
}

int catalan_dp(int n) {
	vector<int> dp(n);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
	return dp[n];
}