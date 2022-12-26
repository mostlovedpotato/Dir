#include<vector>
#include<iostream>


using namespace std;

void diagonal_print(vector<vector<int>>& A) {
    int n = A.size();
    int N = 2 * n - 1;
    vector<vector<int>> res(N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i + j].push_back(A[i][j]);
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << endl;
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
    }
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    diagonal_print(A);

    return 0;
}