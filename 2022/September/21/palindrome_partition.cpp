#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int min_partition(string str) {
	int n = str.size();
	vector<vector<int>> cut(n,vector<int>(n));
	vector<vector<bool>> partition(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		cut[i][i] = 0;
		partition[i][i] = true;
	}
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i < n - k + 1; i++) {
			int j = i + k - 1;
			if (k == 2)
				partition[i][j] = (str[i] == str[j]);
			else
				partition[i][j] = (str[i] == str[j]) && partition[i + 1][j - 1];
			if (partition[i][j] == true)
				cut[i][j] = 0;
			else {
				cut[i][j] = INT_MAX;
				for (int m = i; m <= j - 1; m++) {
					cut[i][j] = min(cut[i][j], cut[i][m] + cut[m + 1][j] + 1);
				}
			}
		}
	}
	return cut[0][n - 1];
}