#include<iostream>
#include<vector>

using namespace std;

int solve() {
	int v1, v2, d, t;
	cin >> v1 >> v2 >> d >> t;
	int sum = 0;
	for (int i = 0; i < t; i++) {
		sum += min(v1 + d * i, v2 + (t - i - 1) * d);
	}
	return sum;
}