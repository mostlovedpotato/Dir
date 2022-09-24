// https://www.spoj.com/problems/ALTSEQ/en/
// maximum length alternating subsequence 

#include<iostream>
#include<vector>


using namespace std;

const int MAXN = 1e4;
int dp[MAXN];

inline int sign(const int& n) {
	return n == 0 ? 0 : (n < 0 ? -1 : 1);
}

int max(int a, int b) {
	return (a > b) ? a : b;
}


int alternating_subseq(const int& p,vector<int> vi) {
	if (dp[p] != -1) return dp[p];
	int res = 1;
	int n = vi.size();
	for (int i = p + 1; i < n; i++) {
		if (sign(vi[i]) == -sign(vi[i])) {
			if (abs(vi[i]) > abs(vi[p])) {
				res = max(res, 1 + alternating_subseq(i,vi));
			}
		}
	}
	return dp[p] = res;
}