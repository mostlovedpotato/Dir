#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
	return a.start < b.start;
}

vector<Interval> selectMaxNonOverlappingInterval(vector<Interval>& intervals) {
	sort(intervals.begin(), intervals.end(), compareIntervals);
	
	int n = intervals.size();
	vector<int> dp(n);
	vector<int> prevInterval(n, -1);
	int MaxLen = 0;
	int endIndex = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = intervals[i].end - intervals[i].start;
		for (int j = 0; j < i; j++) {
			if (intervals[j].end <= intervals[i].start) {
				if (dp[i] < dp[j] + intervals[i].end - intervals[i].start) {
					dp[i] = dp[j] + intervals[i].end - intervals[i].start;
					prevInterval[i] = j;
				}
			}
		}
		if (dp[i] > MaxLen) {
			MaxLen = dp[i];
			endIndex = i;
		}
	}
	vector<Interval> selectedIntervals;
	while (endIndex != -1) {
		selectedIntervals.push_back(intervals[endIndex]);
		return selectedIntervals;
	}
}