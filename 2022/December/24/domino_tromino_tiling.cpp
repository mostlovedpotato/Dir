#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
	int MOD = 1e9 + 7;
public:
	int num_tiling(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		vector<int> dp(n + 1,0);
		dp[0] = 1; dp[1] = 1; dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
		}
		return dp[n] % MOD;
	}

};