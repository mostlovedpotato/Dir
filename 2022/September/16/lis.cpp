#include<iostream>
#include<algorith>


//longest increasing subsequence
// almost n*log(n) time complexity

int lis(std::vector<int>& vi) {
	if (vi.size() == 0)
		return 0;
	std::vector<int> end(vi.size(), 0);
	int length = 1;

	end[0] = vi[0];
	for (int i = 1; i < vi.size(); i++) {
		auto begin_ind = end.begin();
		auto end_ind = begin_ind + length;
		auto it = lower_bound(begin_ind, end_ind, vi[i]);
		if (it == end.begin() + length) {
			end[length++] = vi[i];
		}
		else {
			*it = vi[i];
		}
	}
	return length;
}
