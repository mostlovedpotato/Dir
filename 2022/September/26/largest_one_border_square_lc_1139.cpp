#include<iostream>
#include<vector>

using namespace std;

int largest1BorderedSquare(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::vector<std::vector<int>> rg(m, std::vector<int>(n));
    std::vector<std::vector<int>> cg(m, std::vector<int>(n));


    for (int i = 0; i < m; ++i) {
        rg[i][0] = grid[i][0];
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == 0) {
                rg[i][j] = 0;
            }
            else {
                rg[i][j] = rg[i][j - 1] + 1;
            }
        }
    }

    for (int j = 0; j < n; ++j) {

        cg[0][j] = grid[0][j];

        for (int i = 1; i < m; ++i) {
            if (grid[i][j] == 0) {
                cg[i][j] = 0;
            }
            else {
                cg[i][j] = cg[i - 1][j] + 1;
            }
        }
    }

    int res = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int h = std::min(rg[i][j], cg[i][j]);
            int q = 0;

            for (int k = h - 1; k >= 0; --k)
            {
                if ((cg[i][j - k] < k + 1) || (rg[i - k][j]) < k + 1) continue;
                else {
                    q = k + 1;
                    break;
                }
            }

            res = std::max(res, q);
        }
    }


    return res * res;
}