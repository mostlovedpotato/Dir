#include<iostream>
#include<vector>

using namespace std;

int findMin(vector<int> arr, int i, int sumCalc, int sumTotal)
{
	if (i == 0) {
		return abs((sumTotal - sumCalc) - sumCalc);
	}

	return min(
		findMin(arr, i - 1, sumCalc + arr[i - 1], sumTotal),
		findMin(arr, i - 1, sumCalc, sumTotal)
	);
}

// Recursive approach takes 2^n times two decisions.

int findMin(vector<int> arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	vector<vector<bool>> dp(sum + 1, vector<bool>(n + 1));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = true;
	}
	for (int i = 1; i <= sum; i++) {
		dp[0][j] = false;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			dp[i][j] = dp[i - 1][j];

			if (arr[i - 1] <= j) {
				dp[i][j] |= dp[i - 1][j - arr[i - 1]];
			}
		}
	}
	int diff = INT_MAX;
	for (int j = sum / 2; j >= 0; j--) {
		if (dp[n][j] == true) {
			diff = sum - 2 * j;
			break;
		}
	}
	return diff;

}