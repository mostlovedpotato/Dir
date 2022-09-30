#include<iostream>
#include<vector>

using namespace std;

vector<vector<double>> dp(500, vector<double>(500));

double find_water(double k, double r, double c) {

    dp[0][0] = k;
    for (int i = 0; i < k + 1; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i][j] > 1.0) {
                double remaining = dp[i][j] - 1.0;
                dp[i][j] = 1.0;
                dp[i + 1][j] = remaining / 2.0;
                dp[i + 1][j + 1] = remaining / 2.0;

            }
        }
    }
    return dp[r][c];
}


// This problem is also available on leetcode with name : Champage Tower

double champagneTower(int poured, int query_row, int query_glass) {
    double result[101][101] = { 0.0 };
    result[0][0] = poured;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            if (result[i][j] >= 1) {
                result[i + 1][j] += (result[i][j] - 1) / 2.0;
                result[i + 1][j + 1] += (result[i][j] - 1) / 2.0;
                result[i][j] = 1;
            }
        }
    }
    return result[query_row][query_glass];
}
void print(vector<vector<double>> vvi, int k) {
    for (int i = 0; i < k + 1; i++) {
        for (int j = 0; j < i; j++) {
            cout << vvi[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double k, r, c;
    cin >> k >> r >> c;
    double ret = find_water(k, r, c);
    print(dp, k);
    cout << ret << endl;
    return 0;
}