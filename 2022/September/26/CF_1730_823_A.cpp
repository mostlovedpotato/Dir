#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>

using namespace std;

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	int res = 0;
	for (auto x : mp) {
		res += min(c, x.second);
	}
	cout << res << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}