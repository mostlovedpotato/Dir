#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<pair<int, int>> vpi;
        for (int i = 0; i < in.size(); i++) {
            vpi.push_back(make_pair(in[i][0], in[i][1]));
        }
        vector<vector<int>> ans;
        sort(vpi.begin(), vpi.end());
        int curr_start = vpi[0].first;
        int curr_end = vpi[0].second;

        for (int i = 1; i < vpi.size(); i++) {
            if (vpi[i].first > curr_end) {
                vector<int> temp;
                temp.push_back(curr_start);
                temp.push_back(curr_end);
                ans.push_back(temp);
                curr_start = vpi[i].first;
                curr_end = vpi[i].second;
            }
            else {
                curr_end = max(vpi[i].second, curr_end);
            }
        }
        vector<int> temp;
        temp.push_back(curr_start);
        temp.push_back(curr_end);
        ans.push_back(temp);
        return ans;
    }
};