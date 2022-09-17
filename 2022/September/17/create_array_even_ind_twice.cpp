#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


// Q .Given an integer N, the task is to generate an array A[] of length N such that it satisfies the following conditions for all 1 ≤ i ≤ N−1:

//Ai is multiple of Ai - 1 when i is odd
//Ai is not multiple of Ai - 1 when i is even
//All Ai are pairwise distinct
//1 ≤ Ai ≤ 2 * N

vector<int> create_array(int n) {
	int odd_ele = n - (int)floor(n / 2) + 1;
	int even_ele = 2 * odd_ele;
	vector<int> ret;
	for (int i = 1; i <= n; i++) {
		if ((i % 2) != 0) {
			ret.push_back(odd_ele);
			even_ele = 2 * odd_ele;
			odd_ele++;
		}
		else {
			ret.push_back(even_ele);
		}
	}
	return ret;
}