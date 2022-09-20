#include<iostream>
#include<vector>
#include<algorithm>
#include<ctype.h>
#include<map>
#include<set>


using namespace std;

// travelling n cities each k times 

int count_ways(int n, int k) {
	int path_count = 0;
	vector<int> path;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			path.push_back(i);
		}
	}
	bool is_valid_path;
	while (next_permutation(path.begin(), path.end())) {
		is_valid_path = true;
		for (int i = 0; i < n * k-1; i++) {
			if (path[i] == path[i + 1]) {
				is_valid_path = false;
			}
		}
		if (is_valid_path == true) {
			path_count++;
		}
	}
	return path_count;
}

// init vector vis with all k 
// backtracking because we want all the possibillities
int count_paths_possible(int current_city, int n, vector<int> vis) {
	bool final_check = true;
	for (int i = 1; i <= n; i++) {
		if (vis[i] < 0) {
			return 0;
		}
		if (vis[i] != 0) {
			final_check = false;
		}
	}
	if (final_check == true)
		return 1;
	int path_count = 0;
	for (int i = 1; i <= n; i++) {
		if (current_city == i) {
			continue;
		}
		vis[i]--;
		path_count += count_paths_possible(i, n, vis);
		vis[i]++;
	}
	return path_count;
}


map<pair<int, multiset<int>>, int> mp;

int count_paths(int current_city, int n, vector<int> vis) {
	int already_cnt = mp[{vis[current_city], multiset<int>(vis.begin(), vis.end())}];
	if (already_cnt != 0) {
		return already_cnt;
	}

	bool final_check = true;
	for (int i = 1; i <= n; i++) {
		if (vis[i] < 0)
			return 0;
		if (vis[i] != 0)
			final_check = false;
	}
	if (final_check == true) {
		return 1;
	}

	int path_count = 0;
	for (int i = 1; i <= n; i++) {
		if (current_city == i) {
			continue;
		}
		vis[i]--;
		path_count += count_paths(i, n, vis);
		vis[i]++;
	}
	mp[{vis[current_city], multiset<int>(vis.begin(), vis.end())}] = path_count;
	return path_count;
}


