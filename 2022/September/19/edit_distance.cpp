#include<iostream>
#include<string>
#include<algorithm>
#include<vector>


using namespace std;

int min(int x, int y, int z) {
	return min(min(x, y), z);
}
// If last characters are same 
// we will recur for m-1,n-1

// If last characters are different
//Insert: Recur for m and n-1
//Remove: Recur for m - 1 and n
//Replace : Recur for m - 1 and n - 1

int edit_distances(string first, string second, int m,int n) {
	//int n = first.size();
	//int m = second.size();
	if (n == 0) return m;
	if (m == 0) return n;

	if (first[m - 1] == second[n - 1])
		return edit_distances(first, second, m - 1, n - 1);

	return 1 + min(edit_distances(first, second, m, n - 1), edit_distances(first, second, m - 1, n), edit_distances(first, second, m - 1, n - 1));
}

int edit_distance(string first, string second) {
	//int dp[m + 1][n + 1];
	int m = first.size();
	int n = second.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (first[i - 1] == second[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}
	return dp[m][n];
}