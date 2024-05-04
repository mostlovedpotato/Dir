#include<iostream>
#include<string>

using namespace std;

int modified = false;

void checkString(string &str) {
	int sz = str.size();
	bool to_reverse = false;
	for (int i = 0; i < sz/2; i++) {
		if (str[i] == str[n - i]) {
			continue;
		}
		else {
			if (str[n - i] < str[i]) {
				to_reverse = true;
				modified = true;
				break;
			}
		}
	}
	if (to_reverse) {
		std::reverse(str.begin(), str.end());
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		checkString(s);
		if (modified) {
			if (n % 2 == 0) {
				string temp = s;
				std::reverse(temp.begin(), temp.end());
				s = s + temp;
			}
		}
		else {
			if (n % 2 == 1) {
				string temp = s;
				std::reverse(temp.begin(), temp.end());
				s = s + temp;
			}
		}
		return s;
		
	}
}