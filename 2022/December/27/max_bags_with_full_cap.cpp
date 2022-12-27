#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        // vector<pair<int,int>> vpi;
        vector<int> gp;
        for (int i = 0; i < n; i++) {
            int gap = capacity[i] - rocks[i];
            gp.push_back(gap);
        }
        sort(gp.begin(), gp.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (gp[i] == 0)
                cnt++;
            else {
                if (gp[i] <= additionalRocks) {
                    additionalRocks -= gp[i];
                    cnt++;
                }
            }
        }
        return cnt;
    }
};