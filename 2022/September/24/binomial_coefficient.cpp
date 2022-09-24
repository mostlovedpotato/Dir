#include<iostream>
#include<vector>

using namespace std;

int min(int a, int b) {
	return (a < b) ? a : b;
}


// we have recursion as 
// C(n,k) = C(n-1,k-1)+C(n-1,k)
// C(n,0) = C(n,n) = 1;

int binomial_coeff(int n, int k) {
	if (k > n) return 0;
	if (k == 0 || k == n) {
		return 1;
	}
	return binomial_coeff(n - 1, k - 1) + binomial_coeff(n - 1, k);
}
// funny how time complexity of this approach is O(n*max(k,n-k))
// and same for space complexity

int binomail_coefficient(int n, int k) {
	vector<vector<int>> mat(n + 1, vector<int>(k + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i) {
				mat[i][j] = 1;
			}
			else {
				mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
			}
		}
	}
	return mat[n][k];
}