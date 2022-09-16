#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

//cutRod(n) = max(price[i] + cutRod(n-i-1)) for all i in {0, 1 .. n-1}
// either we cut at current index or we just decrease at current index

int cut_rod(vector<int> price, int ind, int len) {
	if (ind == 0) {
		return len * price[0];
	}

	// if value already present
	if (dp[ind][len]!=-1 ) {
		return dp[ind][len];
	}

	int no_cut = cut_rod(price, ind - 1, len);//no change in length
	int cut = -1e6;
	int rod_len = ind + 1;

	if (rod_len <= len) {
		cut = price[ind] + cut_rod(price, ind, len - rod_len, dp);
	}
	return dp[ind][len] = max(cut, not_cut);
}

int cut_rod(vector<int> price, int len) {
	vector<int> dp(len + 1);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] = max(dp[i], price[i] + dp[i - j - 1]);
		}
	}
	return dp[n];
}

int main() {

}