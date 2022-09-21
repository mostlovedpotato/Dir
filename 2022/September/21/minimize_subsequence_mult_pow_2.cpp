#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> min_operations(vector<int> arr, int n) {
	long sum = 0;
	int idx = 0;
	long min = INT_MAX;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (arr[i] < min) {
			min = arr[i];
			idx = i + 1;
		}
	}
	long power = (long)(log2(sum));
	vector<int> ret;
	if (sum == (long(pow(2, power)))) {
		ret.push_back(0);
		return ret;
	}
	else {
		ret.push_back(1);
		ret.push_back((long)((pow(2, power + 1) - sum) / min)+1);
		ret.push_back(arr[idx - 1]);
	}
	return ret;
}