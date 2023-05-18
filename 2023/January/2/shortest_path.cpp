#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void shortestPath(int i, int j, int k, int m, int n) {
	vector<int> path1, path2;
	int x = m - 1;
	path1.push_back(i);
	while (x != k) {
		path1.push_back(i / 2);
		i /= 2;
		x--;
	}
	int y = n - 1;
	path2.push_back(j);
	while (y != k) {
		path2.push_back(j / 2);
		j /= 2;
		y--;
	}
	//print path1,path2
}

int shortestDistance(int i, int j) {
	vector<int> v1, v2;
	int p1 = i;
	int p2 = j;
	while (i != 0) {
		v1.push_back(i % 2);
		i = i / 2;
	}
	while (j != 0) {
		v2.push_back(j % 2);
		j = j / 2;
	}
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());
	int m = v1.size();
	int n = v2.size();
	int k = 0;
	if (m < n) {
		while (k < m && v1[k] == v2[k])
			k++;
	}
	else {
		while (k < n && v1[k] == v2[k])
			k++;
	}
	shortestPath(p1, p2, k - 1, m, n);
	return m + n - 2 * k;
}