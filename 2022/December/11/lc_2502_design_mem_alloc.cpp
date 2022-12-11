#include<iostream>
#include<vector>

using namespace std;

class Allocator {
public:
	vector<int> v;
	vector<int> next;
	int n;
	Allocator(int N) {
		n = N;
		v.resize(n, -1);
		next.resize(n, 0);
		for (int i = 0; i < n; i++) {
			next[i] = n - i;
		}
	}

	int allocate(int size, int mID) {
		int f = -1;
		for (int i = 0; i < n; i++) {
			if (next[i] >= size) {
				for (int j = 0; j < size; j++) {
					v[i + j] = mID;
					next[i + j] = 0;
				}
				f = i;
				break;
			}
		}
		if (f == -1)
			return -1;
		return f;
	}
	int free(int mID) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] == mID) {
				count++;
				v[i] = -1;
			}
		}
		int free = 1;
		for (int i = n - 1; i >= 0; i--) {
			if (v[i] == -1) {
				next[i] = free;
				free++;
			}
			else {
				free = 1;
			}
		}
		return count;
	}
};