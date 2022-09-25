#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stdlib.h>
#include<iterator>

using namespace std;


struct dsu {
	vector<int> size;
	vector<int> par;

	dsu(int n) {
		size.resize(n, 1);
		par.resize(n);
		for (int i = 0; i < n; i++) par[i] = i;
	}

	int leader(int x) {
		if (x == par[x]) return x;
		return (par[x] = leader(par[x]));
	}

	void merge(int x, int y) {
		x = leader(x);
		y = leader(y);
		if (x == y) return;
		if (size[x] > size[y]) swap(x, y);
		size[y] += size[x];
		par[x] = y;
	}

};

int good_paths(vector<int>& vals, vector<vector<int>>& edges) {
	int n = vals.size();
	vector<vector<int>> g(n);
	for (auto i : edges) {
		g[i[0]].push_back(i[1]);
		g[i[1]].push_back(i[0]);
	}
	map<int, vector<int>> val_to_nodes;
	for (int i = 0; i < n; i++) {
		val_to_nodes[vals[i]].push_back(i);
	}

	dsu DSU(n);
	int res = n;
	vector<bool> is_active(n);
	for (auto y : val_to_nodes) {
		int _ = y.first;
		vector<int> indexes = y.second;
		for (auto i : indexes) {
			for (auto child : g[i]) {
				if (is_active[child]) DSU.merge(i, child);
			}
			is_active[i] = true;
		}

		vector<int> leaders;
		for (auto i : indexes) leaders.push_back(DSU.leader(i));
		sort(leaders.begin(), leaders.end());

		int sz = leaders.size();
		for (int j = 0; j < sz; j++) {
			long long cnt = 0;
			int cur = leaders[j];

			while (j < sz && leaders[j] == cur) j++, cnt++;
			j--;

			res += (cnt * (cnt - 1)) / 2;
		}
	}

	return res;

}