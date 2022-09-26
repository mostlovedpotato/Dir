#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

#define ll long long
#define ld long double

using namespace std;

pair<ld, ld> intersect(pair<ld, ld>& a, pair<ld, ld>& b) {
	if (a.second < b.first || a.second < b.first)
		return { -1,-1 };
	return { max(a.first,b.first), min(a.second,b.second) };
}

void solve() {
	int n;
	cin >> n;
	vector<ll> x(n);
	vector<ll> t(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> t[i];
	ld low = 0, high = 2e8 + 5, ans = 0;
	ll iterations = 30;
	while (iterations--) {
		ll mid = (low + high) / 2;
		ll ok = 1;
		pair<ld, ld> full = { 0,1e8 };
		for (ll i = 0; i < n; i++) {
			if (t[i] > mid) {
				ok = 0;
				break;
			}
			ll diff = mid - t[i];
			pair<ld, ld> range = { x[i] - diff,x[i] + diff };
			full = intersect(range, full);
			if (full.first == -1) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			ans = (full.first + full.second) / 2;
			high = mid;
		}
		else {
			low = mid;
		}
	}
	cout << setprecision(12) << fixed << ans << endl;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}



using i64 = long long;

constexpr int inf = 1E9;

void solve() {
	int n;
	std::cin >> n;

	int min = inf, max = -inf;
	std::vector<int> x(n), t(n);
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> t[i];
		min = std::min(min, x[i] - t[i]);
		max = std::max(max, x[i] + t[i]);
	}
	std::cout << 0.5 * (min + max) << "\n";
}
