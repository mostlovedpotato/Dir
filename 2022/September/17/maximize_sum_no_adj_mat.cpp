#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

// we first write to find the max in each row without taking any adjacent numbers
// then we will have one vector with sums of all the rows without taking any 
// adjacent members in each row. 
// now we want to choose from this vector formed the max sum without choosing
// any adjacent row sums that is we just apply the function one more time.

int maximize_no_adj(vector<int> vi) {
	int n = vi.size();
	int res = 0;
	vector<int> dp(n, 0);
	dp[0] = vi[0];
	res = dp[0];
	if (n < 1)
		return res;
	dp[1] = max(vi[0], vi[1]);
	res = max(res, dp[1]);
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 1], vi[i] + dp[i - 2]);
		res = max(res, dp[i]);
	}
	return res;
}


int solve(vector<vector<int>>& mat) {
	int m = mat.size();
	if (m == 0) return 0;
	vector<int> dp;
	for (int i = 0; i < m; i++) {
		dp.push_back(maximize_no_adj(mat[i]));
	}
	return maximize_no_adj(dp);
}