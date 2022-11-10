#include<iostream>
#include<vector>

#define N 5010
#define LL long long
#define INF 0xffffff


using namespace std;

int a[N];
LL dp[N][N];
LL sum[N];

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = m; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = max(dp[i - m][j - 1] + sum[i] - sum[i - m], dp[i - 1][j]);
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}