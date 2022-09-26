#include<iostream>
#include<vector>


using namespace std;


bool is_possible() {
	int n, m; cin >> n >> m;
	vector<vector<int>> vvi(n + 1, vector<int>(3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> vvi[i][j];
		}
	}

}