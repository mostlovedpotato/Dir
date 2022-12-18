#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool visited[100000];
vector<int> adj[(int)1e5 + 5];

void dfs(int i, int& minx, int& maxx) {
    visited[i] = true;
    minx = min(minx, i);
    maxx = max(maxx, i);
    for (auto x : adj[i]) {
        if (!visited[x]) {
            dfs(x, minx, maxx);
        }
    }
}

int maximumDifference(int g_nodes, vector<int> g_from, vector<int> g_to) {
    // vector<vector<int>> adj;

    for (int i = 0; i < g_from.size(); i++) {
        adj[g_from[i]].push_back(g_to[i]);
        adj[g_to[i]].push_back(g_from[i]);
    }
    int sum = 0;
    for (int i = 1; i <= g_nodes; i++) {
        if (!visited[i]) {
            int maxx = -1e9;
            int minn = +1e9;
            dfs(i, minn, maxx);
            if (maxx != -1e9 && minn != 1e9)
                sum += abs(maxx - minn);
        }
    }
    return sum;
}

int main()
{
    int g_nodes = 5;
    vector<int> from = { 1,1,2,2,3,4 };
    vector<int> to = { 2,3,3,4,4,5 };
    cout << maximumDifference(g_nodes, from, to);

    return 0;
}