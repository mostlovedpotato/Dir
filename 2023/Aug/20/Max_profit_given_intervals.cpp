#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    int startTime;
    int endTime;
    int profit;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.endTime < b.endTime;
}

int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
    int n = startTime.size();
    std::vector<Job> jobs(n);

    for (int i = 0; i < n; ++i) {
        jobs[i] = { startTime[i], endTime[i], profit[i] };
    }

    std::sort(jobs.begin(), jobs.end(), compareJobs);

    std::vector<int> dp(n);

    for (int i = 0; i < n; ++i) {
        dp[i] = jobs[i].profit;
        for (int j = i - 1; j >= 0; --j) {
            if (jobs[j].endTime <= jobs[i].startTime) {
                dp[i] = std::max(dp[i], dp[j] + jobs[i].profit);
                break;
            }
        }
        if (i > 0) {
            dp[i] = std::max(dp[i], dp[i - 1]);
        }
    }

    return dp[n - 1];
}