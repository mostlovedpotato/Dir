#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		--u, --v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	auto check = [&] (int x) {
		int res = 0;
		auto dfs = [&](auto self, int v, int f) -> int {
			int sz = 1;
			for (int u : adj[v]) {
				if (u == f) {
					continue;
				}
				sz += self(self, u, v);
			}
			if (sz >= x && f != v) {
				++res;
				sz = 0;
			}
			return sz;
		};
		int t = dfs(dfs, 0, 0);
		return (res > k || (t >= x && res == k) ? true : false);)
	}


	int low = 1, high = n / (k + 1) + 1;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		if (check(mid)) {
			low = mid;
		}
		else {
			high = mid;
		}
	}
	cout << low << '\n';


}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}