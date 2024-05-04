class Solution {
    vector<vector<long long>> dp;
    long long maxSum(int curr, bool c, int parent, vector<int>& nums, int k, vector<vector<int>>& adjList) {
        if (dp[curr][c] != -1)
            return dp[curr][c];
        int val = (c ? nums[curr] ^ k : nums[curr]);
        long long sum = max(val ^ k, val);
        int numChanges = (val ^ k) > val, minChange = abs((val ^ k) - val);
        for (int nbr : adjList[curr]) {
            if (nbr == parent)
                continue;
            long long withOp = maxSum(nbr, true, curr, nums, k, adjList);
            long long withoutOp = maxSum(nbr, false, curr, nums, k, adjList);
            sum += max(withOp, withoutOp);
            // cout << nbr << ": " << sum << endl;
            numChanges += (withOp > withoutOp);
            minChange = min(minChange, (int)abs(withOp - withoutOp));
        }
        dp[curr][c] = (sum - (numChanges % 2 ? minChange : 0));
        // cout << "dp[" << curr << "," << c << "] = " << dp[curr][c] << endl;
        return dp[curr][c];
    }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector adjList(n, vector<int>());
        for (auto& e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        dp.resize(n, vector<long long>(2, -1));
        // cout << "Ok\n";
        return maxSum(0, false, -1, nums, k, adjList);
    }
};