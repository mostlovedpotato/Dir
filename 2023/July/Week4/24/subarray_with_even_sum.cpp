#include <iostream> 
#include <vector>

using namespace std;

vector<int> subarray_even_sum(vector<int> arr, vector<vector<int>> queries, int n, int m) {
	arr.insert(arr.begin(), 0);
	vector<int> cnt(n + 1), sum(n + 1);
	cnt[0] = sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = (sum[i - 1] + arr[i]) % 2;
		cnt[i] = cnt[i - 1];
		if (sum[i] % 2 == 0) {
			cnt[i]++;
		}
	}
	vector<int> ans;

	for (vector<int> qu : queries) {
		int L = qu[0], R = qu[1];
		int even = cnt[R] - cnt[L-1];
		int odd = R - L + 1 - even;

		if (sum[L - 1] % 2) {
			swap(even, odd);
		}
		even++;
		int qu_cnt = (even * (even - 1)) / 2 + (odd * (odd - 1)) / 2;
		ans.push_back(qu_cnt);
	}
	return ans;
}


int main() {

}