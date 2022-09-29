#include<iostream>	
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long

bool cmp(pair<ll, pair<ll, ll>>& x, pair<ll, pair<ll, ll>>& y) {
	if (x.first == y.first)
		return abs(x.second.first - x.second.second) > abs(y.second.first - y.second.second);

	return x.first < y.first;
}

bool solve(vector<pair<ll, pair<ll, ll>>>& v, ll k) {
	ll n = v.size();
	ll max_temp = k;
	ll min_temp = k;
	ll prev_time = 0;
	for (ll i = 0; i < n; i++) {
		ll time = v[i].first - prev_time;
		ll start = v[i].second.first;
		ll end = v[i].second.second;
		
		max_temp += time;
		min_temp -= time;

		prev_time = v[i].first;

		if (min_temp > end || max_temp < start)
			return false;

		min_temp = max(min_temp, start);
		max_temp = min(max_temp, end);
	}
	return true;
}

int main() {
	ll t = 1;
	//cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		vector<pair<ll, pair<ll, ll>>> v;
		for (ll i = 0; i < n; i++) {
			ll time, start, end;
			cin >> time >> start >> end;
			v.push_back({ time, {start, end} });
		}
		sort(v.begin(), v.end(), cmp);

		bool check = solve(v, k);
		if (check) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}