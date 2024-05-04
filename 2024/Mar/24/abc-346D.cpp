#include<iostream>
#include<vector>
#include<string>


using namespace std;

using ll = long long
ll INF = 1'000'000'000'000'000'000;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	vector<ll> c(n);
	vector dp(n, vector(2, vector(2, INF)));
	dp[0][0][s[0] - '0'] = 0;
	dp[0][0][(s[0] - '0') ^ 1] = c[0];
	for (int i = 1; i < n; i++) {
		int curr = s[i] - '0';
		// if k == 0
		dp[i][0][0] = dp[i - 1][0][1] + (r == 0 ? 0 : c[i]);
		// if we already used up the adj limit
		// we anyway add the cost for the flip of bit. 

		dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][1][1]) + (r == 0 ? 0 : c[i]);

		// if k ==1 
		dp[i][0][1] = dp[i - 1][0][0] + (r == 1 ? 0 : c[i]);
		dp[i][1][1] = min(dp[i - 1][1][0], dp[i - 1][0][1]) + (r == 1 ? 0 : c[i]);

		ll ans = min(dp[n - 1][1][0], dp[n - 1][1][1]);
		cout << ans << '\n';
	}
}