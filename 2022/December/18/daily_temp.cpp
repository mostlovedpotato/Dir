#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        vector<int> res(temp.size(), 0);
        for (int i = 0; i < temp.size(); i++) {
            while (!st.empty() && temp[i] > st.top().second) {
                res[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push(make_pair(i, temp[i]));
        }
        return res;
    }
};