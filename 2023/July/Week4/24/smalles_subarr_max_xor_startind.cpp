#include <iostream> 


using namespace std;

struct TrieNode {
	TrieNode* zero, * one;
};

TrieNode* newNode() {
	TrieNode* temp = new TrieNode;
	temp->zero = temp->one = NULL;
	return temp;
}

void insert(TrieNode* root, int n) {
	TrieNode* temp = root;

	for (int i = 31; i >= 0; i--) {
		bool bit = (n) & (1 << i);
		if (bit == 0) {
			if (temp->zero == NULL) {
				temp->zero = newNode();
			}
			temp = temp->zero;
		}
		else {
			if (temp->one == NULL) {
				temp->one = newNode();
			}
			temp = temp->one;
		}
	}
}

int query(TrieNode* root, int n) {
	TrieNode* temp = root;
	int res = 0;
	for (int i = 31; i >= 0; i--) {
		bool bit = (1 << i) & n;
		if (bit == 0) {
			if (temp->one != NULL) {
				res += (1 << i);
				temp = temp->one;
			}
			else temp = temp->zero;
		}
		else {
			if (temp->zero != NULL) {
				res += (1 << i);
				temp = temp->zero;
			}
			else temp = temp->one;
		}
	}
	return res;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}