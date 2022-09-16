#include<iostream>

using namespace std;


// Q .Given 4 numbers N, M, X, Y.which represent N numbers for the first itemand M numbers
// for the second item, the task is to find the number of arrangements of N + M items together
// such that not more than X first items and not more than Y second items are placed successively.

int limit_first = 0, limit_second = 0;

//4d dp to store n,m,x,y at each point
int dp[101][101][11][11];

int count_ways(int n, int m, int x, int y) {
	if (n + m == 0)
		return 1;
	if (dp[n][m][x][y] != -1)
		return dp[n][m][x][y];
	if (n > 0 and x > 0)
		choose_first = count_ways(n - 1, m, x - 1, limit_second);
	else
		choose_second = count_ways(n, m - 1, limit_first, y - 1);
	return (choose_first + choose_second);
}

int main() {
	int n, m, x, y;
	//input(n, m, x, y);
	cin >> n >> m >> x >> y;
	limit_first = x;
	limit_second = y;
	// then init the 4d vector with -1 
	cout << count_ways(n, m, x, y) << endl;
	return 0;
}