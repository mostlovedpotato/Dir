#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		int a[100005];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a+1, a + n + 1);
		int upto = n;
		int median = a[ceil(n / 2)];
		int median_index = ceil(n / 2);
		for (int i = median_index; i <= n; i++) {
			if (a[i] > median) {
				upto = i;
				break;
			}
		}
		cout << upto - median_index << endl;
	}
}