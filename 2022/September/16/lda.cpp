#include<iostream>
#include<algorithm>

using namespace std;


// longest decreasing subsequence
// we will check for each element number of previous elements greater 
// than it.
//lds[i] = 1 + max(lds[j]) where i > j > 0 and arr[j] > arr[i] or
//lds[i] = 1, if no such j exists.

int lds(vector<int> a, int n) {
	vector<int> lds(n);
	for (int i = 0; i < n; i++) {
		lds[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j] and lds[i] < lds[j] + 1) {
				lds[i] = lds[j] + 1;
			}
		}
	}
	int maxx = *max_element(lds.begin(), lds.end());
	return maxx;
}