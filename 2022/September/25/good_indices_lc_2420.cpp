#include<iostream>
#include<vector>

using namespace std;

vector<int> increasing(vector<int> nums) {
	vector<int> ret(nums.size());
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] >= nums[i - 1]) {
			ret[i] = ret[i - 1] + 1;
		}
		else {
			ret[i] = 0;
		}
	}
	return ret;
}

vector<int> decreasing(vector<int> nums) {
	vector<int> ret(nums.size());
	for (int i = nums.size() - 2; i >= 0; i--) {
		if (nums[i] >= nums[i + 1]) {
			ret[i] = ret[i + 1] + 1;
		}
		else {
			ret[i] = 0;
		}
	}
	return ret;
}

// before i index decreasing that means. 
vector<int> good_indices(vector<int> vi, int k) {
	vector<int> ans;
	vector<int> decr = decreasing(vi);
	vector<int> incr = increasing(vi);
	for (int i = k; i < vi.size(); i++) {
		if ((decr[i - k] - decr[i - 1] == k - 1) && (incr[i + k] - incr[i + 1] == k - 1)) {
			ans.push_back(i);
		}
	}
	return ans;
}