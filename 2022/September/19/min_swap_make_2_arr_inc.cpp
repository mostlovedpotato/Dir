#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// make two dp arrays swap and noswap

int min_swaps(int A[], int B[], int n) {
	const int size_n = n;
	vector<int> swap(n), no_swap(n);

	swap[0] = 1;
	no_swap[0] = 1;
	for (int i = 1; i < n; i++) {
		swap[i] = no_swap[i] = n;
		if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
			swap[i] = swap[i - 1] + 1;
			no_swap[i] = no_swap[i - 1];
		}
		if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
			swap[i] = min(swap[i], no_swap[i - 1] + 1);
			no_swap[i] = min(no_swap[i], swap[i - 1]);
		}
		if ((A[i] < A[i - 1] && A[i] < B[i - 1]) || B[i] < B[i - 1] && B[i] < A[i - 1]) {
			return -1;
		}
	}
	return min(swap[n - 1], no_swap[n - 1]);
}