#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// we have to find minimum number of cubes used to make a given number

vector<int> pow3(47);
vector<int> dp(1e5 + 7,1e7);

void fill_pow3() {
	for (int i = 1; i <= 46; i++) {
		pow3[i] = pow(i, 3);
	}
}
void fill_dp() {
	for (int i = 1; i <= 1e5; i++) {
		for (int j = 1; j <= 46; j++) {
			if (pow3[j] <= i) {
				dp[i] = min(dp[i], dp[i - pow3[j]] + 1);
			}
		}
	}
}