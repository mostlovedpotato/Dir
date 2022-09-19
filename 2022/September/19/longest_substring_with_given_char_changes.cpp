#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>


using namespace std;

int dp[1001][1001][26];
int ans[1001][26];


//Longest Substring of given characters by 
//replacing at most K characters for Q queries

// precompute the values for each possible
// number of replacement of every character


// if we can find longest substring of char ch 
// till pos i with j replacements 
// then we can find longest substring char ch 
// till (i+1) th char 
// if ith char and ch are same then 
// dp[i][j][ch] = dp[i-1][j][ch]+1;
// otherwise if both are different then 
// dp[i][j][k] = dp[i-1][j-1][k]+1;

void pre_process(string s) {
	int n = s.size();
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		dp[i][0][s[i - 1] - 'a'] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < 26; k++) {
				if (s[i - 1] == char(k + 'a')) {
					dp[i][j][k] = dp[i - 1][j][k] + 1;
				}
				else if (j != 0) {
					dp[i][j][k] = dp[i - 1][j - 1][k] + 1;
				}
			}
		}
	}
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 1; k <= n; k++) {
				ans[i][j] = max(ans[i][j], dp[k][i][j]);
			}
		}
	}
}

