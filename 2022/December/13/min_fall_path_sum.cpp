#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a = 1e5, b = 1e5, c = 1e5;
                if (j > 0) {
                    a = dp[i - 1][j - 1];
                }
                if (j < m - 1) {
                    c = dp[i - 1][j + 1];
                }
                b = dp[i - 1][j];
                dp[i][j] = min(a, min(b, c)) + matrix[i][j];
            }
        }
        int ret = 1e9;
        for (int i = 0; i < m; i++) {
            ret = min(ret, dp[n - 1][i]);
        }
        return ret;
    }
};