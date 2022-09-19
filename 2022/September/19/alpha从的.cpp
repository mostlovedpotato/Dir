#include<iostream>
#include<vector>

using namespace std;

// alphacodes decoding ways

int num_codes(vector<int> input) {
	int n = input.size();
	vector<int> output(n + 1);
	output[0] = 1;
	output[1] = 1;
	for (int i = 2; i <= n; i++) {
		output[i] = output[i - 1];
		if (input[i - 2] * 10 + input[i - 1] <= 26) {
			output[i] += output[i - 2];
		}
	}
	return output[n];
}