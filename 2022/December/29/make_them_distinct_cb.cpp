#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> A(n);
		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < n; i++) {
			mp[A[i]]++;
		}
		bool flag = true;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			if (it->second > ((n + 1) / 2)) {
				flag = false;
				break;
			}
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}