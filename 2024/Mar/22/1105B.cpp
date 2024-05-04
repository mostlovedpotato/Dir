#include<iostream>
#include<string>


using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int level = 0;
	int a[26] = { 0 };
	for (char l = 'a'; l <= 'z'; l++) {
		int res = 0;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == l) {
				cnt++;
			}
			else {
				res += cnt / k;
				cnt = 0;
			}
		}
		res += cnt / k;
		a[l - 'a'] = res;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans = max(ans, a[i]);
	}
	cout << ans << endl;
	
}