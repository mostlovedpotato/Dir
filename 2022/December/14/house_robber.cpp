#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        if (n > 1)
            dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
    int rob(vector<int> nums, int n) {
        int pre = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
    }
};