#include<iostream>
#include<vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		vector<int> a(n);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int total_cnt = 0;
		for (int i = 0; i < n; i++) {
			total_cnt += (a[i] == 1 ? 0 : 1);
		}
		if (total_cnt % 2 == 1) {
			cout << -1 << endl;
			break;
		}
		int half_cnt = 0;
		int flag = -1;
		for (int i = 0; i < n; i++) {
			half_cnt += (a[i] == 1 ? 0 : 1);
			if (half_cnt == total_cnt / 2) {
				flag = i+1;
			}
		}
		cout << flag << endl;
	}
}