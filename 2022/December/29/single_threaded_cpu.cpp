#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
#include<iomanip>

using namespace std;

class Solution {
    typedef pair<int, int> T;
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<T, vector<T>, greater<>> pq;
        long n = tasks.size();
        long time = 0, i = 0;
        for (int i = 0; i < n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        vector<int> ans;
        while (i < n || pq.size()) {
            if (pq.empty()) {
                time = max((long)tasks[i][0], time);
            }
            while (i < n && time >= tasks[i][0]) {
                pq.emplace(tasks[i][1], tasks[i][2]);
                ++i;
            }
            auto [processing_time, index] = pq.top();
            pq.pop();
            time += processing_time;
            ans.push_back(index);
        }
        return ans;

    }
};