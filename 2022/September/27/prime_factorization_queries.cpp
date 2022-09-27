#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// we use spf of a number and keep divind that number until 
// it becomes one.
#define MAXN 100001

int spf[MAXN];

void seive() {
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		spf[i] = i;
	}
	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;
	for (int i = 3; i * i < MAXN; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < MAXN; j += i) {
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

vector<int> factor(int n) {
	vector<int> ret;
	while (n != 1) {
		ret.push_back(spf[n]);
		n = n / spf[n];
	}
	return ret;
}