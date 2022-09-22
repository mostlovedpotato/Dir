#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lbs(vector<int> arr) {
	int n = arr.size();
	vector<int> lis(n,1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
				lis[i] = lis[j] + 1;
			}
		}
	}
	vector<int> lds(n, 1);
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j++) {
			if (arr[i] > arr[j] && lds[i] < lds[j] + 1) {
				lds[i] = lds[j] + 1;
			}
		}
	}
	int maxx = lis[0] + lds[0] - 1;
	for (int i = 1; i < n; i++) {
		if (lis[i] + lds[i] - 1 > maxx) {
			maxx = lis[i] + lds[i] - 1;
		}
	}
	return maxx;
}
