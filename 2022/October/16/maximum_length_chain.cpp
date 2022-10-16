#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct interval {
	int left;
	int right;
};

bool static comp(interval a, interval b) {
	return a.right < b.right;
}

int max_chain(struct interval p[], int n) {
	sort(p, p + n, comp);
	int prev = INT_MIN;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].left > prev) {
			ans++;
			prev = p[i].right;
		}
	}
	return ans;
}