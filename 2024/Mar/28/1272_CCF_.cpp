#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	set<int> st;
	string s; cin >> s;
	for (int i = 0; i < k; i++) {
		char x; cin >> x;
		set.insert(x - 'a');
	}
	int curr_len = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (set.find(s[i] - 'a') != set.end()) {
			len++;
		}
		else {
			ans += (curr_len * (curr_len + 1))/ 2;
			curr_len = 0;
		}
	}
	cout << ans << endl;
	return 0;
}