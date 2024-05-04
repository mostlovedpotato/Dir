#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<map>

using ll = long long
using namespace std;
//
//int main() {
//	int H, W, M;
//	cin >> H >> W >> M;
//	unordered_map<int, pair<int, int>> row_map;
//	unordered_map<int, pair<int, int>> col_map;
//	int timer = 0;
//	for (int i = 0; i < M; i++) {
//		int t, a, x;
//		timer++;
//		cin >> t >> a >> x;
//		if (t == 1) {
//			row_map.emplace(a, make_pair(x, timer));
//		}
//		else {
//			col_map.emplace(a, make_pair(x, timer));
//		}
//	}
//	vector<int> colors(M, 0);
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			int x, y;
//			x = row_map[i].second;
//			y = col_map[j].second;
//			if (y > x) {
//				colors[col_map[j].first]++;
//			}
//			else {
//				colors[row_map[i].first]++;
//			}
//		}
//	}
//	map<int, int> ans;
//	for (int i = 0; i < M; i++) {
//		if (colors[i]) {
//			ans[i] = colors[i];
//		}
//	}
//	cout << ans.size() << endl;
//	for (auto x : ans) {
//		cout << x.first << " " << x.second << endl;
//	}
//}

// not working


int main() {
	int h, w, m;
	cin >> h >> w >> m;
	vector<bool> rows(h), columns(w);
	vector<int> t(m), a(m), x(m);
	int untouched_rows = h, untouched_cols = w;
	int X = 200010;
	vector<ll> cnt(X);
	for (int i = 0; i < m; i++) {
		cin >> t[i] >> a[i] >> x[i];
	}
	for (int i = m - 1; i >= 0; i--) {
		if (t[i] == 1) {
			if (!rows[a[i]]) {
				untouched_rows--;
				cnt[x[i]] += untouched_cols;
				rows[a[i]] = true;
			}
		}
		else {
			if (!cols[a[i]]) {
				untouched_cols--;
				cnt[x[i]] += untouched_cols;
				cols[a[i]] = true;
			}
		}
	}
	cnt[0] += untouched_cols * untouched_cols;
	vector<pair<ll, ll>> ans;
	for (int i = 0; i < X; i++) {
		if (cnt[i]) {
			ans.push_back({ i, cnt[i] });
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x.first << " " << x.second << endl;
	}

}
