#include<iostream>
#include<vector>


using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}


// We here have first base case i==0 and w==0 
// if we have traversed through all array of wts then we stop and
// return 0 as no more elemnt possible.
// or else if the weight capacity is reached then also we return 0.
// as we can't include any more 
// then if we have current weight greater than the remaining capcity 
// in the specific recursion then we won't be including that element
// Or else we will return maximum of two choices either take the element
// and include the sum and reduce the weight or second condition 
// without including the element same remaining capacity.

int knapsack(int w, vector<int> wt, vector<int> val, int i) {
	if (i == 0 || w == 0) {
		return 0;
	}
	if (wt[i - 1] > w) {
		return knapsack(w, wt, val, i - 1);
	}
	else {
		return max(val[i - 1] + knapsack(w - wt[i - 1], wt, val, i - 1), knapsack(w, wt, val, i - 1));
	}
}

// tabulation dp 

int knapsack(int w, vector<int> wt, vector<int> val) {
	int n = wt.size();
	vector<vector<int>> mat(n + 1, vector<int>(w + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			if (i == 0 || j == 0) {
				mat[i][j] = 0;
			}
			else if (wt[i - 1] <= j) {
				mat[i][j] = max(val[i - 1] + mat[i][j - wt[i - 1]], mat[i - 1][j]);
			}
			else {
				mat[i][j] = mat[i - 1][j];
			}
		}
	}
	return mat[n][w];
}