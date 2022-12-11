#include<iostream>
#include<vector>


using namespace std;


typedef long long ll;
#define clr(v,d) memset(v,d,sizeof(v))
const int N = 3009;
const int mod = 1e9 + 7;
int n, a[N];

ll dp[N][N][2];

ll cal(int l, int r, int turn) {
	ll& ret = dp[l][r][turn];
	if (~ret) return ret;
	if (l == r) {
		if (turn) return a[l];
		return -1 * a[l];
	}
	if (turn) {
		ret = max(a[l] + cal(l + 1, r, 1 - turn), a[r] + cal(l, r - 1, 1 - turn));
	}
	else {
		ret = min(-1 * a[l] + cal(l + 1, r, 1 - turn), -1 * a[r] + cal(l, r - 1, 1 - turn));
	}
	return ret;
}

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	clr(dp, -1);
	cout << cal(0, n - 1, 1);
}

int main() {
	int q = 1;
	while (q--) {
		sol();
	}
}