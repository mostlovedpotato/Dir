#include<vector>
#include<algorithm>

using namespace std;


class Solution {
	int m, n;
	vector<int> dx = { -1,1,0,0 };
	vector<int> dy = { 0,0,-1,1 };
public:
	bool isValid(int i, int j) {
		return i >= 0 && j >= 0 && i < m&& j < n;
	}
	int dfs(int i, int j, int left, pair<int, int> dest, vector<vector<int>>& grid) {
		if (left == -1 && pair<int, int>(i, j) == dest)
			return 1;
		grid[i][j] = -1;
		int ans = 0;
		for (int k = 0; k < 4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];
			if (isValid(x, y) && grid[x][y] != -1)
				ans += dfs(x, y, left - 1, dest, grid);
		}
		grid[i][j] = 0;
		return ans;
	}
	int uniquepath3(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		pair<int, int> src, dest;
		int empty = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0)
					empty++;
				if (grid[i][j] == 1)
					src = { i,j };
				if (grid[i][j] == 2)
					dest = { i,j };
			}
		}
		return dfs(src.first, src.second, empty, dest, grid);
	}
};