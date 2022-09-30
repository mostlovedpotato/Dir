#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sum(vector<int> freq, int i, int j);

int opt_cost(vector<int> freq, int i, int j) {
	if (j < i) return 0;
	if (j == i) return freq[i];
	int freq_sumij = sum(freq, i, j);
	int min = INT_MAX;

	for (int r = i; r <= j; r++) {
		int cost = opt_cost(freq, i, r - 1) + opt_cost(freq, r + 1, j);
		if (cost < min)
			min = cost;
	}
	return min + freq_sumij;
}

int sum(vector<int> freq, int i, int j) {
	int ret = 0;
	for (int k = i; k <= j; k++)
		ret += freq[k];
	return ret;
}

int opt_binary_search_tree(vector<int> keys, vector<int> freq, int n) {
	vector<vector<int>> cost(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		cost[i][i] = freq[i];
	}
	for (int L = 2; L <= n; L++) {
		for (int i = 0; i <= n - L + 1; i++) {
			int j = i + L - 1;
			cost[i][j] = INT_MAX;
			int range_sum = sum(freq, i, j);
			for (int r = i; r <= j; r++) {
				int cost_r = 0;
				if (r > i)
					cost_r += cost[i][r - 1];
				if (r < j)
					cost_r += cost[r + 1][j];
				if (cost_r < cost[i][j])
					cost[i][j] = cost_r;
			}
		}
		return cost[0][n - 1];
	}
}