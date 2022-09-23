#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

// we will use recursion to solve this problem.
// we will do with the relation 
// L(0,n-1) to if both characters are same
// then we move to L(1,n-2); 
// otherwise 
// max(L(1,n-1),L(0,n-2))
// But we better use dp to store the states.

int max(int x, int y) {
	return (x > y) ? x : y;
}

int longest_panlindromic_subseq(string seq, int i, int j) {
	if (i == j) {
		return 1;
	}
	if (seq[i] == seq[j] && i + 1 == j)
		return 2;
	if (seq[i] == seq[j])
		return longest_panlindromic_subseq(seq, i + 1, j - 1) + 2;

	return max(longest_panlindromic_subseq(seq, i, j - 1), longest_panlindromic_subseq(seq, i + 1, j));
}


// we can store this in table 

int lps(string seq) {
	int n = seq.size();
	vector<vector<int>> mat(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		mat[i][i] = 1;
	}
	for (int sz = 2; sz <= n; sz++) {
		for (int i = 0; i < n - sz + 1; i++) {
			int j = i + sz - 1;
			if (seq[i] == seq[j] && sz == 2) {
				mat[i][j] = 2;
			}
			else if (seq[i] == seq[j]) {
				mat[i][j] = mat[i + 1][j - 1] + 2;
			}
			else {
				mat[i][j] = max(mat[i][j - 1], mat[i + 1][j]);
			}
		}
		return mat[0][n - 1];
	}
}