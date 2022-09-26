#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int kadane(vector<int> arr, int *start, int *finish, int n) {
	int sum = 0, max_sum = INT_MIN;
	*finish = -1;
	int local_start = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum < 0) {
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > max_sum) {
			max_sum = sum;
			*start = local_start;
			*finish = i;
		}
	}
	if (*finish != -1) {
		return max_sum;
	}
	// if all numbers are negative 
	max_sum = arr[0];
	*start = *finish = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > max_sum) {
			max_sum = arr[i];
			*start = *finish = i;
		}
	}
	return max_sum;
}

vector<int>  max_sum_rec(vector<vector<int>> mat) {
	int max_sum = INT_MIN;
	int col = mat.size();
	int row = mat[0].size();
	int finalleft, finalright, finaldown, finaltop;
	int left, right, start, finish;
	int sum;
	for (int left = 0; left < col; left++) {
		vector<int> temp(row, 0);
		for (int right = left; right < col; right++) {
			for (int i = 0; i < row; i++) {
				temp[i] += mat[i][right];
			}
			sum = kadane(temp, &start, &finish, row);
			if (sum > max_sum) {
				max_sum = sum;
				finalleft = left;
				finalright = right;
				finaltop = start;
				finaldown = finish;
			}
		}
	}
	vector<int> ans;
	ans.push_back(max_sum);
	ans.push_back(finalleft);
	ans.push_back(finalright);
	ans.push_back(finaltop);
	ans.push_back(finaldown);
	return ans;
}