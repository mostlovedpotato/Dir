#include<iostream>
#include<vector>


using namespace std;


// Given a string S of length N consisting of digits from ‘0’ to ‘9’.The task is to determine the
// total number of possible ways to partition the string into K substrings such that :

// Each substring has a minimum length of M(M >= 2).
// Substring must start with an even digit numberand end with an odd digit number.

int split_k(int i, int n, int k, int m, string& s) {
	int first_char = s[0] - '0';
	int last_char = s[n - 1] - '0';
	if (first_char % 2 != 0 || last_char % 2 != 1) {
		cout << 0 << endl;
	}
	if (i == n) return 0;
	if (k == 1) {
		int rem_char = n - i;
		if (rem_char >= m)
			return 1;
		return 0;
	}
	int ans = 0;
	int size = 0;
	for (int j = i; j < n - 1; i++) {
		size++;
		int curr_num = s[j] - '0';
		int next_num = s[j + 1] - '0';
		if (size >= m && curr_num % 2 == 1) {
			if (next_num % 2 == 0)
				ans += split_k(j + 1, n, k - 1, m, s);
		}
	}
	return ans;
}


int dp[1001][1001];
int split_string(int i, int N, int K, int M, string& s)
{
	if (i == N)
		return 0;
	if (K == 1) {
		int Remchar = N - i;
		if (Remchar >= M)
			return 1;
		return 0;
	}
	if (dp[i][K] != -1)
		return dp[i][K];
	int ans = 0;
	int length = 0;
	for (int j = i; j < N - 1; j++) {
		length++;
		int CurrentNum = s[j] - '0';
		int NextNum = s[j + 1] - '0';
		if (length >= M && CurrentNum % 2 == 1) {
			if (NextNum % 2 == 0) {
				ans += split_string(j + 1, N, K - 1, M, s);
			}
		}
	}
	return dp[i][K] = ans;
}