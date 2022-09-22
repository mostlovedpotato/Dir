#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

// a variation of LIS

int max_sum_increasing_seq(vector<int> arr) {
	int n = arr.size();
	vector<int> curr(n);
	for (int i = 0; i < n; i++) {
		curr[i] = arr[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && curr[i] < curr[j] + arr[i])
				curr[i] = curr[j] + arr[i];
		}
	}
	int maxx = 0;
	for (int i = 0; i < n; i++) {
		if (maxx < curr[i])
			maxx = curr[i];
	}
	return maxx;
}