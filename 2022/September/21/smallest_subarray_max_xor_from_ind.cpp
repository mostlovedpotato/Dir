#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> max_or_array(vector<int>& nums) {
	int n = nums.size();
	if (n == 1 && nums[0] == 0)
		return { 1 };
	vector<int> next(n), ans(n);
	next[n - 1] = nums[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		next[i] = next[i + 1] | nums[i];
	}
	for (int i = 0; i < n; i++) {
		int j = i;
		int x = 0;
		while (j < n && x != next[i]) {
			x |= nums[j];
			j++;
		}
		if (j < n && nums[j] == 0 && i == j) {
			j++;
		}
		ans[i] = j - i;
	}
	return ans;
}

vector<int> max_or_vector(vector<int>& nums) {
	int n = nums.size();
	vector<int> res(n, 1);
	vector<int> latest(32);
	for(int i=n-1;i>=0;i--){
		for (int j = 0; j < 32; j++) {
			if (nums[i] & (1 << j)) {
				latest[j] = i;
			}
			res[i] = max(res[i], latest[j] - i + 1);
		}
	}
	return res;
}