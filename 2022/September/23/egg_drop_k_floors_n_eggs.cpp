#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int egg_drop(int n, int k) {
	if (k == 1 || k == 0) {
		return k;
	}
	if (n == 1) return k;
	int min = INT_MAX;

	for (int x = 1; x <= k; x++) {
		int res = max(egg_drop(n - 1, x - 1), egg_drop(n, k - x));
		if (res < min) min = res;
	}
	return min + 1;
}
// repeated characters.
int drop_egg(int n,int k) {
	vector<vector<int>> egg_floor(n+1,vector<int> (k+1));
	int res;
	for (int i = 1; i <= n; i++) {
		egg_floor[i][1] = 1;
		egg_floor[i][0] = 0;
	}
	for (int j = 1; j <= k; j++) {
		egg_floor[1][j] = j;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			egg_floor[i][j] = INT_MAX;
			for (int temp = 1; temp <= j; temp++) {
				int res = 1 + max(egg_floor[i - 1][temp - 1], egg_floor[i][j - temp]);
				if (res < egg_floor[i][j])
					egg_floor[i][j] = res;
			}
		}
	}
	return egg_floor[n][k];
}