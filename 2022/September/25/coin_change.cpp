#include<iostream>
#include<vector>

using namespace std;

int count(vector<int> coins, int n, int sum) {
	if (sum == 0)
		return 1;
	if (sum < 0) return 0;
	if (n <= 0) return 0;
	return count(coins, n - 1, sum) + count(coins, n, sum - coins[n - 1]);
}

int count(int coins[], int n, int sum)
{
    vector<int> table(sum + 1,0);
    table[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            table[j] += table[j - coins[i]];
    return table[sum];
}

int count(vector<int> coins, int n, int sum) {
    vector<vector<int>> mat(sum + 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        mat[0][i] = 1;
    }
    for (int i = 1; i < sum; i++) {
        for (int j = 0; j < n; j++) {
            int x=0, y=0;
            if (i >= coins[j])
                x = mat[i - coins[j]][j];
            if (j >= 1)
                y = mat[i][j - 1];
            mat[i][j] = x + y;
        }
    }
    return mat[sum][n - 1];
}