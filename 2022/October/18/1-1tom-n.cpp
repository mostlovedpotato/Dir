#include<iostream>

using namespace std;

int num_paths(int m, int n) {
	int path = 1;
	for (int i = n; i < (m + n - 1); i++) {
		path *= i;
		path /= (i - n + 1);
	}
	return path;
}


// otherwise we can also do with dp ; 
// but space complexity will increase