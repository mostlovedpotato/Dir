#include<iostream>
#include<vector>

using namespace std;

bool f[1000005];
int a[105];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (i < a[j]) break;
			if (f[i - a[j]] == false) {
				f[i] = true;
				break;
			}
		}
	}
	if (f[k] == true) cout << "First";
	else cout << "Second";
}